# Logs index

One directory per GPU batch (one `gpu.lock` turn). `BATCH.md` is the batch's own record from the round's results
files; `<label>.txt` is one engine run (one fresh server and engine); `check-*.json` is the output-check
analysis. Labels: `<batch>-<order>-<arm>`, `B` = production baseline, `N` = a combined set, `c<n>c-` = an
output-check run. Only the runs of settings that are not byte-identical, and the baselines paired with them,
are here.

| Batch | Run | Role | Setting | Lane | Request lines | Harness steps labelled |
|---|---|---|---|---|---|---|
| r7-pa-L2 | [L2-05-B](r7-pa-L2/L2-05-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L2 | [L2-06-A6](r7-pa-L2/L2-06-A6.txt) | X | A6 | production | 32 | 19 of 19 |
| r7-pa-L2 | [L2-07-B](r7-pa-L2/L2-07-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L2 | [L2-08-A6](r7-pa-L2/L2-08-A6.txt) | X | A6 | production | 32 | 19 of 19 |
| r7-pa-L2 | [L2-09-B](r7-pa-L2/L2-09-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L3 | [L3-01-B](r7-pa-L3/L3-01-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L3 | [L3-02-A7](r7-pa-L3/L3-02-A7.txt) | X | A7 | production | 32 | 19 of 19 |
| r7-pa-L3 | [L3-03-B](r7-pa-L3/L3-03-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L3 | [L3-04-A8](r7-pa-L3/L3-04-A8.txt) | X | A8 | production | 32 | 19 of 19 |
| r7-pa-L3 | [L3-05-B](r7-pa-L3/L3-05-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L3 | [L3-06-A9](r7-pa-L3/L3-06-A9.txt) | X | A9 | production | 32 | 19 of 19 |
| r7-pa-L3 | [L3-07-B](r7-pa-L3/L3-07-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L3 | [L3-08-A9](r7-pa-L3/L3-08-A9.txt) | X | A9 | production | 32 | 19 of 19 |
| r7-pa-L3 | [L3-09-B](r7-pa-L3/L3-09-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L3 | [L3-10-A8](r7-pa-L3/L3-10-A8.txt) | X | A8 | production | 32 | 19 of 19 |
| r7-pa-L3 | [L3-11-B](r7-pa-L3/L3-11-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L3 | [L3-12-A7](r7-pa-L3/L3-12-A7.txt) | X | A7 | production | 32 | 19 of 19 |
| r7-pa-L3 | [L3-13-B](r7-pa-L3/L3-13-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-c1 | [c1-01-A7](r7-pa-c1/c1-01-A7.txt) | X | A7 | production | 38 | 21 of 21 |
| r7-pa-c1 | [c1-02-B](r7-pa-c1/c1-02-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c1 | [c1-03-B](r7-pa-c1/c1-03-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c1 | [c1-04-A7](r7-pa-c1/c1-04-A7.txt) | X | A7 | production | 38 | 21 of 21 |
| r7-pa-c2 | [c2-01-A8](r7-pa-c2/c2-01-A8.txt) | X | A8 | production | 38 | 21 of 21 |
| r7-pa-c2 | [c2-02-B](r7-pa-c2/c2-02-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c2 | [c2-03-B](r7-pa-c2/c2-03-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c2 | [c2-04-A8](r7-pa-c2/c2-04-A8.txt) | X | A8 | production | 38 | 21 of 21 |
| r7-pa-c2 | [c2-05-B](r7-pa-c2/c2-05-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-c2 | [c2-06-A19](r7-pa-c2/c2-06-A19.txt) | X | A19 | production | 32 | 19 of 19 |
| r7-pa-c2 | [c2-07-B](r7-pa-c2/c2-07-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-c2 | [c2-08-A19](r7-pa-c2/c2-08-A19.txt) | X | A19 | production | 32 | 19 of 19 |
| r7-pa-c2 | [c2-09-B](r7-pa-c2/c2-09-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L4 | [L4-01-B](r7-pa-L4/L4-01-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L4 | [L4-02-A10](r7-pa-L4/L4-02-A10.txt) | X | A10 | production | 32 | 19 of 19 |
| r7-pa-L4 | [L4-03-B](r7-pa-L4/L4-03-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L4 | [L4-04-A11](r7-pa-L4/L4-04-A11.txt) | X | A11 | production | 32 | 19 of 19 |
| r7-pa-L4 | [L4-05-B](r7-pa-L4/L4-05-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L4 | [L4-06-A11](r7-pa-L4/L4-06-A11.txt) | X | A11 | production | 32 | 19 of 19 |
| r7-pa-L4 | [L4-07-B](r7-pa-L4/L4-07-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L4 | [L4-08-A10](r7-pa-L4/L4-08-A10.txt) | X | A10 | production | 32 | 19 of 19 |
| r7-pa-L4 | [L4-09-B](r7-pa-L4/L4-09-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L5 | [L5-01-B](r7-pa-L5/L5-01-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-L5 | [L5-02-A12](r7-pa-L5/L5-02-A12.txt) | X | A12 | production | 38 | 21 of 21 |
| r7-pa-L5 | [L5-03-B](r7-pa-L5/L5-03-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-L8 | [L8-01-B](r7-pa-L8/L8-01-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L8 | [L8-02-A20](r7-pa-L8/L8-02-A20.txt) | X | A20 | production | 32 | 19 of 19 |
| r7-pa-L8 | [L8-03-B](r7-pa-L8/L8-03-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L8 | [L8-07-B](r7-pa-L8/L8-07-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L8 | [L8-08-A20](r7-pa-L8/L8-08-A20.txt) | X | A20 | production | 32 | 19 of 19 |
| r7-pa-L8 | [L8-09-B](r7-pa-L8/L8-09-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-c3 | [c3-01-A11](r7-pa-c3/c3-01-A11.txt) | X | A11 | production | 38 | 21 of 21 |
| r7-pa-c3 | [c3-02-B](r7-pa-c3/c3-02-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c3 | [c3-03-B](r7-pa-c3/c3-03-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c3 | [c3-04-A11](r7-pa-c3/c3-04-A11.txt) | X | A11 | production | 38 | 21 of 21 |
| r7-pa-c3 | [c3-05-A19](r7-pa-c3/c3-05-A19.txt) | X | A19 | production | 38 | 21 of 21 |
| r7-pa-c3 | [c3-06-B](r7-pa-c3/c3-06-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c3 | [c3-07-B](r7-pa-c3/c3-07-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c3 | [c3-08-A19](r7-pa-c3/c3-08-A19.txt) | X | A19 | production | 38 | 21 of 21 |
| r7-pa-c3 | [c3-09-A20](r7-pa-c3/c3-09-A20.txt) | X | A20 | production | 38 | 21 of 21 |
| r7-pa-c3 | [c3-10-B](r7-pa-c3/c3-10-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c3 | [c3-11-B](r7-pa-c3/c3-11-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c3 | [c3-12-A20](r7-pa-c3/c3-12-A20.txt) | X | A20 | production | 38 | 21 of 21 |
| r7-pa-c4 | [c4-01-B](r7-pa-c4/c4-01-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-c4 | [c4-02-A22](r7-pa-c4/c4-02-A22.txt) | X | A22 | production | 32 | 19 of 19 |
| r7-pa-c4 | [c4-03-B](r7-pa-c4/c4-03-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-c4 | [c4-04-A22](r7-pa-c4/c4-04-A22.txt) | X | A22 | production | 38 | 21 of 21 |
| r7-pa-c4 | [c4-05-B](r7-pa-c4/c4-05-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c4 | [c4-06-B](r7-pa-c4/c4-06-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c4 | [c4-07-A22](r7-pa-c4/c4-07-A22.txt) | X | A22 | production | 38 | 21 of 21 |
| r7-pa-c4 | [c4-08-A10](r7-pa-c4/c4-08-A10.txt) | X | A10 | production | 38 | 21 of 21 |
| r7-pa-c4 | [c4-09-B](r7-pa-c4/c4-09-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c4 | [c4-10-B](r7-pa-c4/c4-10-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c4 | [c4-11-A10](r7-pa-c4/c4-11-A10.txt) | X | A10 | production | 38 | 21 of 21 |
| r7-pa-c5 | [c5-01-A12](r7-pa-c5/c5-01-A12.txt) | X | A12 | production | 41 | 22 of 22 |
| r7-pa-c5 | [c5-02-B](r7-pa-c5/c5-02-B.txt) | B | B | production | 41 | 22 of 22 |
| r7-pa-c5 | [c5-03-B](r7-pa-c5/c5-03-B.txt) | B | B | production | 41 | 22 of 22 |
| r7-pa-c5 | [c5-04-A12](r7-pa-c5/c5-04-A12.txt) | X | A12 | production | 41 | 22 of 22 |
| r7-pa-c6 | [c6-01-B](r7-pa-c6/c6-01-B.txt) | B | B | output-check lane | 21 | 20 of 20 |
| r7-pa-c6 | [c6-04-A11](r7-pa-c6/c6-04-A11.txt) | X | A11 | output-check lane | 20 | 19 of 19 |
| r7-pa-c6 | [c6-05-A19](r7-pa-c6/c6-05-A19.txt) | X | A19 | output-check lane | 20 | 19 of 19 |
| r7-pa-c6 | [c6-06-A22](r7-pa-c6/c6-06-A22.txt) | X | A22 | output-check lane | 20 | 19 of 19 |
| r7-pa-c6 | [c6-07-A12](r7-pa-c6/c6-07-A12.txt) | X | A12 | output-check lane | 21 | 20 of 20 |
| r7-pa-c6 | [c6-08-AC](r7-pa-c6/c6-08-AC.txt) | X | A18+A19+A12+A21 | output-check lane | 21 | 20 of 20 |
| r7-pa-c6 | [c6-09-B](r7-pa-c6/c6-09-B.txt) | B | B | output-check lane | 21 | 20 of 20 |
| r7-pa-c7 | [c7-01-B](r7-pa-c7/c7-01-B.txt) | B | B | production | 41 | 22 of 22 |
| r7-pa-c7 | [c7-02-N](r7-pa-c7/c7-02-N.txt) | X | N | production | 41 | 22 of 22 |
| r7-pa-c7 | [c7-03-N](r7-pa-c7/c7-03-N.txt) | X | N | production | 41 | 22 of 22 |
| r7-pa-c7 | [c7-04-B](r7-pa-c7/c7-04-B.txt) | B | B | production | 41 | 22 of 22 |
| r7-pa-L9 | [L9-03-B](r7-pa-L9/L9-03-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L9 | [L9-04-A24](r7-pa-L9/L9-04-A24.txt) | X | A24 | production | 32 | 19 of 19 |
| r7-pa-L9 | [L9-05-B](r7-pa-L9/L9-05-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L9 | [L9-06-A25](r7-pa-L9/L9-06-A25.txt) | X | A25 | production | 32 | 19 of 19 |
| r7-pa-L9 | [L9-07-B](r7-pa-L9/L9-07-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L9 | [L9-08-A25](r7-pa-L9/L9-08-A25.txt) | X | A25 | production | 32 | 19 of 19 |
| r7-pa-L9 | [L9-09-B](r7-pa-L9/L9-09-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L9 | [L9-10-A24](r7-pa-L9/L9-10-A24.txt) | X | A24 | production | 32 | 19 of 19 |
| r7-pa-L9 | [L9-11-B](r7-pa-L9/L9-11-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L11 | [L11-01-B](r7-pa-L11/L11-01-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L11 | [L11-02-A30](r7-pa-L11/L11-02-A30.txt) | X | A30 | production | 32 | 19 of 19 |
| r7-pa-L11 | [L11-03-B](r7-pa-L11/L11-03-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L11 | [L11-04-A31](r7-pa-L11/L11-04-A31.txt) | X | A31 | production | 32 | 19 of 19 |
| r7-pa-L11 | [L11-05-B](r7-pa-L11/L11-05-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L11 | [L11-06-A32](r7-pa-L11/L11-06-A32.txt) | X | A32 | production | 32 | 19 of 19 |
| r7-pa-L11 | [L11-07-B](r7-pa-L11/L11-07-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L11 | [L11-08-A32](r7-pa-L11/L11-08-A32.txt) | X | A32 | production | 32 | 19 of 19 |
| r7-pa-L11 | [L11-09-B](r7-pa-L11/L11-09-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L11 | [L11-10-A31](r7-pa-L11/L11-10-A31.txt) | X | A31 | production | 32 | 19 of 19 |
| r7-pa-L11 | [L11-11-B](r7-pa-L11/L11-11-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L11 | [L11-12-A30](r7-pa-L11/L11-12-A30.txt) | X | A30 | production | 32 | 19 of 19 |
| r7-pa-L11 | [L11-13-B](r7-pa-L11/L11-13-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L12 | [L12-01-A24](r7-pa-L12/L12-01-A24.txt) | X | A24 | production | 38 | 21 of 21 |
| r7-pa-L12 | [L12-02-B](r7-pa-L12/L12-02-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-L12 | [L12-03-B](r7-pa-L12/L12-03-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-L12 | [L12-04-A24](r7-pa-L12/L12-04-A24.txt) | X | A24 | production | 38 | 21 of 21 |
| r7-pa-L12 | [L12-05-B](r7-pa-L12/L12-05-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L12 | [L12-06-A33](r7-pa-L12/L12-06-A33.txt) | X | A33 | production | 32 | 19 of 19 |
| r7-pa-L12 | [L12-07-B](r7-pa-L12/L12-07-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L12 | [L12-08-A33](r7-pa-L12/L12-08-A33.txt) | X | A33 | production | 32 | 19 of 19 |
| r7-pa-L12 | [L12-09-B](r7-pa-L12/L12-09-B.txt) | B | B | production | 32 | 19 of 19 |
| r7-pa-L12 | [L12c-01-B](r7-pa-L12/L12c-01-B.txt) | B | B | output-check lane | 21 | 20 of 20 |
| r7-pa-L12 | [L12c-02-A24](r7-pa-L12/L12c-02-A24.txt) | X | A24 | output-check lane | 21 | 20 of 20 |
| r7-pa-L12 | [L12c-03-B](r7-pa-L12/L12c-03-B.txt) | B | B | output-check lane | 21 | 20 of 20 |
| r7-pa-c9 | [c9-01-A32](r7-pa-c9/c9-01-A32.txt) | X | A32 | production | 38 | 21 of 21 |
| r7-pa-c9 | [c9-02-B](r7-pa-c9/c9-02-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c9 | [c9-03-B](r7-pa-c9/c9-03-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c9 | [c9-04-A32](r7-pa-c9/c9-04-A32.txt) | X | A32 | production | 38 | 21 of 21 |
| r7-pa-c9 | [c9-05-A31](r7-pa-c9/c9-05-A31.txt) | X | A31 | production | 38 | 21 of 21 |
| r7-pa-c9 | [c9-06-B](r7-pa-c9/c9-06-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c9 | [c9-07-B](r7-pa-c9/c9-07-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c9 | [c9-08-A31](r7-pa-c9/c9-08-A31.txt) | X | A31 | production | 38 | 21 of 21 |
| r7-pa-c9 | [c9c-01-B](r7-pa-c9/c9c-01-B.txt) | B | B | output-check lane | 21 | 20 of 20 |
| r7-pa-c9 | [c9c-02-A32](r7-pa-c9/c9c-02-A32.txt) | X | A32 | output-check lane | 21 | 20 of 20 |
| r7-pa-c9 | [c9c-03-A31](r7-pa-c9/c9c-03-A31.txt) | X | A31 | output-check lane | 21 | 20 of 20 |
| r7-pa-c9 | [c9c-04-B](r7-pa-c9/c9c-04-B.txt) | B | B | output-check lane | 21 | 20 of 20 |
| r7-pa-c10 | [c10-01-A30](r7-pa-c10/c10-01-A30.txt) | X | A30 | production | 38 | 21 of 21 |
| r7-pa-c10 | [c10-02-B](r7-pa-c10/c10-02-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c10 | [c10-03-B](r7-pa-c10/c10-03-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c10 | [c10-04-A30](r7-pa-c10/c10-04-A30.txt) | X | A30 | production | 38 | 21 of 21 |
| r7-pa-c10 | [c10-05-A33](r7-pa-c10/c10-05-A33.txt) | X | A33 | production | 38 | 21 of 21 |
| r7-pa-c10 | [c10-06-B](r7-pa-c10/c10-06-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c10 | [c10-07-B](r7-pa-c10/c10-07-B.txt) | B | B | production | 38 | 21 of 21 |
| r7-pa-c10 | [c10-08-A33](r7-pa-c10/c10-08-A33.txt) | X | A33 | production | 38 | 21 of 21 |
| r7-pa-c10 | [c10c-01-B](r7-pa-c10/c10c-01-B.txt) | B | B | output-check lane | 21 | 20 of 20 |
| r7-pa-c10 | [c10c-02-A30](r7-pa-c10/c10c-02-A30.txt) | X | A30 | output-check lane | 21 | 20 of 20 |
| r7-pa-c10 | [c10c-03-A33](r7-pa-c10/c10c-03-A33.txt) | X | A33 | output-check lane | 21 | 20 of 20 |
| r7-pa-c10 | [c10c-04-B](r7-pa-c10/c10c-04-B.txt) | B | B | output-check lane | 21 | 20 of 20 |
| r7-pa-c11 | [c11-01-B](r7-pa-c11/c11-01-B.txt) | B | B | production | 41 | 22 of 22 |
| r7-pa-c11 | [c11-02-N](r7-pa-c11/c11-02-N.txt) | X | N | production | 41 | 22 of 22 |
| r7-pa-c11 | [c11-03-N](r7-pa-c11/c11-03-N.txt) | X | N | production | 41 | 22 of 22 |
| r7-pa-c11 | [c11-04-B](r7-pa-c11/c11-04-B.txt) | B | B | production | 41 | 22 of 22 |

## Gate computations (`gates/`)

| File | Holds |
|---|---|
| [screen-L2.json](gates/screen-L2.json) | A6 screen and reversed-half pair ratios (with A4, A5) |
| [screen-L3.json](gates/screen-L3.json) | A7, A8, A9 screen and reversed-half pair ratios |
| [confirm-A10-A11-A12-A19-A20-A22.json](gates/confirm-A10-A11-A12-A19-A20-A22.json) | four-pair gates of A10, A11, A12, A19, A20, A22 (and A21) and the prefill choice |
| [screen-L9.json](gates/screen-L9.json) | A24, A25 screen verdicts (with A23) |
| [screen-L11.json](gates/screen-L11.json) | A30, A31, A32 screen verdicts and hit rates |
| [screen-L12.json](gates/screen-L12.json) | A33 screen verdict and hit rates |
| [confirm-A24-A31-A32.json](gates/confirm-A24-A31-A32.json) | four-pair gates of A24, A31, A32 |
| [confirm-A30-A33.json](gates/confirm-A30-A33.json) | four-pair gates of A30, A33 |
| [combined-c7.json](gates/combined-c7.json) | c7 combined-arm gate and metrics |
| [combined-c11.json](gates/combined-c11.json) | c11 combined-arm gate and metrics (the full set) |
