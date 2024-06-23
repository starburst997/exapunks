# 1: Bloodlust Online (US East Realm)

<div align="center"><img src="EXAPUNKS - Bloodlust Online (192, 125, 18, 2023-12-01-13-58-32).gif" /></div>

## Instructions
> Each host contains an item listing (file 200) that lists all of the items in that location (ID, type, and state).
> 
> First, locate mutex8021's hideout by finding the ‗TALISMAN‗ (file 300). Then find the ‗MAP‗ in the hideout and use it to locate the target host: the secret vampire lair. Next, travel to the target host, disconnect the vampire players by terminating their EXAs, set the ‗DOOR‗ to be ‗UNLOCKED‗, and copy the ‗SAFE‗ combination to the ‗CLOCK‗ so that mutex8021 can read it and empty the safe.
> 
> Note that the door to mutex8021's hideout will always be ‗UNLOCKED‗.

## Solution

### [XA](XA.exa) (global)
```asm
GRAB 300
COPY F X
DROP
LINK 800
@REP 5
COPY @{800,1} T
REPL AGENT1
@END
COPY 805 T

MARK AGENT1
LINK T
GRAB 200
MARK SEA1
SEEK 1
TEST F = X
TJMP HIT1
SEEK 1
JUMP SEA1
MARK HIT1 
COPY 1 M
SEEK -9999
COPY M X
MARK SEA2
SEEK 1
TEST F = X
TJMP HIT2
SEEK 1
JUMP SEA2
MARK HIT2 
COPY F M
SEEK -9999
COPY M X
MARK SEA3
SEEK 1
TEST F = X
TJMP HIT3
SEEK 1
JUMP SEA3
MARK HIT3 
COPY F X
DROP
LINK -1
@REP 5
COPY @{800,1} T
REPL AGENT2
@END
COPY 805 T
MARK AGENT2
LINK T
HOST T
TEST T = X
FJMP END
@REP 4
KILL
@END
GRAB 200
COPY M X
MARK SEA4
SEEK 1
TEST F = X
TJMP HIT4
SEEK 1
JUMP SEA4
MARK HIT4 
COPY M F
SEEK -9999
COPY M X
MARK SEA5
SEEK 1
TEST F = X
TJMP HIT5
SEEK 1
JUMP SEA5
MARK HIT5 
COPY F M
SEEK -9999
COPY M X
MARK SEA6
SEEK 1
TEST F = X
TJMP HIT6
SEEK 1
JUMP SEA6
MARK HIT6 
COPY M F









MARK END



```

### [XB](XB.exa) (global)
```asm
NOOP
NOOP
GRAB 300
SEEK 1
COPY 0 X

COPY 25 T
MARK SLEEP
SUBI T 1 T
TJMP SLEEP
COPY M T
SEEK 1
COPY F M
SEEK 2
COPY M F
SEEK -5
COPY F M
NOTE DOOR
COPY F M
SEEK 2
NOTE UNLOCKED
COPY F M
SEEK -3
COPY F M
SEEK 1
COPY M F
SEEK -2
COPY F M
COPY F M

```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 192    | 125  | 18       |
