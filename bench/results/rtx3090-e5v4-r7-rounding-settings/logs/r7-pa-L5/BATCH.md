# r7-pa-L5

- Job exit ?, restore exit ? (the lab wrapper stopped production, ran the job, restored production and verified it with a real completion).
- Runs in this directory: L5-01-B, L5-02-A12, L5-03-B.
- Runs of this batch not copied here (exact-class settings, or baselines paired only with them): L5-04-B (B), L5-05-A13 (A13), L5-06-B (B), L5-07-A13 (A13), L5-08-B (B).
- Below: the batch's section from the round's `RESULTS.md`, verbatim except shortened paths. Paths such as `phase-a/raw/...` and `plans/...` refer to the lab workspace and are not part of this directory.

### r7-pa-L5 (screen: A12 KV prefetch on suite C, A13 PCIe DMA on suite S)

- Window: 2026-10-26T14:39:07+00:00 to 2026-10-26T15:06:47+00:00 UTC; job exit 0, restore exit 0 (state `r7-pa-L5`); elapsed in the job 1617.8 s. The batch waited about six minutes for the lock behind another job (`round2-r7-...`), which is not counted in the job time.
- Production config sha256 before / after: `92c2f588c6bb7d02` / `92c2f588c6bb7d02`; exe `26da5a7e53bf79a1` / `26da5a7e53bf79a1`; PRODCHECK-PRE / POST rc=0, REALREQ-PRE / POST rc=0.
- Pattern: A12 as `B X B` on suite C (its switch can only act past the 32,768 resident cells, so its screen reads `cnt128k`), then A13 as `B X B` on suite S, then A13's reversed half `X B` (slowest arm 284.6 s, needed 686 s, 2,141 s left: run). Eight arms, none skipped; A12's reversed pair is not run (a second suite C baseline would be needed for it) and its two screen pairs are the gate's two.
- Proof: A12 prints `strata KV prefetch: 30 layer prefixes, single existing staging pool` (30 hits: one per prompt read, with the layer count at 128K); A13 has no startup line and is proven by `--pcie-mode dma` in the engine's argv. Free VRAM 385 MiB in the A13 arms against 379 in the baselines.
- Harness: `r7suite.py` sha256 `eac3fd75...`, plan `plans/r7-pa-L5.json` sha256 `ff4f8404...`.
- Raw: `phase-a/raw/gpu/r7-pa-L5/`. Keyscan: 90 files, 0 with the key.

#### Per arm

| Arm | Switch | Status | Proof | D_win | D_real | P | R4 | R32 | R128 | R256 | F | T0 | T1 | D_win tiers (tiny/1k/4k/32k/128k/nat4k) | free MiB | Cached GiB | s |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| L5-01-B | B | ok | ok | 170.02 | 100.76 | 1853.1 | 1456.4 | 2357.7 | 2223.2 | - | 3123.0 | 137.0 | 11005.0 | 96.2/171.9/173.1/165.2/159.1/99.4 | 379 | 79.8 | 285 |
| L5-02-A12 | A12 | ok | ok | 168.44 | 101.65 | 1878.4 | 1471.6 | 2397.7 | 2363.2 | - | 3066.0 | 137.0 | 10801.0 | 97.5/169.2/171.2/164.9/161.4/95.1 | 379 | 79.8 | 277 |
| L5-03-B | B | ok | ok | 168.14 | 105.08 | 1835.7 | 1450.1 | 2323.9 | 2227.0 | - | 3089.0 | 143.5 | 11080.0 | 96.4/169.0/170.6/164.9/157.1/99.8 | 379 | 79.8 | 284 |
| L5-04-B | B | ok | ok | 166.96 | 103.80 | 1837.8 | 1453.2 | 2324.1 | - | - | 3268.0 | 152.5 | 11122.0 | 96.5/168.6/170.7/161.7/-/98.3 | 379 | 79.8 | 154 |
| L5-05-A13 | A13 | ok | ok | 168.00 | 103.24 | 1838.1 | 1464.5 | 2306.9 | - | - | 3231.0 | 146.5 | 11052.0 | 91.1/167.9/171.6/164.6/-/98.7 | 385 | 79.8 | 155 |
| L5-06-B | B | ok | ok | 167.40 | 102.74 | 1840.7 | 1447.9 | 2340.0 | - | - | 3253.0 | 161.0 | 10907.0 | 97.2/169.3/171.1/161.9/-/98.5 | 379 | 79.8 | 154 |
| L5-07-A13 | A13 | ok | ok | 166.34 | 100.48 | 1839.2 | 1452.2 | 2329.3 | - | - | 3270.0 | 140.5 | 11093.0 | 91.2/167.6/169.9/161.6/-/94.0 | 385 | 79.8 | 154 |
| L5-08-B | B | ok | ok | 167.96 | 102.34 | 1846.4 | 1472.1 | 2315.9 | - | - | 3265.0 | 149.5 | 11134.0 | 96.6/168.2/171.1/164.6/-/100.7 | 379 | 79.8 | 154 |

#### Pair ratios (A12's two screen pairs; A13's screen pairs and its reversed half)

| Arm | Pair | Phase | D_win | D_real | P | R4 | R32 | R128 | R256 | F | T0 | T1 | tier dec (tiny/1k/4k/32k/128k/nat4k) | tier read (4k/32k/128k) |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| A12 | L5-01-B (baseline then arm) | screen | 0.991 | 1.009 | 1.014 | 1.010 | 1.017 | 1.063 | - | 1.019 | 1.000 | 1.019 | 1.013/0.984/0.989/0.999/1.015/0.957 | 1.010/1.017/1.063 |
| A12 | L5-03-B (arm then baseline) | screen | 1.002 | 0.967 | 1.023 | 1.015 | 1.032 | 1.061 | - | 1.008 | 1.047 | 1.026 | 1.011/1.001/1.004/1.000/1.028/0.952 | 1.015/1.032/1.061 |
| A13 | L5-04-B (baseline then arm) | screen | 1.006 | 0.995 | 1.000 | 1.008 | 0.993 | - | - | 1.011 | 1.041 | 1.006 | 0.944/0.995/1.005/1.018/-/1.005 | 1.008/0.993/- |
| A13 | L5-06-B (arm then baseline) | screen | 1.004 | 1.005 | 0.999 | 1.011 | 0.986 | - | - | 1.007 | 1.099 | 0.987 | 0.937/0.991/1.003/1.017/-/1.002 | 1.011/0.986/- |
| A13 | L5-06-B (baseline then arm) | screen | 0.994 | 0.978 | 0.999 | 1.003 | 0.995 | - | - | 0.995 | 1.146 | 0.983 | 0.938/0.990/0.993/0.998/-/0.955 | 1.003/0.995/- |
| A13 | L5-08-B (arm then baseline) | screen | 0.990 | 0.982 | 0.996 | 0.986 | 1.006 | - | - | 0.998 | 1.064 | 1.004 | 0.944/0.997/0.993/0.982/-/0.933 | 0.986/1.006/- |

#### Screen verdicts

| Arm | Primary | Screen pair ratios | Gate | Verdict |
|---|---|---|---|---|
| A12 | `R128` (cnt128k prompt read) | 1.063, 1.061 | confirm (both >= 1.02) | confirm (confirmation batch still owed) |
| A13 | `D_win` | 1.006, 1.004 | no measurable effect (both within 0.98 to 1.02) | no measurable effect |

#### Baseline arms

| Baseline | D_win | D_real | P | R4 | R32 | R128 | R256 | F | T0 | T1 |
|---|---|---|---|---|---|---|---|---|---|---|
| L5-01-B | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | - | 1.000 | 1.000 | 1.000 |
| L5-03-B | 0.989 | 1.043 | 0.991 | 0.996 | 0.986 | 1.002 | - | 1.011 | 0.955 | 0.993 |
| L5-04-B | 0.982 | 1.030 | 0.992 | 0.998 | 0.986 | - | - | 0.956 | 0.898 | 0.989 |
| L5-06-B | 0.985 | 1.020 | 0.993 | 0.994 | 0.992 | - | - | 0.960 | 0.851 | 1.009 |
| L5-08-B | 0.988 | 1.016 | 0.996 | 1.011 | 0.982 | - | - | 0.957 | 0.916 | 0.988 |

#### Every run, compact

| Arm | tiny prompt ms x6 | tiny decode x6 | cnt1k dec r1/r2 | cnt4k dec r1/r2 | cnt32k dec r1/r2 | cnt4k read r1/r2 | cnt32k read r1/r2 | nat4k dec r1/r2 | samp4k dec 4242/4243/4244 | agent dec t1/t2 | agent prompt ms t1/t2 (reused) |
|---|---|---|---|---|---|---|---|---|---|---|---|
| L5-01-B | 207 151 107 127 147 118 | 74 96 100 105 122 96 | 130.9/172.0 | 173.9/173.1 | 166.0/165.2 | 1453/1456 | 2383/2358 | 91.3/109.0 | 93.9/106.1/100.7 | 110.9/96.3 | 11005/3123 (18763) |
| L5-02-A12 | 154 157 103 135 139 120 | 74 98 100 108 121 98 | 130.7/169.2 | 171.0/171.3 | 165.4/164.9 | 1474/1472 | 2411/2398 | 88.9/102.2 | 91.9/111.6/103.2 | 108.8/108.7 | 10801/3066 (18763) |
| L5-03-B | 196 154 133 103 162 108 | 75 96 99 103 121 98 | 131.8/169.0 | 170.5/170.6 | 164.2/164.9 | 1452/1450 | 2334/2324 | 90.0/112.1 | 101.9/111.4/106.9 | 108.8/109.3 | 11080/3089 (18763) |
| L5-04-B | 219 133 151 157 154 126 | 75 98 100 102 120 97 | 131.3/168.6 | 170.6/170.7 | 165.0/161.8 | 1446/1453 | 2334/2324 | 88.7/110.2 | 98.1/96.5/105.9 | 116.5/110.9 | 11122/3268 (18763) |
| L5-05-A13 | 203 172 120 160 133 111 | 69 89 97 98 116 93 | 120.2/167.8 | 170.9/171.6 | 162.0/164.6 | 1459/1465 | 2335/2307 | 88.0/112.4 | 99.6/113.7/110.9 | 102.5/104.6 | 11052/3231 (18763) |
| L5-06-B | 188 134 107 196 202 96 | 75 98 100 108 121 97 | 131.0/169.3 | 170.3/171.1 | 164.4/161.9 | 1451/1448 | 2337/2340 | 89.5/109.5 | 102.5/107.0/107.1 | 104.7/104.0 | 10907/3253 (18763) |
| L5-07-A13 | 185 160 149 128 132 123 | 68 90 96 98 116 95 | 120.2/167.6 | 170.0/169.9 | 163.9/161.6 | 1456/1452 | 2335/2329 | 81.9/110.4 | 97.5/102.1/105.2 | 106.1/106.8 | 11093/3270 (18763) |
| L5-08-B | 200 170 107 129 174 93 | 74 97 99 107 120 97 | 131.3/168.2 | 170.2/171.1 | 162.4/164.6 | 1474/1472 | 2340/2316 | 92.5/110.5 | 93.5/104.7/103.6 | 104.3/108.4 | 11134/3265 (18763) |

#### L5 reading (computed)

- **A12 (`STRATA_KV_PREFETCH=1`) confirms on the cnt128k prompt read at the screen**: 2,363.2 tok/s against 2,223.2 and
  2,227.0 (1.063 and 1.061), and the tier's wall time falls from 128.9 and 128.8 s to 122.4 s. The effect is where the
  switch can act: `R4` 1.010 and 1.015, `R32` 1.017 and 1.032 (at 32K the prompt is only just past the resident cells),
  `P` 1.014 and 1.023, `D_win` 0.991 and 1.002, `F` 1.019 and 1.008. `D_real` 1.009 and 0.967 is noise. This is the first
  arm whose primary needed suite C, and it behaves as SWITCHES.md predicted: nothing below 32K, +6% at 128K.
- **A13 (`--pcie-mode dma`) has no measurable effect on `D_win`** (1.006 and 1.004; reversed 0.994 and 0.990), and its
  secondaries are flat (`P` 1.000 / 0.999, `R4` 1.008 / 1.011, `R32` 0.993 / 0.986, `F` 1.011 / 1.007). Descriptive and
  consistent in both halves: tiny decode 0.944 and 0.937 (screen) and 0.938 and 0.944 (reversed), i.e. the copy engine's
  path costs about 6% on 64-token chats while the counting tiers do not move. Not gated (the primary is `D_win`), but
  recorded because it is the one consistent secondary reading of the batch.
- Both suites in one batch behaved as booked: a suite C arm costs 277 to 285 s, a suite S arm 154 to 155 s.
