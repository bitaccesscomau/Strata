### r7-pa-c6: output checks against c6-01-B (deterministic lane)

| Arm | Members | Class | Proof | pcie_frac | tiny:0 | tiny:1 | tiny:2 | tiny:3 | tiny:4 | tiny:5 | id1k | id32k | agent:1 | agent:2 | id128k | needles found (arm/B1) | answers equal | Verdict |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| c6-01-B | (reference) | lane baseline | ok | 0.32 | - | - | - | - | - | - | - | - | - | - | - | 9 of 9 | - | reference |
| c6-02-A18 | A18 | exact | ok | 0.32 | same | same | same | same | same | same | same | same | tok 270 / char 1153 | same | - | 9/9 | yes | FAIL (not byte-identical or counts differ) |
| c6-03-A21 | A21 | exact | ok | 0.32 | same | same | same | same | same | same | same | same | tok 270 / char 1153 | same | - | 9/9 | yes | FAIL (not byte-identical or counts differ) |
| c6-04-A11 | A11 | rounding | ok | 0.32 | same | same | same | same | same | same | tok 33 / char 213 | same | tok 27 / char 135 | tok 3 / char 15 | - | 9/9 | yes | PASS (needles right wherever B1 is right) |
| c6-05-A19 | A19 | rounding | ok | 0.32 | same | same | same | same | same | same | tok 4 / char 29 | same | tok 27 / char 135 | tok 16 / char 73 | - | 9/9 | yes | PASS (needles right wherever B1 is right) |
| c6-06-A22 | A22 | rounding | ok | 0.32 | same | same | same | same | same | same | tok 3 / char 20 | same | tok 27 / char 135 | tok 10 / char 46 | - | 9/9 | yes | PASS (needles right wherever B1 is right) |
| c6-07-A12 | A12 | rounding | ok | 0.32 | same | same | same | same | same | same | same | same | same | tok 52 / char 248 | tok 66 / char 280 | 9/9 | yes | PASS (needles right wherever B1 is right) |
| c6-08-AC | A18+A19+A12+A21 | rounding | ok | 0.32 | same | same | same | same | same | same | tok 6 / char 55 | same | tok 28 / char 141 | tok 10 / char 46 | tok 12 / char 69 | 9/9 | yes | PASS (needles right wherever B1 is right) |
| c6-09-B | B | control | ok | 0.32 | same | same | same | same | same | same | same | same | same | tok 52 / char 248 | tok 66 / char 280 | 9/9 | yes | control: DIFFERS from B1 |

Cells: `same` = byte-identical generated stream with equal prompt/reused/read counts; `tok N / char M` = the first divergent token index (re-tokenized, 0-based) and character index against c6-01-B.

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
