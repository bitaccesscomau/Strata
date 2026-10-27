# r7-pa-c5

- Job exit 0, restore exit 0 (the lab wrapper stopped production, ran the job, restored production and verified it with a real completion).
- Runs in this directory: c5-01-A12, c5-02-B, c5-03-B, c5-04-A12.
- Runs of this batch not copied here (exact-class settings, or baselines paired only with them): c5-05-A21 (A21), c5-06-B (B), c5-07-B (B), c5-08-A21 (A21).
- Below: the batch's section from the round's `RESULTS.md`, verbatim except shortened paths. Paths such as `phase-a/raw/...` and `plans/...` refer to the lab workspace and are not part of this directory.

### r7-pa-c5 (confirmation of A12 on suite C plus cnt256k, A21 on suite C)

- Window: 2026-10-26T18:14:04+00:00 to 2026-10-26T19:00:50+00:00 UTC; job exit 0, restore exit 0; elapsed in the job 2766.0 s.
- Production config sha256 before / after: `92c2f588c6bb7d02` / `92c2f588c6bb7d02`; exe `26da5a7e53bf79a1` / `26da5a7e53bf79a1`; PRODCHECK-POST rc=0; PRODCHECK-PRE rc=0; REALREQ-POST rc=0; REALREQ-PRE rc=0; GPU-POST 250.00 W; restore: restored True, max_context 262144.
- Pattern: per candidate X B B X (ON OFF OFF ON) on suite C (A12: plus cnt256k); A22: B X B on suite S (its screen) then X B B X on suite C, as one group. Groups: A12 run (need 1877 s, left 3450 s); A21 run (need 1183 s, left 1820 s).
- Arms: 8 run, 0 skipped (-), 0 failed (-); proof not ok: none.
- Every arm: engine `/proc/<pid>/exe` and sha256 = deployed, `STRATA_*` environ = production env + the arm's switch, config args block intact; proof ok in all eight (A12: `strata KV prefetch: N layer prefixes, single existing staging pool` after every prompt read; A21: `strata generate: 15 pool workers on logical processors ...` once per arm, never `30 pool workers`; neither line in any baseline).
- The first cnt256k runs of this harness: 255,547 prompt tokens per run (the 0.98 x 262,144 target clamped to 97.5% of the context), 1 run per arm as PLAN.md says; a suite C plus cnt256k arm took 398 to 417 s, a suite C arm 283 to 284 s.
- The batch waited for the lock from 17:41 to 18:14 UTC behind another worker's `r7-pa-L6` (workspace `phase-a3/`); that wait is outside the job's budget. After c5 released the lock, the same worker's `r7-pa-L9` took it (19:00:51 UTC) and c6 was queued behind it.
- Harness: `r7suite3.py` `1a609a2b...`, plan `plans/r7-pa-c5.json` `8c63607e...` (dry run 65 checks, `DRYRUN3 OK`). Keyscan before the copy: 117 files, 0 with the key.
- Raw: `phase-a/raw/gpu/r7-pa-c5/` (arm.json, provenance.json, engine.log, server.log, bench JSON per arm).

#### Per arm (engine-measured; D in tok/s, P and R in tok/s, F, T0, T1 in ms)

| Arm | Switch | Status | Proof | D_win | D_real | D_SA | P | R4 | R32 | R128 | R256 | F | T0 | T1 | decode tiers (tiny/1k/4k/32k/128k/256k/nat4k) | free MiB | Cached GiB | s |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c5-01-A12 | A12 | ok | ok | 168.86 | 107.95 | 111.46 | 1879.5 | 1470.0 | 2403.1 | 2337.5 | 2230.7 | 2897.0 | 134.0 | 10711.0 | 97.1/170.4/171.6/164.6/161.2/153.8/101.3 | 379 | 79.9 | 398 |
| c5-02-B | B | ok | ok | 167.78 | 103.64 | 106.46 | 1833.8 | 1447.4 | 2323.4 | 2206.8 | 2100.1 | 3016.0 | 128.0 | 11053.0 | 96.6/168.8/170.4/164.2/157.9/156.5/98.2 | 379 | 79.9 | 415 |
| c5-03-B | B | ok | ok | 167.43 | 101.53 | 103.74 | 1840.0 | 1449.5 | 2335.6 | 2215.1 | 2076.9 | 2918.0 | 142.5 | 11032.0 | 97.0/169.2/170.9/162.3/159.7/154.4/97.2 | 379 | 79.9 | 417 |
| c5-04-A12 | A12 | ok | ok | 168.22 | 101.86 | 103.24 | 1870.2 | 1453.2 | 2406.7 | 2339.1 | 2231.9 | 2886.0 | 147.5 | 10740.0 | 96.0/168.8/171.4/164.6/160.5/153.8/99.2 | 379 | 79.9 | 400 |
| c5-05-A21 | A21 | ok | ok | 167.89 | 103.37 | 103.27 | 1837.8 | 1449.5 | 2330.2 | 2217.7 | - | 3059.0 | 114.0 | 10998.0 | 99.9/169.0/170.4/164.3/160.4/-/103.6 | 379 | 79.9 | 283 |
| c5-06-B | B | ok | ok | 168.04 | 103.27 | 104.56 | 1831.4 | 1446.9 | 2318.1 | 2218.7 | - | 3077.0 | 134.5 | 10940.0 | 96.7/169.2/170.8/164.2/160.9/-/100.7 | 379 | 79.9 | 284 |
| c5-07-B | B | ok | ok | 167.93 | 103.29 | 105.19 | 1838.4 | 1449.0 | 2332.4 | 2212.7 | - | 3124.0 | 148.5 | 10908.0 | 95.6/169.2/170.8/163.9/160.3/-/99.6 | 379 | 79.9 | 284 |
| c5-08-A21 | A21 | ok | ok | 168.70 | 104.19 | 105.36 | 1836.6 | 1446.9 | 2331.3 | 2218.7 | - | 3125.0 | 117.5 | 11006.0 | 100.4/169.8/171.2/165.2/160.3/-/101.9 | 379 | 79.9 | 284 |

#### Pair ratios (the two confirmation pairs per candidate; arm / baseline for D_win, D_real, D_SA, P, R4, R32, R128, R256; baseline / arm for F, T0, T1)

| Arm | Pair | Phase | D_win | D_real | D_SA | P | R4 | R32 | R128 | R256 | F | T0 | T1 | tier dec (tiny/1k/4k/32k/128k/256k/nat4k/samp4k/agent) | tier read (4k/32k/128k/256k) |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| A12 (c5-01-A12) | c5-02-B (arm then baseline) | confirm | 1.006 | 1.042 | 1.047 | 1.025 | 1.016 | 1.034 | 1.059 | 1.062 | 1.041 | 0.955 | 1.032 | 1.005/1.010/1.007/1.003/1.021/0.983/1.031/1.041/1.053 | 1.016/1.034/1.059/1.062 |
| A12 (c5-04-A12) | c5-03-B (baseline then arm) | confirm | 1.005 | 1.003 | 0.995 | 1.016 | 1.003 | 1.030 | 1.056 | 1.075 | 1.011 | 0.966 | 1.027 | 0.989/0.997/1.003/1.014/1.005/0.996/1.020/0.965/1.026 | 1.003/1.030/1.056/1.075 |
| A21 (c5-05-A21) | c5-06-B (arm then baseline) | confirm | 0.999 | 1.001 | 0.988 | 1.004 | 1.002 | 1.005 | 1.000 | - | 1.006 | 1.180 | 0.995 | 1.033/0.999/0.998/1.001/0.997/-/1.028/0.966/1.010 | 1.002/1.005/1.000/- |
| A21 (c5-08-A21) | c5-07-B (baseline then arm) | confirm | 1.005 | 1.009 | 1.002 | 0.999 | 0.999 | 1.000 | 1.003 | - | 1.000 | 1.264 | 0.991 | 1.050/1.003/1.003/1.008/1.000/-/1.023/1.033/0.971 | 0.999/1.000/1.003/- |

#### Baseline arms (noise reference: each baseline / the first baseline)

| Baseline | D_win | D_real | D_SA | P | R4 | R32 | R128 | R256 | F | T0 | T1 |
|---|---|---|---|---|---|---|---|---|---|---|---|
| c5-02-B | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 |
| c5-03-B | 0.998 | 0.980 | 0.974 | 1.003 | 1.001 | 1.005 | 1.004 | 0.989 | 1.034 | 0.898 | 1.002 |
| c5-06-B | 1.002 | 0.996 | 0.982 | 0.999 | 1.000 | 0.998 | 1.005 | - | 0.980 | 0.952 | 1.010 |
| c5-07-B | 1.001 | 0.997 | 0.988 | 1.002 | 1.001 | 1.004 | 1.003 | - | 0.965 | 0.862 | 1.013 |

#### Every run, compact (engine lines; decode tok/s per run)

| Arm | tiny prompt ms x6 | tiny decode x6 | cnt1k dec r1/r2 | cnt4k dec r1/r2 | cnt32k dec r1/r2 | cnt128k dec r1/r2 | cnt256k dec | cnt4k read r1/r2 | cnt32k read r1/r2 | cnt128k read r1/r2 | cnt256k read | nat4k dec r1/r2 | samp4k dec 4242/4243/4244 | agent dec t1/t2 | agent prompt ms t1/t2 (reused) | drafts acc/offered samp4k; agent |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c5-01-A12 | 202 152 108 143 125 114 | 74 97 100 106 123 98 | 131.1/170.4 | 172.4/171.5 | 164.7/164.6 | 159.6/161.2 | 153.8 | 1462/1470 | 2424/2403 | 2352/2338 | 2231 | 91.1/113.9 | 101.5/114.7/117.6 | 108.4/118.0 | 10711/2897 (18763) | 424/588; 389/568 |
| c5-02-B | 181 206 114 106 142 92 | 74 96 100 106 121 97 | 131.2/168.8 | 170.2/170.4 | 163.8/164.2 | 159.5/157.9 | 156.4 | 1448/1447 | 2327/2323 | 2210/2207 | 2100 | 93.1/104.0 | 100.2/114.0/106.1 | 108.2/103.9 | 11053/3016 (18763) | 414/612; 399/616 |
| c5-03-B | 205 183 131 106 154 119 | 74 97 99 107 122 98 | 131.0/169.2 | 170.8/170.9 | 165.3/162.4 | 156.7/159.7 | 154.4 | 1450/1450 | 2330/2336 | 2221/2215 | 2077 | 93.5/101.3 | 107.2/101.7/117.6 | 101.9/96.6 | 11032/2918 (18763) | 406/550; 422/764 |
| c5-04-A12 | 155 162 143 152 140 119 | 74 96 99 107 117 96 | 132.6/168.7 | 171.0/171.4 | 165.1/164.6 | 160.1/160.5 | 153.8 | 1450/1453 | 2433/2407 | 2357/2339 | 2232 | 94.0/104.9 | 99.5/104.2/111.2 | 107.7/96.5 | 10740/2886 (18763) | 388/567; 423/700 |
| c5-05-A21 | 178 139 110 107 118 95 | 77 99 103 110 124 101 | 132.2/169.0 | 170.4/170.4 | 164.2/164.3 | 160.7/160.4 | - | 1445/1450 | 2331/2330 | 2216/2218 | - | 94.1/115.2 | 98.1/97.7/107.0 | 103.2/110.2 | 10998/3059 (18763) | 364/608; 369/613 |
| c5-06-B | 206 134 103 156 135 121 | 75 98 98 106 121 96 | 129.7/169.2 | 170.6/170.8 | 164.2/164.2 | 160.2/160.9 | - | 1447/1447 | 2334/2318 | 2226/2219 | - | 92.9/110.0 | 102.7/103.8/106.5 | 104.8/104.8 | 10940/3077 (18763) | 384/564; 422/688 |
| c5-07-B | 210 154 143 119 184 109 | 73 95 97 106 120 97 | 130.9/169.2 | 170.9/170.8 | 160.2/163.9 | 159.5/160.3 | - | 1447/1449 | 2335/2332 | 2212/2213 | - | 91.2/109.8 | 103.5/101.0/99.6 | 105.9/114.3 | 10908/3124 (18763) | 377/600; 397/606 |
| c5-08-A21 | 171 137 109 113 122 94 | 76 101 104 110 126 101 | 132.2/169.7 | 170.9/171.3 | 162.4/165.2 | 160.1/160.3 | - | 1447/1447 | 2337/2331 | 2225/2219 | - | 95.7/109.0 | 101.4/106.6/106.4 | 110.1/102.3 | 11006/3125 (18763) | 380/562; 442/737 |

#### Confirmation gate (four pairs per candidate: the two screen pairs of L5 / L8 and these two)

| Candidate | Primary | 4 pair ratios (screen, screen, confirm, confirm) | Median | Bootstrap 95% (20,000, seed 20261026) | Reported beside it | Greedy tier medians (tiny / cnt1k / cnt4k / cnt32k / cnt128k / cnt256k / nat4k) | Extra condition | Verdict |
|---|---|---|---|---|---|---|---|---|
| A12 | `R128` | 1.063, 1.061, 1.059, 1.056 | 1.0602 | 1.0560 to 1.0630 | `R256` 1.062, 1.075 (2 pairs; median 1.0684) | 1.0081 / 0.9993 / 1.0033 / 1.0013 / 1.0176 (4) / 0.9898 (2) / 0.9883 | - | **confirmed** |
| A21 | `T0` | 1.183, 1.129, 1.180, 1.264 | 1.1816 | 1.1292 to 1.2638 | - | 1.0445 / 1.0020 / 1.0054 / 1.0058 / 0.9984 (2) / - / 1.0256 | `F` in every pair >= 0.98: 1.021, 1.017, 1.006, 1.000 | **confirmed** |

#### c5 reading (computed)

- **A12 (`STRATA_KV_PREFETCH=1`) is confirmed on the cnt128k prompt read**: 2,337.5 and 2,339.1 tok/s against 2,206.8 and 2,215.1 in the adjacent baselines (1.059, 1.056; screen 1.063, 1.061), median 1.0602, interval 1.0560 to 1.0630, no greedy tier median below 0.98 (lowest nat4k 0.9883; cnt256k decode 0.9898 over its two pairs). **At 256K the read gains 6.2% and 7.5%**: the 255,547-token prompt reads in 114,559 and 114,497 ms against 121,685 and 123,043 ms (2,230.7 and 2,231.9 tok/s against 2,100.1 and 2,076.9), the switch's largest gain, as round 5 and decision 24 expected. `R32` reads 1.034 and 1.030 (the 32K prompt is just past the 32,768 resident cells) and `R4` 1.016 and 1.003; tiny, 1K and 4K decode cannot see it.
- **A21 (`--pool-workers 15`, no `--aux-cpus`) is confirmed on `T0`**: tiny first-token medians 114.0 and 117.5 ms against 134.5 and 148.5 ms in the adjacent baselines (1.180, 1.264; screen 1.183, 1.129), median 1.1816, interval 1.1292 to 1.2638, and `F` at or above 0.98 in every one of the four pairs (1.021, 1.017, 1.006, 1.000), as addendum 2 requires. Tiny decode rises too (99.9 and 100.4 against 96.7 and 95.6 tok/s; tier median 1.0445); every other tier is flat (`D_win` 0.999 and 1.005, `P` 1.004 and 0.999).
- **State after the confirmations**: confirmed A18 (part 2a), A11, A19, A22, A12, A21; not confirmed A20 (tier rule) and A10 (primary median 1.0179); prefill choice A19. The output checks (c6) cover A18, A21, A11, A19, A22 and A12, plus the provisional combined set A18 + A19 + A12 + A21 (decision 37).
