# 33: TEC EXA-Blaster Modem (Pager Network)

<div align="center"><img src="EXAPUNKS - TEC EXA-Blaster™ Modem (1117, 64, 26, 2023-12-01-13-53-40).gif" /></div>

## Instructions
> Connect to each pager and copy EMBER-2's message (file 300) to the screen (#DATA). Then activate all of the pagers at exactly the same time by writing a value to each #PAGE register in the same cycle.
> 
> A list of phone numbers for the pagers is available in file 301.
> 
> For more information see "Hacker Skills: Modem Control at the Direct Level" in the second issue of the zine.

## Solution

### [XA](XA.exa) (local)
```asm
GRAB 301
LINK 800

COPY 8 X
MARK DIAL
COPY 11 T
MARK DIG
COPY F #DIAL
SUBI T 1 T
TJMP DIG

REPL AGENT


SUBI X 1 X
VOID M
COPY -1 #DIAL
TEST X = 0
FJMP DIAL

MODE
SEEK -9999
COPY 8 X
MARK SYNC
COPY 11 T
MARK SDIG
COPY F #DIAL
SUBI T 1 T
TJMP SDIG
COPY 0 M
SUBI X 1 X
COPY -1 #DIAL
TEST X = 0
FJMP SYNC
LINK -1
HALT



MARK AGENT 
MODE
LINK 800
MARK ALO
COPY M T
FJMP FIN
COPY T #DATA
JUMP ALO
MARK FIN
LINK -1
MODE
COPY 0 M
LINK 800
MODE
NOOP
VOID M
MULI X 20 T
MARK WAIT
SUBI T 1 T
TJMP WAIT
COPY 1 #PAGE
HALT


```

### [XB](XB.exa) (global)
```asm
COPY 8 X
GRAB 300

MARK LO
COPY F M
TEST EOF
FJMP LO
COPY 0 M
SEEK -9999
SUBI X 1 X
TEST X = 0
FJMP LO
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 1117   | 64   | 26       |
