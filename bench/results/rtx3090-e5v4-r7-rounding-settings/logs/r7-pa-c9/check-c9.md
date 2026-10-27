### r7-pa-c9-check: output checks against c9c-01-B (deterministic lane)

| Arm | Members | Class | Proof | pcie_frac | tiny:0 | tiny:1 | tiny:2 | tiny:3 | tiny:4 | tiny:5 | id1k | id32k | agent:1 | agent:2 | id128k | needles found (arm/B1) | answers equal | Verdict |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c9c-01-B | (reference) | lane baseline | ok | 0.32 | - | - | - | - | - | - | - | - | - | - | - | 9 of 9 | - | reference |
| c9c-02-A32 | A32 | rounding | ok | 0.32 | same | tok 16 / char 102 | same | same | tok 4 / char 15 | same | tok 23 / char 164 | same | tok 35 / char 165 | tok 0 / char 0 | tok 0 / char 1 | 9/9 | yes | PASS (needles right wherever B1 is right) |
| c9c-03-A31 | A31 | rounding | ok | 0.32 | tok 17 / char 67 | tok 16 / char 102 | tok 29 / char 113 | same | same | tok 0 / char 1 | tok 51 / char 321 | tok 72 / char 280 | tok 28 / char 136 | tok 10 / char 46 | tok 0 / char 1 | 9/9 | yes | PASS (needles right wherever B1 is right) |
| c9c-04-B | B | control | ok | 0.32 | same | same | same | same | same | same | same | same | tok 277 / char 1189 | tok 3 / char 15 | tok 0 / char 1 | 9/9 | yes | control: DIFFERS from B1 |

Cells: `same` = byte-identical generated stream with equal prompt/reused/read counts; `tok N / char M` = the first divergent token index (re-tokenized, 0-based) and character index against c9c-01-B.

#### Needles per (length, depth): found in the arm / in c9c-01-B, answers byte-equal

| Arm | 8k @10% | 8k @50% | 8k @90% | 16k @10% | 16k @50% | 16k @90% | 28k @10% | 28k @50% | 28k @90% |
|---|---|---|---|---|---|---|---|---|---|
| c9c-02-A32 | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |
| c9c-03-A31 | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |
| c9c-04-B | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |

#### Generated tokens per prompt (engine count, arm / c9c-01-B)

| Arm | tiny:0 | tiny:1 | tiny:2 | tiny:3 | tiny:4 | tiny:5 | id1k | id32k | agent:1 | agent:2 | id128k |
|---|---|---|---|---|---|---|---|---|---|---|---|
| c9c-02-A32 | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 83/69 | 256/256 | 384/384 | 384/291 | 143/132 |
| c9c-03-A31 | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 75/69 | 248/256 | 384/384 | 243/291 | 146/132 |
| c9c-04-B | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 69/69 | 256/256 | 372/384 | 323/291 | 146/132 |
