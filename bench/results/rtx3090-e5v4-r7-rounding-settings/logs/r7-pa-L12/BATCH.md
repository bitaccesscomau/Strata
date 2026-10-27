# r7-pa-L12

- Job exit 0, restore exit 0 (the lab wrapper stopped production, ran the job, restored production and verified it with a real completion).
- Runs in this directory: L12-01-A24, L12-02-B, L12-03-B, L12-04-A24, L12-05-B, L12-06-A33, L12-07-B, L12-08-A33, L12-09-B, L12c-01-B, L12c-02-A24, L12c-03-B.
- Every run of this batch is copied here.
- Below: the batch's section from the round's `RESULTS-5.md`, verbatim except shortened paths. Paths such as `phase-a/raw/...` and `plans/...` refer to the lab workspace and are not part of this directory.
- The output check `r7-pa-L12-check` (runs `L12c-*`) ran in this batch's lock turn after the timing plan.

### r7-pa-L12 (mixed: A24, A33)

- Window: 2026-10-26T23:04:49+00:00 to 2026-10-26T23:48:10+00:00 UTC; job exit 0, restore exit 0 (timing plan 0, check plan 0); elapsed in the timing plan 1905.8 s. Lock turn: LOCKED-START r7-pa-L12 2026-10-26T23:04:49+00:00 holder-before=idle-after-r7-pf1-d2 2026-10-26T23:04:47+00:00.
- Production before / after (sha256 of config and exe, on disk): 92c2f588c6bb7d02 strata-swift-iq3_xxs-256k.json; 26da5a7e53bf79a1 strata / 92c2f588c6bb7d02 strata-swift-iq3_xxs-256k.json; 26da5a7e53bf79a1 strata. r7suite freeze start / end: config `92c2f588c6bb7d02` / `92c2f588c6bb7d02`, exe `26da5a7e53bf79a1` / `26da5a7e53bf79a1`, frozen_ok_end True.
- Checks around the batch: PRODCHECK-PRE r7-pa-L12 rc=0; REALREQ-PRE r7-pa-L12 rc=0; BATCH-RC r7-pa-L12 rc=0 job=0 restore=0 2026-10-26T23:48:11+00:00; PRODCHECK-POST r7-pa-L12 rc=0; REALREQ-POST r7-pa-L12 rc=0; GPU-POST 250.00 W, 23744 MiB. Restore: verified 2026-10-26T23:48:10Z, model strata/swift-1.5-iq3_xxs-256K, max_context 262144, expert slots 10320, reply 'READY'.
- Pattern: A24 X B B X on suite C (its two confirmation pairs), then A33 B X B on suite S (its screen), then A33's reversed half X B if time allows (all or none); 700 s of the batch kept for r7-pa-L12-check. Reversed half: run (slowest arm 285.1 s, needed 687 s, left 1154 s). Arm statuses: ok 9.
- Harness: phase-a5 `r7suite.py` `f73417dd...`, plan `plans/r7-pa-L12.json` (sha256 in the decisions above). Raw: `phase-a/raw5/gpu/r7-pa-L12/`. Keyscan on the VM before the copy: 133 files, 0 with the key.
- Output-check plan `r7-pa-L12-check` (r7check.py `c053e9fa...`): elapsed 655.0 s, frozen_ok_end True, arms L12c-01-B ok (needles 9); L12c-02-A24 ok (needles 9); L12c-03-B ok (needles 9).

#### Per arm (engine-measured; D in tok/s, P and R in tok/s, F, T0, T1 in ms; slots = expert slots at ready)

| Arm | Switch | Status | Proof | D_win | D_real | P | R4 | R32 | R128 | F | T0 | T1 | decode tiny/1k/4k/32k/128k/nat4k/samp4k/agent | slots | free MiB | s |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| L12-01-A24 | A24 | ok | ok | 171.45 | 102.35 | 1836.9 | 1451.6 | 2324.4 | 2212.8 | 3134.0 | 139.5 | 10983.0 | 95.8/171.0/174.7/168.6/163.9/101.1/104.0/102.0 | 10320 | 379 | 285 |
| L12-02-B | B | ok | ok | 168.77 | 103.42 | 1854.9 | 1479.8 | 2324.9 | 2217.5 | 3131.0 | 141.0 | 10986.0 | 95.3/168.9/171.6/165.9/158.7/99.8/102.3/108.4 | 10320 | 379 | 285 |
| L12-03-B | B | ok | ok | 168.66 | 103.19 | 1839.7 | 1454.8 | 2326.4 | 2221.2 | 3137.0 | 137.0 | 11034.0 | 97.1/169.3/171.2/165.5/160.5/100.5/105.0/104.2 | 10320 | 379 | 282 |
| L12-04-A24 | A24 | ok | ok | 171.06 | 103.21 | 1836.2 | 1451.1 | 2323.4 | 2235.7 | 3065.0 | 150.0 | 11025.0 | 95.8/170.8/173.7/168.8/163.5/102.3/100.1/107.4 | 10320 | 379 | 282 |
| L12-05-B | B | ok | ok | 168.36 | 105.97 | 1840.8 | 1458.6 | 2323.3 | - | 3260.0 | 121.0 | 10979.0 | 96.9/169.0/170.8/165.4/-/101.6/107.7/108.7 | 10320 | 379 | 153 |
| L12-06-A33 | A33 | ok | ok | 168.40 | 103.27 | 1832.6 | 1445.8 | 2322.9 | - | 3255.0 | 125.0 | 11005.0 | 96.9/169.1/171.1/165.1/-/94.8/105.4/110.1 | 10320 | 379 | 154 |
| L12-07-B | B | ok | ok | 168.03 | 102.00 | 1851.3 | 1484.3 | 2309.0 | - | 3230.0 | 156.0 | 11138.0 | 97.0/168.4/170.8/164.9/-/97.9/104.6/103.7 | 10320 | 379 | 155 |
| L12-08-A33 | A33 | ok | ok | 168.29 | 105.41 | 1830.6 | 1446.4 | 2316.9 | - | 3206.0 | 136.0 | 10987.0 | 96.0/169.2/170.7/165.1/-/100.4/108.4/107.6 | 10320 | 379 | 153 |
| L12-09-B | B | ok | ok | 168.15 | 101.08 | 1843.7 | 1473.8 | 2306.4 | - | 3212.0 | 143.0 | 11149.0 | 96.6/169.0/171.1/164.4/-/102.0/101.4/99.8 | 10320 | 379 | 156 |

#### Pair ratios (arm / baseline for D_win, D_real, P, R4, R32, R128; baseline / arm for F, T0, T1; phase as the plan declares it)

| Arm | Pair | Phase | D_win | D_real | P | R4 | R32 | R128 | F | T0 | T1 | tier decode (tiny/1k/4k/32k/128k/nat4k/samp4k/agent) |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| A24 (L12-01-A24) | L12-02-B (arm then baseline) | confirm | 1.016 | 0.990 | 0.990 | 0.981 | 1.000 | 0.998 | 0.999 | 1.011 | 1.000 | 1.005/1.013/1.018/1.016/1.033/1.014/1.017/0.940 |
| A24 (L12-04-A24) | L12-03-B (baseline then arm) | confirm | 1.014 | 1.000 | 0.998 | 0.997 | 0.999 | 1.007 | 1.023 | 0.913 | 1.001 | 0.987/1.009/1.014/1.020/1.019/1.018/0.954/1.031 |
| A33 (L12-06-A33) | L12-05-B (baseline then arm) | screen | 1.000 | 0.975 | 0.996 | 0.991 | 1.000 | - | 1.002 | 0.968 | 0.998 | 1.000/1.001/1.002/0.998/-/0.934/0.979/1.013 |
| A33 (L12-06-A33) | L12-07-B (arm then baseline) | screen | 1.002 | 1.012 | 0.990 | 0.974 | 1.006 | - | 0.992 | 1.248 | 1.012 | 0.999/1.004/1.002/1.001/-/0.969/1.008/1.062 |
| A33 (L12-08-A33) | L12-07-B (baseline then arm) | reversed | 1.002 | 1.033 | 0.989 | 0.974 | 1.003 | - | 1.007 | 1.147 | 1.014 | 0.989/1.005/0.999/1.001/-/1.026/1.037/1.038 |
| A33 (L12-08-A33) | L12-09-B (arm then baseline) | reversed | 1.001 | 1.043 | 0.993 | 0.981 | 1.005 | - | 1.002 | 1.051 | 1.015 | 0.994/1.001/0.997/1.004/-/0.985/1.069/1.077 |

#### Screen verdicts (PLAN.md addendum 5 for A30 to A33: primary D_real; D_win must not fall below 0.98 in either screen pair)

| Arm | Primary | Screen pair ratios | Gate | Condition in the screen pairs | Reversed-half primary (descriptive) | Proof | Verdict |
|---|---|---|---|---|---|---|---|
| A33 | D_real | 0.975, 1.012 | confirm (mixed) | D_win 1.000, 1.002 (holds) | 1.033, 1.043 | ok | screen passes: confirm (confirmation pairs owed) |

#### Proof per arm (argv adaptive flags, the tier line, refusals, environ; any self-decision line)

- L12-01-A24 (A24): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_QSA_SPLIT_ATTN', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L12-02-B (B): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L12-03-B (B): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L12-04-A24 (A24): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_QSA_SPLIT_ATTN', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L12-05-B (B): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L12-06-A33 (A33): status ok, proof ok; tier line yes; adaptive flags in the argv {'--adapt-min-gain': ['1.2']}; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L12-07-B (B): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L12-08-A33 (A33): status ok, proof ok; tier line yes; adaptive flags in the argv {'--adapt-min-gain': ['1.2']}; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']
- L12-09-B (B): status ok, proof ok; tier line yes; adaptive flags in the argv none; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']

#### Decode expert cache hit rate per tier (%, VRAM hits over lookups, pooled over the tier's requests; the engine's per-request line; counting tiers: run 2)

| Arm | Switch | agent:1 | agent:2 | agent | samp4k:4242 | samp4k:4243 | samp4k:4244 | samp4k | nat4k | tiny | cnt1k | cnt4k | cnt32k | cnt128k | PCIe % agent / samp4k | drain lines (n, ms) | last pcie_frac |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| L12-01-A24 | A24 | 96.9 | 98.9 | 97.9 | 93.4 | 98.3 | 97.7 | 96.5 | 91.7 | 89.9 | 96.4 | 98.9 | 99.2 | 99.2 | 0.02 / 0.09 | 0, 0 | 0.20 |
| L12-02-B | B | 95.4 | 95.2 | 95.3 | 95.0 | 98.4 | 96.8 | 96.8 | 91.9 | 89.8 | 96.6 | 98.9 | 99.2 | 99.2 | 0.14 / 0.06 | 0, 0 | 0.20 |
| L12-03-B | B | 95.3 | 97.5 | 96.1 | 94.3 | 97.6 | 97.5 | 96.5 | 92.5 | 89.8 | 96.5 | 99.0 | 99.2 | 99.2 | 0.14 / 0.09 | 0, 0 | 0.20 |
| L12-04-A24 | A24 | 95.6 | 95.4 | 95.5 | 94.0 | 98.6 | 97.5 | 96.7 | 92.5 | 89.9 | 96.4 | 99.0 | 99.2 | 99.2 | 0.17 / 0.07 | 0, 0 | 0.20 |
| L12-05-B | B | 94.4 | 96.6 | 95.2 | 92.7 | 97.8 | 97.7 | 96.1 | 92.3 | 89.8 | 96.6 | 99.0 | 99.2 | - | 0.16 / 0.09 | 0, 0 | 0.20 |
| L12-06-A33 | A33 | 93.9 | 96.6 | 95.2 | 93.4 | 98.4 | 97.2 | 96.3 | 92.4 | 89.8 | 96.7 | 98.9 | 99.2 | - | 0.18 / 0.10 | 0, 0 | 0.20 |
| L12-07-B | B | 95.3 | 94.4 | 94.8 | 94.5 | 98.3 | 97.5 | 96.8 | 92.0 | 89.8 | 96.6 | 99.0 | 99.2 | - | 0.21 / 0.06 | 0, 0 | 0.20 |
| L12-08-A33 | A33 | 93.9 | 95.5 | 94.6 | 94.3 | 97.1 | 97.7 | 96.4 | 92.1 | 89.8 | 96.6 | 98.9 | 99.2 | - | 0.19 / 0.10 | 0, 0 | 0.20 |
| L12-09-B | B | 97.3 | 97.9 | 97.6 | 94.7 | 97.6 | 97.7 | 96.6 | 92.0 | 89.8 | 96.5 | 98.9 | 99.2 | - | 0.03 / 0.08 | 0, 0 | 0.20 |

#### Baseline arms (noise reference: each baseline / the first baseline of its suite)

| Baseline | suite | D_win | D_real | P | R4 | R32 | R128 | F | T0 | T1 |
|---|---|---|---|---|---|---|---|---|---|---|
| L12-02-B | C | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 |
| L12-03-B | C | 0.999 | 0.998 | 0.992 | 0.983 | 1.001 | 1.002 | 0.998 | 1.029 | 0.996 |
| L12-05-B | S | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | - | 1.000 | 1.000 | 1.000 |
| L12-07-B | S | 0.998 | 0.963 | 1.006 | 1.018 | 0.994 | - | 1.009 | 0.776 | 0.986 |
| L12-09-B | S | 0.999 | 0.954 | 1.002 | 1.010 | 0.993 | - | 1.015 | 0.846 | 0.985 |

#### Every run, compact (engine lines; decode tok/s per run)

| Arm | tiny prompt ms x6 | tiny decode x6 | cnt1k dec r1/r2 | cnt4k dec r1/r2 | cnt32k dec r1/r2 | cnt128k dec r1/r2 | cnt4k read r1/r2 | cnt32k read r1/r2 | cnt128k read r1/r2 | nat4k dec r1/r2 | samp4k dec 4242/4243/4244 | agent dec t1/t2 | agent prompt ms t1/t2 (reused) | drafts acc/offered samp4k; agent |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| L12-01-A24 | 218 168 138 132 141 107 | 74 98 98 106 108 103 | 131.4/171.0 | 174.2/174.7 | 169.5/168.6 | 160.9/163.9 | 1448/1452 | 2346/2324 | 2220/2213 | 90.1/115.3 | 104.3/104.7/102.9 | 108.2/96.4 | 10983/3134 (18763) | 380/557; 400/707 |
| L12-02-B | 165 165 113 132 150 89 | 73 96 98 104 120 95 | 130.6/168.8 | 171.0/171.6 | 166.3/165.9 | 158.6/158.7 | 1479/1480 | 2335/2325 | 2224/2218 | 88.4/114.5 | 98.0/99.7/109.8 | 109.0/107.9 | 10986/3131 (18763) | 381/579; 455/701 |
| L12-03-B | 204 136 138 108 160 109 | 75 98 100 106 120 97 | 131.6/169.3 | 170.9/171.3 | 165.2/165.5 | 161.2/160.5 | 1448/1455 | 2332/2326 | 2232/2221 | 91.0/112.1 | 97.9/108.7/109.2 | 105.7/101.1 | 11034/3137 (18763) | 397/594; 328/537 |
| L12-04-A24 | 170 148 135 152 155 116 | 74 98 98 105 106 102 | 131.0/170.8 | 172.4/173.7 | 168.3/168.8 | 161.5/163.5 | 1451/1451 | 2335/2323 | 2241/2236 | 93.2/113.3 | 99.7/99.8/100.9 | 105.9/110.0 | 11025/3065 (18763) | 352/532; 358/579 |
| L12-05-B | 207 134 106 108 157 107 | 75 97 100 105 121 96 | 131.3/169.0 | 171.0/170.8 | 163.1/165.3 | - | 1452/1459 | 2341/2323 | - | 91.9/113.5 | 115.8/103.4/104.8 | 109.6/107.3 | 10979/3260 (18763) | 407/569; 365/569 |
| L12-06-A33 | 203 135 115 116 125 125 | 75 97 100 106 120 98 | 130.7/169.0 | 170.7/171.2 | 165.7/165.1 | - | 1447/1446 | 2328/2323 | - | 86.8/104.5 | 98.6/102.6/116.7 | 105.8/115.7 | 11005/3255 (18763) | 394/571; 436/668 |
| L12-07-B | 201 158 115 208 154 122 | 75 98 99 107 120 97 | 131.0/168.4 | 169.9/170.8 | 165.2/165.0 | - | 1485/1484 | 2312/2309 | - | 92.2/104.3 | 101.2/101.7/111.5 | 106.6/101.3 | 11138/3230 (18763) | 387/559; 424/699 |
| L12-08-A33 | 180 136 102 136 160 90 | 74 96 98 106 118 97 | 130.2/169.2 | 170.8/170.7 | 165.3/165.1 | - | 1449/1446 | 2329/2317 | - | 88.9/115.4 | 105.1/111.2/109.1 | 106.1/109.5 | 10987/3206 (18763) | 416/592; 392/610 |
| L12-09-B | 202 157 127 158 129 117 | 73 97 99 106 121 98 | 131.1/169.0 | 170.7/171.1 | 163.2/164.4 | - | 1473/1474 | 2326/2306 | - | 92.0/114.5 | 97.2/113.8/95.1 | 105.0/95.2 | 11149/3212 (18763) | 373/560; 396/696 |


#### A24 confirmation gate (RESULTS-5.md decision 8: four pairs, the two L9 screen pairs and these two; `scripts5/confirm5.py`)

| Phase | Batch | Pair | proof | D_win | D_real | P | R4 | R32 | R128 | F | T0 | T1 | greedy decode (tiny/1k/4k/32k/128k/nat4k) | samp4k/agent decode |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| screen | r7-pa-L9 | L9-04-A24 vs L9-03-B | ok | 1.016 | 1.063 | 0.996 | 0.995 | 0.998 | - | 0.999 | 0.994 | 1.008 | 0.981/1.014/1.013/1.022/-/1.053 | 1.012/1.127 |
| screen | r7-pa-L9 | L9-04-A24 vs L9-05-B | ok | 1.020 | 1.041 | 0.998 | 0.997 | 0.998 | - | 1.012 | 0.935 | 1.011 | 0.969/1.019/1.019/1.022/-/1.021 | 1.045/1.056 |
| confirm | r7-pa-L12 | L12-01-A24 vs L12-02-B | ok | 1.016 | 0.990 | 0.990 | 0.981 | 1.000 | 0.998 | 0.999 | 1.011 | 1.000 | 1.005/1.013/1.018/1.016/1.033/1.014 | 1.017/0.940 |
| confirm | r7-pa-L12 | L12-04-A24 vs L12-03-B | ok | 1.014 | 1.000 | 0.998 | 0.997 | 0.999 | 1.007 | 1.023 | 0.913 | 1.001 | 0.987/1.009/1.014/1.020/1.019/1.018 | 0.954/1.031 |

| Metric | pair ratios (screen, screen, confirm, confirm) | median | bootstrap 95% (20,000, seed 20261026) |
|---|---|---|---|
| D_win (primary) | 1.016, 1.020, 1.016, 1.014 | 1.0162 | 1.0142 to 1.0201 |
| D_real | 1.063, 1.041, 0.990, 1.000 | 1.0203 | 0.9897 to 1.0631 |

| Tier | kind | pair ratios | median | >= 0.98 |
|---|---|---|---|---|
| tiny decode | greedy (gated) | 0.981, 0.969, 1.005, 0.987 | 0.9843 | yes |
| cnt1k decode | greedy (gated) | 1.014, 1.019, 1.013, 1.009 | 1.0134 | yes |
| cnt4k decode | greedy (gated) | 1.013, 1.019, 1.018, 1.014 | 1.0163 | yes |
| cnt32k decode | greedy (gated) | 1.022, 1.022, 1.016, 1.020 | 1.0211 | yes |
| cnt128k decode | greedy (gated) | 1.033, 1.019 | 1.0256 | yes |
| nat4k decode | greedy (gated) | 1.053, 1.021, 1.014, 1.018 | 1.0193 | yes |
| samp4k decode | sampled (reported) | 1.012, 1.045, 1.017, 0.954 | 1.0146 | yes |
| agent decode | sampled (reported) | 1.127, 1.056, 0.940, 1.031 | 1.0432 | yes |

VERDICT A24: not confirmed (median 1.0162 < 1.02)


#### A24 output check, r7-pa-L12-check (deterministic lane; `scripts/check_analyse.py` with the production tokenizer, byte-identical to the pack's files)

| Arm | Members | Class | Proof | pcie_frac | tiny:0 | tiny:1 | tiny:2 | tiny:3 | tiny:4 | tiny:5 | id1k | id32k | agent:1 | agent:2 | id128k | needles found (arm/B1) | answers equal | Verdict |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| L12c-01-B | (reference) | lane baseline | ok | 0.32 | - | - | - | - | - | - | - | - | - | - | - | 9 of 9 | - | reference |
| L12c-02-A24 | A24 | rounding | ok | 0.32 | tok 9 / char 39 | tok 62 / char 303 | tok 23 / char 87 | same | tok 4 / char 15 | same | tok 16 / char 113 | tok 39 / char 163 | tok 17 / char 82 | tok 0 / char 0 | tok 12 / char 69 | 9/9 | yes | PASS (needles right wherever B1 is right) |
| L12c-03-B | B | control | ok | 0.32 | same | same | same | same | same | same | same | same | same | same | tok 66 / char 280 | 9/9 | yes | control: byte-identical to B1 with equal counts on every gated prompt |

Cells: `same` = byte-identical generated stream with equal prompt/reused/read counts; `tok N / char M` = the first divergent token index (re-tokenized, 0-based) and character index against L12c-01-B.

#### Needles per (length, depth): found in the arm / in L12c-01-B, answers byte-equal

| Arm | 8k @10% | 8k @50% | 8k @90% | 16k @10% | 16k @50% | 16k @90% | 28k @10% | 28k @50% | 28k @90% |
|---|---|---|---|---|---|---|---|---|---|
| L12c-02-A24 | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |
| L12c-03-B | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |

#### Generated tokens per prompt (engine count, arm / L12c-01-B)

| Arm | tiny:0 | tiny:1 | tiny:2 | tiny:3 | tiny:4 | tiny:5 | id1k | id32k | agent:1 | agent:2 | id128k |
|---|---|---|---|---|---|---|---|---|---|---|---|
| L12c-02-A24 | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 106/68 | 243/252 | 384/316 | 384/354 | 143/125 |
| L12c-03-B | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 68/68 | 252/252 | 316/316 | 354/354 | 137/125 |

#### L12 reading (computed)

- **A24 (`STRATA_QSA_SPLIT_ATTN=1`) is not confirmed.** Its four `D_win` pairs read 1.016 and 1.020 (L9 screen) and 1.016 and
  1.014 (L12 confirmation): median **1.0162**, bootstrap 95% interval 1.0142 to 1.0201, so the median misses the predeclared
  1.02 bar while the interval lies above 1.0. Every greedy tier passes the tier rule, tiny included (medians: tiny 0.9843
  from 0.981, 0.969, 1.005, 0.987; cnt1k 1.0134; cnt4k 1.0163; cnt32k 1.0211; cnt128k 1.0256 over its two pairs, 1.033 and
  1.019; nat4k 1.0193). So the split attention is a consistent window-cost gain of 1.4 to 2.0% in all four pairs, growing
  with the context (32K about +2.1%, 128K +1.9 to 3.3%), that falls short of the round's confirmation bar; `D_real` reads
  1.063, 1.041, 0.990, 1.000 (median 1.0203, interval 0.9897 to 1.0631). Reported for the parent as a sub-threshold
  effect; not adopted under the gate.
- **A24's output check** (descriptive, as A24 did not confirm): the control B2 is byte-identical to B1 on every gated prompt
  (tiny x6, id1k, id32k and both agent turns, with equal counts) and differs only at id128k token 66, as part 2b's control
  did; A24 diverges on 4 of the 6 tiny prompts (first divergent tokens 9, 62, 23, 4), id1k (16), id32k (39), agent:1 (17),
  agent:2 (0) and id128k (12), which is its rounding (SWITCHES-3.md), and answers all 9 needles with answers byte-equal to
  B1's, so it would pass the Addendum 3 item 3 gate.
- **A33 (`--adapt-min-gain 1.2`): the screen passes on the literal mixed rule** with the weakest reading of the four:
  `D_real` 0.975 and 1.012 (geometric mean 0.9935), `D_win` 1.000 and 1.002 (condition holds), reversed half 1.033 and 1.043.
  The suite S baselines of this batch span 0.954 to 1.000 of the first in `D_real` (L12-05-B reads high), which brackets both
  screen pairs. No mechanism shows on the hit-rate line: tiny 89.8% (every baseline 89.8%), nat4k 92.4 / 92.1% (baselines
  92.0 to 92.3%), agent 95.2 / 94.6% (94.8 to 97.6%), samp4k 96.3 / 96.4% (96.1 to 96.8%), and both A33 arms reproduce the
  baselines' six tiny texts exactly: with the 2.0 candidate floor (`generate.cpp:10694`) a lower gain bar rarely admits an
  extra swap on these requests.
- **Tier behaviour**: no arm printed a self-decision line or a drain line, and the PCIe share settled at 0.20 in every arm.
