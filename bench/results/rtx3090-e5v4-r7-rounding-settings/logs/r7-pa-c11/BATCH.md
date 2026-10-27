# r7-pa-c11

- Job exit 0, restore exit 0 (the lab wrapper stopped production, ran the job, restored production and verified it with a real completion).
- Runs in this directory: c11-01-B, c11-02-N, c11-03-N, c11-04-B.
- Every run of this batch is copied here.
- Below: the batch's section from the round's `RESULTS-6.md`, verbatim except shortened paths. Paths such as `phase-a/raw/...` and `plans/...` refer to the lab workspace and are not part of this directory.

### r7-pa-c11 (combined: A18, A19, A12, A21, A32)

- Window: 2026-10-27T02:07:11+00:00 to 2026-10-27T02:34:33+00:00 UTC; job exit 0, restore exit 0 (timing plan 0, check plan 0); elapsed in the timing plan 1601.1 s. Lock turn: LOCKED-START r7-pa-c11 2026-10-27T02:07:10+00:00 holder-before=idle-after-r7-pa-c10 2026-10-27T02:07:09+00:00.
- Production before / after (sha256 of config and exe, on disk): 92c2f588c6bb7d02 strata-swift-iq3_xxs-256k.json; 26da5a7e53bf79a1 strata / 92c2f588c6bb7d02 strata-swift-iq3_xxs-256k.json; 26da5a7e53bf79a1 strata; PF1 binary before / after: e6298242e44e1842 strata; c90e8ff1316b0efb libstrata_kq.so / e6298242e44e1842 strata; c90e8ff1316b0efb libstrata_kq.so. r7suite freeze start / end: config `92c2f588c6bb7d02` / `92c2f588c6bb7d02`, exe `26da5a7e53bf79a1` / `26da5a7e53bf79a1`, PF1 exe `e6298242e44e1842` / `e6298242e44e1842`, frozen_ok_end True.
- Checks around the batch: PRODCHECK-PRE r7-pa-c11 rc=0; REALREQ-PRE r7-pa-c11 rc=0; BATCH-RC r7-pa-c11 rc=0 job=0 restore=0 2026-10-27T02:34:33+00:00; PRODCHECK-POST r7-pa-c11 rc=0; REALREQ-POST r7-pa-c11 rc=0; GPU-POST 250.00 W, 23744 MiB. Restore: verified 2026-10-27T02:34:32Z, model strata/swift-1.5-iq3_xxs-256K, max_context 262144, expert slots 10320, reply 'READY'.
- Pattern: old new new old (production, production plus A18, A19, A12, A21, A32), suite C plus cnt256k. Arm statuses: ok 4.
- Harness: phase-a6 `r7suite.py` `7df7f0b0...`, plan `plans/r7-pa-c11.json` (sha256 in the decisions above). Raw: `phase-a/raw6/gpu/r7-pa-c11/`. Keyscan on the VM before the copy: 69 files, 0 with the key.

#### Per arm (engine-measured; D in tok/s, P and R in tok/s, F, T0, T1 in ms)

| Arm | Switch | Status | Proof | D_win | D_real | D_SA | P | R4 | R32 | R128 | R256 | F | T0 | T1 | decode tiers (tiny/1k/4k/32k/128k/256k/nat4k) | free MiB | Cached GiB | s |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c11-01-B | B | ok | ok | 168.62 | 102.68 | 103.32 | 1836.5 | 1450.6 | 2325.1 | 2210.0 | 2079.5 | 3041.0 | 161.5 | 11283.0 | 95.3/171.0/171.8/163.2/160.6/152.8/101.4 | 379 | 79.9 | 418 |
| c11-02-N | N | ok | ok | 168.19 | 107.95 | 110.33 | 1930.4 | 1548.7 | 2406.1 | 2358.1 | 2262.3 | 1726.0 | 112.0 | 9291.0 | 104.3/169.2/171.0/164.4/160.5/153.9/103.3 | 379 | 79.9 | 383 |
| c11-03-N | N | ok | ok | 168.11 | 107.07 | 108.84 | 1933.7 | 1551.1 | 2410.6 | 2372.2 | 2260.1 | 1727.0 | 113.5 | 9352.0 | 104.4/168.8/171.1/164.5/160.5/154.0/103.6 | 379 | 79.9 | 383 |
| c11-04-B | B | ok | ok | 168.45 | 100.58 | 102.48 | 1836.5 | 1453.2 | 2320.7 | 2212.5 | 2075.7 | 3016.0 | 154.0 | 11213.0 | 96.9/169.4/171.8/164.2/160.5/153.8/96.9 | 379 | 79.9 | 416 |

#### pair ratios (arm / baseline for D_win, D_real, D_SA, P, R4, R32, R128, R256; baseline / arm for F, T0, T1)

| Arm | Pair | Phase | D_win | D_real | D_SA | P | R4 | R32 | R128 | R256 | F | T0 | T1 | tier dec (tiny/1k/4k/32k/128k/256k/nat4k/samp4k/agent) | tier read (4k/32k/128k/256k) |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| N (c11-02-N) | c11-01-B (baseline then arm) | combined | 0.997 | 1.051 | 1.068 | 1.051 | 1.068 | 1.035 | 1.067 | 1.088 | 1.762 | 1.442 | 1.214 | 1.094/0.989/0.995/1.008/0.999/1.007/1.019/1.043/1.094 | 1.068/1.035/1.067/1.088 |
| N (c11-03-N) | c11-04-B (arm then baseline) | combined | 0.998 | 1.064 | 1.062 | 1.053 | 1.067 | 1.039 | 1.072 | 1.089 | 1.746 | 1.357 | 1.199 | 1.077/0.996/0.996/1.002/1.000/1.001/1.069/1.025/1.101 | 1.067/1.039/1.072/1.089 |

#### baseline arms (noise reference: each baseline / the first baseline)

| Baseline | D_win | D_real | D_SA | P | R4 | R32 | R128 | R256 | F | T0 | T1 |
|---|---|---|---|---|---|---|---|---|---|---|---|
| c11-01-B | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 | 1.000 |
| c11-04-B | 0.999 | 0.980 | 0.992 | 1.000 | 1.002 | 0.998 | 1.001 | 0.998 | 1.008 | 1.049 | 1.006 |

#### every run, compact (engine lines; decode tok/s per run)

| Arm | tiny prompt ms x6 | tiny decode x6 | cnt1k dec r1/r2 | cnt4k dec r1/r2 | cnt32k dec r1/r2 | cnt128k dec r1/r2 | cnt256k dec | cnt4k read r1/r2 | cnt32k read r1/r2 | cnt128k read r1/r2 | cnt256k read | nat4k dec r1/r2 | samp4k dec 4242/4243/4244 | agent dec t1/t2 | agent prompt ms t1/t2 (reused) | drafts acc/offered samp4k; agent |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c11-01-B | 206 183 174 149 130 124 | 73 96 99 106 117 95 | 130.6/171.0 | 172.0/171.8 | 165.4/163.2 | 160.5/160.6 | 152.8 | 1448/1451 | 2351/2325 | 2214/2210 | 2079 | 91.2/114.2 | 99.8/110.6/106.7 | 104.8/97.9 | 11283/3041 (18763) | 397/576; 429/698 |
| c11-02-N | 168 133 105 105 119 98 | 77 102 103 115 127 120 | 130.5/169.2 | 170.6/171.0 | 164.1/164.4 | 160.4/160.5 | 153.9 | 1528/1549 | 2422/2406 | 2368/2358 | 2262 | 93.8/115.0 | 104.5/120.1/106.5 | 106.7/115.0 | 9291/1726 (18763) | 406/560; 455/719 |
| c11-03-N | 154 133 105 108 119 92 | 77 102 104 115 126 121 | 130.0/168.7 | 170.9/171.1 | 165.0/164.6 | 158.2/160.5 | 154.0 | 1535/1551 | 2409/2411 | 2352/2372 | 2260 | 93.6/116.1 | 101.3/109.5/106.1 | 113.4/111.1 | 9352/1727 (18763) | 384/603; 453/688 |
| c11-04-B | 221 203 156 152 151 129 | 74 96 100 108 121 98 | 131.8/169.5 | 170.6/171.8 | 164.7/164.3 | 157.9/160.5 | 153.8 | 1453/1453 | 2319/2321 | 2221/2212 | 2076 | 90.7/103.9 | 106.3/100.4/102.5 | 100.9/103.9 | 11213/3016 (18763) | 394/602; 338/571 |

#### Proof per arm (exe sha256, argv flags, the tier line, refusals, environ)

- c11-01-B (B): status ok, proof ok; exe <home>/strata-builds/v0.2.6-r5-4b7dcaf2/strata sha256 26da5a7e53bf79a1; argv production; lines {'strata verify: window up to 6 tokens': 1, 'strata mtp: draft head over 106299 tokens': 1, 'strata generate: 30 pool workers on logical proc': 1, 'strata aux cpus: .*\\(off at start': 1, 'strata generate: PLE direct read probe: ': 1, 'strata generate: the SSD is kept awake while row': 1, 'strata serve: adaptive tier: blocking, and the a': 1}; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']; Cached at ready 79.9 GiB
- c11-02-N (N): status ok, proof ok; exe <home>/strata-builds/v0.2.6-r5-4b7dcaf2/strata sha256 26da5a7e53bf79a1; argv {'--ple-io': ['mmap'], '--pool-workers': ['15'], '--adapt-decay': ['0.5']}; lines {'strata KV prefetch: \\d+ layer prefixes, single e': 33, 'strata generate: 15 pool workers on logical proc': 1, 'strata serve: adaptive tier: blocking, and the a': 1}; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_KV_PREFETCH', 'STRATA_PREFILL_STREAM_MIN', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']; Cached at ready 79.9 GiB
- c11-03-N (N): status ok, proof ok; exe <home>/strata-builds/v0.2.6-r5-4b7dcaf2/strata sha256 26da5a7e53bf79a1; argv {'--ple-io': ['mmap'], '--pool-workers': ['15'], '--adapt-decay': ['0.5']}; lines {'strata KV prefetch: \\d+ layer prefixes, single e': 33, 'strata generate: 15 pool workers on logical proc': 1, 'strata serve: adaptive tier: blocking, and the a': 1}; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_KV_PREFETCH', 'STRATA_PREFILL_STREAM_MIN', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']; Cached at ready 79.9 GiB
- c11-04-B (B): status ok, proof ok; exe <home>/strata-builds/v0.2.6-r5-4b7dcaf2/strata sha256 26da5a7e53bf79a1; argv production; lines {'strata verify: window up to 6 tokens': 1, 'strata mtp: draft head over 106299 tokens': 1, 'strata generate: 30 pool workers on logical proc': 1, 'strata aux cpus: .*\\(off at start': 1, 'strata generate: PLE direct read probe: ': 1, 'strata generate: the SSD is kept awake while row': 1, 'strata serve: adaptive tier: blocking, and the a': 1}; refusals none; STRATA_* ['STRATA_CKPT_ASYNC', 'STRATA_CKPT_POOL', 'STRATA_SELECT_TWO_PASS', 'STRATA_TOPK_SPLIT']; Cached at ready 79.9 GiB

#### Decode expert cache hit rate per tier (%, VRAM hits over lookups; the engine's per-request line; counting tiers: run 2)

| Arm | Switch | agent:1 | agent:2 | agent | samp4k:4242 | samp4k:4243 | samp4k:4244 | samp4k | nat4k | tiny | cnt1k | cnt4k | cnt32k | cnt128k | PCIe % agent / samp4k | drain lines (n, ms) | last pcie_frac |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c11-01-B | B | 91.4 | 97.1 | 94.3 | 94.5 | 97.8 | 97.9 | 96.8 | 91.9 | 89.8 | 96.5 | 98.9 | 99.1 | 99.2 | 0.27 / 0.06 | 0, 0 | 0.20 |
| c11-02-N | N | 94.1 | 96.4 | 95.2 | 93.5 | 96.4 | 98.2 | 96.0 | 91.9 | 89.6 | 96.3 | 98.8 | 99.1 | 99.0 | 0.15 / 0.11 | 0, 0 | 0.20 |
| c11-03-N | N | 95.3 | 96.6 | 96.0 | 94.5 | 97.6 | 97.9 | 96.7 | 91.6 | 89.6 | 96.3 | 98.8 | 99.0 | 99.1 | 0.12 / 0.07 | 0, 0 | 0.20 |
| c11-04-B | B | 94.0 | 96.7 | 94.9 | 93.3 | 97.7 | 97.8 | 96.3 | 92.0 | 89.8 | 96.6 | 99.0 | 99.2 | 99.2 | 0.18 / 0.09 | 0, 0 | 0.20 |

#### combined arm gate (members: A18, A19, A12, A21, A32)

| Tier / metric | kind | pair N1/B1 | pair N2/B2 | median | >= 0.98 |
|---|---|---|---|---|---|
| tiny decode | greedy decode | 1.094 | 1.077 | 1.0852 | yes |
| cnt1k decode | greedy decode | 0.989 | 0.996 | 0.9927 | yes |
| cnt4k decode | greedy decode | 0.995 | 0.996 | 0.9957 | yes |
| cnt32k decode | greedy decode | 1.008 | 1.002 | 1.0048 | yes |
| cnt128k decode | greedy decode | 0.999 | 1.000 | 0.9997 | yes |
| cnt256k decode | greedy decode | 1.007 | 1.001 | 1.0042 | yes |
| nat4k decode | greedy decode | 1.019 | 1.069 | 1.0442 | yes |
| cnt4k prompt read | prompt read | 1.068 | 1.067 | 1.0675 | yes |
| cnt32k prompt read | prompt read | 1.035 | 1.039 | 1.0368 | yes |
| cnt128k prompt read | prompt read | 1.067 | 1.072 | 1.0696 | yes |
| cnt256k prompt read | prompt read | 1.088 | 1.089 | 1.0884 | yes |
| T0 | prompt ms (baseline / arm) | 1.442 | 1.357 | 1.3994 | yes |
| T1 | prompt ms (baseline / arm) | 1.214 | 1.199 | 1.2067 | yes |
| F | prompt ms (baseline / arm) | 1.762 | 1.746 | 1.7541 | yes |
| samp4k decode | sampled decode | 1.043 | 1.025 | 1.0336 | reported |
| agent decode | sampled decode | 1.094 | 1.101 | 1.0973 | reported |

Gate: PASS (no gated tier median below 0.98)

#### Every metric, combined / production (higher is better; F, T0, T1 as baseline / arm)

| Metric | N1/B1 | N2/B2 | median | B mean | N mean |
|---|---|---|---|---|---|
| D_win | 0.997 | 0.998 | 0.9977 | 168.5 | 168.1 |
| D_real | 1.051 | 1.064 | 1.0579 | 101.6 | 107.5 |
| D_SA | 1.068 | 1.062 | 1.0650 | 102.9 | 109.6 |
| P | 1.051 | 1.053 | 1.0520 | 1836.5 | 1932.0 |
| F | 1.762 | 1.746 | 1.7541 | 3028.5 | 1726.5 |
| T0 | 1.442 | 1.357 | 1.3994 | 157.8 | 112.8 |
| T1 | 1.214 | 1.199 | 1.2067 | 11248.0 | 9321.5 |
| R4 | 1.068 | 1.067 | 1.0675 | 1451.9 | 1549.9 |
| R32 | 1.035 | 1.039 | 1.0368 | 2322.9 | 2408.4 |
| R128 | 1.067 | 1.072 | 1.0696 | 2211.2 | 2365.1 |
| R256 | 1.088 | 1.089 | 1.0884 | 2077.6 | 2261.2 |

#### What a Hermes session sees (production / combined, each the mean of its two arms)

| Moment | Measured as | Production | Combined | Change |
|---|---|---|---|---|
| New session, first read | T1: agent turn 1, 18,768 tokens read fresh (engine prompt ms) | 11248.0 ms | 9321.5 ms | -17.1% |
| Follow-up turn read | F: agent turn 2, 1,786 new tokens on the parked conversation (prompt ms) | 3028.5 ms | 1726.5 ms | -43.0% |
| Short chat, first token | T0: tiny prompts, median engine prompt ms | 157.8 ms | 112.8 ms | -28.5% |
| Decode per token, agent turns | 1000 / pooled agent decode tok/s | 9.8 ms/token | 9.0 ms/token | -8.9% |
| Decode per token, sampled thinking-on | 1000 / pooled samp4k decode tok/s | 9.6 ms/token | 9.3 ms/token | -3.3% |
| Decode per token, greedy natural text | 1000 / pooled nat4k decode tok/s | 10.1 ms/token | 9.7 ms/token | -4.2% |
| Long prompt read, 128K | cnt128k run 2 prompt read | 2211.2 tok/s | 2365.1 tok/s | +7.0% |
| Long prompt read, 256K | cnt256k (1 run) prompt read | 2077.6 tok/s | 2261.2 tok/s | +8.8% |


#### c11 reading (computed)

- **The gate passes.** No gated tier median below 0.98: the lowest is cnt1k decode 0.9927, then cnt4k 0.9957, cnt128k
  0.9997, cnt256k 1.0042, cnt32k 1.0048, and the prompt reads and latency metrics all improve (cnt4k 1.0675, cnt32k
  1.0368, cnt128k 1.0696, cnt256k 1.0884; `T0` 1.3994, `T1` 1.2067, `F` 1.7541). `D_win` is flat (median 0.9977); `D_real`
  median 1.0579 (pairs 1.051 and 1.064). samp4k 1.0336 and agent 1.0973 are reported, not gated.
- **What it buys a Hermes session** (each side the mean of its two arms): a new session's first read of an 18.8K agent
  prompt falls from 11,248 to 9,322 ms (-17.1%), the follow-up turn's read of 1,786 new tokens from 3,029 to 1,727 ms
  (-43.0%), a short chat's first token from 158 to 113 ms (-28.5%); decode per token falls 8.9% on the agent turns, 3.3% on
  sampled thinking-on and 4.2% on greedy natural text; long prompt reads +7.0% at 128K and +8.8% at 256K.
- **Against c7** (A18 + A19 + A12 + A21, no A32; the two batches' baselines are their own): the same read and latency gains
  (F 1.7390 -> 1.7541, `T1` 1.1680 -> 1.2067, `T0` 1.3577 -> 1.3994, R32 1.0250 -> 1.0368, R128 1.0586 -> 1.0696, R256
  1.0729 -> 1.0884) and a `D_real` median 1.0425 -> 1.0579, carried by the agent turns (agent decode 1.0718 -> 1.0973) and,
  in this batch, by nat4k and samp4k too (1.0442 and 1.0336). `D_win` stays flat in both (0.9973, 0.9977). This is
  descriptive: the batches differ in baselines and in time, and A32's own confirmation already showed its gain to be text-
  and draft-acceptance-carried rather than a cache-hit effect (RESULTS-5.md), which phase A cannot separate further.
- **Against the round's target** (PLAN.md: +10% on `D_real` and on `D_win`, separately, from all adopted changes together):
  `D_win` 0.9977 (flat) and `D_real` median 1.0579, so the +10% target is not met; the confirmed set is a prompt-read and
  latency gain of 17% to 43% on the moments a Hermes session pays, plus 3% to 9% per token on real and sampled traffic.
- **Adoption**: the arm's job exit is 0, restore exit 0, production and the PF1 binary unchanged before and after, every
  proof ok. No production change is made here (the parent applies them).
