# r7-pa-c6

- Job exit 0, restore exit 0 (the lab wrapper stopped production, ran the job, restored production and verified it with a real completion).
- Runs in this directory: c6-01-B, c6-04-A11, c6-05-A19, c6-06-A22, c6-07-A12, c6-08-AC, c6-09-B.
- Runs of this batch not copied here (exact-class settings, or baselines paired only with them): c6-02-A18 (A18), c6-03-A21 (A21).
- Below: the batch's section from the round's `RESULTS.md`, verbatim except shortened paths. Paths such as `phase-a/raw/...` and `plans/...` refer to the lab workspace and are not part of this directory.
- `check-c6.md` and `check-c6.json` also hold the exact arms A18 and A21 (their runs are not copied here); its verdict column is the raw comparison, which the round reads together with the B2 control (decision 39 below).

### r7-pa-c6 (output checks: deterministic lane, everything confirmed plus the provisional combined set)

- Window: 2026-10-26T19:35:05+00:00 to 2026-10-26T20:02:34+00:00 UTC; job exit 0, restore exit 0; elapsed in the job 1608.9 s.
- Production config sha256 before / after: `92c2f588c6bb7d02` / `92c2f588c6bb7d02`; exe `26da5a7e53bf79a1` / `26da5a7e53bf79a1`; PRODCHECK-POST rc=0; PRODCHECK-PRE rc=0; REALREQ-POST rc=0; REALREQ-PRE rc=0; GPU-POST 250.00 W; restore: restored True, max_context 262144.
- Pattern: outcheck. Groups: -.
- Arms: 9 run, 0 skipped (-), 0 failed (-); proof not ok: none.
- Raw: `phase-a/raw/gpu/r7-pa-c6/` (arm.json, provenance.json, engine.log, server.log, bench JSON per arm).
- Pattern: per decision 33, B1 (reference) then A18, A21, A11, A19, A22, A12 (each alone), then one descriptive arm with the provisional combined set (A18 + A19 + A12 + A21), then B2 (the control); every arm a fresh server and engine, the lane `STRATA_PREFILL_CPU_SHARE=0 --pcie-frac 0.32 --adapt-every 0`, the prefill arms carrying their own prefill env instead of the share's 0 (`pcie_frac` 0.32 recorded in every arm's provenance). Steps: tiny x6 (64 tokens), id1k and id32k (256), the agent pair (thinking on, card defaults, seed 4242, 33 tools, 384), the seeded needle bench (8k/16k/28k x 3 depths), then id128k (256) for B1, A12, the combined arm and B2.
- Proof ok in all nine arms (A18: `--ple-io mmap` present and no direct-mode line; A21: `15 pool workers`; A12: KV prefetch lines; A11/A19/A22: environ; the baselines print `30 pool workers`, the direct-mode lines and the default share notice). Needles 9 of 9 in every arm, 72 to 75 s per arm.
- Harness: `r7check.py` `fb9c7841...`, plan `plans/r7-pa-c6.json` `8e359a66...` (dry run 64 checks, `DRYRUN3 OK`, the same file as the tested plan). Analysis: `scripts/check_analyse.py` with the production tokenizer (the Mac copies of `vocab.json`, `merges.txt`, `token_type.json`, `tokenizer.json` are byte-identical to `<home>/Strata-data/packs/swift-iq3_xxs/tokenizer/`, checked). Keyscan: 67 files, 0 with the key.


#### Output checks against B1 (deterministic lane)

| Arm | Members | Class | Proof | pcie_frac | tiny:0 | tiny:1 | tiny:2 | tiny:3 | tiny:4 | tiny:5 | id1k | id32k | agent:1 | agent:2 | id128k | needles found (arm/B1) | answers equal | Verdict |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c6-01-B | (reference) | lane baseline | ok | 0.32 | - | - | - | - | - | - | - | - | - | - | - | 9 of 9 | - | reference |
| c6-02-A18 | A18 | exact | ok | 0.32 | same | same | same | same | same | same | same | same | tok 270 / char 1153 | same | - | 9/9 | yes | identity on every greedy prompt; agent:1 differs where the control also differs (decision 39) |
| c6-03-A21 | A21 | exact | ok | 0.32 | same | same | same | same | same | same | same | same | tok 270 / char 1153 | same | - | 9/9 | yes | identity on every greedy prompt; agent:1 differs where the control also differs (decision 39) |
| c6-04-A11 | A11 | rounding | ok | 0.32 | same | same | same | same | same | same | tok 33 / char 213 | same | tok 27 / char 135 | tok 3 / char 15 | - | 9/9 | yes | PASS (needles right wherever B1 is right) |
| c6-05-A19 | A19 | rounding | ok | 0.32 | same | same | same | same | same | same | tok 4 / char 29 | same | tok 27 / char 135 | tok 16 / char 73 | - | 9/9 | yes | PASS (needles right wherever B1 is right) |
| c6-06-A22 | A22 | rounding | ok | 0.32 | same | same | same | same | same | same | tok 3 / char 20 | same | tok 27 / char 135 | tok 10 / char 46 | - | 9/9 | yes | PASS (needles right wherever B1 is right) |
| c6-07-A12 | A12 | rounding | ok | 0.32 | same | same | same | same | same | same | same | same | same | tok 52 / char 248 | tok 66 / char 280 | 9/9 | yes | PASS (needles right wherever B1 is right) |
| c6-08-AC | A18+A19+A12+A21 | rounding | ok | 0.32 | same | same | same | same | same | same | tok 6 / char 55 | same | tok 28 / char 141 | tok 10 / char 46 | tok 12 / char 69 | 9/9 | yes | PASS (needles right wherever B1 is right) |
| c6-09-B | B | control | ok | 0.32 | same | same | same | same | same | same | same | same | same | tok 52 / char 248 | tok 66 / char 280 | 9/9 | yes | control: agent:2 and id128k differ from B1 (the lane is not reproducible there) |

Cells: `same` = byte-identical generated stream with equal prompt/reused/read counts; `tok N / char M` = the first divergent token index (re-tokenized, 0-based) and character index against c6-01-B. The table is the raw comparison; the exact-class verdicts are read with the control (decision 39).

#### Needles per (length, depth): found in the arm / in c6-01-B, answers byte-equal

| Arm | 8k @10% | 8k @50% | 8k @90% | 16k @10% | 16k @50% | 16k @90% | 28k @10% | 28k @50% | 28k @90% |
|---|---|---|---|---|---|---|---|---|---|
| c6-02-A18 | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |
| c6-03-A21 | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |
| c6-04-A11 | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |
| c6-05-A19 | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |
| c6-06-A22 | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |
| c6-07-A12 | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |
| c6-08-AC | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |
| c6-09-B | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |

#### Generated tokens per prompt (engine count, arm / c6-01-B)

| Arm | tiny:0 | tiny:1 | tiny:2 | tiny:3 | tiny:4 | tiny:5 | id1k | id32k | agent:1 | agent:2 | id128k |
|---|---|---|---|---|---|---|---|---|---|---|---|
| c6-02-A18 | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 68/68 | 252/252 | 318/316 | 212/212 | - |
| c6-03-A21 | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 68/68 | 252/252 | 318/316 | 212/212 | - |
| c6-04-A11 | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 67/68 | 252/252 | 384/316 | 222/212 | - |
| c6-05-A19 | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 69/68 | 252/252 | 327/316 | 380/212 | - |
| c6-06-A22 | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 74/68 | 252/252 | 384/316 | 384/212 | - |
| c6-07-A12 | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 68/68 | 252/252 | 316/316 | 354/212 | 137/125 |
| c6-08-AC | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 69/68 | 252/252 | 135/316 | 299/212 | 136/125 |
| c6-09-B | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 68/68 | 252/252 | 316/316 | 354/212 | 137/125 |

#### c6 reading (computed)

- **The lane is byte-deterministic for every greedy prompt**: tiny x6, id1k and id32k are identical, with equal prompt / reused / read counts, in every arm against B1, including the two exact-class arms and the control. The identity evidence for A18 and A21 therefore holds on every greedy prompt of the check.
- **The agent pair is not reproducible in this lane, and the control says so**: B2 (the same production settings as B1, a different process) differs from B1 at agent:2 token 52 (character 248) and at id128k token 66, while A12 reads exactly as B2 does there. In the same way A18 and A21 differ from B1 only at agent:1 token 270. Two identical baselines already diverge on the sampled agent turns (thinking on, temperature 1.0, fixed seed 4242 but a fresh process each), so a per-arm agent-pair difference cannot be attributed to any switch. This is the condition decision 33 named as unattributable, and the baseline-versus-baseline control is what establishes it here; the exact-class verdict below rests on the prompts where the lane does reproduce.
- **Verdicts as decided before the data**: exact classes (A18, A21): identity holds on tiny x6, id1k, id32k and id128k (all byte-identical, equal counts), and their needle answers are byte-equal to B1's 9 of 9; the agent pair is un-attributable in this lane (B2 differs from B1 there as they do). Rounding-changing classes (A11, A19, A22, A12, and the combined set): every needle B1 answers right is answered right, with byte-equal answers, 9 of 9 in each (the gate); their first divergent greedy token is reported (A11 id1k token 33; A19 token 4; A22 token 3; A12 none among the greedy identity prompts, agent:2 token 52 as B2; the combined set id1k token 6, id32k identical).
- **A12's own mechanism is not exercised by these prompts**: all the gated prompts are below the 32,768 resident cells, so its KV prefetch is inert here (`strata KV prefetch: 0 layer prefixes` on every prompt below 32K, which the arms' logs show); id128k (126,948 tokens) is the only prompt past it, and there A12 reads its layer prefixes and differs from B1 at token 66, exactly where B2 differs from B1. Its byte behaviour past 32K is therefore as reproducible as the lane itself, which the control bounds.
- **The combined set (A18 + A19 + A12 + A21) answers every needle 9 of 9 byte-equal**, and its greedy identity prompts diverge only at id1k token 6, which is A19's rounding; its id128k reads as B2 does. This is the descriptive check of decision 37, not a gate.

39. **How the exact-class identity rule is read when the control fails (decided after c6's data, and stated as such)**: c6's
    B2 control differs from B1 at agent:2 (token 52) and id128k, so the sampled agent pair is not reproducible between two
    identical baselines in this launcher. A18's and A21's identity is therefore reported as: byte-identical with equal
    counts on every greedy prompt of the check (tiny x6, id1k, id32k, and id128k for A18), their needle answers byte-equal
    9 of 9, and the agent pair un-attributable because the control itself differs there. The alternative (recording both
    arms as failing byte identity on the agent pair) would attribute to a switch a difference that two baselines show
    between themselves; the raw per-step comparison is in `raw/gpu/r7-pa-c6/` and in `scripts/check_analyse.py`'s tables,
    so the parent can read it either way. No threshold, pair or primary is changed.
