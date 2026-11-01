// R9-hs-2 host test: the coalesce predicate for queued part refills (CPU-only, needs no device).
#include "strata/core/expert_cache.hpp"

#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace strata::core;
namespace {
int checks = 0;
void check(bool ok, const char* label) {
    ++checks;
    if (!ok) { std::fprintf(stderr, "FAIL (want true): %s\n", label); std::exit(1); }
}
void check_false(bool ok, const char* label) {
    ++checks;
    if (ok) { std::fprintf(stderr, "FAIL (want false): %s\n", label); std::exit(1); }
}
}

int main() {
    std::vector<uint8_t> buf(4096);
    const uint8_t* b = buf.data();
    {   // the default three-part map: gapless destination, contiguous sources
        BlobPart p[3] = {{b, 1024, 0}, {b + 1024, 1024, 1024}, {b + 2048, 2048, 2048}};
        check(parts_run_contiguous(p, 3), "three gapless parts");
    }
    {   // single part
        BlobPart p[1] = {{b, 2560, 0}};
        check(parts_run_contiguous(p, 1), "one part from zero");
    }
    {   // destination gap
        BlobPart p[2] = {{b, 1024, 0}, {b + 1024, 1024, 1536}};
        check_false(parts_run_contiguous(p, 2), "destination gap");
    }
    {   // source gap: mmap pieces that are not one run
        static std::vector<uint8_t> far(2048);
        BlobPart p[2] = {{b, 1024, 0}, {far.data(), 1024, 1024}};
        check_false(parts_run_contiguous(p, 2), "source gap");
    }
    {   // not starting at the slot's first byte
        BlobPart p[2] = {{b, 1024, 1024}, {b + 1024, 1024, 2048}};
        check_false(parts_run_contiguous(p, 2), "run does not start at zero");
    }
    {   // parts out of destination order
        BlobPart p[2] = {{b + 1024, 1024, 1024}, {b, 1024, 0}};
        check_false(parts_run_contiguous(p, 2), "parts unordered");
    }
    {   // degenerate: none
        check_false(parts_run_contiguous(nullptr, 0), "no parts");
        check_false(parts_run_contiguous(b ? (BlobPart*) nullptr : nullptr, 3), "null parts");
    }
    std::printf("refill_parts_test: %d checks pass\n", checks);
    return 0;
}
