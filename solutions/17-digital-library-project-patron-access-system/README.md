# 17: Digital Library Project (Patron Access System)

<div align="center"><img src="EXAPUNKS - Digital Library Project (345, 39, 74, 2023-12-01-13-17-57).gif" /></div>

## Instructions
> Books are stored in the host corresponding to the first digit of their call number, while a book's file ID is 200 plus the last two digits of the call number. For example, book 512 would be stored in the host *500-599* as file 212.
> 
> Duplicate each of the books requested by EMBER-2 and bring them back to your host.
> 
> The call numbers for the books EMBER-2 wants are available in file 300.
> 
> Note that EMBER-2 will never request more than one book from the same host.

## Solution

### [XA](XA.exa) (local)
```asm
GRAB 300
MARK LOOP
COPY F X
ADDI X 300 X
REPL FETCH
TEST EOF
FJMP LOOP
HALT

MARK FETCH
LINK 800
SUBI X 100 X
TEST X < 300
FJMP FETCH
REPL READ
MAKE
MARK WRITE
COPY M T
COPY T F
TEST T = 0
FJMP WRITE
SEEK -1
VOID F
SEEK -9999
COPY F X
MARK HOME
LINK -1
ADDI X -100 X
TEST X < 0
FJMP HOME
DROP
HALT

MARK READ
GRAB X
MARK LINE
COPY F M
TEST EOF
FJMP LINE
COPY 0 M
HALT


```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 345    | 39   | 74       |
