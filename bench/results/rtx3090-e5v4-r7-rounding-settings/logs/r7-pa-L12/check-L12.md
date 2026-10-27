### r7-pa-L12-check: output checks against L12c-01-B (deterministic lane)

| Arm | Members | Class | Proof | pcie_frac | tiny:0 | tiny:1 | tiny:2 | tiny:3 | tiny:4 | tiny:5 | id1k | id32k | agent:1 | agent:2 | id128k | needles found (arm/B1) | answers equal | Verdict |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| L12c-01-B | (reference) | lane baseline | ok | 0.32 | - | - | - | - | - | - | - | - | - | - | - | 9 of 9 | - | reference |
| L12c-02-A24 | A24 | rounding | ok | 0.32 | tok 9 / char 39 | tok 62 / char 303 | tok 23 / char 87 | same | tok 4 / char 15 | same | tok 16 / char 113 | tok 39 / char 163 | tok 17 / char 82 | tok 0 / char 0 | tok 12 / char 69 | 9/9 | yes | PASS (needles right wherever B1 is right) |
| L12c-03-B | B | control | ok | 0.32 | same | same | same | same | same | same | same | same | same | same | tok 66 / char 280 | 9/9 | yes | control: byte-identical to B1 with equal counts on every gated prompt |

Cells: `same` = byte-identical generated stream with equal prompt/reused/read counts; `tok N / char M` = the first divergent token index (re-tokenized, 0-based) and character index against L12c-01-B.

#### Needles per (length, depth): found in the arm / in L12c-01-B, answers byte-equal

| Arm | 8k @10% | 8k @50% | 8k @90% | 16k @10% | 16k @50% | 16k @90% | 28k @10% | 28k @50% | 28k @90% |
|---|---|---|---|---|---|---|---|---|---|
| L12c-02-A24 | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |
| L12c-03-B | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |

#### Generated tokens per prompt (engine count, arm / L12c-01-B)

| Arm | tiny:0 | tiny:1 | tiny:2 | tiny:3 | tiny:4 | tiny:5 | id1k | id32k | agent:1 | agent:2 | id128k |
|---|---|---|---|---|---|---|---|---|---|---|---|
| L12c-02-A24 | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 106/68 | 243/252 | 384/316 | 384/354 | 143/125 |
| L12c-03-B | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 68/68 | 252/252 | 316/316 | 354/354 | 137/125 |
