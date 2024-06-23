# 5: Euclid's Pizza (Order System)

<div align="center"><img src="EXAPUNKS - Euclid's Pizza (24, 13, 1, 2023-12-01-13-01-50).gif" /></div>

## Instructions
> Append your order (file 300) to the end of the order list (file 200).
> 
> Note that all orders, including yours, will consist of exactly five keywords.

## Solution

### [XA](XA.exa) (global)
```asm
GRAB 300
MARK LOOP
COPY F M
TEST EOF
FJMP LOOP
```

### [XB](XB.exa) (global)
```asm
LINK 800
GRAB 200
SEEK 9999
COPY 5 T
MARK LOOP
COPY M F
SUBI T 1 T
TJMP LOOP

```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 24     | 13   | 1        |
