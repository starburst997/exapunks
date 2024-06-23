# 24: King's Ransom Online (US West Realm)

<div align="center"><img src="EXAPUNKS - King's Ransom Online (63, 57, 32, 2023-12-01-13-29-39).gif" /></div>

## Instructions
> ﻿Reset the ownership of all castles and sub-buildings to ‗P00000‗ (file 300), the player ID for unowned buildings.
> 
> To ensure that there are no witnesses you must first disconnect all connected players. Terminate every EXA in every host before changing any castle or sub-building files anywhere in the network. If you leave an EXA alive in one host while changing a file in another you will fail the task.
> 
> For more information see "Network Exploration: King's Ransom Online" in the second issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
GRAB 300
LINK 800
COPY F X
@REP 6
COPY @{800,1} T
REPL KILL
@END
@REP 6
COPY @{800,1} T
REPL FIX
@END
LINK -1
HALT 

MARK FIX
NOOP

NOOP
NOOP

NOOP
NOOP
NOOP
LINK T
GRAB 200
SEEK 2
COPY X F
MARK SUB
COPY F T
REPL SF 
TEST EOF
FJMP SUB
HALT 

MARK SF
GRAB T
SEEK 2
COPY X F
JUMP SUB


MARK KILL
LINK T
@REP 3
KILL
@END
HALT



```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 63     | 57   | 32       |
