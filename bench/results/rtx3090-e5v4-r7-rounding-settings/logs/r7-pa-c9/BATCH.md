# r7-pa-c9

- Job exit 0, restore exit 0 (the lab wrapper stopped production, ran the job, restored production and verified it with a real completion).
- Runs in this directory: c9-01-A32, c9-02-B, c9-03-B, c9-04-A32, c9-05-A31, c9-06-B, c9-07-B, c9-08-A31, c9c-01-B, c9c-02-A32, c9c-03-A31, c9c-04-B.
- Every run of this batch is copied here.
- Below: the batch's section from the round's `RESULTS-5.md`, verbatim except shortened paths. Paths such as `phase-a/raw/...` and `plans/...` refer to the lab workspace and are not part of this directory.
- `check-c9.md`'s title says "deterministic lane" (the analysis script's fixed title); the check ran in the adaptive lane (`STRATA_PREFILL_CPU_SHARE=0 --pcie-frac 0.32`, no `--adapt-every 0`), as the run files and the section below record.

### r7-pa-c9 (confirm: A31, A32)

- Window: 2026-10-26T23:49:55+00:00 to 2026-10-27T00:42:50+00:00 UTC; job exit 0, restore exit 0 (timing plan 0, check plan 0); elapsed in the timing plan 2273.0 s. Lock turn: LOCKED-START r7-pa-c9 2026-10-26T23:49:54+00:00 holder-before=idle-after-r7-pa-L12 2026-10-26T23:48:10+00:00.
- Production before / after (sha256 of config and exe, on disk): 92c2f588c6bb7d02 strata-swift-iq3_xxs-256k.json; 26da5a7e53bf79a1 strata / 92c2f588c6bb7d02 strata-swift-iq3_xxs-256k.json; 26da5a7e53bf79a1 strata. r7suite freeze start / end: config `92c2f588c6bb7d02` / `92c2f588c6bb7d02`, exe `26da5a7e53bf79a1` / `26da5a7e53bf79a1`, frozen_ok_end True.
- Checks around the batch: PRODCHECK-PRE r7-pa-c9 rc=0; REALREQ-PRE r7-pa-c9 rc=0; BATCH-RC r7-pa-c9 rc=0 job=0 restore=0 2026-10-27T00:42:50+00:00; PRODCHECK-POST r7-pa-c9 rc=0; REALREQ-POST r7-pa-c9 rc=0; GPU-POST 250.00 W, 23744 MiB. Restore: verified 2026-10-27T00:42:50Z, model strata/swift-1.5-iq3_xxs-256K, max_context 262144, expert slots 10320, reply 'READY'.
- Pattern: per candidate X B B X (ON OFF OFF ON) on suite C, the opposite order to its screen's B X B. Reversed half: not run (slowest arm None s, needed None s, left None s). Arm statuses: ok 8.
- Harness: phase-a5 `r7suite.py` `f73417dd...`, plan `plans/r7-pa-c9.json` (sha256 in the decisions above). Raw: `phase-a/raw5/gpu/r7-pa-c9/`. Keyscan on the VM before the copy: 137 files, 0 with the key.
- Output-check plan `r7-pa-c9-check` (r7check.py `c053e9fa...`): elapsed 862.0 s, frozen_ok_end True, arms c9c-01-B ok (needles 9); c9c-02-A32 ok (needles 9); c9c-03-A31 ok (needles 9); c9c-04-B ok (needles 9).

#### Per arm (engine-measured; D in tok/s, P and R in tok/s, F, T0, T1 in ms; slots = expert slots at ready)

| Arm | Switch | Status | Proof | D_win | D_real | P | R4 | R32 | R128 | F | T0 | T1 | decode tiny/1k/4k/32k/128k/nat4k/samp4k/agent | slots | free MiB | s |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c9-01-A32 | A32 | ok | ok | 170.13 | 103.02 | 1834.7 | 1443.2 | 2332.5 | 2212.1 | 3134.0 | 150.5 | 11267.0 | 100.3/171.6/172.9/166.0/160.8/102.0/103.3/103.8 | 10320 | 379 | 285 |
| c9-02-B | B | ok | ok | 169.04 | 99.78 | 1840.1 | 1451.6 | 2332.5 | 2219.8 | 3065.0 | 170.5 | 11187.0 | 96.4/170.3/171.6/165.3/160.9/98.9/103.1/97.4 | 10320 | 379 | 285 |
| c9-03-B | B | ok | ok | 168.44 | 102.43 | 1849.5 | 1473.2 | 2321.9 | 2212.3 | 3169.0 | 141.0 | 11065.0 | 94.2/169.2/171.5/164.7/160.1/97.8/99.6/110.3 | 10320 | 379 | 284 |
| c9-04-A32 | A32 | ok | ok | 168.52 | 104.29 | 1838.4 | 1450.1 | 2330.8 | 2230.2 | 3089.0 | 151.0 | 11145.0 | 97.9/169.0/171.6/165.1/160.5/102.5/102.6/107.8 | 10320 | 379 | 284 |
| c9-05-A31 | A31 | ok | ok | 169.56 | 101.25 | 1835.2 | 1449.5 | 2323.6 | 2224.4 | 3162.0 | 147.0 | 11171.0 | 104.4/172.4/170.8/165.6/160.0/103.8/96.3/103.9 | 10320 | 379 | 284 |
| c9-06-B | B | ok | ok | 168.63 | 102.42 | 1840.1 | 1457.0 | 2323.9 | 2211.2 | 3089.0 | 143.5 | 11014.0 | 95.5/169.3/171.4/165.3/157.8/96.3/106.2/105.1 | 10320 | 379 | 283 |
| c9-07-B | B | ok | ok | 168.55 | 101.50 | 1834.0 | 1449.5 | 2320.6 | 2216.0 | 3063.0 | 138.5 | 11063.0 | 95.9/169.2/171.4/165.2/160.8/99.3/100.7/104.5 | 10320 | 379 | 284 |
| c9-08-A31 | A31 | ok | ok | 169.61 | 104.04 | 1849.5 | 1474.9 | 2319.2 | 2207.8 | 3030.0 | 136.5 | 11105.0 | 105.3/173.1/171.2/164.6/159.5/102.5/101.0/108.8 | 10320 | 379 | 283 |

#### Pair ratios (arm / baseline for D_win, D_real, P, R4, R32, R128; baseline / arm for F, T0, T1; phase as the plan declares it)

| Arm | Pair | Phase | D_win | D_real | P | R4 | R32 | R128 | F | T0 | T1 | tier decode (tiny/1k/4k/32k/128k/nat4k/samp4k/agent) |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| A32 (c9-01-A32) | c9-02-B (arm then baseline) | confirm | 1.006 | 1.033 | 0.997 | 0.994 | 1.000 | 0.997 | 0.978 | 1.133 | 0.993 | 1.040/1.007/1.007/1.005/0.999/1.032/1.001/1.065 |
| A32 (c9-04-A32) | c9-03-B (baseline then arm) | confirm | 1.000 | 1.018 | 0.994 | 0.984 | 1.004 | 1.008 | 1.026 | 0.934 | 0.993 | 1.039/0.999/1.001/1.002/1.003/1.048/1.031/0.977 |
| A31 (c9-05-A31) | c9-06-B (arm then baseline) | confirm | 1.006 | 0.989 | 0.997 | 0.995 | 1.000 | 1.006 | 0.977 | 0.976 | 0.986 | 1.092/1.018/0.997/1.002/1.014/1.077/0.907/0.989 |
| A31 (c9-08-A31) | c9-07-B (baseline then arm) | confirm | 1.006 | 1.025 | 1.008 | 1.017 | 0.999 | 0.996 | 1.011 | 1.015 | 0.996 | 1.098/1.023/0.999/0.997/0.992/1.032/1.002/1.041 |

#### Proof per arm (argv adaptive flags, the tier line, refusals, environ; any self-decision line)

- c9-01-A32 (A32): status ok, proof ok; tier line yes; adaptive flags in the argv {'--adapt-decay': ['0.5']}; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- c9-02-B (B): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- c9-03-B (B): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- c9-04-A32 (A32): status ok, proof ok; tier line yes; adaptive flags in the argv {'--adapt-decay': ['0.5']}; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- c9-05-A31 (A31): status ok, proof ok; tier line yes; adaptive flags in the argv {'--adapt-every': ['2']}; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- c9-06-B (B): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- c9-07-B (B): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- c9-08-A31 (A31): status ok, proof ok; tier line yes; adaptive flags in the argv {'--adapt-every': ['2']}; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']

#### Decode expert cache hit rate per tier (%, VRAM hits over lookups, pooled over the tier's requests; the engine's per-request line; counting tiers: run 2)

| Arm | Switch | agent:1 | agent:2 | agent | samp4k:4242 | samp4k:4243 | samp4k:4244 | samp4k | nat4k | tiny | cnt1k | cnt4k | cnt32k | cnt128k | PCIe % agent / samp4k | drain lines (n, ms) | last pcie_frac |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c9-01-A32 | A32 | 95.3 | 96.9 | 96.1 | 94.2 | 97.5 | 97.4 | 96.4 | 91.7 | 89.6 | 96.4 | 98.7 | 99.1 | 99.1 | 0.11 / 0.09 | 0, 0 | 0.20 |
| c9-02-B | B | 96.1 | 96.1 | 96.1 | 94.6 | 97.7 | 98.1 | 96.8 | 92.1 | 89.8 | 96.5 | 98.8 | 99.2 | 99.3 | 0.13 / 0.06 | 0, 0 | 0.20 |
| c9-03-B | B | 95.9 | 95.7 | 95.8 | 95.4 | 97.8 | 97.9 | 97.0 | 91.7 | 89.8 | 96.7 | 99.0 | 99.2 | 99.2 | 0.15 / 0.06 | 0, 0 | 0.20 |
| c9-04-A32 | A32 | 94.7 | 96.3 | 95.5 | 95.4 | 97.6 | 97.9 | 97.0 | 91.1 | 89.6 | 96.1 | 98.8 | 99.0 | 99.1 | 0.16 / 0.06 | 0, 0 | 0.20 |
| c9-05-A31 | A31 | 95.0 | 96.9 | 96.0 | 94.4 | 98.3 | 97.9 | 96.9 | 94.0 | 92.6 | 97.7 | 98.7 | 98.9 | 98.9 | 0.12 / 0.08 | 0, 0 | 0.20 |
| c9-06-B | B | 95.6 | 95.5 | 95.5 | 95.2 | 96.6 | 98.0 | 96.6 | 92.3 | 89.8 | 96.6 | 99.0 | 99.2 | 99.2 | 0.14 / 0.10 | 0, 0 | 0.20 |
| c9-07-B | B | 94.6 | 96.9 | 95.6 | 95.2 | 97.5 | 97.6 | 96.8 | 91.9 | 89.8 | 96.5 | 98.9 | 99.2 | 99.2 | 0.13 / 0.07 | 0, 0 | 0.20 |
| c9-08-A31 | A31 | 95.1 | 95.8 | 95.3 | 95.4 | 98.1 | 97.4 | 97.0 | 94.1 | 92.6 | 97.8 | 98.7 | 98.9 | 98.9 | 0.14 / 0.06 | 0, 0 | 0.20 |

#### Baseline arms (noise reference: each baseline / the first baseline of its suite)

| Baseline | suite | D_win | D_real | P | R4 | R32 | R128 | F | T0 | T1 |
|---|---|---|---|---|---|---|---|---|---|---|
| c9-02-B | C | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 |
| c9-03-B | C | 0.996 | 1.027 | 1.005 | 1.015 | 0.995 | 0.997 | 0.967 | 1.209 | 1.011 |
| c9-06-B | C | 0.998 | 1.027 | 1.000 | 1.004 | 0.996 | 0.996 | 0.992 | 1.188 | 1.016 |
| c9-07-B | C | 0.997 | 1.017 | 0.997 | 0.999 | 0.995 | 0.998 | 1.001 | 1.231 | 1.011 |

#### Every run, compact (engine lines; decode tok/s per run)

| Arm | tiny prompt ms x6 | tiny decode x6 | cnt1k dec r1/r2 | cnt4k dec r1/r2 | cnt32k dec r1/r2 | cnt128k dec r1/r2 | cnt4k read r1/r2 | cnt32k read r1/r2 | cnt128k read r1/r2 | nat4k dec r1/r2 | samp4k dec 4242/4243/4244 | agent dec t1/t2 | agent prompt ms t1/t2 (reused) | drafts acc/offered samp4k; agent |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c9-01-A32 | 196 139 108 162 165 119 | 73 99 101 112 119 117 | 131.8/171.6 | 172.5/172.9 | 166.8/166.0 | 160.5/160.8 | 1455/1443 | 2351/2333 | 2224/2212 | 92.2/114.2 | 99.8/103.4/106.9 | 106.8/100.9 | 11267/3134 (18763) | 379/561; 434/709 |
| c9-02-B | 208 168 173 139 185 157 | 74 96 99 107 121 96 | 130.7/170.3 | 170.9/171.5 | 165.3/165.2 | 156.8/160.9 | 1452/1452 | 2339/2333 | 2222/2220 | 89.2/110.9 | 99.9/105.8/103.9 | 99.1/95.9 | 11187/3065 (18763) | 384/577; 324/590 |
| c9-03-B | 215 155 142 105 129 140 | 74 95 97 93 122 96 | 129.9/169.2 | 170.9/171.5 | 164.9/164.8 | 160.4/160.1 | 1477/1473 | 2331/2322 | 2221/2212 | 90.7/106.1 | 94.6/98.0/107.0 | 109.8/111.2 | 11065/3169 (18763) | 355/544; 387/597 |
| c9-04-A32 | 153 167 168 149 140 119 | 73 97 96 113 120 106 | 130.6/168.9 | 171.2/171.6 | 165.6/165.0 | 157.1/160.5 | 1451/1450 | 2322/2331 | 2241/2230 | 90.9/117.6 | 98.4/100.2/110.2 | 101.6/114.9 | 11145/3089 (18763) | 384/589; 462/723 |
| c9-05-A31 | 187 180 140 129 154 103 | 83 100 98 115 129 116 | 148.6/172.4 | 171.5/170.8 | 164.7/165.6 | 160.1/160.0 | 1448/1450 | 2339/2324 | 2232/2224 | 95.3/113.9 | 96.2/92.6/100.5 | 105.6/102.2 | 11171/3162 (18763) | 348/588; 436/710 |
| c9-06-B | 227 150 140 126 147 103 | 75 97 98 100 117 98 | 129.6/169.3 | 171.7/171.4 | 165.2/165.2 | 157.7/157.8 | 1455/1457 | 2334/2324 | 2217/2211 | 90.0/103.6 | 100.4/106.2/112.6 | 109.0/101.5 | 11014/3089 (18763) | 399/563; 312/503 |
| c9-07-B | 182 154 137 133 140 93 | 73 95 98 106 121 97 | 129.6/169.2 | 170.6/171.4 | 162.9/165.1 | 160.3/160.8 | 1451/1450 | 2331/2321 | 2220/2216 | 95.3/103.7 | 96.2/98.4/108.5 | 106.6/101.6 | 11063/3063 (18763) | 371/568; 348/575 |
| c9-08-A31 | 187 170 101 143 130 106 | 81 102 101 118 130 116 | 149.1/173.1 | 170.8/171.2 | 164.4/164.6 | 157.3/159.5 | 1474/1475 | 2333/2319 | 2212/2208 | 98.0/107.3 | 101.6/99.1/102.3 | 110.2/106.6 | 11105/3030 (18763) | 374/590; 374/580 |


#### Confirmation gates, A31 and A32 (decision 8: the two L11 screen pairs and the two c9 pairs; `scripts5/confirm5.py` `01e725ba...`)

##### A31 (primary D_real)

| Phase | Batch | Pair | proof | D_win | D_real | P | R4 | R32 | R128 | F | T0 | T1 | greedy decode (tiny/1k/4k/32k/128k/nat4k) | samp4k/agent decode |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| screen | r7-pa-L11 | L11-04-A31 vs L11-03-B | ok | 1.009 | 1.009 | 1.000 | 1.002 | 0.999 | - | 1.016 | 0.885 | 1.021 | 1.071/1.024/1.009/0.994/-/1.010 | 0.993/1.025 |
| screen | r7-pa-L11 | L11-04-A31 vs L11-05-B | ok | 1.010 | 1.030 | 0.993 | 0.984 | 1.002 | - | 1.005 | 0.898 | 1.022 | 1.081/1.028/1.001/1.001/-/1.037 | 1.013/1.039 |
| confirm | r7-pa-c9 | c9-05-A31 vs c9-06-B | ok | 1.006 | 0.989 | 0.997 | 0.995 | 1.000 | 1.006 | 0.977 | 0.976 | 0.986 | 1.092/1.018/0.997/1.002/1.014/1.077 | 0.907/0.989 |
| confirm | r7-pa-c9 | c9-08-A31 vs c9-07-B | ok | 1.006 | 1.025 | 1.008 | 1.017 | 0.999 | 0.996 | 1.011 | 1.015 | 0.996 | 1.098/1.023/0.999/0.997/0.992/1.032 | 1.002/1.041 |

| Metric | pair ratios (screen, screen, confirm, confirm) | median | bootstrap 95% (20,000, seed 20261026) |
|---|---|---|---|
| D_real (primary) | 1.009, 1.030, 0.989, 1.025 | 1.0172 | 0.9886 to 1.0298 |
| D_win | 1.009, 1.010, 1.006, 1.006 | 1.0075 | 1.0056 to 1.0096 |

| Tier | kind | pair ratios | median | >= 0.98 |
|---|---|---|---|---|
| tiny decode | greedy (gated) | 1.071, 1.081, 1.092, 1.098 | 1.0867 | yes |
| cnt1k decode | greedy (gated) | 1.024, 1.028, 1.018, 1.023 | 1.0233 | yes |
| cnt4k decode | greedy (gated) | 1.009, 1.001, 0.997, 0.999 | 1.0000 | yes |
| cnt32k decode | greedy (gated) | 0.994, 1.001, 1.002, 0.997 | 0.9987 | yes |
| cnt128k decode | greedy (gated) | 1.014, 0.992 | 1.0028 | yes |
| nat4k decode | greedy (gated) | 1.010, 1.037, 1.077, 1.032 | 1.0347 | yes |
| samp4k decode | sampled (reported) | 0.993, 1.013, 0.907, 1.002 | 0.9980 | yes |
| agent decode | sampled (reported) | 1.025, 1.039, 0.989, 1.041 | 1.0321 | yes |

VERDICT A31: not confirmed (median 1.0172 < 1.02; interval reaches 0.9886)

##### A32 (primary D_real)

| Phase | Batch | Pair | proof | D_win | D_real | P | R4 | R32 | R128 | F | T0 | T1 | greedy decode (tiny/1k/4k/32k/128k/nat4k) | samp4k/agent decode |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| screen | r7-pa-L11 | L11-06-A32 vs L11-05-B | ok | 1.003 | 1.031 | 0.994 | 0.986 | 1.002 | - | 0.991 | 0.951 | 1.007 | 1.029/0.999/1.002/1.009/-/0.997 | 1.007/1.092 |
| screen | r7-pa-L11 | L11-06-A32 vs L11-07-B | ok | 0.999 | 1.018 | 0.991 | 0.987 | 0.995 | - | 0.995 | 0.928 | 0.999 | 1.025/0.994/1.002/1.001/-/0.975 | 0.996/1.087 |
| confirm | r7-pa-c9 | c9-01-A32 vs c9-02-B | ok | 1.006 | 1.033 | 0.997 | 0.994 | 1.000 | 0.997 | 0.978 | 1.133 | 0.993 | 1.040/1.007/1.007/1.005/0.999/1.032 | 1.001/1.065 |
| confirm | r7-pa-c9 | c9-04-A32 vs c9-03-B | ok | 1.000 | 1.018 | 0.994 | 0.984 | 1.004 | 1.008 | 1.026 | 0.934 | 0.993 | 1.039/0.999/1.001/1.002/1.003/1.048 | 1.031/0.977 |

| Metric | pair ratios (screen, screen, confirm, confirm) | median | bootstrap 95% (20,000, seed 20261026) |
|---|---|---|---|
| D_real (primary) | 1.031, 1.018, 1.033, 1.018 | 1.0246 | 1.0182 to 1.0325 |
| D_win | 1.003, 0.999, 1.006, 1.000 | 1.0019 | 0.9989 to 1.0064 |

| Tier | kind | pair ratios | median | >= 0.98 |
|---|---|---|---|---|
| tiny decode | greedy (gated) | 1.029, 1.025, 1.040, 1.039 | 1.0343 | yes |
| cnt1k decode | greedy (gated) | 0.999, 0.994, 1.007, 0.999 | 0.9990 | yes |
| cnt4k decode | greedy (gated) | 1.002, 1.002, 1.007, 1.001 | 1.0020 | yes |
| cnt32k decode | greedy (gated) | 1.009, 1.001, 1.005, 1.002 | 1.0032 | yes |
| cnt128k decode | greedy (gated) | 0.999, 1.003 | 1.0009 | yes |
| nat4k decode | greedy (gated) | 0.997, 0.975, 1.032, 1.048 | 1.0143 | yes |
| samp4k decode | sampled (reported) | 1.007, 0.996, 1.001, 1.031 | 1.0041 | yes |
| agent decode | sampled (reported) | 1.092, 1.087, 1.065, 0.977 | 1.0764 | yes |

VERDICT A32: CONFIRMED


#### Output checks, r7-pa-c9-check (adaptive lane, decision 9; `scripts/check_analyse.py` with the production tokenizer)

| Arm | Members | Class | Proof | pcie_frac | tiny:0 | tiny:1 | tiny:2 | tiny:3 | tiny:4 | tiny:5 | id1k | id32k | agent:1 | agent:2 | id128k | needles found (arm/B1) | answers equal | Verdict |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c9c-01-B | (reference) | lane baseline | ok | 0.32 | - | - | - | - | - | - | - | - | - | - | - | 9 of 9 | - | reference |
| c9c-02-A32 | A32 | rounding | ok | 0.32 | same | tok 16 / char 102 | same | same | tok 4 / char 15 | same | tok 23 / char 164 | same | tok 35 / char 165 | tok 0 / char 0 | tok 0 / char 1 | 9/9 | yes | PASS (needles right wherever B1 is right) |
| c9c-03-A31 | A31 | rounding | ok | 0.32 | tok 17 / char 67 | tok 16 / char 102 | tok 29 / char 113 | same | same | tok 0 / char 1 | tok 51 / char 321 | tok 72 / char 280 | tok 28 / char 136 | tok 10 / char 46 | tok 0 / char 1 | 9/9 | yes | PASS (needles right wherever B1 is right) |
| c9c-04-B | B | control | ok | 0.32 | same | same | same | same | same | same | same | same | tok 277 / char 1189 | tok 3 / char 15 | tok 0 / char 1 | 9/9 | yes | control: DIFFERS from B1 |

Cells: `same` = byte-identical generated stream with equal prompt/reused/read counts; `tok N / char M` = the first divergent token index (re-tokenized, 0-based) and character index against c9c-01-B.

#### Needles per (length, depth): found in the arm / in c9c-01-B, answers byte-equal

| Arm | 8k @10% | 8k @50% | 8k @90% | 16k @10% | 16k @50% | 16k @90% | 28k @10% | 28k @50% | 28k @90% |
|---|---|---|---|---|---|---|---|---|---|
| c9c-02-A32 | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |
| c9c-03-A31 | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |
| c9c-04-B | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |

#### Generated tokens per prompt (engine count, arm / c9c-01-B)

| Arm | tiny:0 | tiny:1 | tiny:2 | tiny:3 | tiny:4 | tiny:5 | id1k | id32k | agent:1 | agent:2 | id128k |
|---|---|---|---|---|---|---|---|---|---|---|---|
| c9c-02-A32 | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 83/69 | 256/256 | 384/384 | 384/291 | 143/132 |
| c9c-03-A31 | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 75/69 | 248/256 | 384/384 | 243/291 | 146/132 |
| c9c-04-B | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 69/69 | 256/256 | 372/384 | 323/291 | 146/132 |

#### c9 reading (computed)

- **A32 (`--adapt-decay 0.5`) confirms** on its primary: `D_real` 1.031 and 1.018 (L11 screen), 1.033 and 1.018 (c9):
  median **1.0246**, bootstrap 95% interval **1.0182 to 1.0325**; every greedy tier's median >= 0.98 (tiny 1.0343, cnt1k
  0.9990, cnt4k 1.0020, cnt32k 1.0032, cnt128k 1.0009, nat4k 1.0143). `D_win` stays flat (median 1.0019, 0.9989 to 1.0064).
  Its output check passes the Addendum 3 item 3 needle gate: 9 of 9 needles, answers byte-equal to B1's. It diverges from B1
  at tiny:1 (token 16), tiny:4 (4) and id1k (23), and those are attributable to A32 because B2 reproduces B1 exactly there.
  agent:1, agent:2 and id128k are not attributable, because B2 diverges there too (tokens 277, 3 and 0): the adaptive lane
  is not deterministic run to run on those prompts. Part 2b's deterministic lane cannot test A32 because `--adapt-every 0`
  makes it inert (SWITCHES-5.md consequence 3).
- **What carries A32's gain.** The gain comes from the agent turns: agent decode four-pair median 1.0764 (1.092, 1.087,
  1.065, 0.977). tiny adds 1.0343; samp4k is at 1.0041 and nat4k at 1.0143, while the window and the counting tiers stay
  flat. The hit-rate line shows no mechanism. A32's agent hit rate is 95.2 to 96.1% against 94.8 to 97.6% in part 5's 16
  baselines, samp4k 96.4 to 97.0% against 96.1 to 97.0%, and tiny 89.6% against 89.8%. The tiny gain comes with changed texts:
  A32 changes the same 2 of the 6 tiny texts in all four of its arms, and tiny drafts are accepted at 65.2% against 60.3% in
  every baseline. The agent texts differ in every process (sampled, thinking on); A32's agent draft acceptance is 65.5% and
  68.2% in L11 against 52.6 to 60.9%, and 61.2% and 63.9% in c9 against 54.9 to 64.8%. Generation length does not explain
  it either: baseline agent decode does not track it (r = 0.004 over the 32 baseline turns; 384-token turns 95.2 to 109.7
  tok/s, shorter turns 95.9 to 111.2). So the gate holds on the predeclared real-traffic metric, but the gain is carried by
  changed texts and draft acceptance, not by any cache-hit change the proxy can see. This is a reading, not a gate.
- **A31 (`--adapt-every 2`) is not confirmed**: `D_real` 1.009, 1.030, 0.989, 1.025, median 1.0172 < 1.02, interval 0.9886
  to 1.0298 (reaches below 1.0). It passes the tier rule (tiny 1.0867, cnt1k 1.0233, nat4k 1.0347, the rest 0.999 to 1.003),
  and `D_win` gains a steady 0.6 to 1.0% (median 1.0075, 1.0056 to 1.0096). It is the one arm whose mechanism shows on the
  hit-rate line. With a round every 2 tokens the tier catches up faster where the text is new: tiny 92.6 to 92.9% against
  89.8%, nat4k 94.0 to 94.5% against 91.7 to 92.6%, cnt1k 97.7 to 97.8% against 96.5 to 96.7%. On the sampled real-traffic
  requests its hit rate stays inside the baselines' range and its decode ratio is mixed (samp4k 0.907 in one c9 pair, agent
  0.989). The output check passes the needle gate (9 of 9, answers byte-equal) and is descriptive here. Not adopted under
  the gate.
- **Tier behaviour as in L11 and L12**: no arm printed a self-decision line or a drain line, and the PCIe share settled at
  0.20 in every arm.
