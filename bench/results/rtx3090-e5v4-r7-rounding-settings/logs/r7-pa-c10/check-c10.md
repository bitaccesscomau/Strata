### r7-pa-c10-check: output checks against c10c-01-B (adaptive lane)

| Arm | Members | Class | Proof | pcie_frac | tiny:0 | tiny:1 | tiny:2 | tiny:3 | tiny:4 | tiny:5 | id1k | id32k | agent:1 | agent:2 | id128k | needles found (arm/B1) | answers equal | Verdict |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c10c-01-B | (reference) | lane baseline | ok | 0.32 | - | - | - | - | - | - | - | - | - | - | - | 9 of 9 | - | reference |
| c10c-02-A30 | A30 | rounding | ok | 0.32 | tok 17 / char 67 | tok 25 / char 152 | tok 21 / char 79 | same | same | tok 0 / char 1 | tok 51 / char 321 | tok 162 / char 626 | tok 28 / char 136 | tok 2 / char 4 | tok 11 / char 51 | 9/9 | yes | PASS (needles right wherever B1 is right) |
| c10c-03-A33 | A33 | rounding | ok | 0.32 | same | same | same | same | same | same | same | tok 162 / char 626 | tok 31 / char 151 | tok 2 / char 4 | tok 3 / char 15 | 9/9 | yes | PASS (needles right wherever B1 is right) |
| c10c-04-B | B | control | ok | 0.32 | same | same | same | same | same | same | same | tok 162 / char 626 | tok 31 / char 151 | tok 2 / char 4 | tok 17 / char 90 | 9/9 | yes | control: DIFFERS from B1 |

Cells: `same` = byte-identical generated stream with equal prompt/reused/read counts; `tok N / char M` = the first divergent token index (re-tokenized, 0-based) and character index against c10c-01-B.

#### Needles per (length, depth): found in the arm / in c10c-01-B, answers byte-equal

| Arm | 8k @10% | 8k @50% | 8k @90% | 16k @10% | 16k @50% | 16k @90% | 28k @10% | 28k @50% | 28k @90% |
|---|---|---|---|---|---|---|---|---|---|
| c10c-02-A30 | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |
| c10c-03-A33 | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |
| c10c-04-B | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y | Y/Y |

#### Generated tokens per prompt (engine count, arm / c10c-01-B)

| Arm | tiny:0 | tiny:1 | tiny:2 | tiny:3 | tiny:4 | tiny:5 | id1k | id32k | agent:1 | agent:2 | id128k |
|---|---|---|---|---|---|---|---|---|---|---|---|
| c10c-02-A30 | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 78/69 | 256/256 | 384/249 | 324/208 | 148/139 |
| c10c-03-A33 | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 69/69 | 256/256 | 384/249 | 291/208 | 146/139 |
| c10c-04-B | 64/64 | 64/64 | 64/64 | 51/51 | 64/64 | 64/64 | 69/69 | 256/256 | 384/249 | 297/208 | 144/139 |
