# 21: Sawayama Wonderdisc (Drive Controller)

<div align="center"><img src="EXAPUNKS - Sawayama WonderDisc (7293, 67, 64, 2023-12-01-13-25-45).gif" /></div>

## Instructions
> Modify your WonderDisc, which normally only plays SSEA region games, to play games from any region.
> 
> The SSEA region code is available in file 300.
> 
> It is not necessary to leave no trace. Your EXAs should be written to operate indefinitely.
> 
> For more information see "Hardware Hacks: Sawayama WonderDisc" in the second issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
LINK 800
COPY 8 #AUTH
COPY 0 #AUTH
COPY 3 #AUTH
COPY 2 #AUTH
COPY 7 #AUTH
COPY 1 #AUTH
COPY 0 #AUTH
COPY 4 #AUTH
COPY 9 #AUTH
COPY 5 #AUTH
COPY 1 #AUTH
COPY 2 #AUTH
COPY 5 #AUTH
COPY 2 #AUTH
COPY 6 #AUTH
LINK 800
MARK LO
MAKE
MARK WRI
COPY M T
FJMP NEXT
COPY T F
JUMP WRI 
MARK NEXT
DROP
JUMP LO
```

### [XB](XB.exa) (global)
```asm
GRAB 300
COPY F T
DROP
LINK 800
@REP 15
NOOP
@END
MARK LO
COPY #TRAK X
LINK 801
GRAB X
COPY T X
MARK READ
TEST F > -9999
TJMP SUB
COPY X M
JUMP TEO
MARK SUB
SEEK -1
COPY F M
MARK TEO
TEST EOF
FJMP READ
COPY 0 M
DROP
LINK -1
COPY X T
JUMP LO 




```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 7293   | 67   | 64       |
