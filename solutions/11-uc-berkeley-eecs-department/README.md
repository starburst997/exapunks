# 11: UC Berkeley (EECS Department)

<div align="center"><img src="EXAPUNKS - UC Berkeley (157, 50, 7, 2023-12-01-13-07-30).gif" /></div>

## Instructions
> ﻿Locate the specified host (either *tape-1*, *tape-2*, or *tape-3*), and then locate the specified entry (‗ПАСЬЯНС‗) in the tape backup file in that host (file 200). Create a file in your host containing the entry's data.
> 
> The names of the target host and entry are available in file 300.
> 
> For more information see "Accessing Data in Legacy Storage Systems" in the first issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
GRAB 300
SEEK 1
MARK LOOP
SEEK -1
COPY 0 M
TEST M = F
FJMP LOOP
COPY 1 M
COPY F M
DROP 
MAKE
MARK IN
COPY M X
TEST X = 0 
TJMP END
COPY X F
JUMP IN
MARK END
DROP
HALT


```

### [XB](XB.exa) (global)
```asm
LINK 800
MARK LOOP
TEST M = 0
FJMP REC
LINK 800
LINK 800
HOST M
JUMP LOOP
MARK REC
COPY M X
GRAB 200
SEEK 9999
COPY 0 F
MARK SEA
SEEK -4
TEST X = F
FJMP SEA
COPY F X
COPY F T
SEEK -9999
SEEK X
MARK OUT
COPY F M
SUBI T 1 T
TJMP OUT
COPY 0 M
SEEK 9999
SEEK -1
VOID F
HALT
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 157    | 50   | 7        |
