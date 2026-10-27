# r7-pa-c1

- Job exit ?, restore exit ? (the lab wrapper stopped production, ran the job, restored production and verified it with a real completion).
- Runs in this directory: c1-01-A7, c1-02-B, c1-03-B, c1-04-A7.
- Runs of this batch not copied here (exact-class settings, or baselines paired only with them): c1-05-A18 (A18), c1-06-B (B), c1-07-B (B), c1-08-A18 (A18).
- Below: the batch's section from the round's `RESULTS.md`, verbatim except shortened paths. Paths such as `phase-a/raw/...` and `plans/...` refer to the lab workspace and are not part of this directory.

### r7-pa-c1 (confirmation of A7 `--spec 5` and A18 `--ple-io mmap`, suite C)

- Window: 2026-10-26T12:52:52+00:00 to 2026-10-26T13:31:28+00:00 UTC; job exit 0, restore exit 0 (state `r7-pa-c1`); elapsed in the job 2273.9 s.
- Production config sha256 before / after: `92c2f588c6bb7d02` / `92c2f588c6bb7d02`; exe `26da5a7e53bf79a1` / `26da5a7e53bf79a1`; production checks: PRODCHECK-PRE rc=0, PRODCHECK-POST rc=0, REALREQ-PRE rc=0, REALREQ-POST rc=0; GPU-POST 250 W.
- Pattern: per candidate `X B B X` (the parent's ON OFF OFF ON), suite C (suite S plus cnt128k, 2 runs, run 2 read) for all eight arms; no reversed half (these two pairs are the reversed half of the screen). Groups A7 (`c1-01` to `c1-04`) and A18 (`c1-05` to `c1-08`) both completed; no arm was skipped.
- Every arm: engine `/proc/<pid>/exe` and sha256 = deployed, `STRATA_*` environ = production env + the arm's switch (the A7 arms add none), config args block intact in the argv with extras `[exe, --serve]`; proof ok in all eight arms (`strata verify: window up to 7 tokens` in both A7 arms; `--ple-io mmap` in the argv of both A18 arms and neither direct-mode line printed).
- Harness: `r7suite.py` sha256 `eac3fd75...`, plan `plans/r7-pa-c1.json` sha256 `badaad55...`.
- Raw: `phase-a/raw/gpu/r7-pa-c1/` (arm.json, engine.log, server.log, bench JSON per arm; `analysis.md` holds every engine line). Keyscan before the copy: 100 files, 0 with the key.

#### Per arm (engine-measured; `R4`, `R32`, `R128` are the run-2 prompt read of cnt4k, cnt32k, cnt128k)

| Arm | Switch | Status | Proof | D_win | D_real | P | R4 | R32 | R128 | R256 | F | T0 | T1 | D_win tiers (tiny/1k/4k/32k/128k/nat4k) | free MiB | Cached GiB | s |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c1-01-A7 | A7 | ok | ok | 179.77 | 94.36 | 1841.0 | 1446.4 | 2343.4 | 2231.4 | - | 3100.0 | 137.5 | 11226.0 | 87.2/180.2/184.2/175.1/164.8/91.6 | 327 | 79.7 | 285 |
| c1-02-B | B | ok | ok | 168.33 | 102.88 | 1843.9 | 1453.8 | 2338.8 | 2230.0 | - | 3125.0 | 130.5 | 11144.0 | 96.3/168.6/171.0/165.4/158.3/96.0 | 379 | 79.7 | 284 |
| c1-03-B | B | ok | ok | 168.55 | 102.26 | 1838.0 | 1448.5 | 2332.2 | 2233.9 | - | 3108.0 | 151.0 | 11120.0 | 96.3/169.4/171.4/164.9/158.7/99.0 | 379 | 79.7 | 284 |
| c1-04-A7 | A7 | ok | ok | 177.64 | 97.05 | 1853.6 | 1473.8 | 2331.3 | 2225.5 | - | 3082.0 | 138.0 | 11107.0 | 84.6/177.3/181.6/174.1/167.9/94.2 | 327 | 79.7 | 286 |
| c1-05-A18 | A18 | ok | ok | 167.93 | 105.55 | 1845.0 | 1455.9 | 2338.1 | 2224.2 | - | 2980.0 | 109.5 | 10404.0 | 96.9/168.0/171.2/164.6/160.6/104.6 | 379 | 79.7 | 281 |
| c1-06-B | B | ok | ok | 168.04 | 104.77 | 1837.5 | 1450.1 | 2328.5 | 2212.9 | - | 3090.0 | 137.5 | 11069.0 | 95.4/168.6/170.9/164.6/160.6/100.9 | 379 | 79.7 | 285 |
| c1-07-B | B | ok | ok | 168.08 | 103.48 | 1852.8 | 1477.6 | 2323.3 | 2217.9 | - | 3116.0 | 157.0 | 11088.0 | 96.7/169.4/170.9/164.0/158.3/97.4 | 379 | 79.7 | 285 |
| c1-08-A18 | A18 | ok | ok | 167.97 | 102.13 | 1850.1 | 1476.0 | 2319.1 | 2208.7 | - | 2988.0 | 114.0 | 10459.0 | 100.6/168.8/171.0/164.2/160.0/97.9 | 379 | 79.7 | 284 |

#### Pair ratios (the two confirmation pairs per candidate; arm / baseline for the D and R metrics, baseline / arm for F, T0, T1)

| Arm | Pair | Phase | D_win | D_real | P | R4 | R32 | R128 | R256 | F | T0 | T1 | tier dec (tiny/1k/4k/32k/128k/nat4k) | tier read (4k/32k/128k) |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| A7 | c1-02-B (arm then baseline) | screen | 1.068 | 0.917 | 0.998 | 0.995 | 1.002 | 1.001 | - | 1.008 | 0.949 | 0.993 | 0.906/1.068/1.077/1.059/1.041/0.954 | 0.995/1.002/1.001 |
| A7 | c1-03-B (baseline then arm) | screen | 1.054 | 0.949 | 1.009 | 1.017 | 1.000 | 0.996 | - | 1.008 | 1.094 | 1.001 | 0.878/1.046/1.060/1.056/1.058/0.951 | 1.017/1.000/0.996 |
| A18 | c1-06-B (arm then baseline) | screen | 0.999 | 1.007 | 1.004 | 1.004 | 1.004 | 1.005 | - | 1.037 | 1.256 | 1.064 | 1.016/0.996/1.002/1.000/1.000/1.036 | 1.004/1.004/1.005 |
| A18 | c1-07-B (baseline then arm) | screen | 0.999 | 0.987 | 0.999 | 0.999 | 0.998 | 0.996 | - | 1.043 | 1.377 | 1.060 | 1.040/0.996/1.001/1.001/1.011/1.004 | 0.999/0.998/0.996 |

#### Confirmation gate (four pairs per candidate: the two screen pairs of L3 / L7 and these two)

| Candidate | Primary | 4 pair ratios | Median | Bootstrap 95% (20,000, seed 20261026) | Gate |
|---|---|---|---|---|---|
| A7 | `D_win` | 1.056, 1.057, 1.068, 1.054 | 1.0565 | 1.0539 to 1.0680 | median >= 1.02 and interval above 1.0 |
| A7 | `D_real` | 1.003, 1.003, 0.917, 0.949 | 0.9759 | 0.9172 to 1.0034 | does not confirm |
| A18 | `T1` | 1.075, 1.059, 1.064, 1.060 | 1.0620 | 1.0588 to 1.0747 | median >= 1.02 and interval above 1.0 |
| A18 | `F` | 0.992, 0.970, 1.037, 1.043 | 1.0143 | 0.9697 to 1.0428 | does not confirm (median below 1.02) |

| Candidate | Greedy tier median pair ratios (tiny / cnt1k / cnt4k / cnt32k / cnt128k / nat4k decode) | Below 0.98 | Verdict |
|---|---|---|---|
| A7 | 0.8661 / 1.0459 / 1.0599 / 1.0627 / 1.0495 / 0.9646 | tiny, nat4k | **not confirmed** (the tier rule fails, though `D_win` passes on its own numbers) |
| A18 | 1.0454 / 0.9964 / 1.0020 / 1.0006 / 1.0053 / 0.9977 | none | **confirmed on `T1`** |

#### Baseline arms (noise reference: each baseline / the first baseline)

| Baseline | D_win | D_real | P | R4 | R32 | R128 | R256 | F | T0 | T1 |
|---|---|---|---|---|---|---|---|---|---|---|
| c1-02-B | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | - | 1.000 | 1.000 | 1.000 |
| c1-03-B | 1.001 | 0.994 | 0.997 | 0.996 | 0.997 | 1.002 | - | 1.005 | 0.864 | 1.002 |
| c1-06-B | 0.998 | 1.018 | 0.997 | 0.997 | 0.996 | 0.992 | - | 1.011 | 0.949 | 1.007 |
| c1-07-B | 0.999 | 1.006 | 1.005 | 1.016 | 0.993 | 0.995 | - | 1.003 | 0.831 | 1.005 |

#### Every run, compact (engine lines; decode tok/s per run)

| Arm | tiny prompt ms x6 | tiny decode x6 | cnt1k dec r1/r2 | cnt4k dec r1/r2 | cnt32k dec r1/r2 | cnt4k read r1/r2 | cnt32k read r1/r2 | nat4k dec r1/r2 | samp4k dec 4242/4243/4244 | agent dec t1/t2 | agent prompt ms t1/t2 (reused) |
|---|---|---|---|---|---|---|---|---|---|---|---|
| c1-01-A7 | 189 139 108 159 136 111 | 67 90 91 104 102 85 | 130.5/180.2 | 183.8/184.1 | 171.9/175.1 | 1441/1446 | 2371/2343 | 86.5/97.3 | 96.5/97.3/106.9 | 99.1/87.1 | 11226/3100 (18763) |
| c1-02-B | 217 139 122 112 162 98 | 74 96 99 106 119 97 | 128.9/168.6 | 171.0/171.0 | 165.2/165.3 | 1447/1454 | 2336/2339 | 93.7/98.4 | 94.5/107.2/110.9 | 106.0/114.1 | 11144/3125 (18763) |
| c1-03-B | 200 139 107 196 163 95 | 74 97 99 104 121 96 | 130.5/169.4 | 170.3/171.4 | 164.2/164.9 | 1447/1448 | 2345/2332 | 92.2/106.9 | 98.5/93.2/110.2 | 111.4/104.5 | 11120/3108 (18763) |
| c1-04-A7 | 192 138 107 138 151 125 | 67 87 87 100 95 82 | 130.2/177.3 | 181.8/181.6 | 171.2/174.1 | 1475/1474 | 2335/2331 | 83.1/108.6 | 101.1/96.8/111.1 | 99.4/90.1 | 11107/3082 (18763) |
| c1-05-A18 | 170 149 100 99 119 86 | 74 98 104 100 112 105 | 130.9/167.9 | 170.1/171.2 | 164.7/164.7 | 1455/1456 | 2345/2338 | 94.5/117.0 | 104.6/106.2/100.2 | 106.5/112.8 | 10404/2980 (18763) |
| c1-06-B | 180 135 105 140 145 132 | 72 95 97 105 122 97 | 130.6/168.6 | 170.5/170.9 | 164.6/164.6 | 1443/1450 | 2331/2328 | 94.1/108.8 | 105.4/101.9/106.9 | 106.0/111.8 | 11069/3090 (18763) |
| c1-07-B | 193 162 127 152 178 121 | 74 97 99 106 121 97 | 130.5/169.5 | 170.4/170.9 | 164.4/164.0 | 1474/1478 | 2322/2323 | 89.9/106.5 | 101.2/100.8/113.6 | 114.7/102.9 | 11088/3116 (18763) |
| c1-08-A18 | 160 136 109 107 119 103 | 77 101 103 111 127 100 | 132.3/168.7 | 170.5/171.0 | 164.3/164.2 | 1474/1476 | 2326/2319 | 91.0/105.9 | 104.6/105.7/108.3 | 113.1/93.7 | 10459/2988 (18763) |

#### c1 reading (computed)

- **A7 (`--spec 5`) is rejected by the greedy tier rule, not by its primary.** `D_win` gives 1.068 and 1.054 in the
  confirmation pairs (median over four 1.0565, bootstrap 1.0539 to 1.0680), and every counting tier moves with it
  (cnt1k 1.046, cnt4k 1.060, cnt32k 1.063, and even cnt128k 1.050). But the two greedy tiers that carry real text fall
  below the gate's 0.98 floor: tiny decode 0.8661 (87.2 and 84.6 tok/s against 96.3 / 96.3 / 96.3 / 96.7 in its
  baselines) and nat4k decode 0.9646 (86.5 / 97.3 and 83.1 / 108.6 against 93.7 / 98.4 and 92.2 / 106.9). Its `D_real`
  median is 0.9759 (0.917 and 0.949 in these pairs). So the wider window pays only where every drafted token is accepted
  (the counting tiers, 204 of 204 drafts); on natural text, where acceptance is 1.8 to 2.7 tokens per window, the extra
  GPU rows per verified token cost more than the window saves. This is the effect the round's suite was reshaped to see,
  and it is why the screen's +5.6% on `D_win` does not survive the confirm gate.
- **A18 (`--ple-io mmap`) is confirmed on `T1`.** The agent's fresh 18.8K read runs 10,404 and 10,459 ms against 11,069
  and 11,088 ms in the adjacent baselines (1.064 and 1.060; screen pairs 1.075 and 1.059), median 1.0620 with a bootstrap
  interval of 1.0588 to 1.0747 clear of 1.0, and no greedy tier median below 0.98 (0.9964 to 1.0454). `F` reads 1.037 and
  1.043 in the confirmation pairs; the two screen `F` pairs (0.992, 0.970) were taken with the old label bug, and the
  four-pair `F` median (1.0143) therefore misses the 1.02 bar. The primary that decides the arm is `T1`, and it holds.
- **What else moved for A18** (descriptive, not gated): `D_real` 1.007 and 0.987 (median 0.997), `D_win` 0.999 and 0.999,
  `P` 1.004 and 0.999, `R4` 1.004 / 0.999, `R32` 1.004 / 0.998, `R128` 1.005 / 0.996, `T0` 1.256 and 1.377 (tiny first
  token 109.5 and 114.0 ms against 137.5 and 157.0 ms), tiny decode 1.016 and 1.040. Free VRAM at ready 379 MiB, as for
  every non-spec arm; expert slots 10320.
- **Warm page cache, stated plainly.** Every c1 arm started with `Cached` 79.7 GiB and MemAvailable 100.6 to 100.7 GiB, and
  the six arms that read the table in `direct` mode probed 51,281 to 68,074 rows/s, inside the 44K to 67K rows/s the
  profile recorded for the cold table. A17's pre-fault in L7 and A18's own reads leave the 28.8 GB table's pages in the
  guest's page cache, and there is no root here to drop them, so this batch measured `mmap` **warm**. The cold-from-disk
  case is unmeasured; the guest's Cached figure and the direct-probe rates are the only evidence about the table's state,
  because `mmap` mode prints no load-time line of its own.
- **The label fix works.** Every arm in this batch parked the same 18,763-token conversation (reused count identical in all
  eight arms) and the follow-up's prompt ms no longer separates switch arms from baselines (3,082 to 3,125 ms across both
  classes, against 3,184 to 3,273 for the switch arms of L1 and L2). `F` ratios from this batch onward are therefore valid
  evidence about a switch, unlike L1, L7, L2 and L3.
