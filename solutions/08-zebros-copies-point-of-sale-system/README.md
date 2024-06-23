# 8: Zebros Copies (Point-Of-Sale System)

<div align="center"><img src="EXAPUNKS - Zebros Copies (74, 31, 4, 2023-12-01-13-05-46).gif" /></div>

## Instructions
> Erase Ghast's debt to the copy shop by zeroing out his balance in the customer database (file 200) and appending a payment to the payment log (file 201) with today's date and the exact amount of his prior balance.
> 
> Ghast's customer ID is available in file 300.
> 
> For more information see "Network Exploration: Digicash Point-of-Sale Systems" in the first issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
GRAB 300
COPY F X
DROP
LINK 800
GRAB 200
MARK LOOP
TEST X = F
FJMP HOP
COPY X M
COPY F M
COPY F M
SEEK -2
COPY 0 F
COPY 0 F
DROP
HALT
MARK HOP
SEEK 2
JUMP LOOP
```

### [XB](XB.exa) (global)
```asm
LINK 800
LINK 801
COPY #DATE X
LINK -1
GRAB 201
SEEK 9999
COPY X F
COPY M F
COPY M F
COPY M F
DROP
HALT
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 74     | 31   | 4        |
