# 28: Last Stop Snaxnet (Warehouse 27)

<div align="center"><img src="EXAPUNKS - Last Stop SNAXNET (373, 99, 27, 2023-12-01-13-37-59).gif" /></div>

## Instructions
> An array of five Zippe-type gas centrifuges, ZGC0 through ZGC4, are connected in a cascade configuration.
> 
> Read each of the #ZGCX registers and determine which centrifuge currently has the highest pressure. Then disable that centrifuge's regulator by writing a value of 0 to its #POWR register. Repeat this process until all five regulators have been disabled.

## Solution

### [XA](XA.exa) (global)
```asm
LINK 800
LINK 799
MAKE
MARK 1
COPY M T
FJMP 2
TEST #ZGC0 > X
FJMP 2
COPY #ZGC0 X
COPY 0 F
SEEK -1
MARK 2
COPY M T
FJMP 3
TEST #ZGC1 > X
FJMP 3
COPY #ZGC1 X
COPY 1 F
SEEK -1
MARK 3
COPY M T
FJMP 4
TEST #ZGC2 > X
FJMP 4
COPY #ZGC2 X
COPY 2 F
SEEK -1
MARK 4
COPY M T
FJMP 5
TEST #ZGC3 > X
FJMP 5
COPY #ZGC3 X
COPY 3 F
SEEK -1
MARK 5
COPY M T
FJMP NXT
TEST #ZGC4 > X
FJMP NXT
COPY #ZGC4 X
COPY 4 F
SEEK -1
MARK NXT
COPY F M
COPY 0 X
SEEK -1
JUMP 1
```

### [XB](XB.exa) (global)
```asm
MAKE
@REP 5
COPY 1 F
@END
LINK 800
LINK 798

MARK LO
SEEK -9999
MARK SCAN
COPY F M
TEST EOF
FJMP SCAN
SEEK -9999

COPY M X
COPY X T
FJMP OFF
MARK THERE
LINK 800
SUBI T 1 T
FJMP OFF
JUMP THERE

MARK OFF 
COPY 0 #POWR
COPY X T
FJMP CLEAR

MARK BACK
SUBI T 1 T
LINK -1
TJMP BACK

MARK CLEAR
SEEK -9999
SEEK X
COPY 0 F

COPY 0 X
SEEK -9999
MARK CHECK
ADDI X F X
TEST EOF
FJMP CHECK
COPY X T
FJMP KILL

JUMP LO

MARK KILL
WIPE
LINK -1
LINK 799
KILL
GRAB 401
WIPE

```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 373    | 99   | 27       |
