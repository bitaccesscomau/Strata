// src/kernels/partial_plan_parity.cpp - STRATA_VERIFY_PARTIAL_PLAN's two kernels against a host replay of the host
// pool's plan (expert_source.cpp, expert_pool_dispatch_multi): distinct experts in routing order, the resident ones
// (VRAM) as groups with their entries ascending from entry 0, then the PCIe groups, their entries after the VRAM ones.
//
//   partial_plan    must write exactly the host plan's VRAM part (counts[0], start, dst, tok, ptr) whatever the other
//                   experts are: n = 1..80 entries, ids from pools of 3..512 experts, a residency table with none, a
//                   quarter, three quarters or all of the experts resident, with and without a slot table, and the
//                   test hook's skew.
//   wait_copy_plan  waits for its mapped flag, copies the host's plan; while the device's VRAM part equals the host's
//                   the copy is the host's plan word for word (counts[3] = counts[2] added), and when it differs (the
//                   skew: the device planned fewer experts; a stale device table: it planned experts the host has
//                   evicted) the PCIe call's list holds every GPU entry of the host's plan (its PCIe groups first,
//                   entries from 0, then its VRAM groups), the set of GPU rows is unchanged and the mapped fix-up count
//                   rises by one.
//
// GPU, synthetic, no model.
#include "strata/kernels/verify_kernels.hpp"

#include <cuda_runtime.h>

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <random>
#include <thread>
#include <tuple>
#include <vector>

namespace k = strata::kernels;

namespace {
void ck(cudaError_t e, const char* w) {
    if (e != cudaSuccess) {
        std::fprintf(stderr, "%s: %s\n", w, cudaGetErrorString(e));
        std::exit(2);
    }
}

constexpr int K = 10, NE = 512;
constexpr long long capx = (long long) k::kVerifyMaxT * K;
constexpr long long ptr_off = ((4 + (capx + 1) + 2 * capx) + 1) & ~1ll;
constexpr size_t plan_words = (size_t) (ptr_off + 4 * capx + (capx + 1) + 1);   // Verifier::plan_i32_
constexpr long long blob = 1337;

struct Plan {   // the host pool's plan of one window group
    int g0 = 0, e = 0, f = 0;
    std::vector<int32_t> start, dst, tok, start2;
    std::vector<unsigned long long> ptr, ptr2;
};

// expert_pool_dispatch_multi's plan: VRAM groups (resident by `res`, test skew excluded), then the PCIe groups (every
// `pcie_every`-th missed expert, staging pointers), then the CPU rows (not in the plan)
Plan host_plan(const std::vector<int32_t>& ids, const std::vector<int32_t>& res, const unsigned long long* off,
               uintptr_t cache_base, int skew, int pcie_every) {
    const int n = (int) ids.size();
    Plan p;
    std::vector<int> first_of(n);
    std::vector<int> distinct;
    for (int i = 0; i < n; ++i) {
        first_of[i] = i;
        for (int j = 0; j < i; ++j)
            if (ids[j] == ids[i]) { first_of[i] = first_of[j]; break; }
        if (first_of[i] == i) distinct.push_back(i);
    }
    auto resident = [&](int32_t e) { return e >= 0 && e < NE && res[(size_t) e] >= 0 && !(skew > 0 && e % skew == 0); };
    for (int i0 : distinct) {
        if (!resident(ids[i0])) continue;
        const int32_t slot = res[(size_t) ids[i0]];
        p.ptr.push_back((unsigned long long) cache_base +
                        (off ? off[slot] : (unsigned long long) slot * (unsigned long long) blob));
        p.start.push_back((int32_t) p.dst.size());
        for (int i = i0; i < n; ++i)
            if (first_of[i] == i0) { p.dst.push_back(i); p.tok.push_back(i / K); }
    }
    p.g0 = (int) p.ptr.size();
    p.start.push_back((int32_t) p.dst.size());
    int miss = 0;
    for (int i0 : distinct) {
        if (resident(ids[i0])) continue;
        if (pcie_every <= 0 || miss++ % pcie_every != 0 || (int) p.ptr2.size() >= 16) continue;
        p.ptr2.push_back(0xA0000000ull + (unsigned long long) p.ptr2.size() * 4096ull);
        p.start2.push_back((int32_t) p.dst.size());
        for (int i = i0; i < n; ++i)
            if (first_of[i] == i0) { p.dst.push_back(i); p.tok.push_back(i / K); }
    }
    p.f = (int) p.ptr2.size();
    p.start2.push_back((int32_t) p.dst.size());
    p.e = (int) p.dst.size();
    return p;
}

// the plan block's words, as the host pool writes them into mapped memory (counts[3] is never written there)
std::vector<int32_t> words_of(const Plan& p) {
    std::vector<int32_t> w(plan_words, 0);
    w[0] = p.g0;
    w[1] = p.e;
    w[2] = p.f;
    int32_t* start = w.data() + 4;
    int32_t* dst = start + capx + 1;
    int32_t* tok = dst + capx;
    std::copy(p.start.begin(), p.start.end(), start);
    std::copy(p.dst.begin(), p.dst.end(), dst);
    std::copy(p.tok.begin(), p.tok.end(), tok);
    std::memcpy(w.data() + ptr_off, p.ptr.data(), p.ptr.size() * 8);
    std::memcpy(w.data() + ptr_off + 2 * capx, p.ptr2.data(), p.ptr2.size() * 8);
    std::copy(p.start2.begin(), p.start2.end(), w.data() + ptr_off + 4 * capx);
    return w;
}

// every GPU entry of a plan block as (pointer, row, token), from its VRAM groups and its PCIe list
std::vector<std::tuple<unsigned long long, int32_t, int32_t>> gpu_entries(const std::vector<int32_t>& w) {
    std::vector<std::tuple<unsigned long long, int32_t, int32_t>> out;
    const int32_t* start = w.data() + 4;
    const int32_t* dst = start + capx + 1;
    const int32_t* tok = dst + capx;
    const auto* ptr = (const unsigned long long*) (w.data() + ptr_off);
    const auto* ptr2 = ptr + capx;
    const int32_t* start2 = w.data() + ptr_off + 4 * capx;
    for (int g = 0; g < w[0]; ++g)
        for (int i = start[g]; i < start[g + 1]; ++i) out.emplace_back(ptr[g], dst[i], tok[i]);
    for (int q = 0; q < w[2]; ++q)
        for (int i = start2[q]; i < start2[q + 1]; ++i) out.emplace_back(ptr2[q], dst[i], tok[i]);
    std::sort(out.begin(), out.end());
    return out;
}
}  // namespace

int main() {
    std::mt19937 rng(1517);
    uint8_t* const cache_base = reinterpret_cast<uint8_t*>(uintptr_t(0x40000000));   // never dereferenced

    int32_t *d_ids, *d_res, *d_dev, *d_plan;
    unsigned long long* d_off;
    ck(cudaMalloc(&d_ids, 128 * 4), "ids");
    ck(cudaMalloc(&d_res, NE * 4), "res");
    ck(cudaMalloc(&d_off, 1024 * 8), "off");
    ck(cudaMalloc(&d_dev, plan_words * 4), "dev plan");
    ck(cudaMalloc(&d_plan, plan_words * 4), "plan");
    // mapped host memory, as the verifier's flag B, plan block and fix-up word are
    uint32_t *h_flag = nullptr, *m_flag = nullptr, *h_fix = nullptr, *m_fix = nullptr;
    int32_t *h_src = nullptr, *m_src = nullptr;
    ck(cudaHostAlloc((void**) &h_flag, 64, cudaHostAllocMapped), "flag");
    ck(cudaHostGetDevicePointer((void**) &m_flag, h_flag, 0), "flag dev");
    ck(cudaHostAlloc((void**) &h_fix, 64, cudaHostAllocMapped), "fix");
    ck(cudaHostGetDevicePointer((void**) &m_fix, h_fix, 0), "fix dev");
    ck(cudaHostAlloc((void**) &h_src, plan_words * 4, cudaHostAllocMapped), "src");
    ck(cudaHostGetDevicePointer((void**) &m_src, h_src, 0), "src dev");
    *(volatile uint32_t*) h_flag = 0;
    *(volatile uint32_t*) h_fix = 0;

    std::vector<unsigned long long> off(1024);
    for (int s = 0; s < 1024; ++s) off[s] = (unsigned long long) s * 4096 + (s % 7) * 64;
    ck(cudaMemcpy(d_off, off.data(), 1024 * 8, cudaMemcpyHostToDevice), "off");

    int cases = 0, bad = 0;
    uint32_t ring = 0, fixups_want = 0;
    for (int resident_q = 0; resident_q <= 4; ++resident_q) {   // 0, 1/4, 1/2 ... of the experts resident (4: all)
        std::vector<int32_t> res(NE), res_stale(NE);
        for (int e = 0; e < NE; ++e)
            res[e] = (int) (rng() % 4) < resident_q ? (e * 37 + 11) % 1000 : -1;   // distinct slots, not the identity
        // a device table that still holds experts the host has evicted (each fifth missed one), as one that lags would
        for (int e = 0; e < NE; ++e) res_stale[e] = res[e] < 0 && e % 5 == 0 ? (e * 37 + 11) % 1000 : res[e];
        for (int n = 1; n <= 80; ++n) {
            for (int variant = 0; variant < 4; ++variant) {
                const int pool = variant == 0 ? 3 : (variant == 1 ? 12 : (variant == 2 ? 40 : 512));
                std::vector<int32_t> ids(n);
                for (int i = 0; i < n; ++i) ids[i] = (int32_t) ((rng() % pool) * (512 / pool));
                const bool use_off = (n + variant) % 2 == 1;
                ck(cudaMemcpy(d_ids, ids.data(), n * 4, cudaMemcpyHostToDevice), "ids");
                // mode 0: the tables agree; 1: the test hook's skew (the device plans fewer); 2: a stale device table
                // (the device plans experts the host computes elsewhere)
                for (int mode = 0; mode < 3; ++mode) {
                    const int skew = mode == 1 ? 7 : 0;
                    const std::vector<int32_t>& dres = mode == 2 ? res_stale : res;
                    ck(cudaMemcpy(d_res, dres.data(), NE * 4, cudaMemcpyHostToDevice), "res");
                    // ---- partial_plan: the host plan's VRAM part (by the device's table)
                    const Plan ref = host_plan(ids, dres, use_off ? off.data() : nullptr, (uintptr_t) cache_base, skew, 0);
                    ck(cudaMemset(d_dev, 0xAB, plan_words * 4), "fill");
                    k::partial_plan(d_ids, n, K, d_res, NE, cache_base, use_off ? d_off : nullptr, blob, d_dev, capx, skew,
                                    nullptr);
                    ck(cudaDeviceSynchronize(), "sync");
                    std::vector<int32_t> dev(plan_words);
                    ck(cudaMemcpy(dev.data(), d_dev, plan_words * 4, cudaMemcpyDeviceToHost), "dev");
                    const int32_t want_counts[4] = {ref.g0, ref.e, 0, 0};
                    bool ok = std::memcmp(dev.data(), want_counts, sizeof want_counts) == 0;
                    ok = ok && std::memcmp(dev.data() + 4, ref.start.data(), ref.start.size() * 4) == 0;
                    const int32_t* pdst = dev.data() + 4 + capx + 1;
                    ok = ok && std::memcmp(pdst, ref.dst.data(), ref.dst.size() * 4) == 0;
                    ok = ok && std::memcmp(pdst + capx, ref.tok.data(), ref.tok.size() * 4) == 0;
                    ok = ok && std::memcmp(dev.data() + ptr_off, ref.ptr.data(), ref.ptr.size() * 8) == 0;
                    ok = ok && dev[(size_t) (ptr_off + 4 * capx)] == ref.e;
                    ++cases;
                    if (!ok) {
                        std::printf("    *** partial_plan n=%d pool=%d resident=%d/4 %s mode=%d: differs from the host's VRAM groups ***\n",
                                    n, pool, resident_q, use_off ? "slot_off" : "blob", mode);
                        ++bad;
                    }
                    // ---- wait_copy_plan: the host's whole plan (its own table, no skew) against that device plan
                    const Plan host = host_plan(ids, res, use_off ? off.data() : nullptr, (uintptr_t) cache_base, 0, 2);
                    const std::vector<int32_t> hw = words_of(host);
                    std::memcpy(h_src, hw.data(), plan_words * 4);
                    ++ring;
                    *(volatile uint32_t*) h_flag = ring;
                    ck(cudaMemset(d_plan, 0xCD, plan_words * 4), "fill plan");
                    k::wait_copy_plan(m_flag, ring, d_plan, m_src, (long long) plan_words, d_dev, capx, m_fix, nullptr);
                    ck(cudaDeviceSynchronize(), "sync");
                    std::vector<int32_t> got(plan_words);
                    ck(cudaMemcpy(got.data(), d_plan, plan_words * 4, cudaMemcpyDeviceToHost), "got");
                    const int e0 = host.start[(size_t) host.g0];   // the host's VRAM entries
                    const bool differ = !(ref.g0 == host.g0 && ref.e == e0 && ref.start == host.start && ref.ptr == host.ptr &&
                                          std::equal(ref.dst.begin(), ref.dst.end(), host.dst.begin()) &&
                                          std::equal(ref.tok.begin(), ref.tok.end(), host.tok.begin()));
                    if (mode == 0 && differ) {
                        std::printf("    *** the replays disagree with the same table (test bug) ***\n");
                        ++bad;
                    }
                    bool ok2 = true;
                    if (!differ) {   // the copy, word for word, plus counts[3]
                        std::vector<int32_t> want = hw;
                        want[3] = host.f;
                        ok2 = std::memcmp(got.data(), want.data(), plan_words * 4) == 0;
                    } else {         // the recompute: the PCIe list carries every GPU entry of the host's plan
                        ++fixups_want;
                        ok2 = got[0] == 0 && got[1] == host.e && got[2] == host.f + host.g0 && got[3] == host.f;
                        ok2 = ok2 && gpu_entries(got) == gpu_entries(hw);
                        const int32_t* start2 = got.data() + ptr_off + 4 * capx;
                        for (int q = 0; ok2 && q < got[2]; ++q) ok2 = start2[q] <= start2[q + 1];
                        ok2 = ok2 && start2[0] == 0 && start2[got[2]] == host.e;
                        // the staged ones (the host's PCIe groups) first, their pointers as the host wrote them
                        const auto* ptr2 = (const unsigned long long*) (got.data() + ptr_off + 2 * capx);
                        for (int q = 0; ok2 && q < host.f; ++q) ok2 = ptr2[q] == host.ptr2[(size_t) q];
                    }
                    ok2 = ok2 && *(volatile uint32_t*) h_fix == fixups_want;
                    ++cases;
                    if (!ok2) {
                        std::printf("    *** wait_copy_plan n=%d pool=%d resident=%d/4 %s mode=%d differ=%d: wrong plan or fix-up count (%u, want %u) ***\n",
                                    n, pool, resident_q, use_off ? "slot_off" : "blob", mode, (int) differ,
                                    *(volatile uint32_t*) h_fix, fixups_want);
                        ++bad;
                    }
                }
            }
        }
    }

    // wait_copy_plan waits for its flag: launched with the flag one below, it must still be running 50 ms later, and
    // finish once the flag is raised
    {
        cudaStream_t s;
        ck(cudaStreamCreateWithFlags(&s, cudaStreamNonBlocking), "stream");
        ++ring;
        *(volatile uint32_t*) h_flag = ring - 1;
        k::wait_copy_plan(m_flag, ring, d_plan, m_src, (long long) plan_words, d_dev, capx, nullptr, s);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        const cudaError_t q = cudaStreamQuery(s);
        *(volatile uint32_t*) h_flag = ring;
        ck(cudaStreamSynchronize(s), "wait sync");
        ++cases;
        if (q != cudaErrorNotReady) {
            std::printf("    *** wait_copy_plan did not wait for its flag (%s) ***\n", cudaGetErrorString(q));
            ++bad;
        }
        cudaStreamDestroy(s);
    }

    std::printf("partial_plan / wait_copy_plan: %d cases, %d failures, %u recomputes\n", cases, bad, fixups_want);
    if (bad) return 1;
    std::printf("partial_plan_parity OK\n");
    return 0;
}
