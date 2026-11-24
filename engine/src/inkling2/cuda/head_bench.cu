// Microbenchmark: the vocabulary head's GEMV, one CTA per 8 rows (k_ink_gemv_multi_bf16) against the persistent grid
// walk (k_ink_gemv_head_bf16). Same shapes as Inkling 2 Mini SQ-15: N = 200058, K = 2304, BF16 weights.
//   head_bench [M] [iterations]
#include "ink_kernels.cuh"
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace strata::ink;

int main(int argc, char** argv) {
    const int M = argc > 1 ? std::atoi(argv[1]) : 5;
    const int iters = argc > 2 ? std::atoi(argv[2]) : 30;
    const int N = 200058, K = kInkHidden;
    __nv_bfloat16 *W = nullptr, *W2 = nullptr;
    float *X = nullptr, *Y = nullptr, *Y2 = nullptr;
    if (cudaMalloc(&W, (size_t)N * K * 2) != cudaSuccess) { printf("alloc W failed\n"); return 1; }
    cudaMalloc(&W2, (size_t)N * K * 2);
    cudaMalloc(&X, (size_t)M * K * 4);
    cudaMalloc(&Y, (size_t)M * N * 4);
    cudaMalloc(&Y2, (size_t)M * N * 4);
    std::vector<__nv_bfloat16> hw((size_t)N * K);
    for (size_t i = 0; i < hw.size(); ++i) hw[i] = __float2bfloat16((float)((int)(i * 2654435761u) % 2001 - 1000) / 1000.0f);
    cudaMemcpy(W, hw.data(), hw.size() * 2, cudaMemcpyHostToDevice);
    cudaMemcpy(W2, hw.data(), hw.size() * 2, cudaMemcpyHostToDevice);
    std::vector<float> hx((size_t)M * K);
    for (size_t i = 0; i < hx.size(); ++i) hx[i] = (float)((int)(i * 40503u % 1000) - 500) / 500.0f;
    cudaMemcpy(X, hx.data(), hx.size() * 4, cudaMemcpyHostToDevice);

    int dev = 0, sms = 0;
    cudaGetDevice(&dev);
    cudaDeviceGetAttribute(&sms, cudaDevAttrMultiProcessorCount, dev);
    const int old_grid = (N + 7) / 8;
    const int new_grid = std::max(64, std::min(old_grid, sms * 8));

    InkMultiProj mp{};
    mp.W[0] = reinterpret_cast<const uint8_t*>(W); mp.Y[0] = Y; mp.N[0] = N;
    mp.cumN[0] = 0; mp.cumN[1] = N; mp.count = 1;

    auto launch_old = [&]() {
        if (M == 1)      k_ink_gemv_multi_bf16<1, false><<<old_grid, 128>>>(mp, X, M, K);
        else if (M <= 4) k_ink_gemv_multi_bf16<4, false><<<old_grid, 128>>>(mp, X, M, K);
        else if (M <= 8) k_ink_gemv_multi_bf16<8, false><<<old_grid, 128>>>(mp, X, M, K);
        else             k_ink_gemv_multi_bf16<16, false><<<old_grid, 128>>>(mp, X, M, K);
    };
    auto launch_new = [&]() {
        if (M == 1)      k_ink_gemv_head_bf16<1><<<new_grid, 128>>>(W2, X, M, N, K, Y2);
        else if (M <= 4) k_ink_gemv_head_bf16<4><<<new_grid, 128>>>(W2, X, M, N, K, Y2);
        else if (M <= 8) k_ink_gemv_head_bf16<8><<<new_grid, 128>>>(W2, X, M, N, K, Y2);
        else             k_ink_gemv_head_bf16<16><<<new_grid, 128>>>(W2, X, M, N, K, Y2);
    };
    launch_old(); launch_new();
    cudaError_t e = cudaDeviceSynchronize();
    if (e != cudaSuccess) { printf("launch failed: %s\n", cudaGetErrorString(e)); return 1; }
    std::vector<float> y((size_t)M * N), y2((size_t)M * N);
    cudaMemcpy(y.data(), Y, y.size() * 4, cudaMemcpyDeviceToHost);
    cudaMemcpy(y2.data(), Y2, y2.size() * 4, cudaMemcpyDeviceToHost);
    double maxd = 0; size_t ndiff = 0;
    for (size_t i = 0; i < y.size(); ++i) { double d = std::fabs((double)y[i] - (double)y2[i]); maxd = std::max(maxd, d); if (y[i] != y2[i]) ++ndiff; }
    printf("M=%d N=%d K=%d grids: old %d CTAs, new %d CTAs | parity: %zu of %zu differ, max |d| %.3g\n",
           M, N, K, old_grid, new_grid, ndiff, y.size(), maxd);

    cudaEvent_t a, b; cudaEventCreate(&a); cudaEventCreate(&b);
    auto time_it = [&](auto fn) {
        std::vector<double> v;
        for (int i = 0; i < iters; ++i) {
            cudaEventRecord(a); fn(); cudaEventRecord(b); cudaEventSynchronize(b);
            float ms = 0; cudaEventElapsedTime(&ms, a, b); v.push_back(ms);
        }
        std::sort(v.begin(), v.end());
        return v[v.size() / 2];
    };
    double t_old = time_it(launch_old), t_new = time_it(launch_new);
    printf("median of %d: old %.3f ms, new %.3f ms (%.2fx) | bytes %.0f MB -> old %.0f GB/s, new %.0f GB/s\n",
           iters, t_old, t_new, t_old / t_new, (double)N * K * 2 / 1e6,
           (double)N * K * 2 / 1e6 / t_old, (double)N * K * 2 / 1e6 / t_new);
    return 0;
}
