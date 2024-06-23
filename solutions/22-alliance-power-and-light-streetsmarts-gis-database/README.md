# 22: Alliance Power and Light (Streetsmarts GIS Database)

<div align="center"><img src="EXAPUNKS - Alliance Power and Light (61, 55, 36, 2023-12-01-13-27-35).gif" /></div>

## Instructions
> Locate the two hosts with the specified hostnames (file 300), which correspond to the target power grid substations. When you've found them, cut the power by writing a value of 0 to #POWR.
> 
> For more information see "Network Exploration: Geographic Information Systems" in the second issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
LINK 800
MARK LO
COPY M X
REPL N
REPL S
REPL P
COPY M X
REPL N
REPL S
REPL P
LINK 801
JUMP LO

MARK N
LINK 800
HOST T
TEST X = T
FJMP N
@REP 5
NOOP
@END
COPY 0 #POWR
JUMP N

MARK S
LINK 802
HOST T
TEST X = T
FJMP S
@REP 5
NOOP
@END
COPY 0 #POWR
JUMP S

MARK P
HOST T
TEST X = T
FJMP END
@REP 5
NOOP
@END
COPY 0 #POWR
MARK END
```

### [XB](XB.exa) (global)
```asm
GRAB 300
COPY 4 T
MARK LO
SEEK -2
ADDI T -1 T
COPY F M
COPY F M
TJMP LO
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 61     | 55   | 36       |
