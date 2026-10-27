# Matrix: round-7 settings that are not byte-identical (RTX 3090 / Xeon E5-2698 v4, Strata v0.2.6 + two fork commits, engine 0.1.51)

One row per setting whose output is not byte-identical to production's greedy output, plus the two combined sets that
contain such settings. Every number is engine-measured (the engine log's `strata serve: prompt N tokens = ...` line),
token-weighted, and copied from the round's gate computations (`logs/gates/`) and batch records (`logs/<batch>/BATCH.md`).
Method, metrics and gates: [README.md](README.md#method). None of these settings is deployed.

Notation. Ratios are arm / adjacent baseline (higher is better), and baseline / arm for `F`, `T0`, `T1`. `scr` = a screen
pair, `rev` = a reversed-half pair (descriptive, never gated), `conf` = a confirmation pair (opposite order, later batch).
Four-pair median: the two screen pairs plus the two confirmation pairs, with the percentile bootstrap 95% interval (20,000
resamples, seed 20261026); "screen only" = the arm stopped at its screen. Divergence: the first divergent token index
(0-based, re-tokenised with the production tokenizer) per identity prompt against the batch's B1 reference; `=` =
byte-identical generated stream with equal prompt, reused and read counts. Needles: seeded `tools/needle_bench.py`
8K/16K/28K at depths 10/50/90, found by the arm / 9, answers compared byte for byte with B1's.

## Main table

| Arm | Setting | Output class | Primary | Every pair ratio on the primary | Four-pair median [95%] | Verdict | First divergent token per identity prompt | Needles | Logs |
|---|---|---|---|---|---|---|---|---|---|
| A6 | `STRATA_EXP_MODE=8` | rounding-changing | `D_win` | scr 1.012, 1.014; rev 1.014, 1.013 | screen only | no measurable effect (both screen pairs inside 0.98 to 1.02); the closest miss of the round | not run (stopped at the screen) | not run | [L2](logs/r7-pa-L2/) |
| A7 | `--spec 5` (production `--spec 4`) | output-preserving, window shapes change | `D_win` and `D_real` | `D_win` scr 1.056, 1.057; rev 1.060, 1.060; conf 1.068, 1.054. `D_real` scr 1.003, 1.003; rev 0.932, 0.942; conf 0.917, 0.949 | `D_win` 1.0565 [1.0539, 1.0680]; `D_real` 0.9759 [0.9172, 1.0034] | rejected: the greedy tier rule fails (tiny decode median 0.8661, nat4k decode 0.9646); the gain exists only where every draft is accepted | not run | not run | [L3](logs/r7-pa-L3/), [c1](logs/r7-pa-c1/) |
| A8 | `--spec 6` | output-preserving, window shapes change | `D_win` and `D_real` | `D_win` scr 1.109, 1.108; rev 1.101, 1.097; conf 1.103, 1.099. `D_real` scr 0.974, 0.930; rev 0.969, 0.983; conf 0.929, 0.923 | `D_win` 1.1057 [1.0992, 1.1091]; `D_real` 0.9296 [0.9233, 0.9740] | rejected: the predeclared `D_real` >= 0.98 condition fails; tiny decode 0.8811, nat4k 0.9483 | not run | not run | [L3](logs/r7-pa-L3/), [c2](logs/r7-pa-c2/) |
| A9 | `--mtp-draft-vocab data/draft_vocab_en.bin --mtp-q4 head` | drafts only: output-preserving, window shapes and acceptance change | `D_real` | scr 0.996, 1.006; rev 1.001, 0.988 (`D_win`, descriptive: 1.022, 1.018; rev 1.021, 1.026) | screen only | no measurable effect | not run | not run | [L3](logs/r7-pa-L3/) |
| A10 | `STRATA_SPEC_COUPLED=1 STRATA_SPEC_GUMBEL=1 STRATA_SPEC_MIN_TEMP=0.9` | distribution-preserving (not seed-identical) | `D_real` over samp4k and agent (`D_SA`) | scr 1.049, 1.028; conf 1.008, 1.005 (full `D_real`: scr 1.041, 1.030; rev 1.040, 0.995; conf 1.024, 1.013) | 1.0179 [1.0053, 1.0489] | not confirmed (median below 1.02) | not run | not run | [L4](logs/r7-pa-L4/), [c4](logs/r7-pa-c4/) |
| A11 | `STRATA_PREFILL_CPU_SHARE=auto STRATA_PREFILL_CPU_SHARE_MAX=3072` | rounding-changing | `F` | scr 1.466, 1.471; rev 1.505, 1.477; conf 1.544, 1.564 (`P`: 0.999, 0.996, 1.011, 1.005) | 1.5076 [1.4656, 1.5638] | confirmed; not chosen (a member with more settings needed 1.02 x A19's 1.4847 = 1.5144) | c6, deterministic lane: tiny x6 =; id1k 33; id32k =; agent:1 27; agent:2 3 | 9/9, equal | [L4](logs/r7-pa-L4/), [c3](logs/r7-pa-c3/), [c6](logs/r7-pa-c6/) |
| A12 | `STRATA_KV_PREFETCH=1` | rounding-level | `R128` (cnt128k prompt read) | scr 1.063, 1.061; conf 1.059, 1.056 (`R256`: 1.062, 1.075) | 1.0602 [1.0560, 1.0630] | confirmed; member of c7 and c11 | c6: tiny x6, id1k, id32k, agent:1 all =; agent:2 52 and id128k 66, exactly where the B2 control differs (no attributable divergence) | 9/9, equal | [L5](logs/r7-pa-L5/), [c5](logs/r7-pa-c5/), [c6](logs/r7-pa-c6/) |
| A19 | `STRATA_PREFILL_STREAM_MIN=4096` | rounding-changing | `F`, then `R4` | `F` scr 1.488, 1.473; rev 1.488, 1.481; conf 1.525, 1.482. `R4` scr 1.086, 1.064; rev 1.059, 1.083; conf 1.085, 1.076 | `F` 1.4847 [1.4728, 1.5252]; `R4` 1.0808 [1.0637, 1.0860] | confirmed; the chosen prefill setting (`R32` condition holds, median 0.9971); member of c7 and c11 | c6: tiny x6 =; id1k 4; id32k =; agent:1 27; agent:2 16 | 9/9, equal | [c2](logs/r7-pa-c2/), [c3](logs/r7-pa-c3/), [c6](logs/r7-pa-c6/) |
| A20 | `STRATA_PREFILL_STREAM_MIN=6144` | rounding-changing | `F`, then `R4` | `F` scr 1.494, 1.511; rev 1.484, 1.465; conf 1.457, 1.521. `R4` scr 1.137, 1.146; rev 1.143, 1.144; conf 1.110, 1.135 | `F` 1.5027 [1.4570, 1.5211]; `R4` 1.1363 [1.1102, 1.1462] | not confirmed: the greedy tier rule fails on nat4k decode (median 0.9677; pairs 0.970, 1.073, 0.959, 0.965) | not run | not run | [L8](logs/r7-pa-L8/), [c3](logs/r7-pa-c3/) |
| A22 | `STRATA_PREFILL_STREAM_MIN=6144 STRATA_PREFILL_CPU_SHARE=auto STRATA_PREFILL_CPU_SHARE_MAX=3072` (A20 + A11) | rounding-changing | `F`, then `R4` | `F` scr 1.473, 1.482; conf 1.515, 1.527. `R4` scr 1.128, 1.122; conf 1.152, 1.143 | `F` 1.4988 [1.4729, 1.5271]; `R4` 1.1352 [1.1222, 1.1525] | confirmed; not chosen (1.4988 below 1.5144) | c6: tiny x6 =; id1k 3; id32k =; agent:1 27; agent:2 10 | 9/9, equal | [c4](logs/r7-pa-c4/), [c6](logs/r7-pa-c6/) |
| A24 | `STRATA_QSA_SPLIT_ATTN=1` | rounding-changing | `D_win` | scr 1.016, 1.020; rev 1.014, 1.010; conf 1.016, 1.014 (`D_real`: 1.063, 1.041, 0.990, 1.000) | 1.0162 [1.0142, 1.0201] | not confirmed (median below 1.02; tiny decode median 0.9843) | L12-check, deterministic lane: tiny 9, 62, 23, =, 4, =; id1k 16; id32k 39; agent:1 17; agent:2 0; id128k 12 (the control matches B1 on every gated prompt) | 9/9, equal | [L9](logs/r7-pa-L9/), [L12](logs/r7-pa-L12/) |
| A25 | `STRATA_HC_REQ8=1` | rounding-changing | `D_win` | scr 0.966, 0.969; rev 0.964, 0.963 (`D_real` condition: 0.985, 0.976) | screen only | regression: both screen pairs below 0.98 and the `D_real` condition fails | not run | not run | [L9](logs/r7-pa-L9/) |
| A30 | `--adapt-swaps 192` | rounding-changing | `D_real` (`D_win` >= 0.98 in both screen pairs) | scr 1.024, 1.013; rev 1.048, 1.020; conf 1.010, 0.980 (`D_win` scr 1.001, 1.011) | 1.0117 [0.9798, 1.0242] | not confirmed (median below 1.02, interval reaches below 1.0) | c10-check, adaptive lane: tiny 17, 25, 21, =, =, 0; id1k 51; id32k 162; agent:1 28; agent:2 2; id128k 11 | 9/9, equal | [L11](logs/r7-pa-L11/), [c10](logs/r7-pa-c10/) |
| A31 | `--adapt-every 2` | rounding-changing | as A30 | scr 1.009, 1.030; rev 1.008, 1.011; conf 0.989, 1.025 (`D_win` scr 1.009, 1.010) | 1.0172 [0.9886, 1.0298] | not confirmed (median below 1.02, interval reaches below 1.0) | c9-check, adaptive lane: tiny 17, 16, 29, =, =, 0; id1k 51; id32k 72; agent:1 28; agent:2 10; id128k 0 | 9/9, equal | [L11](logs/r7-pa-L11/), [c9](logs/r7-pa-c9/) |
| A32 | `--adapt-decay 0.5` | rounding-changing | as A30 | scr 1.031, 1.018; rev 1.053, 1.065; conf 1.033, 1.018 (`D_win` scr 1.003, 0.999) | 1.0246 [1.0182, 1.0325] | confirmed (every greedy tier >= 0.98, lowest cnt1k 0.9990); member of c11 | c9-check: tiny =, 16, =, =, 4, =; id1k 23; id32k =; agent:1 35; agent:2 0; id128k 0 | 9/9, equal | [L11](logs/r7-pa-L11/), [c9](logs/r7-pa-c9/) |
| A33 | `--adapt-min-gain 1.2` | rounding-changing | as A30 | scr 0.975, 1.012; rev 1.033, 1.043; conf 1.000, 1.025 (`D_win` scr 1.000, 1.002) | 1.0060 [0.9745, 1.0245] | not confirmed (median below 1.02, interval reaches below 1.0) | c10-check: tiny x6 =; id1k =; id32k 162; agent:1 31; agent:2 2; id128k 3 (the control differs at the same three points before id128k) | 9/9, equal | [L12](logs/r7-pa-L12/), [c10](logs/r7-pa-c10/) |
| c7 | A18 + A19 + A12 + A21: env `STRATA_PREFILL_STREAM_MIN=4096 STRATA_KV_PREFETCH=1`, args `--ple-io mmap --pool-workers 15` | mixed: A19 rounding-changing, A12 rounding-level, A18 and A21 exact | every gated tier (no median below 0.98) | `D_real` 1.077, 1.008; `D_win` 0.993, 1.002; `F` 1.756, 1.722; `T1` 1.158, 1.178; `T0` 1.405, 1.311; `R4` 1.075, 1.066; `R32` 1.018, 1.032; `R128` 1.057, 1.060; `R256` 1.067, 1.079 | two pairs, medians only: `D_real` 1.0425, `D_win` 0.9973, `F` 1.7390, `T1` 1.1680, `T0` 1.3577, `R256` 1.0729 | gate PASS (lowest gated median: cnt1k decode 0.9944); superseded by c11 | c6 combined run (descriptive): tiny x6 =; id1k 6; id32k =; agent:1 28; agent:2 10; id128k 12 | 9/9, equal | [c6](logs/r7-pa-c6/), [c7](logs/r7-pa-c7/) |
| c11 | full set = c7 + A32: env as c7, args `--ple-io mmap --pool-workers 15 --adapt-decay 0.5` | mixed: A19 and A32 rounding-changing, A12 rounding-level, A18 and A21 exact | every gated tier | `D_real` 1.051, 1.064; `D_win` 0.997, 0.998; `F` 1.762, 1.746; `T1` 1.214, 1.199; `T0` 1.442, 1.357; `R4` 1.068, 1.067; `R32` 1.035, 1.039; `R128` 1.067, 1.072; `R256` 1.088, 1.089 | two pairs, medians only: `D_real` 1.0579, `D_win` 0.9977, `F` 1.7541, `T1` 1.2067, `T0` 1.3994, `R256` 1.0884 | gate PASS (lowest gated median: cnt1k decode 0.9927); **not deployed** | no joint check of all five; the members were checked separately (A18, A19, A12, A21 and the c7 set in c6, A32 in c9) | members 9/9 | [c11](logs/r7-pa-c11/) |

## Output checks, prompt by prompt

| Check (lane) | Run | tiny:0 | tiny:1 | tiny:2 | tiny:3 | tiny:4 | tiny:5 | id1k | id32k | agent:1 | agent:2 | id128k | Needles |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c6 (deterministic) | B2 control | = | = | = | = | = | = | = | = | = | 52 | 66 | 9/9 |
| c6 | A11 | = | = | = | = | = | = | 33 | = | 27 | 3 | not run | 9/9 |
| c6 | A19 | = | = | = | = | = | = | 4 | = | 27 | 16 | not run | 9/9 |
| c6 | A22 | = | = | = | = | = | = | 3 | = | 27 | 10 | not run | 9/9 |
| c6 | A12 | = | = | = | = | = | = | = | = | = | 52 | 66 | 9/9 |
| c6 | c7 set (A18 + A19 + A12 + A21) | = | = | = | = | = | = | 6 | = | 28 | 10 | 12 | 9/9 |
| L12-check (deterministic) | B2 control | = | = | = | = | = | = | = | = | = | = | 66 | 9/9 |
| L12-check | A24 | 9 | 62 | 23 | = | 4 | = | 16 | 39 | 17 | 0 | 12 | 9/9 |
| c9-check (adaptive) | B2 control | = | = | = | = | = | = | = | = | 277 | 3 | 0 | 9/9 |
| c9-check | A32 | = | 16 | = | = | 4 | = | 23 | = | 35 | 0 | 0 | 9/9 |
| c9-check | A31 | 17 | 16 | 29 | = | = | 0 | 51 | 72 | 28 | 10 | 0 | 9/9 |
| c10-check (adaptive) | B2 control | = | = | = | = | = | = | = | 162 | 31 | 2 | 17 | 9/9 |
| c10-check | A30 | 17 | 25 | 21 | = | = | 0 | 51 | 162 | 28 | 2 | 11 | 9/9 |
| c10-check | A33 | = | = | = | = | = | = | = | 162 | 31 | 2 | 3 | 9/9 |

Reading the checks:

- A divergence is attributable to the setting only on a prompt where the B2 control (a second production process with
  the reference's settings) reproduces B1. In the deterministic lane the greedy prompts (tiny x6, id1k, id32k) reproduce
  exactly; the agent pair (thinking on, model-card sampling, seed 4242) and id128k do not always (c6's control differs at
  agent:2 and id128k). In the adaptive lane the tier's copy timing makes even a greedy prompt differ between two
  baselines (c10's control at id32k), so there the needle answers are the gate and the indices are a report.
- The gate for every rounding-changing or distribution-preserving setting that confirmed was: every needle B1 answers
  right is answered right by the arm. All checked runs found 9 of 9 with answers byte-equal to B1's. A24, A30, A31 and A33
  were checked although they did not confirm (descriptive).
- Settings that stopped at the screen or were rejected (A6, A7, A8, A9, A10, A20, A25) never reached an output check: the
  plan runs it only after a confirmation.
- Raw per-step comparisons, generated-token counts and needle answers: `check-*.json` and `check-*.md` in the check
  batch's directory; each run's needle answers are also at the end of its `<label>.txt`.

## Switch proof per setting

Every run was proven from the engine process: `/proc/<pid>/exe` and its sha256, `/proc/<pid>/environ` (`STRATA_*`
exactly production's plus the arm's) and `/proc/<pid>/cmdline` (production's args block intact plus the arm's flags).
Where the engine prints a line of its own, the run also had to show it and show no refusal line (the `want` and `absent`
lines at the top of each `<label>.txt`).

| Arm | Proof beyond environ and cmdline |
|---|---|
| A6, A19, A20, A24 | none printed (silent `getenv`); for A19, A20 and A22 the engine's `/metrics` reports `stream_all_min` 4096, 6144 and 6144 against 1024 in every baseline |
| A7, A8 | `strata verify: window up to 7 tokens` / `8 tokens` (baselines: 6); `/metrics` `spec` 7 / 8 |
| A9 | `strata mtp: draft head over 40525 tokens` and the `--mtp-q4` line (baselines: 106299 tokens) |
| A10 | `strata mtp: coupled draft sampling on (STRATA_SPEC_COUPLED) ...`; GUMBEL and MIN_TEMP print nothing |
| A11, A22 | the default notice `prefill: the CPU share is ON by default ...` absent (an explicit share suppresses it); `/metrics` `stream_all_min` 3072 (A11) |
| A12, c7, c11 | `strata KV prefetch: N layer prefixes, single existing staging pool` after every prompt read (N = 0 below 32,768 cells) |
| A25 | `strata generate: STRATA_HC_REQ8: hyper-connection projections as int8 + fp32/32 scales, 675 MiB`; expert slots 10,636 against 10,320 |
| A30 to A33, c11 | the flag once in the cmdline plus the tier line `adaptive tier: blocking, and the asynchronous tier is tried once ...`; no asynchronous-tier self-decision line printed in any run |
| c7, c11 | also `15 pool workers on logical processors 1..15` (A21) and the absence of the two direct-mode PLE lines (A18) |
