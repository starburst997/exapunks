# 30: Holman Dynamics (Sales System)

<div align="center"><img src="EXAPUNKS - Holman Dynamics (6410, 78, 7, 2023-12-01-13-40-44).gif" /></div>

## Instructions
> Create a file in your host containing the contiguous 16-value sequence from the garbage file (file 199) that is a valid credit card number. There will be exactly one such sequence.
> 
> For more information see "How to Validate Credit Card Numbers" in the second issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
MAKE
MARK LO
COPY M T
FJMP RESET
SUBI T 1 T
COPY T F
FJMP EVEN
MULI T 2 T
MODI T 9 T
TJMP S1
ADDI T 9 T
MARK S1
ADDI X T X
MARK EVEN
COPY M T
FJMP RESET
SUBI T 1 T
COPY T F
FJMP SIZE
MODI T 9 T
TJMP S2
ADDI T 9 T
MARK S2
ADDI X T X
MARK SIZE
SEEK -9999
SEEK 15
TEST EOF
TJMP LO
MODI X 10 T
FJMP WIN
NOTE STRIP FIRST ELEMENT
COPY 0 X
SEEK -9999
VOID F
MARK RECALC
COPY F T
FJMP S3
MULI T 2 T
MODI T 9 T
TJMP S3
ADDI T 9 T
MARK S3
ADDI X T X
TEST EOF
TJMP EVEN
COPY F T
FJMP S4
MODI T 9 T
TJMP S4
ADDI T 9 T
MARK S4
ADDI X T X
JUMP RECALC

MARK RESET
WIPE
MAKE
COPY 0 X
JUMP LO

MARK WIN
DROP
LINK 800
LINK 802
LINK 799
KILL
HALT

```

### [XB](XB.exa) (global)
```asm
LINK 800
LINK 802
LINK 799
GRAB 199
MARK LO
ADDI F 1 X
TEST X = -9998
FJMP OUT
COPY 0 X
MARK OUT
COPY X M
TEST EOF
FJMP LO
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 6410   | 78   | 7        |
