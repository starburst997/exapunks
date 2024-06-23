# 32: Unknown Network 2 (Unknown Context)

<div align="center"><img src="EXAPUNKS - UNKNOWN NETWORK 2 (437, 49, 85, 2023-12-01-13-51-08).gif" /></div>

## Instructions
> Terminate all other EXAs and bring any files they were holding back to your host. Only EXAs in the central host will be holding files, and their file IDs will always be between 200 and 299, inclusive.
> 
> Note that some links may become non-traversable as a result of your actions.

## Solution

### [XA](XA.exa) (global)
```asm
MARK LO

REPL SCOUT


MARK SCOUT
LINK 800
LINK 800
LINK 800
LINK 800
MARK KILL
@REP 5
REPL KILLER
@END
NOOP
NOOP
NOOP

LINK 800
COPY 100 T
MARK FETCH
SUBI T 1 T
ADDI T 200 X
REPL FETCHER
TJMP FETCH
@REP 5
LINK -1
REPL KILLER
REPL KILLER
@END


MARK FETCHER
GRAB X
@REP 5
LINK -1
@END 
HALT

MARK KILLER
LINK 800
KILL
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 437    | 49   | 85       |
