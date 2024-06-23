# 25: KGOG-TV (Satellite Uplink)

<div align="center"><img src="EXAPUNKS - KGOG-TV (620, 94, 9, 2023-12-01-13-31-07).gif" /></div>

## Instructions
> Align the satellite dish with the target satellite by setting the azimuth, elevation, and frequency. Then transmit the data from EMBER-2's video (file 301) after encrypting it using the TV station's encryption key (file 199).
> 
> The azimuth, elevation, and frequency of the target satellite are available in file 300.
> 
> Note that you must align the satellite dish before transmitting any data.
> 
> For more information see "Look to the Stars with Satellite Uplink Systems" in the second issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
GRAB 300
@REP 3
SEEK 1
COPY F M
@END
DROP
GRAB 301
LINK 800
REPL ENCR
LINK 799
SEEK 1
MODE
VOID M
VOID M
MODE
MARK SEND
COPY 1 M
COPY F M
COPY M #DATA
TEST EOF
FJMP SEND
COPY 0 M
WIPE
HALT

MARK ENCR
GRAB 199
MARK STR
COPY M T
FJMP END
COPY -9999 X
ADDI X M X
ADDI X F X
TEST X > 0
TJMP OVF
ADDI X 9999 X
JUMP TX
MARK OVF
SUBI X 1 X
MARK TX
COPY X M
TEST EOF
TJMP REW
JUMP STR
MARK REW
SEEK -9999
JUMP STR

MARK END
KILL
HALT


```

### [XB](XB.exa) (global)
```asm
LINK 800
LINK 799
COPY M X
REPL A
COPY M X
COPY M #FREQ
MODE
LINK 801
MARK ELE
COPY #ELEV T
TEST X < T
TJMP UP
COPY #ELEV T
TEST X > T
TJMP DOWN
LINK -1
COPY 0 M
HALT
MARK UP
COPY -1 #MOTR
JUMP ELE
MARK DOWN
COPY 1 #MOTR
JUMP ELE




MARK A
MODE
LINK 800
MARK AZI
COPY #AZIM T
TEST X < T
TJMP E
COPY #AZIM T
TEST X > T
TJMP W
LINK -1
COPY 0 M
HALT
MARK E
COPY -1 #MOTR
JUMP AZI
MARK W
COPY 1 #MOTR
JUMP AZI

```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 620    | 94   | 9        |
