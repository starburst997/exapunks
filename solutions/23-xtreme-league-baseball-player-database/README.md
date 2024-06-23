# 23: Xtreme League Baseball (Player Database)

<div align="center"><img src="EXAPUNKS - Xtreme League Baseball (239, 55, 2, 2023-12-01-13-28-40).gif" /></div>

## Instructions
> The hosts *active* and *penalty* contain files that correspond to extreme baseball players (files 200-299), along with a directory file that contains a list of those files' IDs (file 199). Each player file contains their name and the following statistics in this order: BA, ZA, APB, WRT, OI, OD, PC, and PS.
> 
> Create a file in your host with the name of the player with the highest score using EMBER-2's algorithm:
> 
> SCORE = (BA + ZA + APB) / 3 + ( WRT \* OI ) / OD + (PC - PS) \* 20
> 
> Players in the *penalty* host should be ignored, as they are currently banned from the game.

## Solution

### [XA](XA.exa) (local)
```asm
NOTE ($1+$2+$3)/3+
NOTE $4*$5/$6+
NOTE ($7-$8)*20

LINK 800
GRAB 199
MARK LO
COPY F M
TEST EOF
FJMP LO
COPY 0 M
```

### [XB](XB.exa) (local)
```asm
LINK 800
MARK LO
COPY M T
FJMP END
GRAB T
MODE
COPY F M
COPY F X
ADDI X F X
ADDI X F X
DIVI X 3 X
COPY F T
MULI T F T
DIVI T F T
ADDI X T X
COPY F T
SUBI T F T
MULI T 20 T
ADDI X T M
DROP
MODE
JUMP LO


MARK END
MODE
COPY 0 M

```

### [XC](XC.exa) (global)
```asm
MAKE
COPY 0 F
COPY 0 F
MARK LO
COPY M T
FJMP END
COPY T F
COPY M X
SEEK -2
TEST F < X
TJMP NEW
VOID F
JUMP LO

MARK NEW
SEEK -2
VOID F
VOID F
SEEK 1
COPY X F
JUMP LO


MARK END
SEEK -1
VOID F

```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 239    | 55   | 2        |
