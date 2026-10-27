# r7-pa-c4

- Job exit 0, restore exit 0 (the lab wrapper stopped production, ran the job, restored production and verified it with a real completion).
- Runs in this directory: c4-01-B, c4-02-A22, c4-03-B, c4-04-A22, c4-05-B, c4-06-B, c4-07-A22, c4-08-A10, c4-09-B, c4-10-B, c4-11-A10.
- Every run of this batch is copied here.
- Below: the batch's section from the round's `RESULTS.md`, verbatim except shortened paths. Paths such as `phase-a/raw/...` and `plans/...` refer to the lab workspace and are not part of this directory.

### r7-pa-c4 (A22 screen and confirmation; A10 confirmation)

- Window: 2026-10-26T16:54:02+00:00 to 2026-10-26T17:39:51+00:00 UTC; job exit 0, restore exit 0; elapsed in the job 2708.1 s.
- Production config sha256 before / after: `92c2f588c6bb7d02` / `92c2f588c6bb7d02`; exe `26da5a7e53bf79a1` / `26da5a7e53bf79a1`; PRODCHECK-POST rc=0; PRODCHECK-PRE rc=0; REALREQ-POST rc=0; REALREQ-PRE rc=0; GPU-POST 250.00 W; restore: restored True, max_context 262144.
- Pattern: per candidate X B B X (ON OFF OFF ON) on suite C (A12: plus cnt256k); A22: B X B on suite S (its screen) then X B B X on suite C, as one group. Groups: A22 run (need 1673 s, left 3450 s); A10 run (need 1170 s, left 1881 s).
- Arms: 11 run, 0 skipped (-), 0 failed (-); proof not ok: none.
- Every arm: engine `/proc/<pid>/exe` and sha256 = deployed, `STRATA_*` environ = production env + the arm's switch; proof ok in all eleven (A22: the default share notice absent in all three arms, the three keys in the environ; A10: `strata mtp: coupled draft sampling on (STRATA_SPEC_COUPLED) ... over 106299 tokens` in both arms and in no baseline). Free VRAM at ready: 383 MiB in the A10 arms (the coupled sampler's buffers), 379 MiB elsewhere.
- Harness: `r7suite3.py` `1a609a2b...`, plan `plans/r7-pa-c4.json` `411ae58f...` (dry run `dry/dryrun3-c4.log`, 84 checks, `DRYRUN3 OK`). Keyscan before the copy: 139 files, 0 with the key.
- The lock: after c4 released it, another worker's batch (`r7-pa-L6`, workspace `phase-a3/`, not part of this task) took it at 17:39:52 UTC; c5 was queued behind it.
- Raw: `phase-a/raw/gpu/r7-pa-c4/` (arm.json, provenance.json, engine.log, server.log, bench JSON per arm).

#### Per arm (engine-measured; D in tok/s, P and R in tok/s, F, T0, T1 in ms)

| Arm | Switch | Status | Proof | D_win | D_real | D_SA | P | R4 | R32 | R128 | R256 | F | T0 | T1 | decode tiers (tiny/1k/4k/32k/128k/256k/nat4k) | free MiB | Cached GiB | s |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c4-01-B | B | ok | ok | 170.40 | 104.49 | 105.23 | 1854.8 | 1465.6 | 2347.4 | - | - | 3236.0 | 133.5 | 10989.0 | 95.2/172.4/173.6/165.4/-/-/103.0 | 379 | 79.9 | 154 |
| c4-02-A22 | A22 | ok | ok | 166.69 | 103.82 | 105.94 | 1962.9 | 1652.6 | 2331.5 | - | - | 2197.0 | 159.5 | 10281.0 | 95.0/167.6/169.5/163.0/-/-/99.7 | 379 | 79.9 | 144 |
| c4-03-B | B | ok | ok | 167.78 | 102.63 | 102.71 | 1846.0 | 1472.7 | 2314.0 | - | - | 3256.0 | 149.5 | 10963.0 | 96.5/168.4/170.9/164.1/-/-/102.5 | 379 | 79.9 | 154 |
| c4-04-A22 | A22 | ok | ok | 167.67 | 102.47 | 103.42 | 1966.8 | 1669.3 | 2317.2 | 2212.7 | - | 2033.0 | 137.5 | 10208.0 | 95.7/168.8/170.4/163.9/157.4/-/100.6 | 379 | 79.9 | 273 |
| c4-05-B | B | ok | ok | 167.52 | 98.67 | 98.57 | 1833.2 | 1448.5 | 2320.1 | 2205.4 | - | 3081.0 | 135.0 | 11039.0 | 95.0/168.4/170.1/164.1/159.6/-/98.9 | 379 | 79.9 | 287 |
| c4-06-B | B | ok | ok | 167.05 | 105.99 | 108.83 | 1832.8 | 1447.4 | 2320.9 | 2227.4 | - | 3123.0 | 153.5 | 11118.0 | 90.7/167.5/170.1/163.6/159.4/-/100.5 | 379 | 79.9 | 283 |
| c4-07-A22 | A22 | ok | ok | 168.22 | 99.22 | 97.95 | 1962.9 | 1654.0 | 2329.5 | 2222.9 | - | 2045.0 | 164.0 | 10271.0 | 95.3/169.3/170.7/164.7/159.7/-/101.8 | 379 | 79.9 | 273 |
| c4-08-A10 | A10 | ok | ok | 168.00 | 104.35 | 105.68 | 1842.9 | 1450.1 | 2342.1 | 2210.8 | - | 3127.0 | 149.5 | 11085.0 | 96.3/168.9/170.9/164.3/157.2/-/101.7 | 383 | 79.9 | 284 |
| c4-09-B | B | ok | ok | 168.26 | 101.94 | 104.87 | 1832.6 | 1443.7 | 2326.1 | 2209.5 | - | 3127.0 | 138.0 | 11183.0 | 96.8/169.0/171.2/164.6/159.7/-/96.3 | 379 | 79.9 | 286 |
| c4-10-B | B | ok | ok | 167.89 | 102.24 | 104.10 | 1839.2 | 1447.9 | 2336.1 | 2222.6 | - | 3118.0 | 147.5 | 11149.0 | 95.9/168.6/170.7/164.4/157.2/-/98.6 | 379 | 79.9 | 284 |
| c4-11-A10 | A10 | ok | ok | 167.16 | 103.60 | 104.65 | 1849.4 | 1476.0 | 2317.2 | 2210.0 | - | 3129.0 | 133.5 | 11168.0 | 95.3/168.0/170.1/163.5/159.2/-/101.5 | 383 | 79.9 | 285 |

#### Pair ratios (A22: two screen pairs on suite S, two confirmation pairs on suite C; A10: two confirmation pairs; arm / baseline for D_win, D_real, D_SA, P, R4, R32, R128, R256; baseline / arm for F, T0, T1)

| Arm | Pair | Phase | D_win | D_real | D_SA | P | R4 | R32 | R128 | R256 | F | T0 | T1 | tier dec (tiny/1k/4k/32k/128k/256k/nat4k/samp4k/agent) | tier read (4k/32k/128k/256k) |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| A22 (c4-02-A22) | c4-01-B (baseline then arm) | screen | 0.978 | 0.994 | 1.007 | 1.058 | 1.128 | 0.993 | - | - | 1.473 | 0.837 | 1.069 | 0.998/0.972/0.977/0.985/-/-/0.968/1.009/1.004 | 1.128/0.993/-/- |
| A22 (c4-02-A22) | c4-03-B (arm then baseline) | screen | 0.993 | 1.012 | 1.031 | 1.063 | 1.122 | 1.008 | - | - | 1.482 | 0.937 | 1.066 | 0.984/0.995/0.992/0.993/-/-/0.973/0.994/1.070 | 1.122/1.008/-/- |
| A22 (c4-04-A22) | c4-05-B (arm then baseline) | confirm | 1.001 | 1.039 | 1.049 | 1.073 | 1.152 | 0.999 | 1.003 | - | 1.515 | 0.982 | 1.081 | 1.008/1.002/1.002/0.999/0.986/-/1.018/1.018/1.081 | 1.152/0.999/1.003/- |
| A22 (c4-07-A22) | c4-06-B (baseline then arm) | confirm | 1.007 | 0.936 | 0.900 | 1.071 | 1.143 | 1.004 | 0.998 | - | 1.527 | 0.936 | 1.082 | 1.052/1.011/1.003/1.007/1.002/-/1.013/0.922/0.879 | 1.143/1.004/0.998/- |
| A10 (c4-08-A10) | c4-09-B (arm then baseline) | confirm | 0.998 | 1.024 | 1.008 | 1.006 | 1.004 | 1.007 | 1.001 | - | 1.000 | 0.923 | 1.009 | 0.995/0.999/0.998/0.998/0.984/-/1.056/0.997/1.018 | 1.004/1.007/1.001/- |
| A10 (c4-11-A10) | c4-10-B (baseline then arm) | confirm | 0.996 | 1.013 | 1.005 | 1.006 | 1.019 | 0.992 | 0.994 | - | 0.996 | 1.105 | 0.998 | 0.994/0.996/0.997/0.994/1.013/-/1.029/0.997/1.014 | 1.019/0.992/0.994/- |

#### Baseline arms (noise reference: each baseline / the first baseline)

| Baseline | D_win | D_real | D_SA | P | R4 | R32 | R128 | R256 | F | T0 | T1 |
|---|---|---|---|---|---|---|---|---|---|---|---|
| c4-01-B | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | - | - | 1.000 | 1.000 | 1.000 |
| c4-03-B | 0.985 | 0.982 | 0.976 | 0.995 | 1.005 | 0.986 | - | - | 0.994 | 0.893 | 1.002 |
| c4-05-B | 0.983 | 0.944 | 0.937 | 0.988 | 0.988 | 0.988 | - | - | 1.050 | 0.989 | 0.995 |
| c4-06-B | 0.980 | 1.014 | 1.034 | 0.988 | 0.988 | 0.989 | - | - | 1.036 | 0.870 | 0.988 |
| c4-09-B | 0.987 | 0.976 | 0.997 | 0.988 | 0.985 | 0.991 | - | - | 1.035 | 0.967 | 0.983 |
| c4-10-B | 0.985 | 0.978 | 0.989 | 0.992 | 0.988 | 0.995 | - | - | 1.038 | 0.905 | 0.986 |

#### Every run, compact (engine lines; decode tok/s per run)

| Arm | tiny prompt ms x6 | tiny decode x6 | cnt1k dec r1/r2 | cnt4k dec r1/r2 | cnt32k dec r1/r2 | cnt128k dec r1/r2 | cnt256k dec | cnt4k read r1/r2 | cnt32k read r1/r2 | cnt128k read r1/r2 | cnt256k read | nat4k dec r1/r2 | samp4k dec 4242/4243/4244 | agent dec t1/t2 | agent prompt ms t1/t2 (reused) | drafts acc/offered samp4k; agent |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c4-01-B | 211 162 140 109 127 99 | 68 98 100 106 123 97 | 132.2/172.3 | 172.2/173.5 | 166.2/165.4 | - | - | 1459/1466 | 2346/2347 | - | - | 94.3/113.5 | 104.7/100.6/105.6 | 108.5/105.4 | 10989/3236 (18763) | 383/551; 439/668 |
| c4-02-A22 | 199 155 148 164 199 138 | 74 96 93 105 119 96 | 131.1/167.6 | 169.2/169.5 | 163.5/163.0 | - | - | 1634/1653 | 2344/2332 | - | - | 90.4/111.2 | 101.1/103.7/109.0 | 103.5/113.2 | 10281/2197 (18763) | 409/609; 394/611 |
| c4-03-B | 196 169 131 143 156 126 | 75 96 98 107 122 96 | 130.8/168.4 | 170.5/170.9 | 164.4/164.1 | - | - | 1474/1473 | 2331/2314 | - | - | 94.5/111.9 | 100.9/101.7/113.7 | 96.3/104.0 | 10963/3256 (18763) | 394/565; 393/693 |
| c4-04-A22 | 206 152 113 123 154 93 | 73 95 98 106 120 96 | 130.4/168.8 | 170.0/170.5 | 161.0/163.9 | 159.5/157.4 | - | 1659/1669 | 2327/2317 | 2221/2213 | - | 89.6/114.6 | 105.8/98.0/109.5 | 108.8/97.1 | 10208/2033 (18763) | 383/563; 424/681 |
| c4-05-B | 174 134 137 129 136 120 | 73 95 97 105 121 95 | 129.9/168.4 | 170.0/170.2 | 164.3/164.1 | 159.7/159.6 | - | 1442/1448 | 2329/2320 | 2214/2205 | - | 89.6/110.3 | 98.4/103.9/104.9 | 102.1/88.7 | 11039/3081 (18763) | 379/572; 373/704 |
| c4-06-B | 190 146 126 181 161 104 | 70 90 96 94 105 99 | 129.7/167.6 | 169.0/170.2 | 163.7/163.5 | 158.8/159.4 | - | 1446/1447 | 2339/2321 | 2236/2227 | - | 89.6/114.5 | 99.3/103.9/117.4 | 107.8/117.2 | 11118/3123 (18763) | 410/579; 398/591 |
| c4-07-A22 | 200 150 167 161 174 113 | 75 97 97 102 117 96 | 129.9/169.3 | 170.1/170.6 | 164.7/164.8 | 156.6/159.7 | - | 1631/1654 | 2337/2329 | 2222/2223 | - | 95.6/108.9 | 94.4/102.3/97.7 | 102.7/92.5 | 10271/2045 (18763) | 363/572; 368/635 |
| c4-08-A10 | 173 152 137 163 147 109 | 74 97 98 106 121 97 | 131.4/168.8 | 169.6/170.9 | 164.2/164.3 | 157.4/157.1 | - | 1451/1450 | 2341/2342 | 2215/2211 | - | 91.8/114.0 | 99.3/101.8/118.7 | 99.0/114.9 | 11085/3127 (18763) | 393/509; 388/578 |
| c4-09-B | 203 168 106 135 141 109 | 75 97 99 106 121 97 | 131.8/169.0 | 170.2/171.2 | 164.9/164.6 | 159.9/159.7 | - | 1453/1444 | 2333/2326 | 2213/2209 | - | 87.9/106.5 | 104.6/110.3/104.0 | 101.8/105.5 | 11183/3127 (18763) | 411/596; 425/701 |
| c4-10-B | 182 175 157 104 138 119 | 74 97 95 107 121 96 | 131.9/168.7 | 170.2/170.7 | 164.3/164.4 | 159.7/157.2 | - | 1443/1448 | 2338/2336 | 2226/2223 | - | 88.3/111.6 | 100.2/108.0/109.6 | 100.6/105.2 | 11149/3118 (18763) | 395/558; 368/618 |
| c4-11-A10 | 184 152 107 142 125 114 | 72 95 99 105 119 96 | 128.7/168.0 | 169.7/170.1 | 163.6/163.5 | 156.8/159.2 | - | 1481/1476 | 2326/2317 | 2221/2210 | - | 96.0/107.7 | 105.3/109.6/101.7 | 106.2/101.3 | 11168/3129 (18763) | 396/518; 392/586 |

#### Confirmation gate

| Candidate | Primary | 4 pair ratios (screen, screen, confirm, confirm) | Median | Bootstrap 95% (20,000, seed 20261026) | Second primary (4 pairs, median) | Greedy tier medians (tiny / cnt1k / cnt4k / cnt32k / cnt128k (2) / nat4k) | Extra condition | Verdict |
|---|---|---|---|---|---|---|---|---|
| A22 | `F` | 1.473, 1.482, 1.515, 1.527 (screen and confirmation both in c4) | 1.4988 | 1.4729 to 1.5271 | `R4` 1.128, 1.122, 1.152, 1.143 (1.1352; 1.1222 to 1.1525) | 1.0027 / 0.9987 / 0.9970 / 0.9959 / 0.9942 / 0.9929 | `R32` median 1.0012 (0.993, 1.008, 0.999, 1.004) | **confirmed** (screen gate: both `F` pairs >= 1.02) |
| A10 | `D_SA` (PLAN.md: `D_real` over the sampled and agent tiers; decision 29) | 1.049, 1.028, 1.008, 1.005 | 1.0179 | 1.0053 to 1.0489 | full `D_real` 1.041, 1.030, 1.024, 1.013 (1.0266; 1.0133 to 1.0406) | 0.9957 / 0.9947 / 0.9953 / 0.9971 / 0.9985 / 1.0311 | - | **not confirmed**: median 1.0179 < 1.02 |

A10 against the pooled baselines of its batch (PLAN.md's comparison for the sampled tiers): samp4k decode 1.021, 1.021 (L4), 1.010, 1.005 (c4); agent decode 1.050, 1.050 (L4), 1.021, 1.006 (c4).

#### c4 reading (computed)

- **A22 (`STRATA_PREFILL_STREAM_MIN=6144 STRATA_PREFILL_CPU_SHARE=auto STRATA_PREFILL_CPU_SHARE_MAX=3072`) confirms on `F`**: the screen (suite S) reads 2,197 ms against 3,236 and 3,256 (1.473, 1.482), the confirmation (suite C) 2,033 and 2,045 ms against 3,081 and 3,123 (1.515, 1.527); median 1.4988, interval 1.4729 to 1.5271, every greedy tier median at or above 0.9929, `R32` median 1.0012. Its cnt4k read gains 12 to 15% (`R4` median 1.1352), as A20's did (1.1363), which is what SWITCHES.md addendum 2 predicted from the code (with `STRATA_PREFILL_STREAM_MIN` set, `CPU_SHARE_MAX` cannot reach the staged-chunk limit, so A22 runs A20's path). Its nat4k decode tier reads 0.968, 0.973, 1.018, 1.013 (median 0.9929), where A20's read 0.970, 1.073, 0.959, 0.965 (median 0.9677): the same code path passes the tier rule in one batch and fails it in the other, which says the nat4k decode tier moves by about 3% between processes on these settings; A20's verdict is not revisited (the rule was applied as written).
- **A10 (coupled draft sampling) is not confirmed.** On the predeclared primary (decision 29: PLAN.md's table gives A10 `D_real` over the sampled and agent tiers only, where the switch can act) the confirmation pairs read 1.008 and 1.005, against 1.049 and 1.028 at the screen: median 1.0179, under the 1.02 bar. **Flagged for the parent:** on the full `D_real` (the L4 screen's reading and addendum 3 item 1's wording) the four pairs read 1.041, 1.030, 1.024, 1.013, median 1.0266 with an interval of 1.0133 to 1.0406, which would pass. The difference is nat4k, a greedy tier the switch cannot reach (it acts only at temperature >= 0.9): nat4k decode read 1.056 and 1.029 in the confirmation pairs, and that is what lifts the full `D_real`. On the tiers A10 can touch, the confirmation pairs show samp4k 0.997 and 0.997 and agent 1.018 and 1.014 (per pair), so its measured effect is a 1 to 2% agent gain and none on samp4k.
- **A10's other readings, descriptive**: `F` 1.000 and 0.996 (the screen's 1.091 / 1.084 were park variance, as L4 suspected), `T1` 1.009 / 0.998, `D_win` 0.998 / 0.996, free VRAM 383 MiB.
- **Prefill choice (decision 32), final**: confirmed members A19 (1 setting, median `F` 1.4847), A11 (2 settings, 1.5076) and A22 (3 settings, 1.4988); A20 is not confirmed. Fewest settings: A19. A11 would replace it only at a median `F` >= 1.02 x 1.4847 = **1.5144**: 1.5076 < 1.5144 (A11 / A19 = 1.0154), not chosen. A22 likewise needs >= 1.5144 against A19: 1.4988 < 1.5144 (A22 / A19 = 1.0095), not chosen. **Chosen prefill setting: A19, `STRATA_PREFILL_STREAM_MIN=4096`.**
