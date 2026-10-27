# r7-pa-c10

- Job exit 0, restore exit 0 (the lab wrapper stopped production, ran the job, restored production and verified it with a real completion).
- Runs in this directory: c10-01-A30, c10-02-B, c10-03-B, c10-04-A30, c10-05-A33, c10-06-B, c10-07-B, c10-08-A33, c10c-01-B, c10c-02-A30, c10c-03-A33, c10c-04-B.
- Every run of this batch is copied here.
- Below: the batch's section from the round's `RESULTS-6.md`, verbatim except shortened paths. Paths such as `phase-a/raw/...` and `plans/...` refer to the lab workspace and are not part of this directory.
- The output check `r7-pa-c10-check` (runs `c10c-*`) ran in this batch's lock turn after the timing plan.

### r7-pa-c10 (confirm: A30, A33; then their output checks, r7-pa-c10-check)

- Window: 2026-10-27T01:14:17+00:00 to 2026-10-27T02:07:09+00:00 UTC; job exit 0, restore exit 0 (timing plan 0, check plan 0); elapsed in the timing plan 2272.2 s. Lock turn: LOCKED-START r7-pa-c10 2026-10-27T01:14:16+00:00 holder-before=idle-after-r7-b0-3 2026-10-27T01:09:49+00:00.
- Production before / after (sha256 of config and exe, on disk): 92c2f588c6bb7d02 strata-swift-iq3_xxs-256k.json; 26da5a7e53bf79a1 strata / 92c2f588c6bb7d02 strata-swift-iq3_xxs-256k.json; 26da5a7e53bf79a1 strata; PF1 binary before / after: e6298242e44e1842 strata; c90e8ff1316b0efb libstrata_kq.so / e6298242e44e1842 strata; c90e8ff1316b0efb libstrata_kq.so. r7suite freeze start / end: config `92c2f588c6bb7d02` / `92c2f588c6bb7d02`, exe `26da5a7e53bf79a1` / `26da5a7e53bf79a1`, PF1 exe `e6298242e44e1842` / `e6298242e44e1842`, frozen_ok_end True.
- Checks around the batch: PRODCHECK-PRE r7-pa-c10 rc=0; REALREQ-PRE r7-pa-c10 rc=0; BATCH-RC r7-pa-c10 rc=0 job=0 restore=0 2026-10-27T02:07:09+00:00; PRODCHECK-POST r7-pa-c10 rc=0; REALREQ-POST r7-pa-c10 rc=0; GPU-POST 250.00 W, 23744 MiB. Restore: verified 2026-10-27T02:07:09Z, model strata/swift-1.5-iq3_xxs-256K, max_context 262144, expert slots 10320, reply 'READY'.
- Pattern: A30 X B B X on suite C (its two confirmation pairs), then A33 X B B X on suite C only if the whole pattern fits (the plan's second half: all or none); 700 s of the batch kept for r7-pa-c10-check. Second half (A33's group, all or none): run (slowest arm 284.2 s, needed 1310 s, left 1616 s). Arm statuses: ok 8.
- Harness: phase-a6 `r7suite.py` `7df7f0b0...`, plan `plans/r7-pa-c10.json` (sha256 in the decisions above). Raw: `phase-a/raw6/gpu/r7-pa-c10/`. Keyscan on the VM before the copy: 137 files, 0 with the key.
- Output-check plan `r7-pa-c10-check` (r7check.py `6c09945c...`): elapsed 859.5 s, frozen_ok_end True, arms c10c-01-B ok (needles 9); c10c-02-A30 ok (needles 9); c10c-03-A33 ok (needles 9); c10c-04-B ok (needles 9).

#### Per arm (engine-measured; D in tok/s, P and R in tok/s, F, T0, T1 in ms; slots = expert slots at ready)

| Arm | Switch | Status | Proof | D_win | D_real | P | R4 | R32 | R128 | F | T0 | T1 | decode tiny/1k/4k/32k/128k/nat4k/samp4k/agent | slots | free MiB | s |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c10-01-A30 | A30 | ok | ok | 173.08 | 104.17 | 1865.7 | 1477.6 | 2355.8 | 2237.2 | 3197.0 | 116.5 | 10991.0 | 98.7/177.8/175.0/166.7/161.1/100.0/105.5/107.1 | 10320 | 379 | 283 |
| c10-02-B | B | ok | ok | 168.77 | 103.13 | 1831.4 | 1445.3 | 2320.6 | 2212.2 | 3073.0 | 148.0 | 11181.0 | 94.9/169.1/171.8/165.5/161.0/99.3/105.0/105.3 | 10320 | 379 | 283 |
| c10-03-B | B | ok | ok | 168.70 | 104.54 | 1844.6 | 1455.4 | 2337.8 | 2212.5 | 3073.0 | 148.0 | 11059.0 | 96.1/170.1/170.8/165.3/160.4/101.5/106.1/106.1 | 10320 | 379 | 284 |
| c10-04-A30 | A30 | ok | ok | 169.61 | 102.43 | 1844.7 | 1454.3 | 2339.8 | 2210.1 | 3122.0 | 121.5 | 11079.0 | 97.1/173.2/170.8/164.9/158.1/102.7/100.3/104.3 | 10320 | 379 | 284 |
| c10-05-A33 | A33 | ok | ok | 167.39 | 103.66 | 1834.3 | 1451.1 | 2318.6 | 2211.9 | 3130.0 | 134.0 | 11042.0 | 96.7/168.4/170.8/163.1/157.8/99.8/106.0/105.3 | 10320 | 379 | 285 |
| c10-06-B | B | ok | ok | 167.17 | 103.69 | 1848.4 | 1472.1 | 2320.7 | 2214.7 | 3044.0 | 137.0 | 11018.0 | 96.8/168.2/170.6/162.8/159.8/97.0/105.7/108.8 | 10320 | 379 | 284 |
| c10-07-B | B | ok | ok | 167.89 | 102.34 | 1828.5 | 1445.3 | 2313.4 | 2225.6 | 3113.0 | 129.0 | 11168.0 | 96.8/168.5/170.6/164.6/158.3/102.6/109.0/95.8 | 10320 | 379 | 285 |
| c10-08-A33 | A33 | ok | ok | 168.11 | 104.85 | 1837.2 | 1457.0 | 2316.7 | 2209.1 | 3080.0 | 143.5 | 11084.0 | 96.5/168.5/171.0/164.8/160.5/102.2/105.2/107.2 | 10320 | 379 | 284 |

#### Pair ratios (arm / baseline for D_win, D_real, P, R4, R32, R128; baseline / arm for F, T0, T1; phase as the plan declares it)

| Arm | Pair | Phase | D_win | D_real | P | R4 | R32 | R128 | F | T0 | T1 | tier decode (tiny/1k/4k/32k/128k/nat4k/samp4k/agent) |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| A30 (c10-01-A30) | c10-02-B (arm then baseline) | confirm | 1.025 | 1.010 | 1.019 | 1.022 | 1.015 | 1.011 | 0.961 | 1.270 | 1.017 | 1.040/1.051/1.018/1.007/1.001/1.007/1.005/1.018 |
| A30 (c10-04-A30) | c10-03-B (baseline then arm) | confirm | 1.005 | 0.980 | 1.000 | 0.999 | 1.001 | 0.999 | 0.984 | 1.218 | 0.998 | 1.010/1.018/1.000/0.998/0.986/1.012/0.945/0.983 |
| A33 (c10-05-A33) | c10-06-B (arm then baseline) | confirm | 1.001 | 1.000 | 0.992 | 0.986 | 0.999 | 0.999 | 0.973 | 1.022 | 0.998 | 0.999/1.001/1.001/1.001/0.988/1.029/1.003/0.968 |
| A33 (c10-08-A33) | c10-07-B (baseline then arm) | confirm | 1.001 | 1.025 | 1.005 | 1.008 | 1.001 | 0.993 | 1.011 | 0.899 | 1.008 | 0.997/1.000/1.003/1.001/1.014/0.996/0.965/1.119 |

#### Proof per arm (argv adaptive flags, the tier line, refusals, environ; any self-decision line)

- c10-01-A30 (A30): status ok, proof ok; tier line yes; adaptive flags in the argv {'--adapt-swaps': ['192']}; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- c10-02-B (B): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- c10-03-B (B): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- c10-04-A30 (A30): status ok, proof ok; tier line yes; adaptive flags in the argv {'--adapt-swaps': ['192']}; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- c10-05-A33 (A33): status ok, proof ok; tier line yes; adaptive flags in the argv {'--adapt-min-gain': ['1.2']}; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- c10-06-B (B): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- c10-07-B (B): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- c10-08-A33 (A33): status ok, proof ok; tier line yes; adaptive flags in the argv {'--adapt-min-gain': ['1.2']}; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']

#### Decode expert cache hit rate per tier (%, VRAM hits over lookups, pooled over the tier's requests; the engine's per-request line; counting tiers: run 2)

| Arm | Switch | agent:1 | agent:2 | agent | samp4k:4242 | samp4k:4243 | samp4k:4244 | samp4k | nat4k | tiny | cnt1k | cnt4k | cnt32k | cnt128k | PCIe % agent / samp4k | drain lines (n, ms) | last pcie_frac |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c10-01-A30 | A30 | 94.8 | 96.1 | 95.4 | 94.0 | 98.5 | 97.9 | 96.8 | 94.2 | 91.7 | 98.3 | 99.0 | 99.1 | 99.1 | 0.14 / 0.08 | 0, 0 | 0.20 |
| c10-02-B | B | 94.0 | 96.1 | 95.0 | 93.8 | 97.3 | 98.0 | 96.3 | 91.8 | 89.8 | 96.5 | 98.9 | 99.1 | 99.2 | 0.18 / 0.09 | 0, 0 | 0.20 |
| c10-03-B | B | 94.7 | 95.6 | 95.1 | 94.8 | 96.9 | 97.6 | 96.5 | 91.7 | 89.8 | 96.6 | 99.0 | 99.2 | 99.2 | 0.15 / 0.08 | 0, 0 | 0.20 |
| c10-04-A30 | A30 | 96.2 | 96.9 | 96.5 | 94.1 | 98.6 | 97.3 | 96.7 | 93.6 | 91.7 | 98.3 | 99.0 | 99.1 | 99.2 | 0.13 / 0.08 | 0, 0 | 0.20 |
| c10-05-A33 | A33 | 92.5 | 95.8 | 94.0 | 93.9 | 98.2 | 96.5 | 96.3 | 92.4 | 89.8 | 96.6 | 98.9 | 99.2 | 99.2 | 0.19 / 0.10 | 0, 0 | 0.20 |
| c10-06-B | B | 95.9 | 95.3 | 95.7 | 93.8 | 97.9 | 97.8 | 96.5 | 92.3 | 89.8 | 96.6 | 99.0 | 99.1 | 99.1 | 0.14 / 0.09 | 0, 0 | 0.20 |
| c10-07-B | B | 96.9 | 98.1 | 97.5 | 94.8 | 98.2 | 97.7 | 96.9 | 92.0 | 89.8 | 96.5 | 99.0 | 99.2 | 99.2 | 0.04 / 0.06 | 0, 0 | 0.20 |
| c10-08-A33 | A33 | 93.2 | 95.0 | 93.9 | 93.7 | 98.0 | 97.6 | 96.5 | 91.8 | 89.8 | 96.5 | 98.9 | 99.1 | 99.2 | 0.23 / 0.08 | 0, 0 | 0.20 |

#### Baseline arms (noise reference: each baseline / the first baseline of its suite)

| Baseline | suite | D_win | D_real | P | R4 | R32 | R128 | F | T0 | T1 |
|---|---|---|---|---|---|---|---|---|---|---|
| c10-02-B | C | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 |
| c10-03-B | C | 1.000 | 1.014 | 1.007 | 1.007 | 1.007 | 1.000 | 1.000 | 1.000 | 1.011 |
| c10-06-B | C | 0.990 | 1.006 | 1.009 | 1.019 | 1.000 | 1.001 | 1.010 | 1.080 | 1.015 |
| c10-07-B | C | 0.995 | 0.992 | 0.998 | 1.000 | 0.997 | 1.006 | 0.987 | 1.147 | 1.001 |

#### Every run, compact (engine lines; decode tok/s per run)

| Arm | tiny prompt ms x6 | tiny decode x6 | cnt1k dec r1/r2 | cnt4k dec r1/r2 | cnt32k dec r1/r2 | cnt128k dec r1/r2 | cnt4k read r1/r2 | cnt32k read r1/r2 | cnt128k read r1/r2 | nat4k dec r1/r2 | samp4k dec 4242/4243/4244 | agent dec t1/t2 | agent prompt ms t1/t2 (reused) | drafts acc/offered samp4k; agent |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c10-01-A30 | 175 123 98 114 119 105 | 80 94 102 115 108 105 | 150.8/177.7 | 174.2/174.9 | 166.7/166.6 | 161.2/161.1 | 1478/1478 | 2370/2356 | 2253/2237 | 95.2/105.3 | 99.8/107.8/109.5 | 105.0/109.3 | 10991/3197 (18763) | 395/579; 459/733 |
| c10-02-B | 218 161 104 135 186 115 | 73 96 97 106 117 95 | 130.9/169.1 | 170.8/171.8 | 161.9/165.5 | 160.1/161.1 | 1447/1445 | 2341/2321 | 2220/2212 | 93.4/105.9 | 97.6/109.8/108.4 | 108.0/102.0 | 11181/3073 (18763) | 400/602; 313/508 |
| c10-03-B | 174 145 138 151 184 121 | 75 96 98 107 117 97 | 131.6/170.1 | 170.3/170.7 | 165.6/165.3 | 160.5/160.4 | 1451/1455 | 2334/2338 | 2219/2213 | 91.3/114.2 | 97.0/115.8/107.2 | 105.0/108.1 | 11059/3073 (18763) | 399/573; 357/573 |
| c10-04-A30 | 156 124 112 119 134 99 | 80 94 96 111 109 102 | 148.2/173.2 | 171.3/170.7 | 165.3/164.9 | 160.4/158.1 | 1454/1454 | 2346/2340 | 2217/2210 | 99.9/105.6 | 99.9/96.6/104.7 | 102.9/106.2 | 11079/3122 (18763) | 373/571; 394/651 |
| c10-05-A33 | 175 162 131 137 126 119 | 74 97 100 107 120 96 | 130.4/168.4 | 170.3/170.8 | 166.1/163.0 | 160.8/157.8 | 1451/1451 | 2331/2319 | 2220/2212 | 90.3/111.6 | 99.7/103.9/115.7 | 102.6/108.7 | 11042/3130 (18763) | 408/593; 421/681 |
| c10-06-B | 190 170 136 138 136 93 | 75 97 99 107 120 96 | 130.5/168.2 | 169.7/170.5 | 164.9/162.8 | 159.9/159.8 | 1473/1472 | 2336/2321 | 2227/2215 | 90.5/104.6 | 97.7/110.5/109.8 | 107.3/110.7 | 11018/3044 (18763) | 408/617; 412/652 |
| c10-07-B | 205 134 104 148 124 90 | 74 97 99 106 121 98 | 131.0/168.6 | 170.3/170.6 | 161.5/164.6 | 160.1/158.3 | 1445/1445 | 2321/2313 | 2230/2226 | 92.7/114.9 | 101.2/107.0/120.5 | 100.2/91.8 | 11168/3113 (18763) | 419/605; 378/705 |
| c10-08-A33 | 198 134 159 145 142 133 | 75 97 99 102 122 98 | 131.6/168.5 | 170.3/171.0 | 164.6/164.8 | 160.3/160.5 | 1465/1457 | 2330/2317 | 2215/2209 | 93.5/112.7 | 104.3/106.5/104.7 | 105.9/109.3 | 11084/3080 (18763) | 393/561; 378/588 |


#### Confirmation gates, A30 and A33 (decision 5: the two screen pairs and the two c10 pairs; `scripts6/confirm6.py`, which reproduces the VM gate's `checks/gate-c10.json` figure for figure)

##### A30 (primary D_real)

| Phase | Batch | Pair | proof | D_win | D_real | P | R4 | R32 | R128 | F | T0 | T1 | greedy decode (tiny/1k/4k/32k/128k/nat4k) | samp4k/agent decode |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| screen | r7-pa-L11 | L11-02-A30 vs L11-01-B | ok | 1.001 | 1.024 | 1.001 | 1.002 | 0.999 | - | 0.984 | 1.231 | 0.995 | 0.997/1.017/0.991/0.997/-/0.950 | 1.051/1.077 |
| screen | r7-pa-L11 | L11-02-A30 vs L11-03-B | ok | 1.011 | 1.013 | 1.004 | 1.004 | 1.005 | - | 1.002 | 1.139 | 1.000 | 0.994/1.023/1.013/0.998/-/0.979 | 1.023/1.038 |
| confirm | r7-pa-c10 | c10-01-A30 vs c10-02-B | ok | 1.025 | 1.010 | 1.019 | 1.022 | 1.015 | 1.011 | 0.961 | 1.270 | 1.017 | 1.040/1.051/1.018/1.007/1.001/1.007 | 1.005/1.018 |
| confirm | r7-pa-c10 | c10-04-A30 vs c10-03-B | ok | 1.005 | 0.980 | 1.000 | 0.999 | 1.001 | 0.999 | 0.984 | 1.218 | 0.998 | 1.010/1.018/1.000/0.998/0.986/1.012 | 0.945/0.983 |

| Metric | pair ratios (screen, screen, confirm, confirm) | median | bootstrap 95% (20,000, seed 20261026) |
|---|---|---|---|
| D_real (primary) | 1.024, 1.013, 1.010, 0.980 | 1.0117 | 0.9798 to 1.0242 |
| D_win | 1.001, 1.011, 1.025, 1.005 | 1.0084 | 1.0014 to 1.0255 |

| Tier | kind | pair ratios | median | >= 0.98 |
|---|---|---|---|---|
| tiny decode | greedy (gated) | 0.997, 0.994, 1.040, 1.010 | 1.0039 | yes |
| cnt1k decode | greedy (gated) | 1.017, 1.023, 1.051, 1.018 | 1.0206 | yes |
| cnt4k decode | greedy (gated) | 0.991, 1.013, 1.018, 1.000 | 1.0067 | yes |
| cnt32k decode | greedy (gated) | 0.997, 0.998, 1.007, 0.998 | 0.9981 | yes |
| cnt128k decode | greedy (gated) | 1.001, 0.986 | 0.9932 | yes |
| nat4k decode | greedy (gated) | 0.950, 0.979, 1.007, 1.012 | 0.9930 | yes |
| samp4k decode | sampled (reported) | 1.051, 1.023, 1.005, 0.945 | 1.0143 | yes |
| agent decode | sampled (reported) | 1.077, 1.038, 1.018, 0.983 | 1.0281 | yes |

VERDICT A30: not confirmed (median 1.0117 < 1.02; interval reaches 0.9798)

##### A33 (primary D_real)

| Phase | Batch | Pair | proof | D_win | D_real | P | R4 | R32 | R128 | F | T0 | T1 | greedy decode (tiny/1k/4k/32k/128k/nat4k) | samp4k/agent decode |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| screen | r7-pa-L12 | L12-06-A33 vs L12-05-B | ok | 1.000 | 0.975 | 0.996 | 0.991 | 1.000 | - | 1.002 | 0.968 | 0.998 | 1.000/1.001/1.002/0.998/-/0.934 | 0.979/1.013 |
| screen | r7-pa-L12 | L12-06-A33 vs L12-07-B | ok | 1.002 | 1.012 | 0.990 | 0.974 | 1.006 | - | 0.992 | 1.248 | 1.012 | 0.999/1.004/1.002/1.001/-/0.969 | 1.008/1.062 |
| confirm | r7-pa-c10 | c10-05-A33 vs c10-06-B | ok | 1.001 | 1.000 | 0.992 | 0.986 | 0.999 | 0.999 | 0.973 | 1.022 | 0.998 | 0.999/1.001/1.001/1.001/0.988/1.029 | 1.003/0.968 |
| confirm | r7-pa-c10 | c10-08-A33 vs c10-07-B | ok | 1.001 | 1.025 | 1.005 | 1.008 | 1.001 | 0.993 | 1.011 | 0.899 | 1.008 | 0.997/1.000/1.003/1.001/1.014/0.996 | 0.965/1.119 |

| Metric | pair ratios (screen, screen, confirm, confirm) | median | bootstrap 95% (20,000, seed 20261026) |
|---|---|---|---|
| D_real (primary) | 0.975, 1.012, 1.000, 1.025 | 1.0060 | 0.9745 to 1.0245 |
| D_win | 1.000, 1.002, 1.001, 1.001 | 1.0013 | 1.0002 to 1.0022 |

| Tier | kind | pair ratios | median | >= 0.98 |
|---|---|---|---|---|
| tiny decode | greedy (gated) | 1.000, 0.999, 0.999, 0.997 | 0.9988 | yes |
| cnt1k decode | greedy (gated) | 1.001, 1.004, 1.001, 1.000 | 1.0010 | yes |
| cnt4k decode | greedy (gated) | 1.002, 1.002, 1.001, 1.003 | 1.0020 | yes |
| cnt32k decode | greedy (gated) | 0.998, 1.001, 1.001, 1.001 | 1.0010 | yes |
| cnt128k decode | greedy (gated) | 0.988, 1.014 | 1.0007 | yes |
| nat4k decode | greedy (gated) | 0.934, 0.969, 1.029, 0.996 | 0.9824 | yes |
| samp4k decode | sampled (reported) | 0.979, 1.008, 1.003, 0.965 | 0.9910 | yes |
| agent decode | sampled (reported) | 1.013, 1.062, 0.968, 1.119 | 1.0376 | yes |

VERDICT A33: not confirmed (median 1.0060 < 1.02; interval reaches 0.9745)


#### Output checks, r7-pa-c10-check (adaptive lane; `scripts6/check_analyse6.py` with the production tokenizer; descriptive, both arms failed confirmation)

##### Output-check table, r7-pa-c10-check (as `scripts6/check_analyse6.py` prints it)

| Arm | Members | Class | Proof | pcie_frac | tiny:0 | tiny:1 | tiny:2 | tiny:3 | tiny:4 | tiny:5 | id1k | id32k | agent:1 | agent:2 | id128k | needles found (arm/B1) | answers equal | Verdict |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c10c-01-B | (reference) | lane baseline | ok | 0.32 | - | - | - | - | - | - | - | - | - | - | - | 9 of 9 | - | reference |
| c10c-02-A30 | A30 | rounding | ok | 0.32 | tok 17 / char 67 | tok 25 / char 152 | tok 21 / char 79 | same | same | tok 0 / char 1 | tok 51 / char 321 | tok 162 / char 626 | tok 28 / char 136 | tok 2 / char 4 | tok 11 / char 51 | 9/9 | yes | PASS (needles right wherever B1 is right) |
| c10c-03-A33 | A33 | rounding | ok | 0.32 | same | same | same | same | same | same | same | tok 162 / char 626 | tok 31 / char 151 | tok 2 / char 4 | tok 3 / char 15 | 9/9 | yes | PASS (needles right wherever B1 is right) |
| c10c-04-B | B | control | ok | 0.32 | same | same | same | same | same | same | same | tok 162 / char 626 | tok 31 / char 151 | tok 2 / char 4 | tok 17 / char 90 | 9/9 | yes | control: DIFFERS from B1 |

Cells: `same` = byte-identical generated stream with equal prompt/reused/read counts; `tok N / char M` = the first divergent token index (re-tokenized, 0-based) and character index against c10c-01-B.

#### Needles per (length, depth): found in the arm / in c10c-01-B, answers byte-equal

| Arm | 8k @10% | 8k @50% | 8k @90% | 16k @10% | 16k @50% | 16k @90% | 28k @10% | 28k @50% | 28k @90% |
|---|---|---|---|---|---|---|---|---|---|
| c10c-02-A30 | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |
| c10c-03-A33 | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |
| c10c-04-B | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |

#### Generated tokens per prompt (engine count, arm / c10c-01-B)

| Arm | tiny:0 | tiny:1 | tiny:2 | tiny:3 | tiny:4 | tiny:5 | id1k | id32k | agent:1 | agent:2 | id128k |
|---|---|---|---|---|---|---|---|---|---|---|---|
| c10c-02-A30 | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 78/69 | 256/256 | 384/249 | 324/208 | 148/139 |
| c10c-03-A33 | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 69/69 | 256/256 | 384/249 | 291/208 | 146/139 |
| c10c-04-B | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 69/69 | 256/256 | 384/249 | 297/208 | 144/139 |

#### c10 reading (computed)

- **Neither A30 nor A33 confirms.** A30's `D_real` four-pair ratios read 1.024 and 1.013 (L11 screen) and 1.010 and 0.980
  (c10): median **1.0117**, bootstrap **0.9798 to 1.0242**; A33's read 0.975 and 1.012 (L12 screen) and 1.000 and 1.025
  (c10): median **1.0060**, bootstrap **0.9745 to 1.0245**. Both miss the predeclared 1.02 bar and both intervals reach
  below 1.0. Every greedy tier passes the tier rule for both (A30's lowest nat4k 0.9930, cnt128k 0.9932; A33's lowest nat4k
  0.9824), so neither fails on a tier.
- **A30's L11 gain did not carry.** Its screen pairs were 1.024 and 1.013 with the reversed half at 1.048 and 1.020, but the
  two c10 pairs read 1.010 and 0.980; the means of its two arms' `D_real` are 103.3 (A30) against 103.8 (the c10 baselines),
  so on this batch's data the setting is level. Its secondary readings are small and consistent in sign: `D_win` median 1.0084
  (1.001, 1.011, 1.025, 1.005), `T0` 1.231 to 1.270, `F` 0.961 to 0.984. The hit-rate line keeps the one mechanism part 5
  saw: its two arms' tiny texts (`--adapt-swaps 192` writes 5 of the 6 differently from every baseline, the same 5 in both
  arms) and cnt1k run 2 decode 1.051 and 1.018.
- **A33 is inert on these requests.** `D_win` its four pairs 1.000, 1.002, 1.001, 1.001; `D_real` 1.0060 median; both A33
  arms reproduce all six baseline tiny texts exactly and their tiny decode is 0.997 to 1.000 of the adjacent baselines, which
  is part 5's reading (the 2.0 candidate floor, `generate.cpp:10694`, rarely admits an extra swap on these requests).
- **Output checks.** Both arms pass the needle gate: 9 of 9 needles in each, answers byte-equal to B1's. What is attributable:
  A30 diverges from B1 at tiny:0 (token 17), tiny:1 (25), tiny:2 (21), tiny:4 (0) and id1k (51), where the control B2
  reproduces B1; A33 equals B2 byte for byte on every prompt except agent:2 and id128k, so its id32k (162) and agent:1 (31)
  differences from B1 are not attributable to it. Not attributable (B2 also differs from B1): id32k, agent:1, agent:2 and
  id128k.
- **Observed, not explained**: in this lane B2 differs from B1 on four prompts (id32k, agent:1, agent:2, id128k), where part
  5's c9 check had it differ on one (id128k, token 0); and B2's id32k, agent:1 and tiny texts are byte-identical to A33's.
  The adaptive lane is not reproducible run to run on those prompts (part 5's finding, reproduced), and this batch shows more
  of it than c9's. No gate depends on it.
- **Composition consequence**: with neither confirmed, `gate-c10.py` took variant `none`, so c11 = A18, A19, A12, A21, A32
  (`checks/gate-c10.json`: `eligible []`, `variant none`).
