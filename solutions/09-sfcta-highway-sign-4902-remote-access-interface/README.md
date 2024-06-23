# 9: SFCTA Highway Sign #4902 (Remote Access Interface)

<div align="center"><img src="EXAPUNKS - SFCTA Highway Sign #4902 (140, 15, 4, 2023-12-01-13-06-11).gif" /></div>

## Instructions
> Write EMBER-2's message (file 300) to the highway sign. The file contains one character value for each position on the sign from left to right, top to bottom.
> 
> For more information see "Hardware Hacks: Electronic Highway Signs" in the first issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
LINK 800
MARK LOOP
DIVI X 9 #DATA
MODI X 9 #DATA
COPY M #DATA
ADDI X 1 X
JUMP LOOP
```

### [XB](XB.exa) (global)
```asm
GRAB 300
MARK LO
COPY F M
TEST EOF
FJMP LO
LINK 800
KILL
LINK -1
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 140    | 15   | 4        |
