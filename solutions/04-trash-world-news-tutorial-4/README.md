# 4: Trash World News (Tutorial 4)

<div align="center"><img src="EXAPUNKS - TRASH WORLD NEWS (307, 10, 2, 2023-12-01-22-12-58).gif" /></div>

## Instructions
> File 200 contains exactly one number, N. Create a new file in the *outbox* containing the numbers N through 0 in decreasing order. When you are finished, delete file 200.
> 
> For help completing this task see "Ghast Walks U Thru It" in the first issue of the zine.

## Solution

### [XB](XB.exa) (global)
```asm
LINK 800
GRAB 200
ADDI  F 1 T
WIPE
MAKE
MARK LOOP
SUBI T 1 T
COPY T F
TJMP LOOP
LINK 800

```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 307    | 10   | 2        |
