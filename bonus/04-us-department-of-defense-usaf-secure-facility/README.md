# 4: US Department of Defense (USAF Secure Facility)

<div align="center"><img src="EXAPUNKS - U.S. Department of Defense (1049, 136, 104, 2023-12-01-14-02-33).gif" /></div>

## Instructions
> ﻿Find the unredacted version of the ‗PROJECT OGRE‗ report (file 300), make a copy of it, and bring the copy back to your host. The target file will be behind one or more locks, which each require a three-digit code.
> 
> Since this task takes place inside a network run by the military it includes additional security features not found in other networks. You may not have more than one EXA in the network at a time, and you may not use the M register to communicate between an EXA in the network and an EXA in your host.

## Solution

### [XA](XA.exa) (global)
```asm
GRAB 300
COPY F X
DROP
MAKE
COPY 0 F
COPY X F
LINK 800

COPY 10 X
MARK LOC1_1
SUBI X 1 X
COPY X #LOCK
SWIZ #LOCK 0001 T
FJMP LOC1_1 
ADDI X 100 X
MARK LOC1_10
SUBI X 10 X
COPY X #LOCK
SWIZ #LOCK 0002 T
FJMP LOC1_10
ADDI X 1000 X
MARK LOC1_100
SUBI X 100 X
COPY X #LOCK
SWIZ #LOCK 0003 T
FJMP LOC1_100

SEEK -1
COPY F X
SEEK -2
LINK 800

SEEK -9
@REP 4
COPY @{801,1} F
DROP
LINK @{801,1}
GRAB 200
TEST X = F
DROP
TJMP COPY
LINK -1
GRAB 400
@END

COPY 10 X
MARK LOC2_1
SUBI X 1 X
COPY X #LOCK
SWIZ #LOCK 0001 T
FJMP LOC2_1 
ADDI X 100 X
MARK LOC2_10
SUBI X 10 X
COPY X #LOCK
SWIZ #LOCK 0002 T
FJMP LOC2_10
ADDI X 1000 X
MARK LOC2_100
SUBI X 100 X
COPY X #LOCK
SWIZ #LOCK 0003 T
FJMP LOC2_100

LINK 800
SEEK 1
COPY F X
SEEK -2
@REP 2
COPY @{801,1} F
DROP
LINK @{801,1}
GRAB 200
TEST X = F
DROP
TJMP COPY
LINK -1
GRAB 400
@END


MARK COPY
COPY 1 T
MARK CLOOP
GRAB 200
SEEK T
COPY T X
TEST EOF
TJMP ENDGAME
COPY X T
COPY F X
DROP
LINK -1
GRAB 400
SEEK 9999
COPY X F
SEEK -9999
COPY F X
DROP
LINK X
ADDI T 1 T
JUMP CLOOP
MARK ENDGAME
DROP
LINK -1
GRAB 400
VOID F
LINK -1
LINK -1 
LINK -1








JUMP COPY

```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 1049   | 136  | 104      |
