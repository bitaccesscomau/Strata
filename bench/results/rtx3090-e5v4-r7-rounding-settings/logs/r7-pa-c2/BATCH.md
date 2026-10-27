# r7-pa-c2

- Job exit ?, restore exit ? (the lab wrapper stopped production, ran the job, restored production and verified it with a real completion).
- Runs in this directory: c2-01-A8, c2-02-B, c2-03-B, c2-04-A8, c2-05-B, c2-06-A19, c2-07-B, c2-08-A19, c2-09-B.
- Every run of this batch is copied here.
- Below: the batch's section from the round's `RESULTS.md`, verbatim except shortened paths. Paths such as `phase-a/raw/...` and `plans/...` refer to the lab workspace and are not part of this directory.

### r7-pa-c2 (confirmation of A8 `--spec 6` on suite C; spare budget: A19's screen on suite S)

- Window: 2026-10-26T13:33:55+00:00 to 2026-10-26T14:06:06+00:00 UTC; job exit 0, restore exit 0 (state `r7-pa-c2`); elapsed in the job 1889.2 s.
- Production config sha256 before / after: `92c2f588c6bb7d02` / `92c2f588c6bb7d02`; exe `26da5a7e53bf79a1` / `26da5a7e53bf79a1`; PRODCHECK-PRE / POST rc=0, REALREQ-PRE / POST rc=0.
- Pattern: A8 as `X B B X` on suite C (all four arms), then A19's screen as `B X B` on suite S, then A19's reversed half `X B` (descriptive). Reversed half run: slowest arm 285.1 s, needed 687 s, 1,862 s left. All nine arms ran; none was skipped.
- Every arm: engine exe and sha256 = deployed; `STRATA_*` environ = production env plus the switch (`STRATA_PREFILL_STREAM_MIN=4096` in both A19 arms; A8's arms add none and keep `--spec` replaced in place: `6`); config args block intact in the argv with extras `[exe, --serve]`; proof ok in all nine (A8 prints `strata verify: window up to 8 tokens`; A19 has no log line, so its proof is the environ, as SWITCHES.md records).
- Harness: `r7suite.py` sha256 `eac3fd75...`, plan `plans/r7-pa-c2.json` sha256 `42b82208...`.
- Raw: `phase-a/raw/gpu/r7-pa-c2/` (arm.json, engine.log, server.log, bench JSON per arm; `analysis.md` holds every engine line). Keyscan: 102 files, 0 with the key.

#### Per arm (engine-measured; suite C arms carry `R128`, suite S arms do not)

| Arm | Switch | Status | Proof | D_win | D_real | P | R4 | R32 | R128 | R256 | F | T0 | T1 | D_win tiers (tiny/1k/4k/32k/128k/nat4k) | free MiB | Cached GiB | s |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c2-01-A8 | A8 | ok | ok | 185.79 | 96.93 | 1840.9 | 1452.7 | 2332.9 | 2218.7 | - | 3090.0 | 128.5 | 11003.0 | 84.2/181.8/194.8/181.0/177.0/95.7 | 345 | 79.7 | 284 |
| c2-02-B | B | ok | ok | 168.40 | 104.37 | 1858.7 | 1483.7 | 2328.5 | 2238.4 | - | 3115.0 | 139.5 | 10994.0 | 96.6/169.0/171.1/165.2/161.0/99.4 | 379 | 79.7 | 282 |
| c2-03-B | B | ok | ok | 168.77 | 103.93 | 1836.6 | 1450.1 | 2326.3 | 2211.7 | - | 3100.0 | 154.0 | 11136.0 | 97.3/169.5/171.1/165.7/158.2/98.2 | 379 | 79.7 | 284 |
| c2-04-A8 | A8 | ok | ok | 185.50 | 95.96 | 1833.5 | 1450.1 | 2318.4 | 2225.8 | - | 3122.0 | 151.5 | 11035.0 | 85.7/182.3/191.2/183.1/176.6/92.1 | 345 | 79.7 | 285 |
| c2-05-B | B | ok | ok | 167.86 | 102.31 | 1843.8 | 1452.7 | 2340.2 | - | - | 3257.0 | 145.0 | 11096.0 | 97.1/168.5/170.9/164.2/-/99.0 | 379 | 79.7 | 154 |
| c2-06-A19 | A19 | ok | ok | 167.97 | 101.37 | 1910.1 | 1577.6 | 2312.7 | - | - | 2189.0 | 141.5 | 10325.0 | 97.0/168.9/171.0/164.1/-/102.8 | 379 | 79.7 | 146 |
| c2-07-B | B | ok | ok | 168.04 | 105.39 | 1852.7 | 1483.2 | 2314.4 | - | - | 3224.0 | 149.0 | 11145.0 | 96.4/169.8/170.0/164.4/-/102.1 | 379 | 79.7 | 153 |
| c2-08-A19 | A19 | ok | ok | 168.55 | 102.48 | 1904.6 | 1570.7 | 2309.4 | - | - | 2167.0 | 139.0 | 10278.0 | 96.7/169.4/171.1/165.2/-/99.5 | 379 | 79.7 | 145 |
| c2-09-B | B | ok | ok | 166.42 | 101.47 | 1830.9 | 1450.1 | 2311.7 | - | - | 3210.0 | 165.0 | 11013.0 | 96.5/168.2/170.0/161.2/-/99.5 | 379 | 79.7 | 156 |

#### Pair ratios (A8's two confirmation pairs and A19's two screen pairs; A19's last two are its reversed half, descriptive)

| Arm | Pair | Phase | D_win | D_real | P | R4 | R32 | R128 | R256 | F | T0 | T1 | tier dec (tiny/1k/4k/32k/128k/nat4k) | tier read (4k/32k/128k) |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| A8 | c2-02-B (arm then baseline) | screen | 1.103 | 0.929 | 0.990 | 0.979 | 1.002 | 0.991 | - | 1.008 | 1.086 | 0.999 | 0.872/1.076/1.139/1.096/1.100/0.962 | 0.979/1.002/0.991 |
| A8 | c2-03-B (baseline then arm) | screen | 1.099 | 0.923 | 0.998 | 1.000 | 0.997 | 1.006 | - | 0.993 | 1.017 | 1.009 | 0.881/1.075/1.117/1.105/1.116/0.937 | 1.000/0.997/1.006 |
| A19 | c2-05-B (baseline then arm) | screen | 1.001 | 0.991 | 1.036 | 1.086 | 0.988 | - | - | 1.488 | 1.025 | 1.075 | 0.999/1.002/1.001/0.999/-/1.038 | 1.086/0.988/- |
| A19 | c2-07-B (arm then baseline) | screen | 1.000 | 0.962 | 1.031 | 1.064 | 0.999 | - | - | 1.473 | 1.053 | 1.079 | 1.007/0.995/1.006/0.998/-/1.007 | 1.064/0.999/- |
| A19 | c2-07-B (arm then baseline) | screen | 1.003 | 0.972 | 1.028 | 1.059 | 0.998 | - | - | 1.488 | 1.072 | 1.084 | 1.004/0.998/1.007/1.005/-/0.975 | 1.059/0.998/- |
| A19 | c2-09-B (baseline then arm) | screen | 1.013 | 1.010 | 1.040 | 1.083 | 0.999 | - | - | 1.481 | 1.187 | 1.072 | 1.003/1.007/1.007/1.025/-/1.000 | 1.083/0.999/- |

#### A8 confirmation gate (four pairs: its two L3 screen pairs and these two)

| Primary | 4 pair ratios | Median | Bootstrap 95% | Gate |
|---|---|---|---|---|
| `D_win` | 1.109, 1.108, 1.103, 1.099 | 1.1057 | 1.0992 to 1.1091 | median >= 1.02, interval above 1.0 |
| `D_real` | 0.974, 0.930, 0.929, 0.923 | 0.9296 | 0.9233 to 0.9740 | does not confirm |

| Greedy tier | tiny | cnt1k | cnt4k | cnt32k | cnt128k | nat4k |
|---|---|---|---|---|---|---|
| A8 median pair ratio (decode) | 0.8811 | 1.0757 | 1.1242 | 1.1148 | 1.1077 | 0.9483 |

**A8 verdict: rejected.** `D_win` confirms strongly (median 1.1057, interval 1.0992 to 1.1091), but the parent's
condition fails: the `D_real` median over four pairs is 0.9296, far below 0.98. The greedy tier rule fails too (tiny
decode 0.8811, nat4k decode 0.9483). Its `D_real` loss is the same window-shape effect A7 shows, larger because the
8-token window is the cap.

#### A19 screen (the addendum's `F` then `cnt4k` prompt read, plus its `cnt32k` >= 0.98 condition)

| Primary | Pair ratios (screen) | Gate | Extra condition | Verdict |
|---|---|---|---|---|
| `F` | 1.488, 1.473 | confirm (both >= 1.02) | - | confirm |
| `R4` (cnt4k read) | 1.086, 1.064 | confirm (both >= 1.02) | `R32` 0.988 and 0.999, both >= 0.98 | confirm |

Reversed half (descriptive): `F` 1.488 and 1.481, `R4` 1.059 and 1.083, `R32` 0.998 and 0.999.

#### Baseline arms (noise reference: each baseline / the first baseline)

| Baseline | D_win | D_real | P | R4 | R32 | R128 | R256 | F | T0 | T1 |
|---|---|---|---|---|---|---|---|---|---|---|
| c2-02-B | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | - | 1.000 | 1.000 | 1.000 |
| c2-03-B | 1.002 | 0.996 | 0.988 | 0.977 | 0.999 | 0.988 | - | 1.005 | 0.906 | 0.987 |
| c2-05-B | 0.997 | 0.980 | 0.992 | 0.979 | 1.005 | - | - | 0.956 | 0.962 | 0.991 |
| c2-07-B | 0.998 | 1.010 | 0.997 | 1.000 | 0.994 | - | - | 0.966 | 0.936 | 0.986 |
| c2-09-B | 0.988 | 0.972 | 0.985 | 0.977 | 0.993 | - | - | 0.970 | 0.845 | 0.998 |

#### Every run, compact (engine lines; decode tok/s per run)

| Arm | tiny prompt ms x6 | tiny decode x6 | cnt1k dec r1/r2 | cnt4k dec r1/r2 | cnt32k dec r1/r2 | cnt4k read r1/r2 | cnt32k read r1/r2 | nat4k dec r1/r2 | samp4k dec 4242/4243/4244 | agent dec t1/t2 | agent prompt ms t1/t2 (reused) |
|---|---|---|---|---|---|---|---|---|---|---|---|
| c2-01-A8 | 225 135 122 162 102 122 | 66 89 84 95 96 84 | 130.4/181.9 | 193.9/194.9 | 185.1/181.0 | 1451/1453 | 2361/2333 | 85.4/108.8 | 94.8/102.2/106.5 | 94.5/94.1 | 11003/3090 (18763) |
| c2-02-B | 203 136 144 127 143 126 | 74 98 99 104 121 97 | 130.6/169.0 | 171.1/171.1 | 164.1/165.1 | 1480/1484 | 2338/2328 | 91.3/109.1 | 101.5/110.8/102.2 | 110.9/107.2 | 10994/3115 (18763) |
| c2-03-B | 210 179 107 142 166 121 | 74 98 100 107 123 97 | 131.4/169.5 | 170.4/171.1 | 164.3/165.6 | 1450/1450 | 2351/2326 | 89.1/109.3 | 101.2/97.8/108.9 | 113.1/108.9 | 11136/3100 (18763) |
| c2-04-A8 | 210 196 137 151 152 112 | 69 93 86 96 97 84 | 129.0/182.4 | 190.2/191.1 | 178.3/183.1 | 1448/1450 | 2324/2318 | 80.5/107.5 | 97.3/99.7/92.6 | 94.9/106.3 | 11035/3122 (18763) |
| c2-05-B | 188 152 138 117 165 133 | 75 97 99 106 121 98 | 129.8/168.5 | 169.8/170.8 | 164.5/164.2 | 1454/1453 | 2347/2340 | 93.1/105.7 | 103.9/102.9/107.0 | 105.9/99.9 | 11096/3257 (18763) |
| c2-06-A19 | 192 137 141 142 149 129 | 75 97 100 106 121 98 | 131.7/168.9 | 170.4/171.1 | 164.5/164.1 | 1554/1578 | 2321/2313 | 92.7/115.3 | 97.4/102.7/108.0 | 101.4/96.5 | 10325/2189 (18763) |
| c2-07-B | 182 161 137 133 187 111 | 74 98 100 107 120 94 | 131.4/169.8 | 171.1/170.0 | 164.9/164.4 | 1484/1483 | 2337/2314 | 92.8/113.4 | 101.7/109.8/100.5 | 113.9/105.8 | 11145/3224 (18763) |
| c2-08-A19 | 156 135 107 143 164 122 | 74 98 99 107 121 96 | 129.7/169.4 | 170.2/171.2 | 164.5/165.1 | 1555/1571 | 2326/2309 | 90.0/111.2 | 97.9/112.9/104.4 | 100.9/106.3 | 10278/2167 (18763) |
| c2-09-B | 209 178 140 169 161 119 | 74 98 98 105 122 96 | 130.8/168.2 | 170.6/169.9 | 164.0/161.2 | 1448/1450 | 2324/2312 | 94.2/105.4 | 101.4/103.2/107.2 | 99.7/102.5 | 11013/3210 (18763) |

#### c2 reading (computed)

- **A8 (`--spec 6`) is rejected on `D_real`, exactly the case the parent pre-declared.** Its `D_win` gain is the largest
  in the round (1.099 to 1.109; counting-tier decode 1.076 / 1.124 / 1.115 / 1.108 on cnt1k / cnt4k / cnt32k / cnt128k),
  and its four-pair `D_win` median 1.1057 has an interval clear of 1.0. But `D_real` falls in all four pairs (0.923 to
  0.974; median 0.9296), the tiny chats lose 12% of decode (84.2 / 85.7 tok/s against 96.6 to 97.3) and nat4k loses 5%
  (95.7 / 92.1 against 99.4 / 98.2). Adopting it would trade a real-traffic regression for a benchmark-shaped gain.
- **A19 (`STRATA_PREFILL_STREAM_MIN=4096`) screens as confirm on both primaries, with a large `F` gain.** The agent
  follow-up's engine prompt ms falls from 3,257 and 3,224 ms to 2,189 and 2,167 ms (1.488 and 1.473; reversed 1.488 and
  1.481), and the cnt4k prompt read rises 6.4 to 8.6% (1,577.6 and 1,570.7 tok/s against 1,452.7 and 1,483.2). Its
  `cnt32k` read stays at 0.988 and 0.999, so the addendum's >= 0.98 condition holds. `D_win` is flat (1.001, 1.000),
  `T1` 1.075 and 1.079, `D_real` 0.991 and 0.962 (nat4k decode 1.038 and 1.007 in the first pair, 0.975 and 1.000 in the
  reversed half: noise-level).
- **What A19's gain is.** The switch moves chunks of 1,024 to 4,095 tokens from the streaming ring to the 8-slot STAGE
  path, and (as SWITCHES.md's addendum records) also widens the production default CPU share's staged-chunk limit from
  1,024 to 4,096 tokens. The follow-up's 1,786 new tokens and cnt4k's chunks fall in that band, which is why `F` and `R4`
  move while cnt32k (whose chunks are at or above 4,096) does not. This is the combined change, not the STAGE threshold
  alone; the numbers are the combined effect's.
- **A19's confirmation is not part of part 2a.** It screened in c2's spare budget as the parent instructed; with only L8
  left in this task (A20, A21) and no pairs to be added after data, its two more pairs in the opposite order belong to a
  later batch. Its screen is unambiguous on both primaries, so a confirmation batch is the natural next step for the
  parent, not an open question of measurement.
- Suite C's `cnt128k` behaves as expected in these arms: 2,211 to 2,238 tok/s prompt read, 158 to 177 tok/s decode; a
  128,451-token prompt costs about 128 s per arm (2 runs), which is what the c1 and c2 budgets were booked against.
