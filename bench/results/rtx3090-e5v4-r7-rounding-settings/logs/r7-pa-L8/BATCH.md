# r7-pa-L8

- Job exit ?, restore exit ? (the lab wrapper stopped production, ran the job, restored production and verified it with a real completion).
- Runs in this directory: L8-01-B, L8-02-A20, L8-03-B, L8-07-B, L8-08-A20, L8-09-B.
- Runs of this batch not copied here (exact-class settings, or baselines paired only with them): L8-04-A21 (A21), L8-05-B (B), L8-06-A21 (A21).
- Below: the batch's section from the round's `RESULTS.md`, verbatim except shortened paths. Paths such as `phase-a/raw/...` and `plans/...` refer to the lab workspace and are not part of this directory.

### r7-pa-L8 (screen: A20 stream min 6144, A21 pool workers 15 without aux CPUs, suite S)

- Window: 2026-10-26T15:10:01+00:00 to 2026-10-26T15:33:34+00:00 UTC; job exit 0, restore exit 0 (state `r7-pa-L8`); elapsed in the job 1370.9 s. The batch waited about two minutes for the lock behind `round2-r7-dk-gates-3`.
- Production config sha256 before / after: `92c2f588c6bb7d02` / `92c2f588c6bb7d02`; exe `26da5a7e53bf79a1` / `26da5a7e53bf79a1`; PRODCHECK-PRE / POST rc=0, REALREQ-PRE / POST rc=0.
- Pattern: `B A20 B A21 B`, then the reversed half `A21 B A20 B` (slowest arm 159.1 s, needed 760 s, 2,684 s left: run). Nine arms, none skipped. A19 was screened in c2's spare budget, so this batch screens A20 and A21 only (RESULTS.md decision 21).
- Proof: A20 has no log line (silent `getenv`); its proof is `STRATA_PREFILL_STREAM_MIN=6144` beside the four production keys in `/proc/<pid>/environ` of both its arms. A21 prints `strata generate: 15 pool workers on logical processors ...` once in each of its arms and never in a baseline (the baselines print `30 pool workers`). Note that A20's arms still print the default notice `prefill: the CPU share is ON by default for prompt chunks below 1024 tokens`, whose text does not change although the arm's real staged-chunk limit is 6,144 (`prefill.cpp:2423` prints a fixed string); the environ, not the notice, is what proves the arm.
- Harness: `r7suite.py` sha256 `eac3fd75...`, plan `plans/r7-pa-L8.json` (written by `mkplans2.py` with `R7PA_L8=A20,A21`).
- Raw: `phase-a/raw/gpu/r7-pa-L8/`. Keyscan: 94 files, 0 with the key.

#### Per arm

| Arm | Switch | Status | Proof | D_win | D_real | P | R4 | R32 | R128 | R256 | F | T0 | T1 | D_win tiers (tiny/1k/4k/32k/128k/nat4k) | free MiB | Cached GiB | s |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| L8-01-B | B | ok | ok | 169.57 | 105.33 | 1846.0 | 1455.4 | 2341.4 | - | - | 3271.0 | 134.0 | 11016.0 | 96.6/171.1/172.4/165.3/-/99.4 | 379 | 79.8 | 154 |
| L8-02-A20 | A20 | ok | ok | 168.23 | 103.90 | 1959.4 | 1655.4 | 2319.2 | - | - | 2189.0 | 141.0 | 10184.0 | 96.0/169.4/171.1/164.2/-/96.5 | 379 | 79.8 | 144 |
| L8-03-B | B | ok | ok | 167.02 | 91.13 | 1823.5 | 1444.2 | 2302.4 | - | - | 3308.0 | 142.0 | 11106.0 | 94.5/168.3/170.1/162.7/-/89.9 | 379 | 79.8 | 159 |
| L8-04-A21 | A21 | ok | ok | 168.48 | 103.95 | 1856.4 | 1471.6 | 2341.7 | - | - | 3240.0 | 120.0 | 10994.0 | 99.8/169.2/171.5/164.8/-/103.0 | 379 | 79.8 | 155 |
| L8-05-B | B | ok | ok | 167.78 | 102.26 | 1844.0 | 1453.2 | 2339.8 | - | - | 3295.0 | 135.5 | 10956.0 | 96.1/169.1/170.1/164.2/-/100.8 | 379 | 79.8 | 155 |
| L8-06-A21 | A21 | ok | ok | 168.15 | 104.98 | 1831.2 | 1446.9 | 2317.7 | - | - | 3218.0 | 122.5 | 11040.0 | 98.8/169.4/170.6/164.5/-/98.5 | 379 | 79.8 | 153 |
| L8-07-B | B | ok | ok | 166.76 | 105.45 | 1830.4 | 1448.5 | 2313.0 | - | - | 3261.0 | 140.0 | 11103.0 | 96.1/169.3/170.6/160.6/-/101.9 | 379 | 79.8 | 154 |
| L8-08-A20 | A20 | ok | ok | 167.60 | 104.61 | 1953.5 | 1656.1 | 2304.2 | - | - | 2198.0 | 152.0 | 10321.0 | 95.8/168.8/170.2/163.9/-/100.3 | 379 | 79.8 | 144 |
| L8-09-B | B | ok | ok | 167.75 | 104.59 | 1826.9 | 1447.9 | 2305.1 | - | - | 3221.0 | 141.5 | 11099.0 | 96.5/168.5/170.9/163.9/-/99.6 | 379 | 79.8 | 154 |

#### Pair ratios (first two pairs per arm are the screen; the last four are the reversed half, descriptive)

| Arm | Pair | Phase | D_win | D_real | P | R4 | R32 | R128 | R256 | F | T0 | T1 | tier dec (tiny/1k/4k/32k/128k/nat4k) | tier read (4k/32k/128k) |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| A20 | L8-01-B (baseline then arm) | screen | 0.992 | 0.986 | 1.061 | 1.137 | 0.991 | - | - | 1.494 | 0.950 | 1.082 | 0.994/0.990/0.993/0.994/-/0.970 | 1.137/0.991/- |
| A20 | L8-03-B (arm then baseline) | screen | 1.007 | 1.140 | 1.075 | 1.146 | 1.007 | - | - | 1.511 | 1.007 | 1.091 | 1.015/1.007/1.006/1.009/-/1.073 | 1.146/1.007/- |
| A21 | L8-03-B (baseline then arm) | screen | 1.009 | 1.141 | 1.018 | 1.019 | 1.017 | - | - | 1.021 | 1.183 | 1.010 | 1.056/1.005/1.008/1.013/-/1.146 | 1.019/1.017/- |
| A21 | L8-05-B (arm then baseline) | screen | 1.004 | 1.016 | 1.007 | 1.013 | 1.001 | - | - | 1.017 | 1.129 | 0.997 | 1.039/1.001/1.008/1.004/-/1.022 | 1.013/1.001/- |
| A21 | L8-09-B (baseline then arm) | screen | 1.002 | 1.004 | 1.002 | 0.999 | 1.005 | - | - | 1.001 | 1.155 | 1.005 | 1.023/1.005/0.998/1.004/-/0.988 | 0.999/1.005/- |
| A21 | L8-07-B (arm then baseline) | screen | 1.008 | 0.996 | 1.000 | 0.999 | 1.002 | - | - | 1.013 | 1.143 | 1.006 | 1.028/1.001/1.000/1.024/-/0.966 | 0.999/1.002/- |
| A20 | L8-07-B (baseline then arm) | screen | 1.005 | 0.992 | 1.067 | 1.143 | 0.996 | - | - | 1.484 | 0.921 | 1.076 | 0.996/0.997/0.998/1.020/-/0.984 | 1.143/0.996/- |
| A20 | L8-09-B (arm then baseline) | screen | 0.999 | 1.000 | 1.069 | 1.144 | 1.000 | - | - | 1.465 | 0.931 | 1.075 | 0.992/1.001/0.996/1.000/-/1.007 | 1.144/1.000/- |

#### Screen verdicts

| Arm | Primary | Screen pair ratios | Gate | Extra condition | Verdict |
|---|---|---|---|---|---|
| A20 | `F` | 1.494, 1.511 | confirm (both >= 1.02) | - | confirm (confirmation batch still owed) |
| A20 | `R4` (cnt4k read) | 1.137, 1.146 | confirm (both >= 1.02) | `R32` 0.991 and 1.007, both >= 0.98 | confirm |
| A21 | `T0` | 1.183, 1.129 | confirm (both >= 1.02) | `F` 1.021 and 1.017, neither below 0.98 | confirm (confirmation batch still owed) |

#### Baseline arms

| Baseline | D_win | D_real | P | R4 | R32 | R128 | R256 | F | T0 | T1 |
|---|---|---|---|---|---|---|---|---|---|---|
| L8-01-B | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | - | - | 1.000 | 1.000 | 1.000 |
| L8-03-B | 0.985 | 0.865 | 0.988 | 0.992 | 0.983 | - | - | 0.989 | 0.944 | 0.992 |
| L8-05-B | 0.989 | 0.971 | 0.999 | 0.999 | 0.999 | - | - | 0.993 | 0.989 | 1.005 |
| L8-07-B | 0.983 | 1.001 | 0.992 | 0.995 | 0.988 | - | - | 1.003 | 0.957 | 0.992 |
| L8-09-B | 0.989 | 0.993 | 0.990 | 0.995 | 0.984 | - | - | 1.016 | 0.947 | 0.993 |

#### Every run, compact

| Arm | tiny prompt ms x6 | tiny decode x6 | cnt1k dec r1/r2 | cnt4k dec r1/r2 | cnt32k dec r1/r2 | cnt4k read r1/r2 | cnt32k read r1/r2 | nat4k dec r1/r2 | samp4k dec 4242/4243/4244 | agent dec t1/t2 | agent prompt ms t1/t2 (reused) |
|---|---|---|---|---|---|---|---|---|---|---|---|
| L8-01-B | 255 172 102 130 138 111 | 73 97 98 107 122 98 | 131.7/171.1 | 172.5/172.4 | 165.6/165.2 | 1453/1455 | 2352/2341 | 89.0/112.7 | 102.7/103.3/108.9 | 109.7/115.3 | 11016/3271 (18763) |
| L8-02-A20 | 198 169 126 134 148 116 | 73 97 99 107 119 96 | 130.5/169.4 | 170.3/171.2 | 164.0/164.3 | 1630/1655 | 2337/2319 | 89.1/105.2 | 109.0/101.9/107.7 | 111.1/107.2 | 10184/2189 (18763) |
| L8-03-B | 171 166 128 107 156 126 | 74 91 97 105 115 97 | 120.2/168.3 | 170.1/170.1 | 161.6/162.7 | 1438/1444 | 2330/2302 | 84.7/95.9 | 91.5/101.3/97.5 | 96.0/79.7 | 11106/3308 (18763) |
| L8-04-A21 | 176 142 116 115 124 95 | 75 99 103 110 127 101 | 132.0/169.2 | 170.9/171.5 | 165.1/164.9 | 1471/1472 | 2347/2342 | 93.6/114.6 | 102.2/106.4/112.6 | 100.3/104.3 | 10994/3240 (18763) |
| L8-05-B | 209 209 119 146 125 111 | 74 97 99 104 120 96 | 130.4/169.1 | 170.5/170.1 | 164.8/164.2 | 1453/1453 | 2346/2340 | 92.1/111.3 | 110.6/105.3/103.7 | 103.4/96.2 | 10956/3295 (18763) |
| L8-06-A21 | 169 137 108 115 130 96 | 75 98 102 106 126 100 | 131.0/169.5 | 170.8/170.6 | 164.4/164.6 | 1445/1447 | 2339/2318 | 90.1/108.6 | 106.5/109.3/110.8 | 108.2/107.4 | 11040/3218 (18763) |
| L8-07-B | 221 136 134 144 161 89 | 75 97 97 106 121 95 | 131.1/169.3 | 170.4/170.5 | 163.8/160.6 | 1452/1448 | 2317/2313 | 93.0/112.7 | 101.0/103.5/105.1 | 112.6/110.2 | 11103/3261 (18763) |
| L8-08-A20 | 170 174 151 130 153 96 | 75 98 99 104 115 95 | 131.2/168.8 | 169.6/170.2 | 161.3/163.9 | 1637/1656 | 2334/2304 | 93.9/107.6 | 106.4/107.1/108.9 | 106.7/105.5 | 10321/2198 (18763) |
| L8-09-B | 152 134 139 144 167 126 | 74 97 98 107 121 97 | 131.6/168.5 | 170.2/170.9 | 164.5/163.9 | 1444/1448 | 2324/2305 | 93.9/106.1 | 96.4/109.8/107.8 | 111.3/108.4 | 11099/3221 (18763) |

#### L8 reading (computed)

- **A20 (`STRATA_PREFILL_STREAM_MIN=6144`) confirms on both its primaries, and reproduces A19's shape.** `F` 2,189 and
  2,198 ms against 3,271 and 3,308 ms (1.494 and 1.511; reversed 1.484 and 1.465), the cnt4k prompt read 1,655.4 and
  1,656.1 tok/s against 1,444.2 to 1,455.4 (1.137 and 1.146; reversed 1.143 and 1.144), and the addendum's `cnt32k`
  condition holds (0.991 and 1.007; reversed 0.996 and 1.000). `T1` 1.082 and 1.091, `D_win` 0.992 and 1.007, `D_real`
  0.986 and 1.140 (the second pair's baseline is the batch's outlier, below). As for A19, this is the combined change:
  the STAGE ring from 1,024 to 6,143 tokens plus the CPU share's limit widened to 6,144 (SWITCHES.md).
- **A21 (`--pool-workers 15`, no `--aux-cpus`) confirms on `T0` with `F` holding.** Tiny first-token medians 120.0 and
  122.5 ms against 142.0 and 135.5 ms (1.183 and 1.129; reversed 1.155 and 1.143), and `F` 1.021 and 1.017, i.e. above
  0.98 in both pairs as the addendum requires (reversed 1.001 and 1.013). Everything else is flat: `D_win` 1.009 and
  1.004, `P` 1.018 and 1.007, `R4` 1.019 and 1.013, `R32` 1.017 and 1.001. So the L1 secondary reading (fewer pool
  workers make short prompts cheaper, `T0` 1.13 to 1.26) reproduces at 1.13 to 1.18 without `--aux-cpus`, and the `F`
  regression that came with `--aux-cpus` in L1 does not appear.
- **One baseline outlier, recorded not smoothed.** `L8-03-B` read `D_real` 91.13 (nat4k decode 89.9 tok/s) against 102.3
  to 105.5 for the other four baselines, and its `D_win` 167.0 was the lowest of them by 0.5%. It is A20's second pair's
  baseline and A21's first pair's baseline, which is why A20's second `D_real` ratio reads 1.140 and A21's first 1.141.
  Neither `D_real` is a primary in this batch and no gate touches it; the four pair ratios of the primaries are tight.
- **What part 2a leaves for confirmation** (all screens are in, none is a confirmation): A19 `F` 1.488 / 1.473 and `R4`
  1.086 / 1.064; A20 `F` 1.494 / 1.511 and `R4` 1.137 / 1.146; A21 `T0` 1.183 / 1.129; A10 `D_real` 1.041 / 1.030; A11
  `F` 1.466 / 1.471; A12 `R128` 1.063 / 1.061. Each needs two pairs in the opposite order before the combined arm.
