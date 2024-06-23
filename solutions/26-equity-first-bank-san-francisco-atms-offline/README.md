# 26: Equity First Bank (San Francisco - ATMs Offline)

<div align="center"><img src="EXAPUNKS - Equity First Bank (110, 55, 6, 2023-12-01-13-32-05).gif" /></div>

## Instructions
> ﻿Move EMBER-2's new account (file 300) into *checking*. Then iterate over the checking accounts listed in the directory (file 199) and, in that order, transfer $1.00 from each target account to EMBER-2's account. Finally, add the file ID of EMBER-2's account file to the end of the directory.
> 
> The keywords ‗CREDIT‗ and ‗DEBIT‗ are available in file 301.
> 
> For more information see "Network Exploration: Equity First Bank" in the first issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
GRAB 300
LINK 800
LINK 800
MODE
COPY F X
REPL INDX
SEEK 9999
MARK MLO
COPY M F
MODE
COPY M F
MODE
COPY 1 F
COPY 0 F
JUMP MLO


MARK INDX
GRAB 199
MARK ILO
COPY X T
COPY F X
REPL COLL
@REP 6
NOOP
@END
COPY T X
TEST EOF
FJMP ILO
COPY 300 F
DROP
KILL
LINK -1
LINK -1
KILL 
HALT

MARK COLL
GRAB X
COPY F M
SEEK 9999
COPY T F
MODE 
COPY M F
MODE
COPY 1 F
COPY 0 F
DROP
HALT
```

### [XB](XB.exa) (global)
```asm
GRAB 301
MARK LO
COPY F M
COPY F M
SEEK -2
JUMP LO
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 110    | 55   | 6        |
