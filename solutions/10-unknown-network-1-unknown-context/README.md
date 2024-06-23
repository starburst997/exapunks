# 10: Unknown Network 1 (Unknown Context)

<div align="center"><img src="EXAPUNKS - UNKNOWN NETWORK 1 (19, 36, 28, 2023-12-01-13-06-44).gif" /></div>

## Instructions
> Find file 276 in the network and bring it back to your host.
> 
> Note that an EXA cannot grab a file that is being held by another EXA.

## Solution

### [XA](XA.exa) (global)
```asm
COPY 4 T
COPY 800 X
MARK SPAWN
LINK X

SUBI T 1 T
FJMP GO
COPY 800 X
REPL SPAWN
COPY 801 X
REPL SPAWN

MARK GO
KILL
GRAB 276
LINK -1
LINK -1
LINK -1
LINK -1
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 34     | 17   | 34       |
