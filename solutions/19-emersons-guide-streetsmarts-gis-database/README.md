# 19: Emerson's Guide (Streetsmarts GIS Database)

<div align="center"><img src="EXAPUNKS - Emerson's Guide (50, 43, 6, 2023-12-01-13-20-49).gif" /></div>

## Instructions
> Each host contains a list of restaurants and their ratings, from one to five stars (file 200). Locate the entry that corresponds to the Last Stop on Eddy Street and change its rating from one to five stars.
> 
> The name of the target restaurant and its location within the GIS grid is available in file 300. The first coordinate is the number of times to move east, while the second coordinate is the number of times to move north (positive) or south (negative).
> 
> For more information see "Network Exploration: Geographic Information Systems" in the second issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
GRAB 300
LINK 800
SEEK 1
COPY F T
FJMP LON
MARK GE
LINK 801
ADDI T -1 T
TJMP GE


MARK LON
COPY F X
TEST X < 0
TJMP SOU
TEST X > 0
TJMP NOR
JUMP NEXT
MARK SOU
COPY X T
MARK GS
LINK 802
ADDI T 1 T
TJMP GS
JUMP NEXT
MARK NOR
COPY X T
MARK GN
LINK 800
ADDI T -1 T
TJMP GN

MARK NEXT
SEEK -9999
COPY F X
WIPE
GRAB 200
MARK SEEK
TEST X = F
FJMP SEEK
COPY F X
@REP 4
COPY X F
@END
HALT




```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 50     | 43   | 6        |
