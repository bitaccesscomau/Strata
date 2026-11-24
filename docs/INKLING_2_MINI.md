# Inkling 2 Mini: what the speed work measured

Inkling 2 Mini SQ-15 (MLX 8-bit affines, 256K window) on one RTX 3090, `--kv fp16` unless stated. Every number is a
median of repeated runs on one engine build; the logs sit in `~/ink-r24/logs/` on the bench host. Measurements are
power-of-two contexts: the prompt is exactly one block of 1792 tokens plus the window, so no block straddles.

## The served path, which is the number that matters

`strata-inkling --serve` (the mode production runs), 32K context, 400-token generations:

| case | v0.2.21 + the verify-window MoE fix | v0.2.19 + round-24 fixes |
|---|---|---|
| 1K greedy | 99.0 tok/s | 111.1 tok/s |
| 1K sampled | 88.2 tok/s | 81.8 tok/s |
| 30K greedy | 66.1 tok/s | 56.7 tok/s |
| 30K sampled | 62.5 tok/s | 40.9 tok/s |
| 32K greedy | 65.9 tok/s | 57.5 tok/s |
| 32K sampled | 56.6 tok/s | 53.6 tok/s |
| prefill | 1,924-2,408 tok/s | 973-1,186 tok/s |
| first token at 30K | 15.0 s | 29.5 s |

Upstream's engine wins five of six decode cases and doubles prefill; the round-24 build's single win (1K greedy) comes
with its shorter generations that stop on the anti-loop guard. Porting the round-24 fixes therefore means porting them
**onto** v0.2.21, not keeping the older engine.

### `--bench` decode is not the served path

The per-stage harness (`--bench`, and the development target `cuda/strata-inkling-cuda`) drives its own speculative
loop, `ink_spec_step_tree`: a fixed beam of 7 over 12 nodes, independent of the backend's `--draft-beam` /
`--draft-cost` / `--draft-plain` settings (sweeping those changes nothing there). Its decode figure moved differently
from the served one between the two releases, so it must not be used to judge the drafter. Use `--serve` for decode
speed and the harness only for per-stage costs (draft / verify / commit milliseconds).

## Parallel chats

Same build, 32K, 1K prompts, fp16 KV, aggregate decode over `--parallel N` slots:

| slots | 1 | 2 | 4 | 8 |
|---|---|---|---|---|
| aggregate decode | 85.0 tok/s | 96.5 tok/s | 153.1 tok/s | 225.0 tok/s |
| prefill | 2,696 tok/s | 2,658 tok/s | 2,544 tok/s | 2,174 tok/s |

Slots scale aggregate decode 2.65x at eight with prefill within 20%, so the engine handles concurrent chats well when
the card has room. `STRATA_INK_PREFILL_CAP=128` changed nothing here (92.4 vs 92.2 tok/s with two slots), so it is not a
lever on this model.

## 256K and the two-card question

At `--max-context 262144 --kv fp8` the card has 9,719 MiB free after the experts and the K/V wants 4,092 MiB per
256K slot: two slots fit, four do not. The auto prefill chunk falls from 2,048 to 512 once more than one slot is
configured, so a single-slot 256K entry is the fastest configuration for one chat.

Expert parallel across both cards (`--gpus 2`, 4K prompt, 32K) measured 2,133.7 tok/s prefill and 55.8 tok/s decode,
slower than one card (about 2,500 and 85-99), so there is no two-card win for this model on v0.2.21.

## What each change bought (single card, 4K prompt, 32K, fp16)

| change | effect |
|---|---|
| verify-window MoE reads each expert body once (row width from the rows a step holds) | the verify step's MoE drops from a 64-row grid per expert to one pass over the rows the window holds; the round-24 measurements put it at 118 -> 154 tok/s in that path, and it is what keeps the sampled path competitive |
| prefill attention in fixed 1792-token blocks with a bounded resident block set | the prefill path's MoE stops re-reading evicted expert bodies per chunk; combined with upstream's own prefill work it is the 2x prefill measured above |
| a check that every layer's K/V row is whole blocks | unchanged tensors on every existing path; the block kernel assumes it |
| `--kv auto` / `--parallel` | `auto` = fp8 whenever the card has 16 GB or more, fp16 otherwise; `--parallel` sets the slot count |

## Hill-climb: KV dtype, chunk, speculation shape (2026-11-25)

Method: `inference-optimisation` skill. Served path (`--serve`), 64K context unless said, one RTX 3090, 6 cells a run
(1K/30K/64K, greedy and sampled), interleaved controls, medians of repeated runs, a needle gate before promoting.
Ceilings in the bench kit's `THEORY.md`; every run in `~/ink-r24/results/ledger.jsonl`.

### KV dtype, 64K context, chunk 2048, five interleaved runs (tok/s)

| dtype | 1K greedy | 1K sampled | 30K greedy | 30K sampled | 64K greedy | 64K sampled |
|---|---:|---:|---:|---:|---:|---:|
| fp8 (E4M3) | 92.8-93.6 | 78.2-79.1 | 60.1-60.9 | 50.7-51.3 | 44.1-44.3 | 38.7-38.9 |
| **k8v8** | **95.8-96.3** | 71.9-72.2 | **64.7-64.9** | **61.4-61.6** | **52.4-52.6** | 41.4-41.5 |
| fp16 | 94.9 | **85.1** | 64.1 | 61.0 | 46.7 | **42.7** |

FP8_E4M3 — what `--kv auto` used to pick when memory was tight — is the slowest in every cell, at the same bytes per
element. K8V8 takes the short-context sampled cell badly (−15% against fp16, because the dequant is not amortised at a
1K sequence) and wins at depth (+12% at 64K greedy against fp16, +20% against fp8 at 30K sampled). FP16 cannot hold
256K on a 24 GB card, so the served 256K entry uses K8V8, and `--kv auto` now takes K8V8 in the branches that used to
take FP8 (verified: 16 slots at 8K selects `kv=k8v8`, 275.1 against 264.3 tok/s aggregate for explicit fp8).

### A needle at the end of the window

| config | context | result |
|---|---|---|
| k8v8 | 261,888 tokens | passphrase **found** (read 744.7 tok/s, decode 29.1, first token 352 s) |
| k8v4 | 65,280 tokens | **found** (decode 64.9 against fp16's 58.2) |
| fp16 | 65,280 tokens | **found** |

### Prefill chunk (30K prompt, prefill only)

| chunk | prefill |
|---:|---:|
| 1024 | 1,816.5 tok/s |
| **2048** | **1,919.8 tok/s** (+5.7%) |
| 4096 | 1,932.1 tok/s (+6.4%) |

2048 is the pick: nearly all of 4096's gain without a larger decode stall for a second chat.

### Speculation shape: rejected

`--draft-beam 1` (one linear chain) beat the default beam of 4 by 3.4-3.7% at 32K context, and again 3.1-3.6% in the
promotion window — but at 64K context it **regressed** 1K greedy by 7.4% and 30K sampled by 10.6% against both
controls. A win that does not hold across contexts is not promoted; the default stays.

### Dual card: rejected twice

Expert parallel (`--gpus 2`) measured 2,133.7 tok/s prefill and 55.8 tok/s decode; the layer split (`--gpus 2
--layer-split auto`, and `24,24`) 2,102.8-2,107.9 tok/s and 54.7-56.3 tok/s. One card does ~2,500 and 85-99. With no
peer-to-peer link the pipeline's transfers and serialisation cost more than the second card's bandwidth adds.

### Parallel chats, 32K, chunk 2048

Aggregate decode 82.6 / 93.6 / 149.1 / 220.1 tok/s at 1 / 2 / 4 / 8 slots; prefill 2,449 → 2,332. At 256K the card has
9,719 MiB free and a K8V8 slot's K/V wants 4.1 GB, so two slots fit and four do not.

## Second campaign: the head, prefix reuse, and the 2-slot gate (2026-11-25)

The decode step's phase profile names `unembed+softcap` at 15-17 ms a batch, but that interval is measured across a
stream synchronisation: it covers the whole queued 48-visit step, not the head. An isolated microbenchmark
(`cuda/head_bench.cu`, medians of 30 with a parity check) puts the head where it belongs:

| rows M | old launch (25,008 CTAs) | persistent grid (656 CTAs) | bytes/s |
|---:|---:|---:|---:|
| 1 | **1.098 ms** | 1.149 ms | 840 GB/s |
| 5 | **1.891 ms** | 2.417 ms | 487 GB/s |
| 12 | **5.514 ms** | 6.101 ms | 167 GB/s |

At M=1 the head already reads its 922 MB at 840 GB/s, which is this card's measured copy bandwidth, and the persistent
variants were 4-22% slower at every M (bit-identical output, 0 of 2,400,696 values differ). The change was reverted:
the head is not a lever. With the head out of the budget, a step at M=5 reads about 9-10 GB (dense 2.07 GB, the expert
union near 7 GB, the head 0.92 GB), a floor near 12 ms against a measured 15-17 ms — **the step is at roughly 75% of
its memory floor**, and everything left is fewer bytes per accepted token, which is drafter work.

Two gates came out clean this round:

- **Multi-turn prefix reuse works.** A 6,030-token document answered, then a follow-up: `RESUME 6330` of an expected
  6,330 tokens, first token 2.908 s → **0.092 s**.
- **Two slots at 256K pass.** Two concurrent 100,055- and 100,054-token requests with passphrases at 85 % depth both
  answered exactly (wall 173.5 s, 256K, k8v8, chunk 2048). The served entry now runs `--parallel 2`.

## Third campaign: the verify window is the lever that moves bytes (2026-11-25)

Decode had been flat against every config knob because the step's cost is the **union of experts its rows route to**,
and the window size was a literal 12. `--draft-nodes` (or `STRATA_INK_SPEC_NODES`) now sets it, 1..12, and the sweep at
32K context, one card, k8v8, chunk 2048, served path:

| nodes | 1K greedy | 1K sampled | 30K greedy | 30K sampled | 32K greedy | 32K sampled |
|---:|---:|---:|---:|---:|---:|---:|
| 12 (a) | 98.5 | 73.5 | 65.5 | 62.6 | 63.1 | 71.7 |
| 8 | 97.1 | 72.7 | 65.2 | 61.9 | 63.0 | 71.0 |
| 6 | 98.3 | 72.2 | 71.5 | 61.5 | 66.4 | 70.8 |
| **4** | **106.9** | 71.7 | **73.0** | 61.3 | **72.4** | 70.7 |
| 12 (b) | 96.1 | 72.1 | 64.8 | 61.4 | 62.1 | 70.7 |

A second window repeated four nodes (107.6 / 106.5 at 1K greedy, 72.4-73.7 at 30K) and showed three and two nodes below
it (104.0 / 103.9 at 1K, 69.3 / 69.2 at 32K), so four is the floor of useful acceptance. At depth, in the 256K entry
with a 60K prompt, four nodes gave 53.6 tok/s against 50.2-50.5 (+6.4%) with prefill unchanged. A step at four nodes
carries about 5-6 GB of weights against 9-10 GB at twelve.

### KV dtype at depth: k8v4 gates clean, but is workload-dependent

| config | 60K prompt | 131K prompt | needle at 261,888 |
|---|---:|---:|---|
| k8v8, 4 nodes | 53.5 | 33.4 | passed earlier |
| **k8v4, 4 nodes** | **58.9 (+10.1%)** | **35.3 (+5.7%)** | **passed** |

On the served path at 32K context, four interleaved runs say k8v4 wins 1K sampled (+20.2%), 32K greedy (+11.7%) and 1K
greedy (+4.1%), but loses 30K greedy (−3.7%) and 32K sampled (−20.3%). Past the 3% regression bar, so the served entry
keeps k8v8; k8v4 stays the documented long-context option.

Served entry: `--max-context 262144 --kv k8v8 --chunk 2048 --parallel 2 --draft-nodes 4`.

## Fourth campaign: shape, chunk, and a four-slot entry (2026-11-25)

At four nodes the window's *shape* stops mattering: beam 1, 2 and 4 give the same sampled cells (72 / 61.6 / 71 at
1K / 30K / 32K) and differ by noise on greedy, and `--draft-adapt` costs 7% on 30K sampled. The sampled-to-greedy gap
is acceptance, not shape.

A larger prefill chunk is the second served/bench disagreement: at a 30K prompt `--chunk 4096` beats 2048 by 1.2% in
the harness and loses 4.6% (30K greedy) and 7.6% (32K sampled) on the served path; at 256K it also leaves 3,977 MiB
free against 5,759, less than one 256K slot's K/V. 2048 stays.

Four slots at 64K are now a served entry of their own (`strata/inkling-2-mini-sq-15-64k`, `--parallel 4`): four
concurrent 60K-token requests with passphrases at 85% depth all answered, and through the router four concurrent 1K
generations ran **122.2 tok/s aggregate** (30.5 a stream) against 112.6 for one chat alone.

## Fifth campaign: where prefill time actually goes (2026-11-25)

`STRATA_INK_PROF=2` was printing only seven of sixteen phase buckets, so 38% of every prefill chunk looked
unattributed. With all buckets printed, one 2,048-token chunk at 23K context reads:

| phase | ms / chunk | share |
|---|---:|---:|
| MoE gate/up | 287 | 24% |
| MoE down | 138 | 12% |
| MoE remainder (bin/gather/scatter) | 225 | 19% |
| MoE router + top-k | 13 | 1% |
| **MoE total** | **663** | **56%** |
| attention | 165 | 14% |
| dense qkv | 146 | 12% |
| residual / control / norms | 117 | 10% |
| dense wo | 39 | 3% |
| unembed | 24 | 2% |
| short-conv + KV | 26 | 2% |

Prefill is MoE-bound, and the MoE path is the already-vectorised int8/dp4a one (`sk_unpack8_lane8`, unpack-once per
row): the next win there is expert-GEMM kernel work, not a flag. `STRATA_INK_MOE_V1=1` measured neutral (1,910-1,926
against 1,921-1,954 tok/s). An eight-wide S_K→BF16 dequant was written and made bit-correct (the first version faulted
with CUDA 716 because a 262-byte superblock gives no alignment guarantee) and measured no change, because the dense
linears are BF16 on SQ-15; it is reverted and the negative is recorded.

The four-slot 64K entry also passed a sustained soak this round: four 30,000-token requests with passphrases at 85%
depth, 93 s, four of four found.
