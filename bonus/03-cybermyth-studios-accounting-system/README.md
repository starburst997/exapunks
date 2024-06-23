# 3: Cybermyth Studios (Accounting System)

<div align="center"><img src="EXAPUNKS - Cybermyth Studios (926, 180, 10, 2023-12-01-14-00-39).gif" /></div>

## Instructions
> Each host contains two files: a list of accounts and a list of transactions. Although the entries in these files vary, the first value of each entry is a unique identifier that connects an account to one or more transactions.
> 
> Determine the amount of back-pay owed to Ghast and Moss by subtracting the amount that they were paid (file 221) from the amount that they were owed (file 231). Then add their shell company (file 300) to the list of accounts payable (file 220) and issue a single payment to it for the total amount owed (file 221).
> 
> Note that all monetary amounts are represented as two values: dollars, then cents.

## Solution

### [XA](XA.exa) (global)
```asm
LINK 800
COPY 3 T
REPL AGENT
COPY 2 T
MARK AGENT
ADDI T 799 X
LINK X
MULI T 10 T
ADDI T 200 T
GRAB T
MARK CLIENT
COPY M X
REPL READER
MARK IX
SEEK 1
TEST X = F
TJMP HIT
JUMP IX
MARK HIT
SEEK -2
MODE
COPY F M
SEEK 9999
COPY 0 F
COPY 0 F
MARK ADD
SEEK -2
COPY M X
TEST X = -1
TJMP FIN 
ADDI F X X
SEEK -1
COPY X F
ADDI F M X
SEEK -1
COPY X F
JUMP ADD

MARK FIN
COPY 100 T
MARK SLEEP
SUBI T 1 T
TJMP SLEEP
MODE 
COPY 1 M
TEST M = 1
FJMP SUM
SEEK -9999
COPY M X
JUMP IX

MARK SUM
SEEK 9999
SEEK -4
COPY -9999 X
ADDI F X X
COPY F T
ADDI F X X
ADDI F T T
COPY X F
COPY T F
SEEK -6
@REP 4
VOID F
@END
KILL
COPY 0 M
HALT

SEEK 1
COPY F X
SEEK -2
DIVI X 100 T
ADDI F T T
SEEK -1
COPY T F
MODI X 100 F
NOOP

MARK READER
MODE
ADDI T 1 T
GRAB T
MARK ID
COPY M X
JUMP COLL
MARK COLL
TEST F = X
TJMP PICK
SEEK 3
TEST EOF
TJMP EOT
JUMP COLL
MARK PICK
SEEK 1
COPY F M
COPY F M
TEST EOF
TJMP EOT
JUMP COLL
MARK EOT
COPY -1 M
SEEK -9999
JUMP ID
```

### [XC](XC.exa) (global)
```asm
GRAB 300
LINK 800
COPY F X
COPY X M
COPY X M
COPY F X
VOID M
COPY 1 M
COPY X M
VOID M
COPY 1 M
COPY X M
VOID M
COPY 0 M
VOID M
VOID M
COPY 0 M
VOID M

REPL COLLECTOR
LINK 804
COPY M X
SUBI X M X
SUBI M 9 T
ADDI T X X
COPY M T
COPY F M

COPY #DATE M
COPY X M
COPY T M

WIPE
HALT



MARK COLLECTOR
LINK 802
GRAB 230
SEEK 9999
SEEK -2
COPY F X
TEST X < 0
FJMP ASIS
ADDI X 9999 X
MARK ASIS
COPY X M
COPY F T
SEEK -2
VOID F
VOID F
DROP
LINK -1
LINK 801
GRAB 220
SEEK 9999
SEEK -2
ADDI F 9999 M
SUBI T F T
SEEK -2
VOID F
VOID F
ADDI T 900 T
DIVI T 100 M
MODI T 100 M
SEEK -2
ADDI F 1 T
SEEK 1
COPY T F
COPY M F
DROP
GRAB 221
SEEK 9999
COPY T F
COPY M F
COPY M X
TEST X < 0
TJMP ADD
COPY X F
JUMP END
MARK ADD
ADDI X 9999 F
MARK END
COPY M F





```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 926    | 180  | 10       |
