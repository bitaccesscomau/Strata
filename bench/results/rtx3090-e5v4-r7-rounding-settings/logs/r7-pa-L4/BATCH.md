# r7-pa-L4

- Job exit ?, restore exit ? (the lab wrapper stopped production, ran the job, restored production and verified it with a real completion).
- Runs in this directory: L4-01-B, L4-02-A10, L4-03-B, L4-04-A11, L4-05-B, L4-06-A11, L4-07-B, L4-08-A10, L4-09-B.
- Every run of this batch is copied here.
- Below: the batch's section from the round's `RESULTS.md`, verbatim except shortened paths. Paths such as `phase-a/raw/...` and `plans/...` refer to the lab workspace and are not part of this directory.

### r7-pa-L4 (screen: A10 coupled draft sampling, A11 CPU share limit 3072, suite S)

- Window: 2026-10-26T14:09:11+00:00 to 2026-10-26T14:32:44+00:00 UTC; job exit 0, restore exit 0 (state `r7-pa-L4`); elapsed in the job 1371.6 s.
- Production config sha256 before / after: `92c2f588c6bb7d02` / `92c2f588c6bb7d02`; exe `26da5a7e53bf79a1` / `26da5a7e53bf79a1`; PRODCHECK-PRE / POST rc=0, REALREQ-PRE / POST rc=0.
- Pattern: `B A10 B A11 B`, then the reversed half `A11 B A10 B` (slowest arm 155.5 s, needed 744 s, 2,686 s left: run). Nine arms, none skipped.
- Proof: A10 prints `strata mtp: coupled draft sampling on (STRATA_SPEC_COUPLED): sampled requests draft with the target's chain and Philox draw over 106299 tokens` in both its arms and in neither baseline. A11 has no positive line; its proof is that the default notice (`prefill: the CPU share is ON by default for prompt chunks below 1024 tokens`) appears 7 times in the batch, in the seven baseline and A10 arms, and never in the two A11 arms, whose environ holds `STRATA_PREFILL_CPU_SHARE=auto` and `STRATA_PREFILL_CPU_SHARE_MAX=3072`. Free VRAM 383 MiB in the A10 arms (the coupled sampler's buffers) against 379 in the baselines.
- Harness: `r7suite.py` sha256 `eac3fd75...`, plan `plans/r7-pa-L4.json` sha256 `94cc15e0...`.
- Raw: `phase-a/raw/gpu/r7-pa-L4/`. Keyscan: 94 files, 0 with the key.

#### Per arm

| Arm | Switch | Status | Proof | D_win | D_real | P | R4 | R32 | R128 | R256 | F | T0 | T1 | D_win tiers (tiny/1k/4k/32k/128k/nat4k) | free MiB | Cached GiB | s |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| L4-01-B | B | ok | ok | 169.42 | 100.86 | 1861.9 | 1482.0 | 2339.0 | - | - | 3276.0 | 145.0 | 11030.0 | 96.0/170.6/172.7/165.1/-/97.9 | 379 | 79.8 | 154 |
| L4-02-A10 | A10 | ok | ok | 167.63 | 104.95 | 1840.2 | 1448.5 | 2338.0 | - | - | 3004.0 | 149.5 | 10955.0 | 95.6/168.1/170.4/164.4/-/100.3 | 383 | 79.8 | 154 |
| L4-03-B | B | ok | ok | 168.34 | 101.93 | 1832.1 | 1447.9 | 2318.2 | - | - | 3255.0 | 147.0 | 11164.0 | 95.9/169.2/171.5/164.4/-/97.1 | 379 | 79.8 | 155 |
| L4-04-A11 | A11 | ok | ok | 167.85 | 103.00 | 1830.0 | 1445.3 | 2317.0 | - | - | 2221.0 | 132.0 | 10231.0 | 97.0/168.9/170.3/164.4/-/101.2 | 379 | 79.8 | 145 |
| L4-05-B | B | ok | ok | 168.21 | 101.29 | 1836.6 | 1457.0 | 2315.0 | - | - | 3267.0 | 145.5 | 11115.0 | 95.2/169.1/170.4/165.2/-/95.6 | 379 | 79.8 | 156 |
| L4-06-A11 | A11 | ok | ok | 167.78 | 105.97 | 1839.3 | 1452.7 | 2328.8 | - | - | 2171.0 | 154.5 | 10277.0 | 96.6/168.3/170.8/164.3/-/101.8 | 379 | 79.8 | 145 |
| L4-07-B | B | ok | ok | 167.04 | 100.68 | 1836.0 | 1449.5 | 2325.4 | - | - | 3206.0 | 163.5 | 11176.0 | 95.7/168.1/171.6/161.6/-/99.1 | 379 | 79.8 | 156 |
| L4-08-A10 | A10 | ok | ok | 167.92 | 104.69 | 1858.2 | 1480.4 | 2332.4 | - | - | 3051.0 | 144.0 | 10925.0 | 96.0/168.6/170.4/164.7/-/101.7 | 383 | 79.8 | 154 |
| L4-09-B | B | ok | ok | 168.29 | 105.21 | 1832.8 | 1447.4 | 2320.7 | - | - | 3255.0 | 144.5 | 10984.0 | 95.8/168.9/171.2/164.8/-/104.0 | 379 | 79.8 | 153 |

#### Pair ratios (first two pairs per arm are the screen; the last four are the reversed half, descriptive)

| Arm | Pair | Phase | D_win | D_real | P | R4 | R32 | R128 | R256 | F | T0 | T1 | tier dec (tiny/1k/4k/32k/128k/nat4k) | tier read (4k/32k/128k) |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| A10 | L4-01-B (baseline then arm) | screen | 0.989 | 1.041 | 0.988 | 0.977 | 1.000 | - | - | 1.091 | 0.970 | 1.007 | 0.996/0.986/0.987/0.996/-/1.024 | 0.977/1.000/- |
| A10 | L4-03-B (arm then baseline) | screen | 0.996 | 1.030 | 1.004 | 1.000 | 1.009 | - | - | 1.084 | 0.983 | 1.019 | 0.997/0.993/0.994/1.000/-/1.033 | 1.000/1.009/- |
| A11 | L4-03-B (baseline then arm) | screen | 0.997 | 1.011 | 0.999 | 0.998 | 0.999 | - | - | 1.466 | 1.114 | 1.091 | 1.012/0.998/0.993/1.000/-/1.042 | 0.998/0.999/- |
| A11 | L4-05-B (arm then baseline) | screen | 0.998 | 1.017 | 0.996 | 0.992 | 1.001 | - | - | 1.471 | 1.102 | 1.086 | 1.019/0.999/0.999/0.996/-/1.058 | 0.992/1.001/- |
| A11 | L4-05-B (baseline then arm) | screen | 0.997 | 1.046 | 1.001 | 0.997 | 1.006 | - | - | 1.505 | 0.942 | 1.082 | 1.014/0.995/1.002/0.995/-/1.065 | 0.997/1.006/- |
| A11 | L4-07-B (arm then baseline) | screen | 1.004 | 1.053 | 1.002 | 1.002 | 1.001 | - | - | 1.477 | 1.058 | 1.087 | 1.009/1.001/0.995/1.017/-/1.028 | 1.002/1.001/- |
| A10 | L4-07-B (baseline then arm) | screen | 1.005 | 1.040 | 1.012 | 1.021 | 1.003 | - | - | 1.051 | 1.135 | 1.023 | 1.003/1.003/0.993/1.019/-/1.027 | 1.021/1.003/- |
| A10 | L4-09-B (arm then baseline) | screen | 0.998 | 0.995 | 1.014 | 1.023 | 1.005 | - | - | 1.067 | 1.003 | 1.005 | 1.002/0.999/0.995/0.999/-/0.978 | 1.023/1.005/- |

#### Screen verdicts

| Arm | Primary | Screen pair ratios | Gate | Verdict |
|---|---|---|---|---|
| A10 | `D_real` | 1.041, 1.030 | confirm (both >= 1.02) | confirm (confirmation batch still owed) |
| A11 | `F` | 1.466, 1.471 | confirm (both >= 1.02) | confirm (confirmation batch still owed) |
| A11 | `P` | 0.999, 0.996 | no measurable effect (both within 0.98 to 1.02) | reported, not gated |

#### Baseline arms

| Baseline | D_win | D_real | P | R4 | R32 | R128 | R256 | F | T0 | T1 |
|---|---|---|---|---|---|---|---|---|---|---|
| L4-01-B | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | - | - | 1.000 | 1.000 | 1.000 |
| L4-03-B | 0.994 | 1.011 | 0.984 | 0.977 | 0.991 | - | - | 1.006 | 0.986 | 0.988 |
| L4-05-B | 0.993 | 1.004 | 0.986 | 0.983 | 0.990 | - | - | 1.003 | 0.997 | 0.992 |
| L4-07-B | 0.986 | 0.998 | 0.986 | 0.978 | 0.994 | - | - | 1.022 | 0.887 | 0.987 |
| L4-09-B | 0.993 | 1.043 | 0.984 | 0.977 | 0.992 | - | - | 1.006 | 1.003 | 1.004 |

#### Every run, compact

| Arm | tiny prompt ms x6 | tiny decode x6 | cnt1k dec r1/r2 | cnt4k dec r1/r2 | cnt32k dec r1/r2 | cnt4k read r1/r2 | cnt32k read r1/r2 | nat4k dec r1/r2 | samp4k dec 4242/4243/4244 | agent dec t1/t2 | agent prompt ms t1/t2 (reused) |
|---|---|---|---|---|---|---|---|---|---|---|---|
| L4-01-B | 156 144 102 146 167 112 | 74 97 98 107 116 97 | 130.8/170.5 | 172.0/172.8 | 162.9/165.0 | 1479/1482 | 2353/2339 | 91.0/106.0 | 103.2/102.8/109.6 | 102.7/95.8 | 11030/3276 (18763) |
| L4-02-A10 | 208 137 148 155 151 114 | 74 96 96 104 120 96 | 129.5/168.0 | 170.2/170.5 | 163.3/164.4 | 1450/1448 | 2341/2338 | 92.7/109.4 | 100.5/115.0/108.9 | 105.8/108.0 | 10955/3004 (18763) |
| L4-03-B | 186 169 142 113 152 89 | 71 97 100 107 119 97 | 131.6/169.2 | 170.6/171.4 | 164.0/164.4 | 1450/1448 | 2330/2318 | 89.8/105.8 | 104.3/105.4/111.5 | 104.3/100.0 | 11164/3255 (18763) |
| L4-04-A11 | 198 138 104 159 126 119 | 74 97 100 106 121 97 | 131.5/168.9 | 170.0/170.3 | 164.6/164.4 | 1449/1445 | 2322/2317 | 92.4/111.9 | 100.6/100.3/108.8 | 110.8/93.7 | 10231/2221 (18763) |
| L4-05-B | 167 152 139 126 160 112 | 71 95 98 106 121 97 | 129.9/169.0 | 170.3/170.4 | 164.4/165.1 | 1455/1457 | 2333/2315 | 88.5/104.0 | 99.8/106.8/107.5 | 105.4/102.5 | 11115/3267 (18763) |
| L4-06-A11 | 207 151 122 161 158 111 | 74 97 99 107 120 96 | 129.2/168.3 | 170.2/170.8 | 164.5/164.3 | 1453/1453 | 2334/2329 | 95.0/109.8 | 106.0/109.0/106.0 | 106.9/111.5 | 10277/2171 (18763) |
| L4-07-B | 193 170 130 157 178 112 | 73 96 97 105 119 98 | 130.0/168.1 | 170.1/171.6 | 160.6/161.6 | 1450/1450 | 2338/2325 | 86.5/115.9 | 96.3/108.0/106.2 | 100.0/99.5 | 11176/3206 (18763) |
| L4-08-A10 | 194 134 144 144 163 104 | 74 96 97 107 120 96 | 130.6/168.7 | 169.2/170.4 | 163.6/164.7 | 1484/1480 | 2339/2332 | 92.8/112.5 | 95.0/106.1/103.8 | 112.1/110.5 | 10925/3051 (18763) |
| L4-09-B | 237 150 139 153 129 133 | 72 96 96 107 122 98 | 131.0/168.9 | 171.0/171.2 | 164.5/164.8 | 1447/1447 | 2319/2321 | 94.7/115.3 | 104.2/104.1/115.5 | 107.8/96.7 | 10984/3255 (18763) |

#### L4 reading (computed)

- **A10 (`STRATA_SPEC_COUPLED=1 STRATA_SPEC_GUMBEL=1 STRATA_SPEC_MIN_TEMP=0.9`) confirms on `D_real` at the screen.** The
  sampled and agent part of the suite gains 4.1% and 3.0% in the first half (1.040 and 0.995 in the reversed half, whose
  last pair is against a baseline that read `D_real` 105.2, the fastest of the batch). `D_win` is flat to -1.1%
  (0.989, 0.996), `P` 0.988 and 1.004, `T1` 1.007 and 1.019: the switch acts only where a request is sampled with
  temperature >= 0.9, which is samp4k and the agent turns, and the greedy counting tiers cannot see it. Its `F` reads
  1.091 and 1.084, which a drafting switch should not touch; the agent turn-1 park and the follow-up's prompt ms moved
  together in both arms (3,004 and 3,051 ms against 3,206 to 3,276 ms in the four baselines), so this is treated as park
  variance, not a prompt-read effect, and `F` is not a primary for A10.
- **A11 (`STRATA_PREFILL_CPU_SHARE=auto`, `MAX=3072`) confirms on `F` with a 47% cut in the agent follow-up's engine prompt
  ms**: 2,221 and 2,171 ms against 3,255 and 3,267 ms (1.466 and 1.471; reversed 1.505 and 1.477). `P` is unchanged
  (0.999, 0.996; reversed 1.001, 1.002), so the gain is confined to the short chunk: the follow-up appends 1,786 tokens,
  below the 3,072-token limit, and the idle CPU pool takes a share of its experts instead of every one streaming. The
  cnt4k tiers also lose about 2.2 s of wall time per tier (14.3 s against 16.5 s) while their run-2 read rate is flat,
  i.e. the first run and the calibration probes are what got faster. Secondary and descriptive: `D_real` 1.011 and 1.017
  (reversed 1.046, 1.053), `T1` 1.091 and 1.086, `T0` 1.114 and 1.102, tiny decode 1.012 and 1.019. This arm is
  rounding-changing (the CPU rounds the shared experts), so a confirmation carries the first-divergence report, not byte
  identity.
- **Both arms' F readings are valid evidence** (constant bench label, identical parked sizes in all nine arms).
