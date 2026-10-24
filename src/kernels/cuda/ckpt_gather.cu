// src/kernels/cuda/ckpt_gather.cu - STRATA_CKPT_ASYNC: the small parts of a checkpoint's running state into one image.
//
// A turn checkpoint's PLE history and each QSA layer's indexer tail are a few hundred kilobytes together, but they are
// scattered over 13 allocations, and a device-to-host copy per allocation costs more than the bytes: measured on the
// RTX 3090, 37 such copies held the host for about 70 ms, while the 112 MB of GDN rows behind them took 10 ms.  One
// kernel writes them all into the pinned staging image (device-writable, cudaHostAllocMapped), on the copy stream,
// so one event after it says every small part is out.
#include "strata/kernels/verify_kernels.hpp"

#include <cuda_runtime.h>

namespace strata::kernels {
namespace {

__global__ void ckpt_gather_kernel(uint8_t* image, const CkptGatherSpan* spans, size_t n) {
    const int i = (int) blockIdx.x;
    if (i >= n) return;
    const uint8_t* src = (const uint8_t*) spans[i].src;
    uint8_t* dst = image + spans[i].dst_at;
    for (size_t k = threadIdx.x; k < spans[i].bytes; k += blockDim.x) dst[k] = src[k];
}

}  // namespace

bool ckpt_gather(void* image, const CkptGatherSpan* spans, size_t n, void* stream) {
    if (n <= 0) return true;
    if (image == nullptr || spans == nullptr) return false;
    ckpt_gather_kernel<<<(unsigned) n, 128, 0, (cudaStream_t) stream>>>((uint8_t*) image, spans, n);
    return cudaGetLastError() == cudaSuccess;
}

}  // namespace strata::kernels
