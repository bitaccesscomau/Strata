# r7-pa-c3

- Job exit 0, restore exit 0 (the lab wrapper stopped production, ran the job, restored production and verified it with a real completion).
- Runs in this directory: c3-01-A11, c3-02-B, c3-03-B, c3-04-A11, c3-05-A19, c3-06-B, c3-07-B, c3-08-A19, c3-09-A20, c3-10-B, c3-11-B, c3-12-A20.
- Every run of this batch is copied here.
- Below: the batch's section from the round's `RESULTS.md`, verbatim except shortened paths. Paths such as `phase-a/raw/...` and `plans/...` refer to the lab workspace and are not part of this directory.

### r7-pa-c3 (confirmation of A11, A19, A20 on suite C)

- Window: 2026-10-26T15:55:45+00:00 to 2026-10-26T16:52:20+00:00 UTC; job exit 0, restore exit 0; elapsed in the job 3355.1 s.
- Production config sha256 before / after: `92c2f588c6bb7d02` / `92c2f588c6bb7d02`; exe `26da5a7e53bf79a1` / `26da5a7e53bf79a1`; PRODCHECK-POST rc=0; PRODCHECK-PRE rc=0; REALREQ-POST rc=0; REALREQ-PRE rc=0; GPU-POST 250.00 W; restore: restored True, max_context 262144.
- Pattern: per candidate X B B X (ON OFF OFF ON) on suite C (A12: plus cnt256k); A22: B X B on suite S (its screen) then X B B X on suite C, as one group. Groups: A11 run (need 1183 s, left 3450 s); A19 run (need 1162 s, left 2334 s); A20 run (need 1166 s, left 1218 s).
- Arms: 12 run, 0 skipped (-), 0 failed (-); proof not ok: none.
- Every arm: engine `/proc/<pid>/exe` and sha256 = deployed, `STRATA_*` environ = production env + the arm's switch, config args block intact in the argv with extras `[exe, --serve]`; proof ok in all twelve (A11: the default share notice absent in both arms and both keys in the environ; A19, A20: no log line exists, environ only; the four production keys in every arm).
- Harness: `r7suite3.py` `1a609a2b...`, plan `plans/r7-pa-c3.json` `e3536834...`. Keyscan before the copy: 157 files, 0 with the key.
- Raw: `phase-a/raw/gpu/r7-pa-c3/` (arm.json, provenance.json, engine.log, server.log, bench JSON per arm).

#### Per arm (engine-measured; D in tok/s, P and R in tok/s, F, T0, T1 in ms)

| Arm | Switch | Status | Proof | D_win | D_real | D_SA | P | R4 | R32 | R128 | R256 | F | T0 | T1 | decode tiers (tiny/1k/4k/32k/128k/256k/nat4k) | free MiB | Cached GiB | s |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c3-01-A11 | A11 | ok | ok | 171.39 | 101.91 | 103.39 | 1854.1 | 1449.5 | 2371.5 | 2234.5 | - | 2030.0 | 154.0 | 10338.0 | 95.7/173.3/174.5/166.4/160.4/-/99.0 | 379 | 79.9 | 273 |
| c3-02-B | B | ok | ok | 168.25 | 103.28 | 103.36 | 1833.6 | 1446.4 | 2324.6 | 2205.3 | - | 3135.0 | 131.5 | 10980.0 | 96.7/169.8/170.2/164.8/159.7/-/103.1 | 379 | 79.9 | 285 |
| c3-03-B | B | ok | ok | 168.29 | 100.92 | 102.91 | 1842.1 | 1461.8 | 2321.2 | 2224.2 | - | 3148.0 | 132.5 | 11052.0 | 96.9/169.1/170.9/164.9/160.4/-/97.0 | 379 | 79.9 | 283 |
| c3-04-A11 | A11 | ok | ok | 168.26 | 101.14 | 101.54 | 1850.4 | 1477.1 | 2318.1 | 2209.5 | - | 2013.0 | 157.5 | 10250.0 | 96.5/169.3/170.9/164.6/159.8/-/100.4 | 379 | 79.9 | 276 |
| c3-05-A19 | A19 | ok | ok | 167.89 | 103.92 | 105.75 | 1914.0 | 1570.7 | 2332.4 | 2222.0 | - | 2022.0 | 127.5 | 10147.0 | 96.7/169.3/170.4/164.0/160.2/-/100.3 | 379 | 79.9 | 272 |
| c3-06-B | B | ok | ok | 167.81 | 101.90 | 104.34 | 1839.7 | 1447.4 | 2338.3 | 2212.3 | - | 3084.0 | 151.0 | 11085.0 | 96.3/168.5/170.1/164.8/160.3/-/97.2 | 379 | 79.9 | 285 |
| c3-07-B | B | ok | ok | 168.08 | 99.16 | 102.05 | 1849.9 | 1472.7 | 2323.8 | 2215.8 | - | 3132.0 | 141.0 | 11153.0 | 97.1/169.0/171.2/164.1/159.8/-/93.6 | 379 | 79.9 | 286 |
| c3-08-A19 | A19 | ok | ok | 167.56 | 102.10 | 105.09 | 1916.1 | 1585.2 | 2316.0 | 2203.9 | - | 2114.0 | 173.0 | 10315.0 | 96.7/168.9/170.2/163.7/156.3/-/96.4 | 379 | 79.9 | 273 |
| c3-09-A20 | A20 | ok | ok | 167.35 | 101.31 | 104.66 | 1936.1 | 1636.3 | 2290.9 | 2184.4 | - | 2127.0 | 158.0 | 10516.0 | 96.1/169.0/169.9/163.3/159.2/-/94.9 | 379 | 79.9 | 278 |
| c3-10-B | B | ok | ok | 166.64 | 102.12 | 103.73 | 1857.7 | 1473.8 | 2341.6 | 2216.0 | - | 3099.0 | 145.0 | 11178.0 | 92.7/168.1/170.4/161.5/159.6/-/99.0 | 379 | 79.9 | 287 |
| c3-11-B | B | ok | ok | 167.78 | 100.44 | 101.17 | 1844.2 | 1455.9 | 2336.1 | 2215.0 | - | 3135.0 | 144.0 | 11042.0 | 97.4/168.4/170.4/164.5/159.6/-/99.0 | 379 | 79.9 | 284 |
| c3-12-A20 | A20 | ok | ok | 168.26 | 101.14 | 104.06 | 1963.1 | 1652.6 | 2331.9 | 2220.9 | - | 2061.0 | 158.0 | 10192.0 | 97.0/169.3/170.8/164.7/160.2/-/95.5 | 379 | 79.9 | 273 |

#### Pair ratios (the two confirmation pairs per candidate; arm / baseline for D_win, D_real, D_SA, P, R4, R32, R128, R256; baseline / arm for F, T0, T1)

| Arm | Pair | Phase | D_win | D_real | D_SA | P | R4 | R32 | R128 | R256 | F | T0 | T1 | tier dec (tiny/1k/4k/32k/128k/256k/nat4k/samp4k/agent) | tier read (4k/32k/128k/256k) |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| A11 (c3-01-A11) | c3-02-B (arm then baseline) | confirm | 1.019 | 0.987 | 1.000 | 1.011 | 1.002 | 1.020 | 1.013 | - | 1.544 | 0.854 | 1.062 | 0.990/1.021/1.025/1.010/1.004/-/0.960/0.949/1.054 | 1.002/1.020/1.013/- |
| A11 (c3-04-A11) | c3-03-B (baseline then arm) | confirm | 1.000 | 1.002 | 0.987 | 1.005 | 1.010 | 0.999 | 0.993 | - | 1.564 | 0.841 | 1.078 | 0.996/1.001/1.000/0.998/0.996/-/1.034/0.983/0.991 | 1.010/0.999/0.993/- |
| A19 (c3-05-A19) | c3-06-B (arm then baseline) | confirm | 1.000 | 1.020 | 1.014 | 1.040 | 1.085 | 0.997 | 1.004 | - | 1.525 | 1.184 | 1.092 | 1.004/1.005/1.002/0.995/0.999/-/1.033/1.003/1.024 | 1.085/0.997/1.004/- |
| A19 (c3-08-A19) | c3-07-B (baseline then arm) | confirm | 0.997 | 1.030 | 1.030 | 1.036 | 1.076 | 0.997 | 0.995 | - | 1.482 | 0.815 | 1.081 | 0.996/0.999/0.994/0.997/0.978/-/1.030/0.987/1.074 | 1.076/0.997/0.995/- |
| A20 (c3-09-A20) | c3-10-B (arm then baseline) | confirm | 1.004 | 0.992 | 1.009 | 1.042 | 1.110 | 0.978 | 0.986 | - | 1.457 | 0.918 | 1.063 | 1.037/1.005/0.997/1.011/0.998/-/0.959/0.976/1.043 | 1.110/0.978/0.986/- |
| A20 (c3-12-A20) | c3-11-B (baseline then arm) | confirm | 1.003 | 1.007 | 1.028 | 1.064 | 1.135 | 0.998 | 1.003 | - | 1.521 | 0.911 | 1.083 | 0.997/1.005/1.002/1.001/1.004/-/0.965/1.031/1.026 | 1.135/0.998/1.003/- |

#### Baseline arms (noise reference: each baseline / the first baseline)

| Baseline | D_win | D_real | D_SA | P | R4 | R32 | R128 | R256 | F | T0 | T1 |
|---|---|---|---|---|---|---|---|---|---|---|---|
| c3-02-B | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | - | 1.000 | 1.000 | 1.000 |
| c3-03-B | 1.000 | 0.977 | 0.996 | 1.005 | 1.011 | 0.999 | 1.009 | - | 0.996 | 0.992 | 0.993 |
| c3-06-B | 0.997 | 0.987 | 1.009 | 1.003 | 1.001 | 1.006 | 1.003 | - | 1.017 | 0.871 | 0.991 |
| c3-07-B | 0.999 | 0.960 | 0.987 | 1.009 | 1.018 | 1.000 | 1.005 | - | 1.001 | 0.933 | 0.984 |
| c3-10-B | 0.990 | 0.989 | 1.004 | 1.013 | 1.019 | 1.007 | 1.005 | - | 1.012 | 0.907 | 0.982 |
| c3-11-B | 0.997 | 0.972 | 0.979 | 1.006 | 1.007 | 1.005 | 1.004 | - | 1.000 | 0.913 | 0.994 |

#### Every run, compact (engine lines; decode tok/s per run)

| Arm | tiny prompt ms x6 | tiny decode x6 | cnt1k dec r1/r2 | cnt4k dec r1/r2 | cnt32k dec r1/r2 | cnt128k dec r1/r2 | cnt256k dec | cnt4k read r1/r2 | cnt32k read r1/r2 | cnt128k read r1/r2 | cnt256k read | nat4k dec r1/r2 | samp4k dec 4242/4243/4244 | agent dec t1/t2 | agent prompt ms t1/t2 (reused) | drafts acc/offered samp4k; agent |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c3-01-A11 | 208 181 147 141 161 93 | 72 97 100 104 122 96 | 131.2/173.3 | 174.8/174.6 | 166.5/166.4 | 158.1/160.4 | - | 1452/1450 | 2379/2371 | 2248/2234 | - | 89.8/110.3 | 93.2/104.1/106.1 | 101.6/110.9 | 10338/2030 (18763) | 382/592; 447/711 |
| c3-02-B | 194 208 113 113 150 113 | 74 97 99 106 121 97 | 133.0/169.8 | 170.8/170.2 | 163.8/164.9 | 159.4/159.7 | - | 1449/1446 | 2331/2325 | 2224/2205 | - | 94.2/114.0 | 101.1/112.1/106.1 | 100.4/100.8 | 10980/3135 (18763) | 402/560; 396/677 |
| c3-03-B | 206 155 104 103 149 116 | 74 97 100 108 121 97 | 131.6/169.1 | 170.5/170.9 | 164.7/164.9 | 160.3/160.4 | - | 1458/1462 | 2330/2321 | 2232/2224 | - | 93.9/100.4 | 99.5/98.0/105.7 | 109.5/96.0 | 11052/3148 (18763) | 375/580; 325/502 |
| c3-04-A11 | 169 185 167 148 143 119 | 74 97 98 105 122 97 | 131.0/169.3 | 170.6/170.9 | 164.2/164.6 | 160.2/159.8 | - | 1471/1477 | 2322/2318 | 2214/2209 | - | 90.9/112.0 | 99.0/96.8/101.9 | 101.0/107.1 | 10250/2013 (18763) | 360/552; 442/724 |
| c3-05-A19 | 193 134 106 138 121 121 | 75 97 99 106 121 97 | 131.3/169.3 | 169.7/170.5 | 164.3/163.9 | 155.9/160.2 | - | 1554/1571 | 2343/2332 | 2232/2222 | - | 89.5/114.1 | 99.6/101.2/107.3 | 112.2/105.3 | 10147/2022 (18763) | 369/517; 418/634 |
| c3-06-B | 173 181 106 159 143 112 | 74 97 99 105 121 96 | 130.2/168.5 | 170.7/170.1 | 164.8/164.8 | 159.8/160.3 | - | 1448/1447 | 2341/2338 | 2218/2212 | - | 88.6/107.5 | 98.8/113.1/96.5 | 108.3/104.6 | 11085/3084 (18763) | 397/598; 453/698 |
| c3-07-B | 209 138 107 144 165 124 | 75 97 100 106 122 98 | 131.3/168.9 | 170.6/171.3 | 164.5/164.1 | 159.7/159.8 | - | 1477/1473 | 2340/2324 | 2227/2216 | - | 86.1/102.6 | 98.9/103.8/105.5 | 104.4/98.7 | 11153/3132 (18763) | 380/567; 430/726 |
| c3-08-A19 | 201 179 138 173 173 118 | 75 96 99 107 121 96 | 129.3/168.9 | 169.7/170.2 | 164.7/163.7 | 159.3/156.3 | - | 1571/1585 | 2332/2316 | 2223/2204 | - | 90.4/103.3 | 97.9/102.0/104.1 | 109.8/107.6 | 10315/2114 (18763) | 396/623; 363/551 |
| c3-09-A20 | 216 176 164 152 137 90 | 73 96 99 105 120 97 | 129.8/168.9 | 169.9/169.9 | 164.3/163.3 | 157.4/159.2 | - | 1616/1636 | 2297/2291 | 2193/2184 | - | 86.5/105.2 | 97.2/106.6/104.3 | 108.6/104.6 | 10516/2127 (18763) | 383/569; 389/615 |
| c3-10-B | 171 190 157 105 133 99 | 73 96 97 103 105 92 | 128.5/168.1 | 170.0/170.4 | 164.3/161.5 | 156.9/159.6 | - | 1473/1474 | 2342/2342 | 2227/2216 | - | 87.9/113.3 | 96.1/109.1/111.3 | 107.4/97.9 | 11178/3099 (18763) | 394/561; 434/731 |
| c3-11-B | 154 149 139 154 138 89 | 76 97 100 107 121 97 | 130.8/168.5 | 170.4/170.5 | 164.2/164.5 | 157.0/159.6 | - | 1455/1456 | 2343/2336 | 2209/2215 | - | 92.7/106.2 | 97.4/103.8/105.5 | 96.2/107.7 | 11042/3135 (18763) | 386/594; 338/572 |
| c3-12-A20 | 193 176 148 104 168 93 | 74 98 100 107 120 97 | 130.9/169.3 | 171.1/170.8 | 164.6/164.7 | 160.3/160.2 | - | 1630/1653 | 2333/2332 | 2232/2221 | - | 88.8/103.5 | 95.8/108.7/112.9 | 103.5/102.3 | 10192/2061 (18763) | 399/593; 435/689 |

#### Confirmation gate (four pairs per candidate: the two screen pairs of L4 / c2 / L8 and these two)

| Candidate | Primary | 4 pair ratios (screen, screen, confirm, confirm) | Median | Bootstrap 95% (20,000, seed 20261026) | Second primary (4 pairs, median) | Greedy tier medians (tiny / cnt1k / cnt4k / cnt32k / cnt128k (2) / nat4k) | Extra condition | Verdict |
|---|---|---|---|---|---|---|---|---|
| A11 | `F` | 1.466, 1.471, 1.544, 1.564 | 1.5076 | 1.4656 to 1.5638 | `P` 0.999, 0.996, 1.011, 1.005 (1.0017) | 1.0037 / 1.0000 / 0.9997 / 0.9990 / 1.0003 / 1.0380 | - | **confirmed** |
| A19 | `F` | 1.488, 1.473, 1.525, 1.482 | 1.4847 | 1.4728 to 1.5252 | `R4` 1.086, 1.064, 1.085, 1.076 (1.0808; 1.0637 to 1.0860) | 1.0016 / 1.0007 / 1.0013 / 0.9978 / 0.9887 / 1.0311 | `R32` median 0.9971 (0.988, 0.999, 0.997, 0.997) | **confirmed** |
| A20 | `F` | 1.494, 1.511, 1.457, 1.521 | 1.5027 | 1.4570 to 1.5211 | `R4` 1.137, 1.146, 1.110, 1.135 (1.1363; 1.1102 to 1.1462) | 1.0059 / 1.0053 / 0.9993 / 1.0051 / 1.0006 / **0.9677** | `R32` median 0.9944 (0.991, 1.007, **0.978** flagged, 0.998) | **not confirmed**: the greedy tier rule fails on nat4k decode (median 0.9677 < 0.98) |

nat4k decode per pair for A20: 0.970 (L8-02 / L8-01), 1.073 (L8-02 / L8-03, the L8 outlier baseline), 0.959 (c3-09 / c3-10), 0.965 (c3-12 / c3-11); A19's are 1.038, 1.007, 1.033, 1.030 and A11's 1.042, 1.058, 0.960, 1.034.

#### c3 reading (computed)

- **A11 (`STRATA_PREFILL_CPU_SHARE=auto STRATA_PREFILL_CPU_SHARE_MAX=3072`) is confirmed on `F`.** The agent follow-up's engine prompt ms is 2,030 and 2,013 ms against 3,135 and 3,148 ms in the adjacent baselines (1.544 and 1.564; screen 1.466 and 1.471), median 1.5076 with a bootstrap interval of 1.4656 to 1.5638, and no greedy tier median below 0.98 (0.9990 to 1.0380). `P` stays flat (median 1.0017), as at the screen: the gain is confined to chunks below the 3,072-token limit.
- **A19 (`STRATA_PREFILL_STREAM_MIN=4096`) is confirmed on `F`**: 2,022 and 2,114 ms against 3,084 and 3,132 ms (1.525, 1.482), median 1.4847, interval 1.4728 to 1.5252; every greedy tier median at or above 0.98 (lowest cnt128k 0.9887 over its two pairs); the cnt4k read gains 8.5% and 7.6% again (`R4` median 1.0808), and addendum 2's `cnt32k` condition holds (`R32` median 0.9971, every pair at or above 0.988).
- **A20 (`STRATA_PREFILL_STREAM_MIN=6144`) has the largest `R4` gain (median 1.1363) and an `F` median of 1.5027 with an interval clear of 1.0, but it is not confirmed**: its nat4k decode tier reads 0.959 and 0.965 in the two confirmation pairs and 0.970 in its first screen pair (the fourth, 1.073, is against L8's slow outlier baseline), so the tier's median pair ratio is 0.9677, below the predeclared 0.98 floor. Every nat4k reply differs in text from every other arm's (production lane, a fresh process each; drafts accepted 195 to 228 of 320 to 367 per 384-token run in all arms), so the decode deficit is partly a text effect, but the rule was written before the data and is applied as written. One `R32` pair (0.978) is also below 0.98; its median (0.9944) holds.
- **Secondary readings, descriptive**: `T1` (agent turn 1, an 18.8K fresh read) improves 6.2% to 9.2% for all three (A11 1.062, 1.078; A19 1.092, 1.081; A20 1.063, 1.083). `T0` read 0.85 / 0.84 for A11 here against 1.11 / 1.10 at its L4 screen, and 1.18 / 0.82 for A19: the tiny first-token times (89 to 216 ms per request, the first request after a start the slowest) are too noisy to read in two pairs, and `T0` is not a primary for any of the three. `D_win` 0.997 to 1.019, `D_real` 0.987 to 1.030, free VRAM 379 MiB at ready in every arm.
- **The choice rule so far** (decision 32; A22 still to come): confirmed members A19 (1 setting, median `F` 1.4847) and A11 (2 settings, 1.5076). A11 replaces A19 only if 1.5076 >= 1.02 x 1.4847 = 1.5144: it does not (A11 / A19 = 1.0154). A20 is out (not confirmed). Current choice: **A19**, pending A22 in c4, which would need a median `F` of at least 1.5144.
