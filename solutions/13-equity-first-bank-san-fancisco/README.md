# 13: Equity First Bank (San Fancisco)

<div align="center"><img src="EXAPUNKS - Equity First Bank (3015, 25, 10, 2023-12-01-13-09-40).gif" /></div>

## Instructions
> Dispense all available cash from all connected ATMs.
> 
> For more information see "Network Exploration: Equity First Bank" in the first issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
LINK 800
LINK 800
LINK 800
@REP 6
COPY @{800,1} X
REPL FET
@END
COPY 806 X

MARK FET 
LINK X 
COPY #CASH T
MARK OUT
COPY 20 #DISP
SUBI T 1 T
TJMP OUT
MARK END
HALT
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 3015   | 25   | 10       |
