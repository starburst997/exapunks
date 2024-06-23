# 31: US Government (Fema Genetic Database)

<div align="center"><img src="EXAPUNKS - U.S. Government (1300, 116, 43, 2023-12-01-13-46-44).gif" /></div>

## Instructions
> ﻿Overwrite the genetic sequence of ‗SEN WALKER CAINE JR‗ with the genetic sequence of ‗PRES WALKER CAINE‗ so that it looks like the younger politician is actually a clone of the older politician.
> 
> The names of these two politicians are available in file 300.
> 
> Note that you may need to overwrite a data chunk with another data chunk from the same file.
> 
> For more information see "Accessing Data in Legacy Storage Systems" in the first issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
GRAB 300
COPY 1 M
COPY F M
DROP
MAKE
COPY 10 T
MARK SUB
COPY M F
SUBI T 1 T
TJMP SUB
DROP

GRAB 300
SEEK 1
COPY 1 M
COPY F M
DROP
MAKE
COPY 10 T
MARK SUB2
COPY M F
SUBI T 1 T
TJMP SUB2
DROP

COPY 0 M
COPY 10 T
MODE

MARK CP
ADDI T -1 T
GRAB 400
SEEK T
COPY F X
REPL IN
DROP
GRAB 401
SEEK T
COPY F X
REPL OUT
DROP

MODE
COPY T X
MAKE
COPY 10 T
MARK TLO1
COPY M F
SUBI T 1 T
TJMP TLO1
MODE
COPY 0 M
MODE
SEEK -9999
COPY 10 T
MARK TLO2
COPY F M
SUBI T 1 T
TJMP TLO2
MODE

WIPE
COPY X T
TJMP CP


MARK IN
MODE
LINK 800
SWIZ X 0003 T
ADDI T 800 T
LINK T
SWIZ X 0002 T
ADDI T 200 T
GRAB T
SWIZ X 0010 T
SEEK T
COPY 10 T
MARK ILO
COPY F M
SUBI T 1 T
TJMP ILO
HALT

MARK OUT
VOID M
MODE
LINK 800
SWIZ X 0003 T
ADDI T 800 T
LINK T
SWIZ X 0002 T
ADDI T 200 T
GRAB T
SWIZ X 0010 T
SEEK T
COPY 10 T
MARK OLO
COPY M F
SUBI T 1 T
TJMP OLO
DROP
HALT






```

### [XB](XB.exa) (global)
```asm
LINK 800
LINK 801
GRAB 200
MARK LO
COPY M T
FJMP DIE
COPY M X
MARK SEEK
TEST F = X
TJMP READ
SEEK 10
JUMP SEEK

MARK READ
COPY 10 T
MARK RLO
COPY F M
SUBI T 1 T
TJMP RLO
SEEK -9999
JUMP LO
MARK DIE
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 1300   | 116  | 43       |
