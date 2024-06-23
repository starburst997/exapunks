# 18: TEC EXA-Blaster Modem (Radio Stations)

<div align="center"><img src="EXAPUNKS - TEC EXA-Blaster™ Modem (493, 60, 19, 2023-12-01-13-19-00).gif" /></div>

## Instructions
> ﻿Connect to each radio station and replace every song in the playlist (file 200) with ‗CAN'T (NOT) GET OVER YOU‗ by ‗ME2U‗ (file 300). Each song in a playlist consists of two keywords: the song name and the artist name.
> 
> A list of phone numbers for the radio stations is available in file 301.
> 
> Note that EXAs in global mode can only communicate if there is a path of links connecting them.
> 
> For more information see "Hacker Skills: Modem Control at the Direct Level" in the second issue of the zine.

## Solution

### [XA](XA.exa) (local)
```asm
GRAB 300
MARK LO
COPY F M
COPY F M
SEEK -2
JUMP LO

```

### [XB](XB.exa) (global)
```asm
GRAB 301
REPL SPAWN
MARK LO
COPY 10 T
MARK SEN
COPY F M
ADDI T -1 T
TJMP SEN
REPL SPAWN
COPY F M
TEST EOF
FJMP LO
KILL
KILL
WIPE
LINK 800
COPY -1 #DIAL
HALT

MARK SPAWN
MAKE
MODE
COPY M F
COPY M F
MODE
LINK 800
COPY 11 T
COPY -1 #DIAL
MARK DIAL
COPY M #DIAL
ADDI T -1 T
TJMP DIAL
LINK 800
MODE
REPL WRI
MARK TRA
SEEK -9999
COPY F M
COPY F M
COPY M T
TJMP TRA
WIPE
HALT


MARK WRI
GRAB 200
MARK LINE
COPY M F
COPY M F
TEST EOF
TJMP EOL
COPY 1 M
JUMP LINE
MARK EOL
COPY 0 M
HALT



```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 493    | 60   | 19       |
