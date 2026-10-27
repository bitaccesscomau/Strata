# r7-pa-L9

- Job exit 0, restore exit 0 (the lab wrapper stopped production, ran the job, restored production and verified it with a real completion).
- Runs in this directory: L9-03-B, L9-04-A24, L9-05-B, L9-06-A25, L9-07-B, L9-08-A25, L9-09-B, L9-10-A24, L9-11-B.
- Runs of this batch not copied here (exact-class settings, or baselines paired only with them): L9-01-B (B), L9-02-A23 (A23), L9-12-A23 (A23), L9-13-B (B).
- Below: the batch's section from the round's `RESULTS-3.md`, verbatim except shortened paths. Paths such as `phase-a/raw/...` and `plans/...` refer to the lab workspace and are not part of this directory.

### r7-pa-L9 (screen: A23, A24, A25, suite S)

- Window: 2026-10-26T19:00:51+00:00 to 2026-10-26T19:35:03+00:00 UTC; job exit 0, restore exit 0; elapsed in the job 2011.3 s. Lock turn: LOCKED-START r7-pa-L9 2026-10-26T19:00:51+00:00 holder-before=idle-after-r7-pa-c5 2026-10-26T19:00:50+00:00.
- Production before / after (sha256 of config and exe, on disk): 92c2f588c6bb7d02 strata-swift-iq3_xxs-256k.json; 26da5a7e53bf79a1 strata / 92c2f588c6bb7d02 strata-swift-iq3_xxs-256k.json; 26da5a7e53bf79a1 strata. r7suite freeze start / end: config `92c2f588c6bb7d02` / `92c2f588c6bb7d02`, exe `26da5a7e53bf79a1` / `26da5a7e53bf79a1`, frozen_ok_end True.
- Checks around the batch: PRODCHECK-PRE r7-pa-L9 rc=0; REALREQ-PRE r7-pa-L9 rc=0; BATCH-RC r7-pa-L9 rc=0 job=0 restore=0 2026-10-26T19:35:03+00:00; PRODCHECK-POST r7-pa-L9 rc=0; REALREQ-POST r7-pa-L9 rc=0; GPU-POST 250.00 W, 23744 MiB. Restore: verified 2026-10-26T19:35:03Z, model strata/swift-1.5-iq3_xxs-256K, max_context 262144, expert slots 10320, reply 'READY'.
- Pattern: B X1 B X2 B X3 B (X1 = A23, X2 = A24, X3 = A25), then the reversed half X3 B X2 B X1 B if time allows (all or none). Reversed half: run (slowest arm 156.0 s, needed 1090 s, left 2371 s). Arm statuses: ok 13.
- Harness: phase-a3 `r7suite.py` `f9bfff99...`, plan `plans/r7-pa-L9.json` (sha256 in the decisions above). Raw: `phase-a/raw3/gpu/r7-pa-L9/`. Keyscan on the VM before the copy: 143 files, 0 with the key.

#### Per arm (engine-measured; D in tok/s, P and R in tok/s, F, T0, T1 in ms; slots = expert slots at ready)

| Arm | Switch | Status | Proof | D_win | D_real | P | R4 | R32 | F | T0 | T1 | decode tiny/1k/4k/32k/nat4k/samp4k/agent | slots | free MiB | s |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| L9-01-B | B | ok | ok | 169.60 | 102.16 | 1833.8 | 1443.7 | 2329.3 | 3273.0 | 148.5 | 10984.0 | 96.2/170.8/172.5/165.6/100.8/104.7/101.0 | 10320 | 379 | 155 |
| L9-02-A23 | A23 | ok | ok | 168.52 | 104.21 | 1832.5 | 1447.4 | 2320.1 | 3278.0 | 149.0 | 11018.0 | 96.3/169.2/171.5/164.9/100.9/104.8/107.0 | 10320 | 379 | 154 |
| L9-03-B | B | ok | ok | 169.08 | 100.95 | 1837.9 | 1450.6 | 2328.6 | 3207.0 | 159.5 | 11101.0 | 95.9/170.0/172.2/165.2/98.7/105.2/99.1 | 10320 | 379 | 155 |
| L9-04-A24 | A24 | ok | ok | 171.87 | 107.32 | 1831.3 | 1443.2 | 2323.8 | 3211.0 | 160.5 | 11012.0 | 94.1/172.4/174.4/168.9/103.9/106.5/111.7 | 10320 | 379 | 152 |
| L9-05-B | B | ok | ok | 168.48 | 103.14 | 1835.7 | 1447.9 | 2327.3 | 3249.0 | 150.0 | 11128.0 | 97.1/169.2/171.1/165.2/101.8/101.8/105.8 | 10320 | 379 | 154 |
| L9-06-A25 | A25 | ok | ok | 162.70 | 101.61 | 1855.4 | 1470.0 | 2341.9 | 3116.0 | 163.5 | 11068.0 | 90.5/163.9/165.6/158.7/96.0/100.1/109.1 | 10636 | 377 | 156 |
| L9-07-B | B | ok | ok | 167.95 | 104.07 | 1844.1 | 1450.1 | 2345.3 | 3252.0 | 120.5 | 10982.0 | 96.8/169.4/172.0/162.5/100.4/105.3/106.7 | 10320 | 379 | 153 |
| L9-08-A25 | A25 | ok | ok | 161.97 | 101.16 | 1859.0 | 1478.2 | 2338.0 | 3179.0 | 133.5 | 11097.0 | 91.4/163.4/165.7/157.0/99.0/105.6/99.0 | 10636 | 377 | 157 |
| L9-09-B | B | ok | ok | 168.26 | 102.20 | 1836.1 | 1447.9 | 2328.3 | 3293.0 | 154.5 | 11102.0 | 96.3/169.0/171.2/164.6/100.9/107.2/98.7 | 10320 | 379 | 155 |
| L9-10-A24 | A24 | ok | ok | 170.61 | 106.12 | 1836.3 | 1453.8 | 2319.4 | 3216.0 | 155.5 | 11010.0 | 94.9/170.8/173.7/167.4/102.2/102.6/114.0 | 10320 | 379 | 154 |
| L9-11-B | B | ok | ok | 168.89 | 103.73 | 1842.9 | 1446.4 | 2348.2 | 3281.0 | 133.0 | 11071.0 | 97.0/169.6/172.0/165.1/101.1/99.5/110.9 | 10320 | 379 | 154 |
| L9-12-A23 | A23 | ok | ok | 168.81 | 100.33 | 1831.8 | 1446.4 | 2320.1 | 3282.0 | 165.5 | 11044.0 | 92.1/169.3/171.8/165.4/98.7/104.1/98.2 | 10320 | 379 | 156 |
| L9-13-B | B | ok | ok | 168.74 | 101.80 | 1840.2 | 1451.1 | 2333.6 | 3263.0 | 131.0 | 11005.0 | 96.1/170.1/171.1/165.1/99.9/104.2/101.3 | 10320 | 379 | 155 |

#### Pair ratios (arm / baseline for D_win, D_real, P, R4, R32; baseline / arm for F, T0, T1; the first two pairs of each first-half arm are the screen, the rest the reversed half, descriptive)

| Arm | Pair | Phase | D_win | D_real | P | R4 | R32 | F | T0 | T1 | tier decode (tiny/1k/4k/32k/nat4k/samp4k/agent) |
|---|---|---|---|---|---|---|---|---|---|---|---|
| A23 (L9-02-A23) | L9-01-B (baseline then arm) | screen | 0.994 | 1.020 | 0.999 | 1.003 | 0.996 | 0.998 | 0.997 | 0.997 | 1.000/0.991/0.994/0.996/1.001/1.001/1.060 |
| A23 (L9-02-A23) | L9-03-B (arm then baseline) | screen | 0.997 | 1.032 | 0.997 | 0.998 | 0.996 | 0.978 | 1.070 | 1.008 | 1.004/0.995/0.996/0.999/1.023/0.997/1.079 |
| A24 (L9-04-A24) | L9-03-B (baseline then arm) | screen | 1.016 | 1.063 | 0.996 | 0.995 | 0.998 | 0.999 | 0.994 | 1.008 | 0.981/1.014/1.013/1.022/1.053/1.012/1.127 |
| A24 (L9-04-A24) | L9-05-B (arm then baseline) | screen | 1.020 | 1.041 | 0.998 | 0.997 | 0.998 | 1.012 | 0.935 | 1.011 | 0.969/1.019/1.019/1.022/1.021/1.045/1.056 |
| A25 (L9-06-A25) | L9-05-B (baseline then arm) | screen | 0.966 | 0.985 | 1.011 | 1.015 | 1.006 | 1.043 | 0.917 | 1.005 | 0.932/0.969/0.968/0.961/0.944/0.983/1.031 |
| A25 (L9-06-A25) | L9-07-B (arm then baseline) | screen | 0.969 | 0.976 | 1.006 | 1.014 | 0.999 | 1.044 | 0.737 | 0.992 | 0.935/0.967/0.962/0.976/0.957/0.951/1.023 |
| A25 (L9-08-A25) | L9-07-B (baseline then arm) | reversed | 0.964 | 0.972 | 1.008 | 1.019 | 0.997 | 1.023 | 0.903 | 0.990 | 0.945/0.964/0.963/0.966/0.987/1.002/0.928 |
| A25 (L9-08-A25) | L9-09-B (arm then baseline) | reversed | 0.963 | 0.990 | 1.012 | 1.021 | 1.004 | 1.036 | 1.157 | 1.000 | 0.949/0.967/0.968/0.953/0.981/0.985/1.004 |
| A24 (L9-10-A24) | L9-09-B (baseline then arm) | reversed | 1.014 | 1.038 | 1.000 | 1.004 | 0.996 | 1.024 | 0.994 | 1.008 | 0.985/1.011/1.014/1.017/1.012/0.957/1.155 |
| A24 (L9-10-A24) | L9-11-B (arm then baseline) | reversed | 1.010 | 1.023 | 0.996 | 1.005 | 0.988 | 1.020 | 0.855 | 1.006 | 0.978/1.007/1.009/1.014/1.011/1.031/1.028 |
| A23 (L9-12-A23) | L9-11-B (baseline then arm) | reversed | 1.000 | 0.967 | 0.994 | 1.000 | 0.988 | 1.000 | 0.804 | 1.002 | 0.950/0.998/0.999/1.002/0.976/1.046/0.886 |
| A23 (L9-12-A23) | L9-13-B (arm then baseline) | reversed | 1.000 | 0.986 | 0.995 | 0.997 | 0.994 | 0.994 | 0.792 | 0.996 | 0.959/0.995/1.004/1.002/0.988/0.999/0.970 |

#### Screen verdicts (PLAN.md addendum 4: primary D_win; D_real must not fall below 0.98 in either screen pair)

| Arm | Primary | Screen pair ratios | Gate | D_real in the screen pairs (>= 0.98 both) | Reversed-half D_win (descriptive) | Proof | Verdict |
|---|---|---|---|---|---|---|---|
| A23 | D_win | 0.994, 0.997 | no measurable effect | 1.020, 1.032 (holds) | 1.000, 1.000 | ok | no measurable effect |
| A24 | D_win | 1.016, 1.020 | confirm (mixed) | 1.063, 1.041 (holds) | 1.014, 1.010 | ok | confirm (confirmation batch owed) |
| A25 | D_win | 0.966, 0.969 | confirm (literal "otherwise"; both pairs below 0.98) | 0.985, 0.976 (FAILS) | 0.964, 0.963 | ok | regression: D_win 0.98 below in both pairs and the D_real condition fails (not a candidate) |

#### Proof per candidate arm

- L9-02-A23 (A23): proof ok; patterns {'strata expdec: CUDA\\d+ gate/up type 16: expdec_gu_kernel R \\d+ MINB \\d+, \\d+ rows per block': 1, 'strata expdec: CUDA\\d+ gate/up type 17: expdec_gu_kernel R \\d+ MINB \\d+, \\d+ rows per block': 1, 'strata expdec: CUDA\\d+ gate/up type 18: expdec_gu_kernel R \\d+ MINB \\d+, \\d+ rows per block': 1, 'strata expdec: CUDA\\d+ gate/up type 21: expdec_gu_kernel R \\d+ MINB \\d+, \\d+ rows per block': 1, 'strata expdec: CUDA\\d+ gate/up type 22: expdec_gu_kernel R \\d+ MINB \\d+, \\d+ rows per block': 1, 'strata expdec: CUDA\\d+ down type 42: expdec_down_kernel R \\d+, \\d+ rows per block': 1}; refusals none; engine STRATA_* environ ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_EXPDEC', 'STRATA_EXPDEC_DOWN', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']; lines: strata expdec: CUDA0 gate/up type 16: expdec_gu_kernel R 1 MINB 4, 64 rows per block, grid 20 x 60 (cap 60 groups), captured into a graph | strata expdec: CUDA0 gate/up type 17: expdec_gu_kernel R 1 MINB 4, 64 rows per block, grid 20 x 60 (cap 60 groups), captured into a graph | strata expdec: CUDA0 gate/up type 18: expdec_gu_kernel R 1 MINB 4, 64 rows per block, grid 20 x 60 (cap 60 groups), captured into a graph | strata expdec: CUDA0 gate/up type 21: expdec_gu_kernel R 1 MINB 4, 64 rows per block, grid 20 x 60 (cap 60 groups), captured into a graph | strata expdec: CUDA0 gate/up type 22: expdec_gu_kernel R 1 MINB 4, 64 rows per block, grid 20 x 60 (cap 60 groups), captured into a graph | strata expdec: CUDA0 down type 42: expdec_down_kernel R 4, 128 rows per block, grid 20 x 60 (cap 60 groups), captured into a graph
- L9-04-A24 (A24): proof ok; patterns (none: environ is the proof); refusals none; engine STRATA_* environ ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_QSA_SPLIT_ATTN', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L9-06-A25 (A25): proof ok; patterns {'strata generate: STRATA_HC_REQ8: hyper-connection projections as int8 \\+ fp32/32 scales, \\d+ MiB': 1}; refusals none; engine STRATA_* environ ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_HC_REQ8', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']; lines: strata generate: STRATA_HC_REQ8: hyper-connection projections as int8 + fp32/32 scales, 675 MiB
- L9-08-A25 (A25): proof ok; patterns {'strata generate: STRATA_HC_REQ8: hyper-connection projections as int8 \\+ fp32/32 scales, \\d+ MiB': 1}; refusals none; engine STRATA_* environ ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_HC_REQ8', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']; lines: strata generate: STRATA_HC_REQ8: hyper-connection projections as int8 + fp32/32 scales, 675 MiB
- L9-10-A24 (A24): proof ok; patterns (none: environ is the proof); refusals none; engine STRATA_* environ ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_QSA_SPLIT_ATTN', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L9-12-A23 (A23): proof ok; patterns {'strata expdec: CUDA\\d+ gate/up type 16: expdec_gu_kernel R \\d+ MINB \\d+, \\d+ rows per block': 1, 'strata expdec: CUDA\\d+ gate/up type 17: expdec_gu_kernel R \\d+ MINB \\d+, \\d+ rows per block': 1, 'strata expdec: CUDA\\d+ gate/up type 18: expdec_gu_kernel R \\d+ MINB \\d+, \\d+ rows per block': 1, 'strata expdec: CUDA\\d+ gate/up type 21: expdec_gu_kernel R \\d+ MINB \\d+, \\d+ rows per block': 1, 'strata expdec: CUDA\\d+ gate/up type 22: expdec_gu_kernel R \\d+ MINB \\d+, \\d+ rows per block': 1, 'strata expdec: CUDA\\d+ down type 42: expdec_down_kernel R \\d+, \\d+ rows per block': 1}; refusals none; engine STRATA_* environ ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_EXPDEC', 'STRATA_EXPDEC_DOWN', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']; lines: strata expdec: CUDA0 gate/up type 16: expdec_gu_kernel R 1 MINB 4, 64 rows per block, grid 20 x 60 (cap 60 groups), captured into a graph | strata expdec: CUDA0 gate/up type 17: expdec_gu_kernel R 1 MINB 4, 64 rows per block, grid 20 x 60 (cap 60 groups), captured into a graph | strata expdec: CUDA0 gate/up type 18: expdec_gu_kernel R 1 MINB 4, 64 rows per block, grid 20 x 60 (cap 60 groups), captured into a graph | strata expdec: CUDA0 gate/up type 21: expdec_gu_kernel R 1 MINB 4, 64 rows per block, grid 20 x 60 (cap 60 groups), captured into a graph | strata expdec: CUDA0 gate/up type 22: expdec_gu_kernel R 1 MINB 4, 64 rows per block, grid 20 x 60 (cap 60 groups), captured into a graph | strata expdec: CUDA0 down type 42: expdec_down_kernel R 4, 128 rows per block, grid 20 x 60 (cap 60 groups), captured into a graph

#### Baseline arms (noise reference: each baseline / the first baseline)

| Baseline | D_win | D_real | P | R4 | R32 | F | T0 | T1 |
|---|---|---|---|---|---|---|---|---|
| L9-01-B | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 |
| L9-03-B | 0.997 | 0.988 | 1.002 | 1.005 | 1.000 | 1.021 | 0.931 | 0.989 |
| L9-05-B | 0.993 | 1.010 | 1.001 | 1.003 | 0.999 | 1.007 | 0.990 | 0.987 |
| L9-07-B | 0.990 | 1.019 | 1.006 | 1.004 | 1.007 | 1.006 | 1.232 | 1.000 |
| L9-09-B | 0.992 | 1.000 | 1.001 | 1.003 | 1.000 | 0.994 | 0.961 | 0.989 |
| L9-11-B | 0.996 | 1.015 | 1.005 | 1.002 | 1.008 | 0.998 | 1.117 | 0.992 |
| L9-13-B | 0.995 | 0.996 | 1.003 | 1.005 | 1.002 | 1.003 | 1.134 | 0.998 |

#### Every run, compact (engine lines; decode tok/s per run)

| Arm | tiny prompt ms x6 | tiny decode x6 | cnt1k dec r1/r2 | cnt4k dec r1/r2 | cnt32k dec r1/r2 | cnt4k read r1/r2 | cnt32k read r1/r2 | nat4k dec r1/r2 | samp4k dec 4242/4243/4244 | agent dec t1/t2 | agent prompt ms t1/t2 (reused) | drafts accepted/offered cnt1k/4k/32k r2 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| L9-01-B | 172 184 131 132 165 117 | 74 95 98 106 122 97 | 131.4/170.8 | 170.6/172.5 | 165.8/165.6 | 1447/1444 | 2348/2329 | 91.2/112.7 | 101.2/112.1/101.5 | 101.6/100.3 | 10984/3273 (18763) | 192/192 192/192 192/192 |
| L9-02-A23 | 189 171 140 148 150 106 | 74 96 98 107 121 97 | 130.7/169.2 | 171.2/171.5 | 164.9/164.9 | 1444/1447 | 2333/2320 | 96.4/105.9 | 100.6/102.4/112.1 | 102.1/114.8 | 11018/3278 (18763) | 192/192 192/192 192/192 |
| L9-03-B | 165 157 106 162 166 123 | 74 96 99 106 117 98 | 130.3/170.0 | 171.4/172.1 | 165.8/165.2 | 1452/1451 | 2333/2329 | 87.4/113.4 | 107.8/104.1/103.7 | 99.3/99.0 | 11101/3207 (18763) | 192/192 191/192 192/192 |
| L9-04-A24 | 196 154 107 189 167 142 | 74 96 97 101 105 102 | 130.9/172.4 | 174.1/174.4 | 168.4/168.8 | 1450/1443 | 2334/2324 | 95.5/114.0 | 101.3/115.9/103.3 | 113.4/109.3 | 11012/3211 (18763) | 192/192 192/192 192/192 |
| L9-05-B | 235 135 124 175 165 119 | 75 97 100 106 121 98 | 131.3/169.2 | 171.2/171.1 | 165.0/165.2 | 1449/1448 | 2337/2327 | 92.2/113.5 | 98.8/102.4/104.4 | 113.3/101.5 | 11128/3249 (18763) | 192/192 192/192 192/192 |
| L9-06-A25 | 207 178 149 111 180 97 | 69 99 94 102 99 91 | 126.9/163.9 | 165.1/165.6 | 155.5/158.7 | 1468/1470 | 2356/2342 | 85.5/109.5 | 97.8/93.9/110.0 | 105.8/114.3 | 11068/3116 (18763) | 192/192 192/192 192/192 |
| L9-07-B | 155 137 104 104 163 90 | 75 97 98 105 122 98 | 130.8/169.4 | 171.2/172.1 | 165.2/162.5 | 1448/1450 | 2347/2345 | 93.3/108.5 | 101.2/105.3/109.7 | 105.2/109.6 | 10982/3252 (18763) | 192/192 191/192 193/195 |
| L9-08-A25 | 205 135 108 138 132 127 | 70 98 94 101 102 93 | 126.6/163.3 | 165.5/165.7 | 156.7/157.0 | 1468/1478 | 2348/2338 | 87.5/114.0 | 96.2/115.2/107.1 | 98.9/99.1 | 11097/3179 (18763) | 192/192 192/192 193/195 |
| L9-09-B | 211 156 106 153 173 116 | 74 95 99 104 121 98 | 131.6/169.0 | 170.4/171.2 | 165.3/164.6 | 1449/1448 | 2335/2328 | 97.4/104.7 | 107.3/105.6/108.8 | 104.4/93.5 | 11102/3293 (18763) | 192/192 192/192 192/192 |
| L9-10-A24 | 192 185 123 150 161 135 | 74 97 96 106 106 102 | 130.7/170.8 | 172.2/173.6 | 167.5/167.5 | 1449/1454 | 2331/2319 | 98.8/105.7 | 98.8/102.8/106.5 | 116.8/111.4 | 11010/3216 (18763) | 192/192 192/192 192/192 |
| L9-11-B | 211 154 106 143 123 104 | 75 97 100 106 122 96 | 131.7/169.6 | 171.5/172.1 | 165.5/165.0 | 1444/1446 | 2358/2348 | 94.2/109.1 | 95.6/100.7/102.6 | 108.2/113.7 | 11071/3281 (18763) | 192/192 192/192 192/192 |
| L9-12-A23 | 174 173 158 154 178 129 | 71 92 97 95 105 101 | 130.6/169.3 | 170.4/171.8 | 165.4/165.4 | 1443/1446 | 2332/2320 | 90.7/108.3 | 97.8/101.1/115.1 | 107.7/91.0 | 11044/3282 (18763) | 192/192 192/192 192/192 |
| L9-13-B | 207 142 106 138 124 105 | 73 96 99 105 121 97 | 130.6/170.1 | 170.5/171.1 | 165.1/165.0 | 1451/1451 | 2338/2334 | 92.7/108.4 | 99.9/104.1/109.1 | 107.0/95.7 | 11005/3263 (18763) | 192/192 191/192 192/192 |

#### L9 reading (computed; secondary metrics are descriptive, not gates)

- **A23 (`STRATA_EXPDEC=1 STRATA_EXPDEC_DOWN=1`): no measurable effect on `D_win`** (0.994 and 0.997; reversed 1.000 and
  1.000), `D_real` 1.020 and 1.032 (holds). All five gate/up lines and the Q2_0 down line printed with `captured into a graph`,
  the down at `R 4` (the code default, as SWITCHES-3.md records), and the IQ4_NL `down type 20 ... not covered` note printed
  once per arm. So the DK3b exact change buys nothing measurable on this window mix, which is consistent with DK3b's own
  projection: about 0.40 ms of a 24.6 ms window for the Q2_0 down at the microbench rate (441 GB/s at `_DR=2`, 396 at the
  default `_DR=4` that this arm runs), against a `D_win` resolution of about 0.7% here (seven baselines span 0.995 to 1.000).
- **A24 (`STRATA_QSA_SPLIT_ATTN=1`): confirm (mixed)** on `D_win`: 1.016 and 1.020 (one pair below 1.02), `D_real` 1.063 and
  1.041. The reversed half reads 1.014 and 1.010, so all four `D_win` pairs are positive (1.0 to 2.0%) and both `D_real` pairs
  are strongly positive (2.3 to 6.3%, driven by agent turn 2 1.06 to 1.13 and nat4k). Secondary, for the confirmation to watch:
  tiny decode reads 0.969 and 0.981 in the screen pairs (0.978 and 0.985 reversed), i.e. around the 0.98 greedy tier line that
  the confirm gate applies. `P`, `R4`, `R32` flat (0.995 to 0.998).
- **A25 (`STRATA_HC_REQ8=1`): a regression, not a candidate.** `D_win` 0.966 and 0.969 (reversed 0.964, 0.963); every counting
  tier loses decode (cnt1k 0.967 to 0.969, cnt4k 0.962 to 0.968, cnt32k 0.953 to 0.976), `D_real` 0.985 and 0.976 (fails the
  0.98 condition), and `T0` falls in three pairs of four (0.917, 0.737, 0.903; 1.157 reversed). The line printed
  (`... as int8 + fp32/32 scales, 675 MiB`) and the expert cache grew from 10,320 to 10,636 slots, but the extra slots do not
  pay for the int8 down/up kernels on every one of the window's 96 hyper-connection reads (two per layer). Reported for the parent; no
  confirmation is owed.
- **Baselines.** Seven baselines: `D_win` 0.995 to 1.000, `D_real` 0.992 to 1.022, `T0` 0.99 to 1.13 of the first (the spread that the
  `T0` comparisons above must be read against).
