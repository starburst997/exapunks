# 15: Trash World News (Unknown Context)

<div align="center"><img src="EXAPUNKS - TRASH WORLD NEWS (810, 27, 4, 2023-12-01-13-11-13).gif" /></div>

## Instructions
> ﻿Find and replace the keywords in the target message (file 212) as directed by EMBER-2.
> 
> A list of keyword pairs indicating which words should be found and what they should be replaced with is available in file 300. For example, the keyword ‗AI‗ should be replaced with the keyword ‗COLLECTIVE‗. Each keyword will only occur once, but may occur in any order.
> 
> Also, move file 200 to the *outbox*.

## Solution

### [XA](XA.exa) (global)
```asm
GRAB 300
MARK LOOP
COPY F M
TEST EOF
FJMP LOOP
COPY 0 M

```

### [XB](XB.exa) (global)
```asm
LINK 800
LINK 799
GRAB 212
MARK LOOP
COPY M X
TEST X = 0
TJMP END
MARK SEA
TEST F = X
TJMP HIT
JUMP SEA
MARK HIT
SEEK -1
COPY M F
SEEK -9999
JUMP LOOP
MARK END
```

### [XC](XC.exa) (global)
```asm
LINK 800
GRAB 200
LINK 800
HALT
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 810    | 27   | 4        |
