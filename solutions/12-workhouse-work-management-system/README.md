# 12: Workhouse (Work Management System)

<div align="center"><img src="EXAPUNKS - WorkHouse (413, 32, 3, 2023-12-01-22-07-55).gif" /></div>

## Instructions
> Locate EMBER-2's user file in the *users* host and overwrite it so that the sum of the values is the same but no individual value exceeds $75. All values, except for the last, must be the maximum value ($75). You will need to add additional values to accomplish this.
> 
> EMBER-2's username is available in file 300.
> 
> Note that the sum of the values in EMBER-2's account will always be less than $10,000.
> 
> For more information see "Network Exploration: Workhouse" in the first issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
GRAB 300
COPY F M
DROP
LINK 800
LINK 799
COPY M X

GRAB X
COPY 0 X
SEEK 2
MARK SUM
ADDI X F X
TEST EOF
FJMP SUM

DIVI X 75 T

SEEK -9999
SEEK 2

MARK FAK
COPY 75 F
SUBI T 1 T
TJMP FAK
MODI X 75 F
```

### [XB](XB.exa) (global)
```asm
LINK 800
GRAB 199
COPY M X
MARK SEC
TEST X = F
TJMP FILE
SEEK 2
JUMP SEC

MARK FILE
SEEK 1
COPY F M

```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 413    | 32   | 3        |
