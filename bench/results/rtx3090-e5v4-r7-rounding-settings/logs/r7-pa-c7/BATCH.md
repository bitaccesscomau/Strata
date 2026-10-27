# r7-pa-c7

- Job exit 0, restore exit 0 (the lab wrapper stopped production, ran the job, restored production and verified it with a real completion).
- Runs in this directory: c7-01-B, c7-02-N, c7-03-N, c7-04-B.
- Every run of this batch is copied here.
- Below: the batch's section from the round's `RESULTS.md`, verbatim except shortened paths. Paths such as `phase-a/raw/...` and `plans/...` refer to the lab workspace and are not part of this directory.

### r7-pa-c7 (combined arm: production against production plus A18, A19, A12, A21; suite C plus cnt256k)

- Window: 2026-10-26T20:47:14+00:00 to 2026-10-26T21:14:32+00:00 UTC; job exit 0, restore exit 0; elapsed in the job 1598.4 s.
- Production config sha256 before / after: `92c2f588c6bb7d02` / `92c2f588c6bb7d02`; exe `26da5a7e53bf79a1` / `26da5a7e53bf79a1`; PRODCHECK-POST rc=0; PRODCHECK-PRE rc=0; REALREQ-POST rc=0; REALREQ-PRE rc=0; GPU-POST 250.00 W; restore: restored True, max_context 262144.
- Pattern: old new new old (production, production plus every adopted setting), suite C plus cnt256k. Groups: combined run (need 1877 s, left 3450 s).
- Arms: 4 run, 0 skipped (-), 0 failed (-); proof not ok: none.
- Raw: `phase-a/raw/gpu/r7-pa-c7/` (arm.json, provenance.json, engine.log, server.log, bench JSON per arm).
- Members (decision 34): `--ple-io mmap` (A18), `STRATA_PREFILL_STREAM_MIN=4096` (A19), `STRATA_KV_PREFETCH=1` (A12), `--pool-workers 15` (A21). A10 and A20 are not in it (not confirmed). N arms' environ = production env + `STRATA_PREFILL_STREAM_MIN=4096 STRATA_KV_PREFETCH=1`; N arms' args = production args + `--ple-io mmap --pool-workers 15`.
- Proof ok in all four arms (N prints `strata KV prefetch: N layer prefixes` and `15 pool workers`; the baselines print `30 pool workers` and no prefetch line). Each arm is a fresh server and engine on production's own config.
- The batch waited for the lock from 19:53 to 20:47 UTC behind another worker's `r7-pa-L10` (workspace `phase-a3/`); that wait is outside the job's budget of 1,598 s.
- Harness: `r7suite3.py` `1a609a2b...`, plan `plans/r7-pa-c7.json` `57cc5516...` (dry run 49 checks, `DRYRUN3 OK`, the same file as the tested plan). Keyscan: 69 files, 0 with the key.

#### Per arm (engine-measured; D in tok/s, P and R in tok/s, F, T0, T1 in ms)

| Arm | Switch | Status | Proof | D_win | D_real | D_SA | P | R4 | R32 | R128 | R256 | F | T0 | T1 | decode tiers (tiny/1k/4k/32k/128k/256k/nat4k) | free MiB | Cached GiB | s |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c7-01-B | B | ok | ok | 169.94 | 98.84 | 97.77 | 1849.2 | 1457.5 | 2346.2 | 2221.1 | 2097.1 | 2996.0 | 154.5 | 10969.0 | 95.9/170.8/173.4/165.7/160.6/156.1/101.0 | 379 | 79.9 | 415 |
| c7-02-N | N | ok | ok | 168.74 | 106.46 | 109.04 | 1933.9 | 1566.4 | 2387.7 | 2348.8 | 2237.3 | 1706.0 | 110.0 | 9473.0 | 100.6/169.4/171.5/165.4/160.4/155.9/101.5 | 379 | 79.9 | 383 |
| c7-03-N | N | ok | ok | 169.33 | 103.46 | 105.10 | 1930.4 | 1548.7 | 2406.3 | 2346.3 | 2241.0 | 1700.0 | 111.0 | 9475.0 | 100.4/170.3/172.0/165.7/160.7/156.2/100.3 | 379 | 79.9 | 384 |
| c7-04-B | B | ok | ok | 169.04 | 102.64 | 105.53 | 1839.9 | 1452.2 | 2331.2 | 2214.1 | 2077.0 | 2927.0 | 145.5 | 11163.0 | 94.7/170.9/171.2/165.1/160.2/156.3/97.1 | 379 | 79.9 | 415 |

#### Pair ratios (old new new old; arm / baseline for D_win, D_real, D_SA, P, R4, R32, R128, R256; baseline / arm for F, T0, T1)

| Arm | Pair | Phase | D_win | D_real | D_SA | P | R4 | R32 | R128 | R256 | F | T0 | T1 | tier dec (tiny/1k/4k/32k/128k/256k/nat4k/samp4k/agent) | tier read (4k/32k/128k/256k) |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| N (c7-02-N) | c7-01-B (baseline then arm) | combined | 0.993 | 1.077 | 1.115 | 1.046 | 1.075 | 1.018 | 1.057 | 1.067 | 1.756 | 1.405 | 1.158 | 1.049/0.992/0.989/0.998/0.999/0.999/1.005/1.065/1.168 | 1.075/1.018/1.057/1.067 |
| N (c7-03-N) | c7-04-B (arm then baseline) | combined | 1.002 | 1.008 | 0.996 | 1.049 | 1.066 | 1.032 | 1.060 | 1.079 | 1.722 | 1.311 | 1.178 | 1.060/0.997/1.005/1.004/1.003/0.999/1.033/1.016/0.976 | 1.066/1.032/1.060/1.079 |

#### Baseline arms (noise reference: each baseline / the first baseline)

| Baseline | D_win | D_real | D_SA | P | R4 | R32 | R128 | R256 | F | T0 | T1 |
|---|---|---|---|---|---|---|---|---|---|---|---|
| c7-01-B | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 |
| c7-04-B | 0.995 | 1.038 | 1.079 | 0.995 | 0.996 | 0.994 | 0.997 | 0.990 | 1.024 | 1.062 | 0.983 |

#### every run, compact (engine lines; decode tok/s per run)

| Arm | tiny prompt ms x6 | tiny decode x6 | cnt1k dec r1/r2 | cnt4k dec r1/r2 | cnt32k dec r1/r2 | cnt128k dec r1/r2 | cnt256k dec | cnt4k read r1/r2 | cnt32k read r1/r2 | cnt128k read r1/r2 | cnt256k read | nat4k dec r1/r2 | samp4k dec 4242/4243/4244 | agent dec t1/t2 | agent prompt ms t1/t2 (reused) | drafts acc/offered samp4k; agent |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c7-01-B | 167 163 136 146 190 111 | 73 96 98 103 122 98 | 130.7/170.7 | 172.2/173.4 | 166.6/165.7 | 157.0/160.6 | 156.1 | 1455/1458 | 2365/2346 | 2226/2221 | 2097 | 92.2/111.7 | 98.4/98.9/104.0 | 98.5/92.2 | 10969/2996 (18763) | 365/557; 379/712 |
| c7-02-N | 171 132 103 103 117 91 | 77 102 104 109 126 101 | 131.1/169.4 | 171.0/171.5 | 164.9/165.4 | 160.6/160.4 | 155.9 | 1551/1566 | 2421/2388 | 2360/2349 | 2237 | 94.9/109.0 | 101.5/107.2/112.6 | 116.5/104.9 | 9473/1706 (18763) | 380/562; 348/528 |
| c7-03-N | 170 138 104 105 117 90 | 77 99 104 109 127 101 | 130.8/170.4 | 171.7/172.0 | 166.0/165.7 | 160.8/160.7 | 156.2 | 1527/1549 | 2425/2406 | 2358/2346 | 2241 | 94.4/106.9 | 96.0/111.0/111.0 | 106.9/101.7 | 9475/1700 (18763) | 375/552; 362/625 |
| c7-04-B | 207 147 144 131 169 118 | 74 94 97 107 119 91 | 131.0/170.8 | 171.3/171.2 | 166.2/165.0 | 160.6/160.2 | 156.3 | 1454/1452 | 2352/2331 | 2218/2214 | 2077 | 91.9/102.9 | 103.2/101.2/107.3 | 104.5/111.6 | 11163/2927 (18763) | 391/595; 380/593 |

#### Combined-arm gate and metrics (computed) (members: A18, A19, A12, A21)

| Tier / metric | kind | pair N1/B1 | pair N2/B2 | median | >= 0.98 |
|---|---|---|---|---|---|
| tiny decode | greedy decode | 1.049 | 1.060 | 1.0542 | yes |
| cnt1k decode | greedy decode | 0.992 | 0.997 | 0.9944 | yes |
| cnt4k decode | greedy decode | 0.989 | 1.005 | 0.9967 | yes |
| cnt32k decode | greedy decode | 0.998 | 1.004 | 1.0010 | yes |
| cnt128k decode | greedy decode | 0.999 | 1.003 | 1.0009 | yes |
| cnt256k decode | greedy decode | 0.999 | 0.999 | 0.9991 | yes |
| nat4k decode | greedy decode | 1.005 | 1.033 | 1.0186 | yes |
| cnt4k prompt read | prompt read | 1.075 | 1.066 | 1.0706 | yes |
| cnt32k prompt read | prompt read | 1.018 | 1.032 | 1.0250 | yes |
| cnt128k prompt read | prompt read | 1.057 | 1.060 | 1.0586 | yes |
| cnt256k prompt read | prompt read | 1.067 | 1.079 | 1.0729 | yes |
| T0 | prompt ms (baseline / arm) | 1.405 | 1.311 | 1.3577 | yes |
| T1 | prompt ms (baseline / arm) | 1.158 | 1.178 | 1.1680 | yes |
| F | prompt ms (baseline / arm) | 1.756 | 1.722 | 1.7390 | yes |
| samp4k decode | sampled decode | 1.065 | 1.016 | 1.0407 | reported |
| agent decode | sampled decode | 1.168 | 0.976 | 1.0718 | reported |

Gate: PASS (no gated tier median below 0.98)

#### Every metric, combined / production (higher is better; F, T0, T1 as baseline / arm)

| Metric | N1/B1 | N2/B2 | median | B mean | N mean |
|---|---|---|---|---|---|
| D_win | 0.993 | 1.002 | 0.9973 | 169.5 | 169.0 |
| D_real | 1.077 | 1.008 | 1.0425 | 100.7 | 105.0 |
| D_SA | 1.115 | 0.996 | 1.0555 | 101.7 | 107.1 |
| P | 1.046 | 1.049 | 1.0475 | 1844.6 | 1932.2 |
| F | 1.756 | 1.722 | 1.7390 | 2961.5 | 1703.0 |
| T0 | 1.405 | 1.311 | 1.3577 | 150.0 | 110.5 |
| T1 | 1.158 | 1.178 | 1.1680 | 11066.0 | 9474.0 |
| R4 | 1.075 | 1.066 | 1.0706 | 1454.9 | 1557.5 |
| R32 | 1.018 | 1.032 | 1.0250 | 2338.7 | 2397.0 |
| R128 | 1.057 | 1.060 | 1.0586 | 2217.6 | 2347.6 |
| R256 | 1.067 | 1.079 | 1.0729 | 2087.0 | 2239.1 |

#### What a Hermes session sees (production / combined, each the mean of its two arms)

| Moment | Measured as | Production | Combined | Change |
|---|---|---|---|---|
| New session, first read | T1: agent turn 1, 18,768 tokens read fresh (engine prompt ms) | 11066.0 ms | 9474.0 ms | -14.4% |
| Follow-up turn read | F: agent turn 2, 1,786 new tokens on the parked conversation (prompt ms) | 2961.5 ms | 1703.0 ms | -42.5% |
| Short chat, first token | T0: tiny prompts, median engine prompt ms | 150.0 ms | 110.5 ms | -26.3% |
| Decode per token, agent turns | 1000 / pooled agent decode tok/s | 9.9 ms/token | 9.3 ms/token | -6.2% |
| Decode per token, sampled thinking-on | 1000 / pooled samp4k decode tok/s | 9.8 ms/token | 9.4 ms/token | -3.9% |
| Decode per token, greedy natural text | 1000 / pooled nat4k decode tok/s | 10.1 ms/token | 9.9 ms/token | -1.8% |
| Long prompt read, 128K | cnt128k run 2 prompt read | 2217.6 tok/s | 2347.6 tok/s | +5.9% |
| Long prompt read, 256K | cnt256k (1 run) prompt read | 2087.0 tok/s | 2239.1 tok/s | +7.3% |

#### c7 reading (computed)

- **The gate passes with margin**: no gated tier median below 0.98. The lowest is cnt1k decode 0.9944; cnt4k decode 0.9967, cnt256k decode 0.9991, D_win's pairs 0.993 and 1.002. Every prompt read improves: cnt4k +7.1%, cnt32k +2.5%, cnt128k +5.9%, cnt256k +7.3% (2,239.1 tok/s against 2,087.0, the 255,547-token prompt read in about 114 s against about 123 s).
- **What the four settings together buy a Hermes session** (each side the mean of its two arms): a new session's first read of an 18.8K agent prompt falls from 11,066 to 9,474 ms (-14.4%, A18's `mmap` plus A19's STAGE band); the follow-up turn's read of 1,786 new tokens falls from 2,962 to 1,703 ms (-42.5%, A19 and A11's path, the largest effect of the round); a short chat's first token falls from 150 to 110 ms (-26.3%, A21); decode per token falls 6.2% on the agent turns, 3.9% on sampled thinking-on and 1.8% on greedy natural text. The counting tiers' decode is flat (D_win median 0.9973), as expected: none of the four touches decode.
- **Against the round's target** (PLAN.md: +10% on `D_real` and on `D_win`, separately, from all adopted changes together): `D_win` 0.9973 (flat) and `D_real` median 1.0425 (pair means +7.7%, +0.8%; the two baselines differ by 3.8% on `D_real` themselves), so **the +10% target is not met**: the round's confirmed settings are a prompt-read and latency gain, not a throughput gain. `D_real`'s gain is A18's and A19's sampled/agent decode reading (samp4k 1.065 and 1.016, agent 1.168 and 0.976) on top of the read-time saving the agent turn also pays.
- **Adoption**: the arm's job exit is 0, restore exit 0, production unchanged before and after; the settings below are the ones these data support. No production change is made here (the parent applies them).
