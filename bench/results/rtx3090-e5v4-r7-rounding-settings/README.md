# RTX 3090 / Xeon E5-2698 v4: round-7 settings that change rounding or the distribution (not deployed)

Measured 2026-10-26 and 2026-10-27 (UTC) by Stefano Sinden on one home-lab machine. Round 7 screened existing Strata
engine switches against production (a predeclared ladder, arms A1 to A33). This directory keeps the evidence for every
setting whose output is **not byte-identical** to production's greedy output (classified in the switch audit as
rounding-changing, rounding-level, distribution-preserving, or output-preserving with different verify-window shapes),
and for the two combined sets that contain such settings: the per-run engine lines, the switch proofs, the output
checks, the gate computations and the configuration change.

**None of these settings is deployed.** The full set (c11 below) passed its combined arm but changes rounding, so it
was staged and not applied. Production runs the **output-exact** set from the same round (`r7-pa-c12`, deployed
2026-10-27 03:37 UTC): the PF1 build (fork draft PR #5, `c2cbd04a`) with `STRATA_PREFILL_ROUTED_STREAM=1`, plus
`--ple-io mmap --pool-workers 15`; its output was byte-identical to the previous production on all eight identity
prompts of a joint check. That set's evidence is not in this directory.

Main limitations: one machine, one model and quantisation, engine 0.1.51, a KVM guest, a 250 W power cap and an unlocked
tensor rate (below); the combined set c11 has no joint output check of all five members.

- Per-setting results: [`matrix.md`](matrix.md)
- Per-run logs, batch records, output checks and gate computations: [`logs/INDEX.md`](logs/INDEX.md)

## Hardware and software

| Item | Value |
|---|---|
| GPU | one NVIDIA GeForce RTX 3090 24 GB (sm_86), PCI passthrough to a KVM guest; power cap **250 W** (default 350 W) |
| Tensor rate | **unlocked** by a kernel module (gpu-unlock, active since 2026-10-26): full FP16/BF16 (FP32 accumulate) and TF32 tensor rate on GeForce Ampere. Every run here, baselines included, ran with it on |
| PCIe | 3.0 x16; the engine's start-up probe read 11.4 to 12.2 GB/s host to device across these runs (about 11.8 GB/s under load) |
| CPU | Xeon E5-2698 v4 (Broadwell-EP: AVX2, FMA, F16C; no AVX-512, no AVX-VNNI); the guest has 32 vCPUs pinned to 16 physical cores |
| RAM | DDR4-2133, 4 channels; the guest sees about 149 GiB (MemTotal 156,504,288 KiB), no swap |
| Storage | the guest's virtual disk (host storage type not recorded here); the 28.8 GB PLE table probed 47K to 80K rows/s in direct mode across these runs |
| OS, driver | Ubuntu 24.04 guest; NVIDIA driver 580.178.04; CUDA 13.0 |
| Strata | v0.2.6 (upstream `4b9e05a2`, engine 0.1.51) plus two commits of the fork, `20f29ce6` (`STRATA_SELECT_TWO_PASS`, upstream #4119) and `4b7dcaf2` (`STRATA_CKPT_ASYNC`): branch `prod/v0.2.6-r5-applied` of bitaccesscomau/Strata at `4b7dcaf2` |
| Build | source build: `-G Ninja -DCMAKE_BUILD_TYPE=Release -DSTRATA_ENABLE_CUDA=ON -DSTRATA_Q6K_EXPERTS=ON -DSTRATA_MMQ_KQUANTS=ON -DCMAKE_CUDA_ARCHITECTURES=86` with CUDA 13.0's `nvcc` and the tree's `third_party/llama.cpp`; `strata` sha256 `26da5a7e53bf79a1023869b99216b1d2659be17f0558e4a2da5c3be35a6591ce`, `libstrata_kq.so` sha256 `049824c7d21678818e7bd68a9c8e0fbfd9c03c9cea9e0b52bfdcefb88acf4132`. Every run in this directory used this binary |
| Server | production's `serve/server.py` (v0.2.6, sha256 `c9e6d3e382fa521f...`), with an API key (the key is in no file here) |
| Other load | production and the router were stopped by the batch wrapper for each batch; one GPU lock, so no other GPU job ran |

## Model and configuration (the production baseline every arm started from)

- Model: Swift-Qwen3.8-Flash-Next GSQ-RCO IQ3_XXS (`Swift-Qwen3.8-Flash-Next-GSQ-RCO-IQ3_XXS-00001-of-00002.gguf`, served
  as `swift-1.5-iq3_xxs-256K`), native-experts pack `swift-iq3_xxs`, the MTP draft layer `mtp/rt`, the shipped expert
  profile `data/expert-profile.bin`. Repository revision: not recorded here.
- Context 262,144 tokens; KV int8 with 32,768 cells resident in VRAM (the rest streamed from 3.09 GiB of pinned RAM);
  expert cache auto, 10,320 slots (16.73 GiB); prefill auto (8,192-token chunks, a 384-slot ring); 30 CPU pool workers
  plus the host thread; MTP with `--spec 4` (verify windows up to 6 tokens) and `--spec-min-p 0.5`; the sm_86 card
  defaults (nine exact switches); experts held in a 39.97 GiB pinned arena. No calibration or experimental
  speed-projection flag in the command line; no vision.
- Production `env` during the measurements: `STRATA_TOPK_SPLIT=1 STRATA_CKPT_POOL=1 STRATA_SELECT_TWO_PASS=1
  STRATA_CKPT_ASYNC=1` (config sha256 `92c2f588c6bb7d02...`, checked unchanged before and after every batch).
- The engine command line as the engine logged it (paths shortened):

```text
<home>/strata-builds/v0.2.6-r5-4b7dcaf2/strata --serve --pack <home>/Strata-data/packs/swift-iq3_xxs
  --native <home>/Strata-data/models/swift-IQ3_XXS/Swift-Qwen3.8-Flash-Next-GSQ-RCO-IQ3_XXS-00001-of-00002.gguf
  --ple-gguf <home>/Strata-data/models/swift-IQ3_XXS/Swift-Qwen3.8-Flash-Next-GSQ-RCO-IQ3_XXS-00001-of-00002.gguf
  --expert-profile <home>/Strata/data/expert-profile.bin --expert-cache auto --prefill auto --spec 4 --spec-min-p 0.5
  --mtp <home>/Strata-data/mtp/rt --max-context 262144 --kv int8 --kv-resident 32768
  --conversation-cache-min-tokens 2048 --conversation-cache-mib 8192
```

- An arm's configuration is production's with only `log`, `env` (every production key plus the arm's) and `args`
  (production's plus the arm's flags; `--spec` replaced in place for A7 and A8) changed. The `engine started:` line at
  the top of each run's log file shows the exact command line of that run.

## Method

The round's plan and its dated addenda fixed every arm, pair, primary and threshold before the data they govern
existed; none was changed after data.

- **Batches.** Each batch is one turn of a GPU lock: a wrapper stops production and the router, runs the job (at most
  3,600 s), then restores production and verifies it with a real completion. Every batch here ended with job exit 0 and
  restore exit 0. Each run is a fresh server and engine, started after VRAM drained below 500 MiB, proven from the engine
  process's `/proc/<pid>/exe` and sha256, `/proc/<pid>/environ` (`STRATA_*`) and `/proc/<pid>/cmdline`, plus the
  setting's own log line where the engine prints one ([`matrix.md`](matrix.md#switch-proof-per-setting)).
- **Suite S** (screening), in this order after a readiness completion: `tiny` (6 short chats, greedy, thinking off,
  `presence_penalty` 0, 64 tokens); `cnt1k`, `cnt4k`, `cnt32k` (a counting prompt at 0.98 x the tier, 2 runs of unique
  content, 256 tokens, run 2 read; every draft is accepted, so these measure the cost of a full verify window); `nat4k`
  (a 3,828-token prompt of real source code with a question that needs a long answer, greedy, 384 tokens, twice with
  different prefixes); `samp4k` (thinking on, temperature 1.0, seeds 4242 to 4244, 256 tokens); `agent` (a first turn of 18,768
  tokens: Hermes-shaped system text, 33 tool definitions and a short user turn; thinking on, model-card sampling, seed
  4242, 384 tokens; then a follow-up turn that appends a tool result and a question, 1,786 new tokens on the parked
  conversation). **Suite C** = S plus `cnt128k` (2 runs, run 2 read), plus `cnt256k` (1 run) for prompt-read switches and
  the combined arms. Every greedy request sends `presence_penalty: 0` explicitly (the model card's 1.5 would otherwise
  apply).
- **Metrics** (engine log `strata serve: prompt N tokens = ...` lines; token-weighted: total tokens over total ms):
  `D_win` = geometric mean of run-2 decode tok/s over cnt1k, cnt4k, cnt32k; `D_real` = geometric mean of decode tok/s
  over nat4k (both runs pooled), samp4k (three seeds pooled) and agent (both turns pooled); `D_SA` = the same over samp4k
  and agent only (A10's primary); `P` = geometric mean of run-2 prompt read over cnt4k and cnt32k; `R4`, `R32`, `R128`,
  `R256` = that tier's run-2 prompt read (cnt256k: its one run); `F` = the agent follow-up's engine prompt ms; `T0` =
  median engine prompt ms of the six tiny chats; `T1` = the agent first turn's engine prompt ms.
- **Pairs.** Screens: `B X1 B X2 B X3 B`, each candidate paired with the baseline before and after it; then the
  reversed half `X3 B X2 B X1 B` when the whole of it fitted the batch (descriptive, never gated). Confirmations: two
  more pairs in the opposite order in a later batch (`X B B X`), suite C. Combined arms: `B N N B` (old, new, new, old).
  Ratios are arm / baseline, and baseline / arm for `F`, `T0`, `T1`, so higher is better throughout.
- **Gates.** Screen: both pair ratios on the primary at or above 1.02, or mixed: confirm; both within 0.98 to 1.02: no
  measurable effect; both below 0.98: regression. Confirmation: the median of the four pair ratios (two screen, two
  confirmation) at least 1.02, its percentile bootstrap 95% interval (20,000 resamples, seed 20261026) entirely above
  1.0, and no greedy tier's median pair ratio below 0.98. Arm-specific conditions: A7 and A8 have two primaries
  (`D_win`, `D_real`), and A8's confirmation also required `D_real` >= 0.98 (set after its screen, before its
  confirmation data); A19, A20, A22 need the cnt32k read >= 0.98; A23 to A29 need `D_real` >= 0.98, and A30 to A33
  `D_win` >= 0.98, in both screen pairs. Prefill choice among confirmed A11, A19, A20, A22: the highest median `F`, a
  member with more settings chosen only if its median is at least 1.02 x the simpler one's. Combined arm: no gated
  tier's median pair ratio below 0.98 (greedy decode of every tier, the prompt reads, `T0`, `T1`, `F`; samp4k and agent
  decode reported).
- **Deterministic lane** (identity): `STRATA_PREFILL_CPU_SHARE=0 --pcie-frac 0.32 --adapt-every 0`, greedy, thinking off.
  The prefill arms (A11, A19, A22) keep their own prefill settings instead of the share's 0; the adaptive-tier arms (A30
  to A33) use the **adaptive lane**, the deterministic lane without `--adapt-every 0` (that flag switches the tier off),
  in which the tier's copy timing makes two baseline processes differ on some prompts. In the production lane two
  baseline processes already differ (the adaptive PCIe/CPU split), so production-lane text is never compared.
- **Output checks** (rounding-changing and distribution-preserving settings that confirmed, plus some descriptive ones):
  B1 (reference), the arm, B2 (control), each a fresh process in the lane; tiny x6 (64 tokens), id1k and id32k (256),
  the agent pair (thinking on, model-card sampling, seed 4242, 384), the seeded `tools/needle_bench.py` at 8K/16K/28K x
  depths 10/50/90, then id128k (descriptive). Reported: the first divergent token index per prompt (re-tokenised with
  the production tokenizer). Gate: every needle B1 answers right is answered right by the arm. A divergence counts
  against a setting only where B2 reproduces B1.
- **Prompts.** `nat4k` is `src/core/conversation_memory.cpp` of the v0.2.6 tree with a review question; the agent system
  text is cut from the Strata docs (3,771 tokens) plus 33 Hermes TUI tool definitions; the tiny chats, the sampled 4K
  prompt and the counting tiers come from the round's earlier fixtures and the lab's `bench_ctx.py`. The fixture files
  and the harness are lab tooling on the measuring machine and are not included; the engine's own counts for every
  request are in the logs.

## Which settings are here, and why each is not byte-identical

Classes and citations are from the round's switch audit. Line numbers are as the audit cites them: at v0.2.6
`4b9e05a2` for A6 to A22, and in the deployed `4b7dcaf2` tree (the one the binary was built from) for A24, A25, A28 and
A30 to A33. The two fork commits touch only `qsa_select`, `prefill.cpp`, `generate.cpp` and `conversation_state.cpp`.

| Arm | Setting | Why the output is not byte-identical |
|---|---|---|
| A6 | `STRATA_EXP_MODE=8` | On sm_86 the default IQ4_NL down projection sums with the 8-lane `row_dot_sub8` path (`iq_kernels.cu:2191-2192`), while mode 8's `native_down_lds_kernel` sums lane-strided items with a 32-lane `warp_sum` (`:4829-4846`): a different summation order, so the code's "bitwise" comments are not shown to hold on this card |
| A7 | `--spec 5` | Every token is the target's, but verify windows grow to 7 tokens (`generate.cpp:3213-3216`; `strata verify: window up to 7 tokens`, `verify.cpp:1088`) and the window shape changes the GPU's rounding in the production lane (greedy ids match only with `STRATA_IQ_MT_MIN=1`) |
| A8 | `--spec 6` | As A7, with windows up to 8 tokens, the cap (`kVerifyMaxT = 8`, `verify_kernels.hpp:21`) |
| A9 | `--mtp-draft-vocab data/draft_vocab_en.bin --mtp-q4 head` | Drafts only: the 40,525-token draft subset (`mtp.cpp:692-737`) and the Q4_0 draft head (`:242`) change acceptance and therefore window shapes, which changes rounding as for A7 |
| A10 | `STRATA_SPEC_COUPLED=1 STRATA_SPEC_GUMBEL=1 STRATA_SPEC_MIN_TEMP=0.9` | Sampled requests at temperature >= 0.9 draft with the target's chain and a Philox draw (`mtp.cpp:604`, `:610`; `coupled_draft.hpp:57-62`, `sampler.cu:1112`, `spec_prob.hpp:67-71`): the output distribution is preserved, not the seeded token sequence; greedy requests are unaffected |
| A11 | `STRATA_PREFILL_CPU_SHARE=auto STRATA_PREFILL_CPU_SHARE_MAX=3072` | The CPU computes the shared experts of staged prompt chunks up to 3,072 tokens instead of the default 1,024 (`prefill.cpp:204-212`, `:221-229`, `:2430`); the CPU rounds differently from the GPU (mean KL about 0.004, `:2427-2429`) |
| A12 | `STRATA_KV_PREFETCH=1` | Classified rounding-level (deterministic-lane identical in round 5); it acts only on layers whose K/V stream from RAM, i.e. prompts past the 32,768 resident cells (`prefill.cpp:2603-2606`, `:5033`). This round found no attributable divergence: identical on every greedy identity prompt, and where it differed the control differed identically |
| A19 | `STRATA_PREFILL_STREAM_MIN=4096` | Chunks of 1,024 to 4,095 tokens move from the streaming ring to the 8-slot STAGE path (`prefill.cpp:184-188`, `:138`, `:318`, `:330`, `:1275`), and `arm_cpu_share` makes the same value the default CPU share's staged-chunk limit (`:2430`), so the CPU also rounds those chunks' shared experts. Measured: id1k diverges at token 4 |
| A20 | `STRATA_PREFILL_STREAM_MIN=6144` | As A19 for chunks of 1,024 to 6,143 tokens |
| A22 | A20 + A11 | `stream_all_min()` returns an explicit `STRATA_PREFILL_STREAM_MIN` first (`prefill.cpp:184-188`), so `CPU_SHARE_MAX` cannot reach the staged-chunk limit (`:2430`, `:2912-2919`): the code predicts A20's behaviour plus an explicit share; rounding-changing as both |
| A24 | `STRATA_QSA_SPLIT_ATTN=1` | Replaces the sm_86 default `ATTN_DAILY` decode attention with the split kernel, "Not bitwise the decode kernel" (`qsa_prompt_attn.hpp:37-41`; `docs/DETAILS.md:920` "Rounding level") |
| A25 | `STRATA_HC_REQ8=1` | Requantises the hyper-connection projections to int8 plus an fp32 scale per 32 values (`weights.cpp:525-597`), "opt-in, changes the output" (`generate.cpp:4104`); the freed VRAM also raises the expert slots to 10,636 |
| A30 | `--adapt-swaps 192` | The adaptive tier's per-round swap cap 96 -> 192 (deployed `generate.cpp:10708`). Residency decides which experts the GPU computes and the GPU rounds differently from the CPU (`nv_defaults.hpp:35-36` and the start-up note), so any residency change is rounding-changing |
| A31 | `--adapt-every 2` | A tier round every 2 verify windows instead of 4 (deployed `generate.cpp:15532`); rounding-changing as A30 |
| A32 | `--adapt-decay 0.5` | Expert-use counts decay by 0.5 instead of 0.7 per round (deployed `generate.cpp:10840`); rounding-changing as A30 |
| A33 | `--adapt-min-gain 1.2` | A swap needs a count margin of 1.2 instead of 1.5 (deployed `generate.cpp:10703`); rounding-changing as A30 |
| c7 | A18 + A19 + A12 + A21 | Contains A19 (rounding-changing) and A12 (rounding-level); A18 and A21 are exact |
| c11 | c7 + A32 (the full set) | Contains A19 and A32 (rounding-changing) and A12 (rounding-level); A18 and A21 are exact |

Not here, because the audit classifies them exact (same bytes, or placement only): A1 to A5, A13 to A18, A21, A23 and
A26 to A29. In particular **A28 `STRATA_QFUSE=1` is exact** ("the same bytes", `verify.cpp:165`; "the bytes the separate
launch writes", `fused_gr.cu:219-223`): its real-traffic slowdown (`D_real` 0.851 and 0.856) is a speed result, not an
output change.

## The full set (c11): configuration change, not applied

The change the round staged for production's config (`apply_r7c.py full`): two `env` keys added to the four deployed
ones, three flags appended to `args`, the binary unchanged. The resulting fields (the elided part of `args` is
production's, unchanged):

```text
"env": {
  "STRATA_TOPK_SPLIT": "1",
  "STRATA_CKPT_POOL": "1",
  "STRATA_SELECT_TWO_PASS": "1",
  "STRATA_CKPT_ASYNC": "1",
  "STRATA_PREFILL_STREAM_MIN": "4096",
  "STRATA_KV_PREFETCH": "1"
},
"args": [ ..., "--conversation-cache-mib", "8192", "--ple-io", "mmap", "--pool-workers", "15", "--adapt-decay", "0.5" ]
```

The command line of a full-set run as its engine logged it ends `... --conversation-cache-mib 8192 --ple-io mmap
--pool-workers 15 --adapt-decay 0.5` (`logs/r7-pa-c11/c11-02-N.txt`), with `STRATA_PREFILL_STREAM_MIN=4096` and
`STRATA_KV_PREFETCH=1` in the engine's environ.

| Member | Setting | Class |
|---|---|---|
| A18 | `--ple-io mmap` (PLE table through the page cache instead of direct reads) | exact |
| A19 | `STRATA_PREFILL_STREAM_MIN=4096` | rounding-changing |
| A12 | `STRATA_KV_PREFETCH=1` | rounding-level |
| A21 | `--pool-workers 15` (no `--aux-cpus`) | exact (placement) |
| A32 | `--adapt-decay 0.5` | rounding-changing |

c7 is the same set without A32 (`--adapt-decay 0.5`); c11 superseded it. **Neither is deployed.**

### Combined-arm gate (median of two pairs, combined / production; `T0`, `T1`, `F` as production / combined)

c12, the output-exact set production runs now, is shown for contrast only; it is not part of this directory.

| Tier or metric | Kind | c7 | c11 (full set) | c12 (exact set, deployed) |
|---|---|---|---|---|
| tiny decode | greedy decode | 1.0542 | 1.0852 | 1.0501 |
| cnt1k decode | greedy decode | 0.9944 | 0.9927 | 0.9934 |
| cnt4k decode | greedy decode | 0.9967 | 0.9957 | 0.9973 |
| cnt32k decode | greedy decode | 1.0010 | 1.0048 | 1.0091 |
| cnt128k decode | greedy decode | 1.0009 | 0.9997 | 1.0041 |
| cnt256k decode | greedy decode | 0.9991 | 1.0042 | 1.0021 |
| nat4k decode | greedy decode | 1.0186 | 1.0442 | 1.0446 |
| cnt4k prompt read | prompt read | 1.0706 | 1.0675 | 1.0629 |
| cnt32k prompt read | prompt read | 1.0250 | 1.0368 | 1.0499 |
| cnt128k prompt read | prompt read | 1.0586 | 1.0696 | 1.0654 |
| cnt256k prompt read | prompt read | 1.0729 | 1.0884 | 1.0633 |
| `T0` | prompt ms | 1.3577 | 1.3994 | 1.2588 |
| `T1` | prompt ms | 1.1680 | 1.2067 | 1.1220 |
| `F` | prompt ms | 1.7390 | 1.7541 | 1.2969 |
| samp4k decode | sampled (reported) | 1.0407 | 1.0336 | 1.0725 |
| agent decode | sampled (reported) | 1.0718 | 1.0973 | 1.0416 |
| `D_win` | metric | 0.9973 | 0.9977 | 0.9999 |
| `D_real` | metric | 1.0425 | 1.0579 | 1.0526 |
| **Gate** | no gated median below 0.98 | PASS | PASS | PASS |

### What a Hermes session sees (production -> combined, each side the mean of its two runs)

| Moment | Measured as | c11 full set (not deployed) | c7 (superseded) | c12 exact set (deployed) |
|---|---|---|---|---|
| New session, first read | `T1`: agent turn 1, 18,768 tokens read fresh | 11,248 -> 9,322 ms (-17.1%) | 11,066 -> 9,474 ms (-14.4%) | 11,028 -> 9,829 ms (-10.9%) |
| Follow-up turn read | `F`: agent turn 2, 1,786 new tokens on the parked conversation | 3,029 -> 1,727 ms (-43.0%) | 2,962 -> 1,703 ms (-42.5%) | 3,006 -> 2,318 ms (-22.9%) |
| Short chat, first token | `T0`: median tiny prompt ms | 158 -> 113 ms (-28.5%) | 150 -> 111 ms (-26.3%) | 142 -> 113 ms (-20.5%) |
| Decode per token, agent turns | 1000 / pooled agent decode tok/s | 9.8 -> 9.0 ms (-8.9%) | 9.9 -> 9.3 ms (-6.2%) | 9.3 -> 9.0 ms (-3.9%) |
| Decode per token, sampled thinking-on | 1000 / pooled samp4k decode tok/s | 9.6 -> 9.3 ms (-3.3%) | 9.8 -> 9.4 ms (-3.9%) | 9.8 -> 9.2 ms (-6.8%) |
| Decode per token, greedy natural text | 1000 / pooled nat4k decode tok/s | 10.1 -> 9.7 ms (-4.2%) | 10.1 -> 9.9 ms (-1.8%) | 10.2 -> 9.7 ms (-4.2%) |
| Long prompt read, 128K | cnt128k run-2 prompt read | 2,211 -> 2,365 tok/s (+7.0%) | 2,218 -> 2,348 tok/s (+5.9%) | 2,215 -> 2,360 tok/s (+6.5%) |
| Long prompt read, 256K | cnt256k prompt read (one run) | 2,078 -> 2,261 tok/s (+8.8%) | 2,087 -> 2,239 tok/s (+7.3%) | 2,081 -> 2,213 tok/s (+6.3%) |

Each batch has its own baselines. c7 and c11 differ by A32 and by about five hours; on their shared metrics they agree
to within 1 to 4 points (`F` 1.739 against 1.754, `T1` 1.168 against 1.207, `R256` 1.073 against 1.088), which is the
batch-to-batch spread to read these columns against. The full set's lead over the exact set is
mainly the follow-up read (-43% against -23%; A19's STAGE band, which is rounding-changing, is what shortens a
1,786-token read) and the first read (-17% against -11%). The round's target (+10% on `D_real` and on `D_win`) was not
met by any set: `D_win` is flat in all three.

## Files

| Path | Content |
|---|---|
| `matrix.md` | one row per setting: class, primary, every pair ratio, four-pair median and interval, verdict, first divergent token per identity prompt, needles; then the output checks prompt by prompt and the switch proofs |
| `logs/INDEX.md` | every run file with its batch, role, setting and lane |
| `logs/<batch>/BATCH.md` | the batch's own record from the round's results files: window, exit codes, production hashes before and after, per-run metrics, pair ratios, per-tier ratios, every run in compact form, the batch's reading |
| `logs/<batch>/<label>.txt` | one engine run: setting, lane, window, exe sha256, `STRATA_*` environ, recorded cmdline flags, the engine's `/metrics` at ready, the run's metrics, its pairs, the proof patterns and their counts, the start-up and switch-proof lines, every request line with its decode hit-rate line (and the PCIe-share, KV-prefetch and adaptive-tier lines) labelled with the harness step, and the needle answers for check runs |
| `logs/<batch>/check-*.json`, `check-*.md` | output-check analysis: per prompt identity, counts, first divergent token and character, needle comparison |
| `logs/gates/` | the gate computations quoted in `matrix.md` (screen pair ratios, four-pair medians and intervals, tier medians, combined-arm gates) |

Engine log lines are verbatim except for shortened paths. Request lines labelled `probe` are the counting tiers'
1-token calibration calls and `ready` is the readiness completion; neither enters a metric.

## Sanitisation and key scan

- Paths: the measuring machine's home directory is replaced by `<home>`. No host names, IP addresses, user names or
  e-mail addresses remain.
- No configuration files are included: the lab configs hold the server's API key and never left the measuring machine.
  Server logs and the raw per-request JSON are not included; the engine lines are the measurement.
- Key scan: every file in this directory (188 files, about 3 MB) was scanned for the server's real API key, read into
  memory from the measuring machine's config over SSH and never printed or written: 0 files contain the full value and
  0 contain any 16-character piece of it. A generic scan of the same files (this paragraph aside, which names the
  patterns) found no `api_key` or `api-key`, `Authorization` or `Bearer`, token prefixes (`sk-`, `ghp_`/`gho_`-style,
  `github_pat_`, `AKIA`, `xox`), `password` or `secret`, IPv4 address (version strings such as `0.1.40.3` aside), host
  alias or local host suffix, home path, `user@host`, e-mail address, em or en dash, or other non-ASCII character. The
  only 64-hex strings are the two binary hashes above (`strata` and `libstrata_kq.so`), and the only personal name is
  the author's at the top of this file. The round's harness had also key-scanned every batch directory on the measuring
  machine before copying it (0 files with the key).

## Limits

- One machine, one model and quantisation (IQ3_XXS), engine 0.1.51 on Strata v0.2.6 plus two fork commits; KVM guest
  with an unlocked tensor rate at a 250 W cap. Numbers do not transfer to other hardware or revisions.
- Two pairs per screen and four per confirmation; the bootstrap interval of four ratios is coarse. Combined arms have two
  pairs and no interval.
- c11 has no joint output check of all five members; its members were checked separately, and the c7 subset jointly
  (descriptive). A12 acts only past 32,768 cells, so most checked prompts do not exercise it.
- A18 (a member of both sets) was measured with the PLE table warm in the page cache; the cold-from-disk case is
  unmeasured.
- In batches L2 and L3 the agent follow-up time `F` is not valid for comparison (a harness label bug, fixed from the next
  batch); no primary there was `F`.
- The settings are reported as measured on this build; nothing here is a recommendation to change a default.
