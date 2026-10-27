# r7-pa-L11

- Job exit 0, restore exit 0 (the lab wrapper stopped production, ran the job, restored production and verified it with a real completion).
- Runs in this directory: L11-01-B, L11-02-A30, L11-03-B, L11-04-A31, L11-05-B, L11-06-A32, L11-07-B, L11-08-A32, L11-09-B, L11-10-A31, L11-11-B, L11-12-A30, L11-13-B.
- Every run of this batch is copied here.
- Below: the batch's section from the round's `RESULTS-5.md`, verbatim except shortened paths. Paths such as `phase-a/raw/...` and `plans/...` refer to the lab workspace and are not part of this directory.

### r7-pa-L11 (screen: A30, A31, A32)

- Window: 2026-10-26T22:17:50+00:00 to 2026-10-26T22:51:51+00:00 UTC; job exit 0, restore exit 0 (timing plan 0, check plan 0); elapsed in the timing plan 2000.9 s. Lock turn: LOCKED-START r7-pa-L11 2026-10-26T22:17:49+00:00 holder-before=idle-after-r7-pf1-d1 2026-10-26T22:17:48+00:00.
- Production before / after (sha256 of config and exe, on disk): 92c2f588c6bb7d02 strata-swift-iq3_xxs-256k.json; 26da5a7e53bf79a1 strata / 92c2f588c6bb7d02 strata-swift-iq3_xxs-256k.json; 26da5a7e53bf79a1 strata. r7suite freeze start / end: config `92c2f588c6bb7d02` / `92c2f588c6bb7d02`, exe `26da5a7e53bf79a1` / `26da5a7e53bf79a1`, frozen_ok_end True.
- Checks around the batch: PRODCHECK-PRE r7-pa-L11 rc=0; REALREQ-PRE r7-pa-L11 rc=0; BATCH-RC r7-pa-L11 rc=0 job=0 restore=0 2026-10-26T22:51:51+00:00; PRODCHECK-POST r7-pa-L11 rc=0; REALREQ-POST r7-pa-L11 rc=0; GPU-POST 250.00 W, 23744 MiB. Restore: verified 2026-10-26T22:51:51Z, model strata/swift-1.5-iq3_xxs-256K, max_context 262144, expert slots 10320, reply 'READY'.
- Pattern: B X1 B X2 B X3 B (X1 = A30, X2 = A31, X3 = A32), then the reversed half X3 B X2 B X1 B if time allows (all or none). Reversed half: run (slowest arm 155.4 s, needed 1086 s, left 2370 s). Arm statuses: ok 13.
- Harness: phase-a5 `r7suite.py` `f73417dd...`, plan `plans/r7-pa-L11.json` (sha256 in the decisions above). Raw: `phase-a/raw5/gpu/r7-pa-L11/`. Keyscan on the VM before the copy: 143 files, 0 with the key.

#### Per arm (engine-measured; D in tok/s, P and R in tok/s, F, T0, T1 in ms; slots = expert slots at ready)

| Arm | Switch | Status | Proof | D_win | D_real | P | R4 | R32 | R128 | F | T0 | T1 | decode tiny/1k/4k/32k/128k/nat4k/samp4k/agent | slots | free MiB | s |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| L11-01-B | B | ok | ok | 169.61 | 101.70 | 1838.4 | 1451.6 | 2328.3 | - | 3205.0 | 154.5 | 11099.0 | 96.3/170.2/173.3/165.4/-/104.3/102.8/98.1 | 10320 | 379 | 154 |
| L11-02-A30 | A30 | ok | ok | 169.84 | 104.16 | 1839.7 | 1454.3 | 2327.1 | - | 3257.0 | 125.5 | 11151.0 | 96.0/173.1/171.7/164.8/-/99.0/108.0/105.7 | 10320 | 379 | 153 |
| L11-03-B | B | ok | ok | 167.92 | 102.80 | 1832.1 | 1449.0 | 2316.5 | - | 3265.0 | 143.0 | 11150.0 | 96.6/169.2/169.4/165.2/-/101.2/105.5/101.8 | 10320 | 379 | 154 |
| L11-04-A31 | A31 | ok | ok | 169.39 | 103.75 | 1832.8 | 1451.6 | 2314.0 | - | 3214.0 | 161.5 | 10926.0 | 103.5/173.2/171.0/164.1/-/102.2/104.8/104.3 | 10320 | 379 | 154 |
| L11-05-B | B | ok | ok | 167.78 | 100.75 | 1846.4 | 1475.4 | 2310.5 | - | 3230.0 | 145.0 | 11168.0 | 95.7/168.5/170.9/164.0/-/98.5/103.5/100.3 | 10320 | 379 | 155 |
| L11-06-A32 | A32 | ok | ok | 168.36 | 103.87 | 1835.5 | 1454.8 | 2315.9 | - | 3260.0 | 152.5 | 11088.0 | 98.5/168.4/171.2/165.5/-/98.2/104.2/109.5 | 10320 | 379 | 155 |
| L11-07-B | B | ok | ok | 168.55 | 102.00 | 1852.1 | 1474.3 | 2326.6 | - | 3243.0 | 141.5 | 11075.0 | 96.2/169.4/170.9/165.4/-/100.7/104.6/100.8 | 10320 | 379 | 154 |
| L11-08-A32 | A32 | ok | ok | 168.40 | 107.38 | 1836.0 | 1448.5 | 2327.1 | - | 3281.0 | 152.5 | 11121.0 | 99.8/169.0/171.0/165.3/-/104.5/105.4/112.4 | 10320 | 379 | 152 |
| L11-09-B | B | ok | ok | 168.48 | 100.82 | 1842.9 | 1449.0 | 2343.9 | - | 3260.0 | 118.0 | 11133.0 | 96.2/169.2/171.4/164.9/-/99.3/99.9/103.3 | 10320 | 379 | 154 |
| L11-10-A31 | A31 | ok | ok | 169.65 | 101.60 | 1829.7 | 1444.8 | 2317.2 | - | 3265.0 | 131.5 | 11021.0 | 99.8/173.1/171.0/164.9/-/102.1/100.2/102.5 | 10320 | 379 | 154 |
| L11-11-B | B | ok | ok | 167.93 | 100.50 | 1853.6 | 1476.0 | 2327.8 | - | 3246.0 | 147.5 | 10993.0 | 95.1/169.1/170.9/163.9/-/98.6/100.5/102.4 | 10320 | 379 | 155 |
| L11-12-A30 | A30 | ok | ok | 170.11 | 105.31 | 1836.0 | 1451.1 | 2323.1 | - | 3205.0 | 135.5 | 11116.0 | 96.2/174.0/171.7/164.7/-/104.8/98.9/112.7 | 10320 | 379 | 154 |
| L11-13-B | B | ok | ok | 168.48 | 103.26 | 1833.8 | 1449.5 | 2319.9 | - | 3244.0 | 139.0 | 11105.0 | 95.4/169.6/171.2/164.6/-/97.8/108.7/103.6 | 10320 | 379 | 152 |

#### Pair ratios (arm / baseline for D_win, D_real, P, R4, R32, R128; baseline / arm for F, T0, T1; phase as the plan declares it)

| Arm | Pair | Phase | D_win | D_real | P | R4 | R32 | R128 | F | T0 | T1 | tier decode (tiny/1k/4k/32k/128k/nat4k/samp4k/agent) |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| A30 (L11-02-A30) | L11-01-B (baseline then arm) | screen | 1.001 | 1.024 | 1.001 | 1.002 | 0.999 | - | 0.984 | 1.231 | 0.995 | 0.997/1.017/0.991/0.997/-/0.950/1.051/1.077 |
| A30 (L11-02-A30) | L11-03-B (arm then baseline) | screen | 1.011 | 1.013 | 1.004 | 1.004 | 1.005 | - | 1.002 | 1.139 | 1.000 | 0.994/1.023/1.013/0.998/-/0.979/1.023/1.038 |
| A31 (L11-04-A31) | L11-03-B (baseline then arm) | screen | 1.009 | 1.009 | 1.000 | 1.002 | 0.999 | - | 1.016 | 0.885 | 1.021 | 1.071/1.024/1.009/0.994/-/1.010/0.993/1.025 |
| A31 (L11-04-A31) | L11-05-B (arm then baseline) | screen | 1.010 | 1.030 | 0.993 | 0.984 | 1.002 | - | 1.005 | 0.898 | 1.022 | 1.081/1.028/1.001/1.001/-/1.037/1.013/1.039 |
| A32 (L11-06-A32) | L11-05-B (baseline then arm) | screen | 1.003 | 1.031 | 0.994 | 0.986 | 1.002 | - | 0.991 | 0.951 | 1.007 | 1.029/0.999/1.002/1.009/-/0.997/1.007/1.092 |
| A32 (L11-06-A32) | L11-07-B (arm then baseline) | screen | 0.999 | 1.018 | 0.991 | 0.987 | 0.995 | - | 0.995 | 0.928 | 0.999 | 1.025/0.994/1.002/1.001/-/0.975/0.996/1.087 |
| A32 (L11-08-A32) | L11-07-B (baseline then arm) | reversed | 0.999 | 1.053 | 0.991 | 0.982 | 1.000 | - | 0.988 | 0.928 | 0.996 | 1.038/0.997/1.001/0.999/-/1.038/1.008/1.116 |
| A32 (L11-08-A32) | L11-09-B (arm then baseline) | reversed | 1.000 | 1.065 | 0.996 | 1.000 | 0.993 | - | 0.994 | 0.774 | 1.001 | 1.038/0.999/0.998/1.002/-/1.053/1.054/1.088 |
| A31 (L11-10-A31) | L11-09-B (baseline then arm) | reversed | 1.007 | 1.008 | 0.993 | 0.997 | 0.989 | - | 0.998 | 0.897 | 1.010 | 1.037/1.023/0.998/1.000/-/1.028/1.003/0.993 |
| A31 (L11-10-A31) | L11-11-B (arm then baseline) | reversed | 1.010 | 1.011 | 0.987 | 0.979 | 0.995 | - | 0.994 | 1.122 | 0.997 | 1.050/1.024/1.001/1.006/-/1.035/0.998/1.001 |
| A30 (L11-12-A30) | L11-11-B (baseline then arm) | reversed | 1.013 | 1.048 | 0.991 | 0.983 | 0.998 | - | 1.013 | 1.089 | 0.989 | 1.012/1.029/1.005/1.005/-/1.062/0.984/1.100 |
| A30 (L11-12-A30) | L11-13-B (arm then baseline) | reversed | 1.010 | 1.020 | 1.001 | 1.001 | 1.001 | - | 1.012 | 1.026 | 0.999 | 1.009/1.026/1.003/1.001/-/1.072/0.910/1.088 |

#### Screen verdicts (PLAN.md addendum 5 for A30 to A33: primary D_real; D_win must not fall below 0.98 in either screen pair)

| Arm | Primary | Screen pair ratios | Gate | Condition in the screen pairs | Reversed-half primary (descriptive) | Proof | Verdict |
|---|---|---|---|---|---|---|---|
| A30 | D_real | 1.024, 1.013 | confirm (mixed) | D_win 1.001, 1.011 (holds) | 1.048, 1.020 | ok | screen passes: confirm (confirmation pairs owed) |
| A31 | D_real | 1.009, 1.030 | confirm (mixed) | D_win 1.009, 1.010 (holds) | 1.008, 1.011 | ok | screen passes: confirm (confirmation pairs owed) |
| A32 | D_real | 1.031, 1.018 | confirm (mixed) | D_win 1.003, 0.999 (holds) | 1.053, 1.065 | ok | screen passes: confirm (confirmation pairs owed) |

#### Proof per arm (argv adaptive flags, the tier line, refusals, environ; any self-decision line)

- L11-01-B (B): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L11-02-A30 (A30): status ok, proof ok; tier line yes; adaptive flags in the argv {'--adapt-swaps': ['192']}; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L11-03-B (B): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L11-04-A31 (A31): status ok, proof ok; tier line yes; adaptive flags in the argv {'--adapt-every': ['2']}; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L11-05-B (B): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L11-06-A32 (A32): status ok, proof ok; tier line yes; adaptive flags in the argv {'--adapt-decay': ['0.5']}; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L11-07-B (B): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L11-08-A32 (A32): status ok, proof ok; tier line yes; adaptive flags in the argv {'--adapt-decay': ['0.5']}; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L11-09-B (B): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L11-10-A31 (A31): status ok, proof ok; tier line yes; adaptive flags in the argv {'--adapt-every': ['2']}; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L11-11-B (B): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L11-12-A30 (A30): status ok, proof ok; tier line yes; adaptive flags in the argv {'--adapt-swaps': ['192']}; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L11-13-B (B): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']

#### Decode expert cache hit rate per tier (%, VRAM hits over lookups, pooled over the tier's requests; the engine's per-request line; counting tiers: run 2)

| Arm | Switch | agent:1 | agent:2 | agent | samp4k:4242 | samp4k:4243 | samp4k:4244 | samp4k | nat4k | tiny | cnt1k | cnt4k | cnt32k | cnt128k | PCIe % agent / samp4k | drain lines (n, ms) | last pcie_frac |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| L11-01-B | B | 96.1 | 97.3 | 96.5 | 94.2 | 98.3 | 98.1 | 96.9 | 91.8 | 89.8 | 96.6 | 99.0 | 99.2 | - | 0.10 / 0.06 | 0, 0 | 0.20 |
| L11-02-A30 | A30 | 95.3 | 97.4 | 96.5 | 94.6 | 98.0 | 97.5 | 96.7 | 94.4 | 91.7 | 98.3 | 99.1 | 99.1 | - | 0.07 / 0.08 | 0, 0 | 0.20 |
| L11-03-B | B | 97.0 | 95.5 | 96.4 | 93.2 | 98.4 | 97.9 | 96.5 | 91.8 | 89.8 | 96.5 | 98.9 | 99.2 | - | 0.14 / 0.08 | 0, 0 | 0.20 |
| L11-04-A31 | A31 | 96.1 | 95.9 | 96.0 | 95.1 | 97.2 | 97.4 | 96.6 | 94.5 | 92.6 | 97.8 | 98.7 | 98.9 | - | 0.11 / 0.07 | 0, 0 | 0.20 |
| L11-05-B | B | 94.9 | 96.9 | 95.9 | 94.6 | 98.5 | 97.6 | 96.8 | 92.2 | 89.8 | 96.5 | 99.0 | 99.2 | - | 0.13 / 0.08 | 0, 0 | 0.20 |
| L11-06-A32 | A32 | 94.2 | 96.3 | 95.2 | 94.7 | 97.4 | 97.1 | 96.4 | 91.8 | 89.6 | 96.2 | 98.8 | 99.1 | - | 0.16 / 0.08 | 0, 0 | 0.20 |
| L11-07-B | B | 94.7 | 96.1 | 95.3 | 93.4 | 98.1 | 98.0 | 96.5 | 92.1 | 89.8 | 96.6 | 98.9 | 99.2 | - | 0.14 / 0.08 | 0, 0 | 0.20 |
| L11-08-A32 | A32 | 94.6 | 96.2 | 95.2 | 94.1 | 97.3 | 98.0 | 96.5 | 92.1 | 89.6 | 96.3 | 98.8 | 99.0 | - | 0.16 / 0.08 | 0, 0 | 0.20 |
| L11-09-B | B | 97.3 | 95.7 | 96.6 | 94.8 | 97.4 | 98.3 | 96.9 | 92.2 | 89.8 | 96.6 | 98.9 | 99.2 | - | 0.09 / 0.06 | 0, 0 | 0.20 |
| L11-10-A31 | A31 | 97.1 | 95.5 | 96.5 | 94.8 | 97.1 | 97.6 | 96.5 | 94.4 | 92.9 | 97.8 | 98.6 | 98.9 | - | 0.11 / 0.08 | 0, 0 | 0.20 |
| L11-11-B | B | 95.3 | 95.0 | 95.2 | 94.2 | 97.6 | 98.0 | 96.7 | 92.1 | 89.8 | 96.6 | 99.0 | 99.1 | - | 0.15 / 0.09 | 0, 0 | 0.20 |
| L11-12-A30 | A30 | 94.7 | 97.0 | 95.8 | 95.0 | 97.1 | 98.1 | 96.8 | 93.4 | 91.7 | 98.3 | 99.0 | 99.1 | - | 0.14 / 0.08 | 0, 0 | 0.20 |
| L11-13-B | B | 95.7 | 95.7 | 95.7 | 94.5 | 97.2 | 97.2 | 96.3 | 92.6 | 89.8 | 96.6 | 99.0 | 99.2 | - | 0.12 / 0.09 | 0, 0 | 0.20 |

#### Baseline arms (noise reference: each baseline / the first baseline of its suite)

| Baseline | suite | D_win | D_real | P | R4 | R32 | R128 | F | T0 | T1 |
|---|---|---|---|---|---|---|---|---|---|---|
| L11-01-B | S | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | - | 1.000 | 1.000 | 1.000 |
| L11-03-B | S | 0.990 | 1.011 | 0.997 | 0.998 | 0.995 | - | 0.982 | 1.080 | 0.995 |
| L11-05-B | S | 0.989 | 0.991 | 1.004 | 1.016 | 0.992 | - | 0.992 | 1.066 | 0.994 |
| L11-07-B | S | 0.994 | 1.003 | 1.007 | 1.016 | 0.999 | - | 0.988 | 1.092 | 1.002 |
| L11-09-B | S | 0.993 | 0.991 | 1.002 | 0.998 | 1.007 | - | 0.983 | 1.309 | 0.997 |
| L11-11-B | S | 0.990 | 0.988 | 1.008 | 1.017 | 1.000 | - | 0.987 | 1.047 | 1.010 |
| L11-13-B | S | 0.993 | 1.015 | 0.997 | 0.999 | 0.996 | - | 0.988 | 1.112 | 0.999 |

#### Every run, compact (engine lines; decode tok/s per run)

| Arm | tiny prompt ms x6 | tiny decode x6 | cnt1k dec r1/r2 | cnt4k dec r1/r2 | cnt32k dec r1/r2 | cnt128k dec r1/r2 | cnt4k read r1/r2 | cnt32k read r1/r2 | cnt128k read r1/r2 | nat4k dec r1/r2 | samp4k dec 4242/4243/4244 | agent dec t1/t2 | agent prompt ms t1/t2 (reused) | drafts acc/offered samp4k; agent |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| L11-01-B | 184 161 106 148 183 89 | 74 97 99 105 121 96 | 130.0/170.2 | 172.0/173.3 | 166.3/165.3 | - | 1453/1452 | 2337/2328 | - | 95.6/114.7 | 100.8/102.0/105.6 | 98.2/98.0 | 11099/3205 (18763) | 381/565; 340/647 |
| L11-02-A30 | 155 154 95 115 135 116 | 78 92 99 113 106 100 | 149.4/173.1 | 170.9/171.7 | 165.4/164.9 | - | 1452/1454 | 2348/2327 | - | 93.2/105.7 | 104.5/110.1/109.6 | 104.7/106.4 | 11151/3257 (18763) | 408/586; 389/642 |
| L11-03-B | 197 167 135 148 138 121 | 74 97 98 106 121 97 | 130.5/169.2 | 171.0/169.4 | 165.7/165.2 | - | 1448/1449 | 2328/2317 | - | 91.3/113.5 | 104.8/107.3/104.5 | 102.9/100.3 | 11150/3265 (18763) | 395/580; 381/671 |
| L11-04-A31 | 162 174 161 173 153 120 | 83 101 96 114 128 115 | 148.3/173.2 | 170.7/171.0 | 164.4/164.1 | - | 1453/1452 | 2330/2314 | - | 96.9/108.0 | 101.1/112.6/101.6 | 110.9/99.4 | 10926/3214 (18763) | 391/567; 401/650 |
| L11-05-B | 174 135 156 138 152 120 | 73 96 97 106 120 97 | 130.6/168.5 | 170.9/170.9 | 164.5/164.0 | - | 1474/1475 | 2327/2311 | - | 92.3/105.5 | 96.1/108.4/106.9 | 104.5/96.5 | 11168/3230 (18763) | 394/597; 425/739 |
| L11-06-A32 | 205 155 150 144 191 133 | 71 95 97 112 120 118 | 128.9/168.5 | 171.4/171.3 | 164.8/165.5 | - | 1455/1455 | 2324/2316 | - | 88.2/110.8 | 101.5/103.2/108.0 | 106.1/113.7 | 11088/3260 (18763) | 389/580; 441/673 |
| L11-07-B | 171 165 159 122 124 111 | 74 97 98 102 120 98 | 131.4/169.4 | 170.4/170.9 | 165.2/165.4 | - | 1471/1474 | 2346/2327 | - | 91.9/111.3 | 101.6/100.5/112.4 | 102.5/98.6 | 11075/3243 (18763) | 396/591; 387/654 |
| L11-08-A32 | 197 137 150 157 155 110 | 73 98 99 111 119 117 | 130.4/169.0 | 170.8/171.0 | 164.5/165.3 | - | 1448/1448 | 2336/2327 | - | 95.5/115.5 | 97.8/109.2/110.0 | 112.7/111.9 | 11121/3281 (18763) | 397/555; 364/534 |
| L11-09-B | 204 134 105 109 125 111 | 75 95 98 106 119 97 | 131.1/169.3 | 170.6/171.4 | 162.8/165.0 | - | 1450/1449 | 2341/2344 | - | 88.8/112.5 | 99.3/105.2/95.8 | 100.4/107.5 | 11133/3260 (18763) | 355/534; 384/665 |
| L11-10-A31 | 187 187 137 126 118 91 | 83 101 100 114 109 100 | 148.8/173.1 | 170.7/171.0 | 164.3/165.0 | - | 1447/1445 | 2325/2317 | - | 95.4/109.8 | 95.3/107.4/98.6 | 98.0/109.8 | 11021/3265 (18763) | 372/572; 365/620 |
| L11-11-B | 200 172 129 146 149 122 | 73 95 97 104 120 96 | 129.4/169.1 | 169.9/170.9 | 164.6/163.9 | - | 1474/1476 | 2339/2328 | - | 95.2/102.3 | 98.3/99.6/103.6 | 105.2/99.4 | 10993/3246 (18763) | 366/537; 405/665 |
| L11-12-A30 | 187 150 106 127 144 95 | 78 91 98 114 110 99 | 149.2/174.1 | 171.1/171.7 | 164.7/164.7 | - | 1452/1451 | 2324/2323 | - | 97.2/113.6 | 94.4/108.3/95.1 | 115.5/109.8 | 11116/3205 (18763) | 351/544; 445/651 |
| L11-13-B | 200 200 105 152 126 101 | 74 95 95 103 122 97 | 130.5/169.7 | 170.5/171.2 | 164.8/164.6 | - | 1446/1450 | 2328/2320 | - | 87.0/111.5 | 100.7/114.2/112.2 | 102.5/105.0 | 11105/3244 (18763) | 409/576; 263/436 |

#### L11 reading (computed; secondary readings are descriptive, not gates)

- **All three screens pass on the mixed gate**, each with one `D_real` pair at or above 1.02 and the other between 1.009 and
  1.018, and `D_win` flat in every pair (condition holds): **A30** `--adapt-swaps 192` 1.024, 1.013 (reversed 1.048, 1.020);
  **A31** `--adapt-every 2` 1.009, 1.030 (reversed 1.008, 1.011); **A32** `--adapt-decay 0.5` 1.031, 1.018 (reversed 1.053,
  1.065). Geometric means of the screen pairs (the c9 order of decision 9): A32 1.0246, A31 1.0195, A30 1.0187. The seven
  baselines' own `D_real` spans 0.988 to 1.015 of the first, so each of these screens sits within about one baseline spread;
  that is what the confirmation pairs are for.
- **Where the tier helps, by the hit-rate line** (no diagnostic switch): A30 and A31 raise the decode hit rate on the short
  and greedy tiers, tiny 91.7 / 91.7 (A30) and 92.6 / 92.9% (A31) against 89.8% in every baseline, nat4k 93.4 to 94.5%
  against 91.8 to 92.6%, cnt1k run 2 97.8 to 98.3% against 96.5 to 96.6%, and the first counting run after the tiny tier
  decodes 148 to 149 tok/s against 129 to 131 (+14%): with twice the swaps a round, or a round twice as often, the tier
  catches up with a new text faster. On the agent turns and samp4k their hit rates stay inside the baselines' range (agent
  95.8 to 96.5% against 95.2 to 96.6%; samp4k 96.5 to 96.8% against 96.3 to 96.9%). A32 (faster forgetting) changes no hit
  rate measurably (agent 95.2%, samp4k 96.4 / 96.5%, tiny 89.6%).
- **The sampled tiers' decode follows their text**: A32's `D_real` gain is the agent turns (decode 1.092 / 1.087, reversed
  1.116 / 1.088) with an unchanged hit rate and more drafts accepted (agent 65.5% and 68.2% of drafts against 52.6% to 60.9%
  in the seven baselines); the agent and samp4k texts differ in every process (thinking on, card sampling), so these tiers
  carry a text effect beside any switch effect.
- **The greedy tiny texts change under all three and stay fixed in every baseline**: the seven baselines produce the same six
  tiny texts (equal sha256), while A30 changes 5 of the 6 (the same 5 in both A30 arms), A31 3 of 6 (a different set in each
  of its arms) and A32 2 of 6 (the same in both); the nat4k texts differ in every arm, baselines included. The tier's
  residency moves experts between the GPU's and the CPU's rounding (SWITCHES-5.md), so the arms are rounding-changing as
  audited, and their tiny decode carries a text effect (tiny drafts accepted 59.7% and 60.5% for A30, 66.9% and 60.3% for
  A31, 65.2% in both A32 arms, against 60.3% in every baseline).
- **The asynchronous tier was never tried**: no arm printed a self-decision line (all 13 stayed on the blocking tier), no
  request waited 1 ms or more for a round in flight (no drain line), and the PCIe share settled at 0.20 in every arm.
- **Secondary**: A30 `T0` 1.231 / 1.139 (reversed 1.089 / 1.026), A31 0.885 / 0.898 (reversed 0.897 / 1.122), A32 0.951 /
  0.928; baseline `T0` moves 1.047 to 1.309 of the first. `P`, `R4`, `R32`, `F`, `T1` within 0.98 to 1.02 everywhere except
  A31's `R4` 0.984 and A32's `R4` 0.986 / 0.987 (the 4K read: baseline `R4` itself moves 0.998 to 1.017).
- **Confirmation owed** (decision 9): A30, A31 and A32, with A33's screen still to come in L12; c9 holds at most two groups.
