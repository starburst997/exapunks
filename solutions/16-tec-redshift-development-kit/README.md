# 16: TEC Redshift (Development Kit)

<div align="center"><img src="EXAPUNKS - TEC Redshift™ (4972, 22, 7, 2023-12-01-13-13-28).gif" /></div>

## Instructions
> There is an unknown three-digit code (such as 4-7-3) that, when entered one digit at a time into #PASS, will unlock the link between *debug* and *secret*. Find the three-digit code and create a file in your host that contains the code as a sequence of three values, followed by the development kit's RDK ID.

## Solution

### [XA](XA.exa) (global)
```asm
LINK 800

COPY -1 X
MARK LOOP
ADDI X 1 X 
SWIZ X 003 #PASS
SWIZ X 002 #PASS
SWIZ X 001 #PASS
REPL LOOP


LINK 800
LINK -1
KILL
LINK 800
GRAB 199
COPY F T
DROP
MAKE
SWIZ X 003 F
SWIZ X 002 F
SWIZ X 001 F
COPY T F

LINK -1
LINK -1

```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 4972   | 22   | 7        |
