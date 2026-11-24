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
