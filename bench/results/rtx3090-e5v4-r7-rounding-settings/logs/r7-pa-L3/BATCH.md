# r7-pa-L3

- Job exit 0, restore exit 0 (the lab wrapper stopped production, ran the job, restored production and verified it with a real completion).
- Runs in this directory: L3-01-B, L3-02-A7, L3-03-B, L3-04-A8, L3-05-B, L3-06-A9, L3-07-B, L3-08-A9, L3-09-B, L3-10-A8, L3-11-B, L3-12-A7, L3-13-B.
- Every run of this batch is copied here.
- Below: the batch's section from the round's `RESULTS.md`, verbatim except shortened paths. Paths such as `phase-a/raw/...` and `plans/...` refer to the lab workspace and are not part of this directory.

### r7-pa-L3

- Window: 2026-10-26T12:06:03+00:00 to 2026-10-26T12:40:15+00:00 UTC; job exit 0, restore exit 0; elapsed in the job 2011.9 s.
- Production config sha256 before / after: `92c2f588c6bb7d02` / `92c2f588c6bb7d02`; exe `26da5a7e53bf79a1` / `26da5a7e53bf79a1`; production checks before and after: PRODCHECK-POST rc=0; PRODCHECK-PRE rc=0; REALREQ-POST rc=0; REALREQ-PRE rc=0.
- Reversed half: run (slowest arm 156.8 s, needed 1095 s, left 2366 s).
- Every arm: engine `/proc` exe and sha256 = deployed, `STRATA_*` environ = production env + the switch, config args block intact in the argv with extras `[exe, --serve]` (asserted at start; `provenance.json` per arm).
- Raw: `phase-a/raw/gpu/r7-pa-L3/` (arm.json, engine.log, server.log, bench JSON per arm; `analysis.md` has every engine line).

#### Per arm (raw readings, computed by analyse.py)

| Arm | Switch | Status | Proof | D_win | D_real | P | F | T0 | T1 | tiny | cnt1k | cnt4k | cnt32k | nat4k | samp4k | agent | free MiB at ready | MemAvail GiB ready / min | s |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| L3-01-B | B | ok | ok | 167.76 | 99.36 | 1836.4 | 3066 | 144.5 | 11094 | 92.2 | 170.4 | 172.3 | 160.8 | 98.1 | 100.7 | 99.3 | 379 | 100.7 / - | 154 |
| L3-02-A7 | A7 | ok | ok | 177.11 | 99.70 | 1839.8 | 3245 | 155.5 | 11009 | 78.8 | 176.4 | 181.3 | 173.7 | 95.7 | 97.8 | 105.9 | 327 | 100.2 / - | 157 |
| L3-03-B | B | ok | ok | 167.50 | 99.41 | 1838.7 | 3041 | 150.5 | 10878 | 95.3 | 168.8 | 171.0 | 162.8 | 97.0 | 101.9 | 99.4 | 379 | 100.6 / - | 155 |
| L3-04-A8 | A8 | ok | ok | 185.78 | 96.83 | 1840.7 | 3307 | 148.5 | 11112 | 84.7 | 182.3 | 192.0 | 183.1 | 93.0 | 101.7 | 96.0 | 345 | 100.7 / - | 157 |
| L3-05-B | B | ok | ok | 167.65 | 104.07 | 1836.1 | 3046 | 148.5 | 10924 | 96.1 | 169.8 | 170.7 | 162.6 | 100.5 | 102.0 | 109.9 | 379 | 100.6 / - | 154 |
| L3-06-A9 | A9 | ok | ok | 171.26 | 103.67 | 1848.9 | 3246 | 140.5 | 11083 | 95.1 | 172.2 | 174.3 | 167.4 | 99.6 | 103.1 | 108.4 | 377 | 100.7 / - | 153 |
| L3-07-B | B | ok | ok | 168.18 | 103.03 | 1836.6 | 3069 | 151.0 | 11072 | 96.9 | 168.6 | 170.7 | 165.3 | 99.7 | 102.9 | 106.6 | 379 | 100.6 / - | 154 |
| L3-08-A9 | A9 | ok | ok | 171.75 | 103.18 | 1847.1 | 3255 | 150.0 | 11121 | 96.6 | 171.9 | 174.7 | 168.6 | 99.9 | 101.9 | 107.9 | 377 | 100.7 / - | 153 |
| L3-09-B | B | ok | ok | 167.47 | 104.41 | 1834.4 | 3060 | 136.5 | 11136 | 96.3 | 169.2 | 170.9 | 162.4 | 98.9 | 104.9 | 109.7 | 379 | 100.7 / - | 154 |
| L3-10-A8 | A8 | ok | ok | 184.35 | 101.22 | 1841.1 | 3262 | 150.0 | 11069 | 84.7 | 182.3 | 192.3 | 178.6 | 93.6 | 105.0 | 105.6 | 345 | 100.7 / - | 154 |
| L3-11-B | B | ok | ok | 168.04 | 102.97 | 1838.2 | 3019 | 159.0 | 11149 | 96.5 | 168.9 | 171.0 | 164.3 | 103.0 | 102.6 | 103.2 | 379 | 100.7 / - | 155 |
| L3-12-A7 | A7 | ok | ok | 178.05 | 95.97 | 1837.4 | 3266 | 129.0 | 10903 | 84.7 | 178.1 | 181.4 | 174.6 | 98.5 | 94.5 | 95.0 | 327 | 100.6 / - | 156 |
| L3-13-B | B | ok | ok | 167.89 | 101.86 | 1830.0 | 3055 | 147.5 | 11040 | 95.4 | 168.6 | 170.9 | 164.2 | 103.1 | 102.2 | 100.3 | 379 | 100.7 / - | 154 |

#### Pair ratios

| Arm | Pair | D_win | D_real | P | F | T0 | T1 |
|---|---|---|---|---|---|---|---|
| A7 (L3-02-A7) | first B before (L3-01-B) | 1.056 | 1.003 | 1.002 | 0.945 | 0.929 | 1.008 |
| A7 (L3-02-A7) | first B after (L3-03-B) | 1.057 | 1.003 | 1.001 | 0.937 | 0.968 | 0.988 |
| A8 (L3-04-A8) | first B before (L3-03-B) | 1.109 | 0.974 | 1.001 | 0.920 | 1.013 | 0.979 |
| A8 (L3-04-A8) | first B after (L3-05-B) | 1.108 | 0.930 | 1.003 | 0.921 | 1.000 | 0.983 |
| A9 (L3-06-A9) | first B before (L3-05-B) | 1.022 | 0.996 | 1.007 | 0.938 | 1.057 | 0.986 |
| A9 (L3-06-A9) | first B after (L3-07-B) | 1.018 | 1.006 | 1.007 | 0.945 | 1.075 | 0.999 |
| A9 (L3-08-A9) | reversed B before (L3-07-B) | 1.021 | 1.001 | 1.006 | 0.943 | 1.007 | 0.996 |
| A9 (L3-08-A9) | reversed B after (L3-09-B) | 1.026 | 0.988 | 1.007 | 0.940 | 0.910 | 1.001 |
| A8 (L3-10-A8) | reversed B before (L3-09-B) | 1.101 | 0.969 | 1.004 | 0.938 | 0.910 | 1.006 |
| A8 (L3-10-A8) | reversed B after (L3-11-B) | 1.097 | 0.983 | 1.002 | 0.926 | 1.060 | 1.007 |
| A7 (L3-12-A7) | reversed B before (L3-11-B) | 1.060 | 0.932 | 1.000 | 0.924 | 1.233 | 1.023 |
| A7 (L3-12-A7) | reversed B after (L3-13-B) | 1.060 | 0.942 | 1.004 | 0.935 | 1.143 | 1.013 |

#### Screen verdicts

| Arm | Primary | Pair ratios | Gate | Proof | Verdict |
|---|---|---|---|---|---|
| A7 | D_real | 1.003, 1.003 | no measurable effect | ok | confirm |
| A7 | D_win | 1.056, 1.057 | confirm | ok | confirm |
| A8 | D_real | 0.974, 0.930 | confirm (literal "otherwise"; both pairs below 0.98) | ok | confirm |
| A8 | D_win | 1.109, 1.108 | confirm | ok | confirm |
| A9 | D_real | 0.996, 1.006 | no measurable effect | ok | no measurable effect |

#### Baseline arms (noise reference)

| Baseline | D_win | D_real | P | F | T0 | T1 |
|---|---|---|---|---|---|---|
| L3-01-B | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 |
| L3-03-B | 0.998 | 1.001 | 1.001 | 1.008 | 0.960 | 1.020 |
| L3-05-B | 0.999 | 1.047 | 1.000 | 1.007 | 0.973 | 1.016 |
| L3-07-B | 1.002 | 1.037 | 1.000 | 0.999 | 0.957 | 1.002 |
| L3-09-B | 0.998 | 1.051 | 0.999 | 1.002 | 1.059 | 0.996 |
| L3-11-B | 1.002 | 1.036 | 1.001 | 1.016 | 0.909 | 0.995 |
| L3-13-B | 1.001 | 1.025 | 0.997 | 1.004 | 0.980 | 1.005 |

#### Every run, every tier

| Arm | tiny prompt ms x6 | tiny decode x6 | cnt1k dec r1/r2 | cnt4k dec r1/r2 | cnt32k dec r1/r2 | cnt4k read tok/s r1/r2 | cnt32k read tok/s r1/r2 | nat4k dec r1/r2 | samp4k dec 4242/4243/4244 | agent dec t1/t2 | agent prompt ms t1/t2 (reused t2) |
|---|---|---|---|---|---|---|---|---|---|---|---|
| L3-01-B | 188 181 121 105 168 91 | 71 93 99 95 105 100 | 132.2/170.4 | 171.8/172.3 | 165.1/160.8 | 1446/1451 | 2351/2324 | 92.7/104.1 | 105.1/103.8/93.8 | 100.7/97.1 | 11094/3066 (18763) |
| L3-02-A7 | 212 157 162 126 154 131 | 63 73 84 95 95 77 | 129.3/176.4 | 180.5/181.2 | 173.8/173.7 | 1462/1460 | 2337/2319 | 86.1/107.7 | 93.3/106.7/94.5 | 101.7/111.2 | 11009/3245 (18763) |
| L3-03-B | 197 184 120 104 181 112 | 74 95 97 106 117 96 | 130.4/168.8 | 171.2/171.0 | 164.4/162.8 | 1453/1452 | 2332/2328 | 90.3/104.7 | 99.5/104.3/102.1 | 102.4/96.3 | 10878/3041 (18763) |
| L3-04-A8 | 215 175 148 149 143 95 | 68 92 85 94 96 84 | 129.8/182.3 | 190.1/192.0 | 178.0/183.2 | 1462/1462 | 2320/2317 | 82.0/107.4 | 101.0/104.9/99.4 | 89.6/103.3 | 11112/3307 (18763) |
| L3-05-B | 211 163 115 149 148 113 | 75 97 99 102 120 96 | 131.7/169.7 | 170.5/170.7 | 164.8/162.7 | 1449/1453 | 2340/2321 | 88.9/115.6 | 101.9/104.1/100.2 | 108.8/111.6 | 10924/3046 (18763) |
| L3-06-A9 | 184 193 105 153 128 124 | 74 87 99 106 126 97 | 130.6/172.2 | 173.5/174.3 | 165.6/167.5 | 1473/1474 | 2336/2319 | 89.0/113.1 | 99.3/106.3/104.0 | 111.6/103.4 | 11083/3246 (18763) |
| L3-07-B | 211 168 159 143 125 92 | 74 98 99 105 121 97 | 132.6/168.7 | 170.9/170.7 | 162.0/165.3 | 1447/1450 | 2334/2326 | 91.3/109.8 | 110.8/94.6/104.7 | 108.6/103.9 | 11072/3069 (18763) |
| L3-08-A9 | 211 156 143 161 144 132 | 74 88 101 107 128 101 | 130.9/171.9 | 174.2/174.7 | 165.7/168.7 | 1471/1471 | 2333/2319 | 91.3/110.2 | 101.0/96.3/109.3 | 109.3/105.9 | 11121/3255 (18763) |
| L3-09-B | 183 177 132 104 141 120 | 75 98 97 106 120 96 | 131.0/169.3 | 170.1/170.9 | 162.2/162.4 | 1447/1446 | 2344/2327 | 90.8/108.5 | 102.7/105.8/106.4 | 106.4/113.1 | 11136/3060 (18763) |
| L3-10-A8 | 261 169 150 150 119 119 | 67 91 83 91 96 89 | 130.0/182.4 | 189.9/192.4 | 183.0/178.7 | 1467/1463 | 2323/2317 | 83.5/106.4 | 98.5/116.5/101.7 | 106.0/104.8 | 11069/3262 (18763) |
| L3-11-B | 218 172 149 157 161 120 | 75 97 98 106 120 97 | 130.9/168.8 | 170.4/171.0 | 164.9/164.3 | 1446/1447 | 2333/2335 | 93.5/114.7 | 92.9/103.7/113.3 | 104.5/101.9 | 11149/3019 (18763) |
| L3-12-A7 | 156 146 105 155 112 94 | 67 86 90 95 98 82 | 129.7/178.2 | 181.5/181.4 | 174.0/174.6 | 1462/1460 | 2335/2312 | 89.5/109.4 | 91.2/93.1/99.7 | 99.2/90.3 | 10903/3266 (18763) |
| L3-13-B | 204 171 137 158 125 112 | 73 96 97 103 122 96 | 131.8/168.7 | 169.1/170.9 | 164.0/164.2 | 1446/1443 | 2342/2321 | 94.9/112.8 | 101.5/98.6/106.9 | 101.4/99.0 | 11040/3055 (18763) |

#### L3 reading (computed)

- A7 (`--spec 5`): `D_win` 1.056 and 1.057 (cnt1k 176.4 against 168.8 to 170.4, cnt4k 181.3 against 171.0, cnt32k 173.7
  against 160.8 to 162.8), reversed half 1.060, 1.060; `D_real` 1.003 and 1.003 (reversed 0.932, 0.942). Proof `window
  up to 7 tokens`; free VRAM at ready 327 MiB against 379 in the baselines (the wider window's buffers), no out-of-memory
  line. A7 confirms on `D_win`.
- A8 (`--spec 6`): `D_win` 1.109 and 1.108 (cnt1k 182.3, cnt4k 192.0 to 192.3, cnt32k 178.6 to 183.1), reversed 1.101,
  1.097; `D_real` 0.974 and 0.930, reversed 0.969, 0.983: **every pair below 1, two of the first-half pairs below 0.98**.
  The nat4k decode fell from about 99.5 to 93.0 / 93.6 tok/s and the tiny chats from 92 to 96 down to 84.7 (the wider
  window costs GPU time per row on real text, a window-shape effect, inferred). Proof `window up to 8 tokens`, free VRAM
  345 MiB. The literal gate reads "confirm" on `D_win` (1.108) and "confirm (literal 'otherwise'; both pairs below 0.98)"
  on `D_real`; it confirms on `D_win` and its `D_real` regression is flagged for the parent, not hidden by the rule. Only
  the counting tiers gain.
- A9 (`--mtp-draft-vocab ... --mtp-q4 head`): `D_real` 0.996 and 1.006 (reversed 1.001, 0.988) -> no measurable effect
  under the literal gate; `D_win` 1.022 and 1.018 (reversed 1.021, 1.026), i.e. +2% on the counting tiers from the
  smaller draft head, not a primary. Baseline `D_real` drifted 0.949 to 1.051 against L3-01 across the batch (samp4k and
  agent text differ per process), so a 0.996/1.006 pair on `D_real` is inside this batch's baseline spread. Proof: both
  `draft head over 40525 tokens` and `--mtp-q4: draft head over 40525 tokens as Q4_0`.
- `F` is confounded for every X arm as in L1 and L2 (the harness bug above).
