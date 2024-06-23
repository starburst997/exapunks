# 2: Motor Vehicle Administration (Scheduling System)

<div align="center"><img src="EXAPUNKS - Motor Vehicle Administration (533, 93, 8, 2023-12-01-13-59-16).gif" /></div>

## Instructions
> There is a list of appointments (file 200) in *storage* that contains an appointment for NthDimension (file 300) to take his driving test. Remove the appointment from the list of appointments, change the date to today's date (#DATE register), and insert it between today's appointments and tomorrow's appointments.
> 
> To gain access to the *storage* host you will need to unlock it by writing the lowest ticket number to the #NEXT register. Each EXA in *public* is holding a ticket; terminate them all to find the ticket of the next EXA to be served.
> 
> Note that writing an incorrect ticket number to the #NEXT register will fail the _leave no trace_ requirement.

## Solution

### [XA](XA.exa) (global)
```asm
LINK 800
@REP 5
KILL
@END
COPY 200 X
MARK LOWEST
REPL TAKE
ADDI X 1 X
JUMP LOWEST

MARK TAKE
GRAB X
KILL
COPY F #NEXT
DROP
LINK 800
GRAB 200
COPY #DATE T
COPY M X
MARK DEL
SEEK 1
TEST F = X
TJMP HIT_DEL
SEEK 1
JUMP DEL

MARK HIT_DEL 
COPY F M
SEEK -3
VOID F
VOID F
VOID F
COPY 0 X
SEEK -9999
TEST F = #DATE
FJMP COUNT
SEEK 9999
MARK MOV
SEEK -3
COPY F X
TEST X = #DATE
SEEK 2
COPY X F
SEEK -3
COPY F X
SEEK 2
COPY X F
SEEK -3
COPY F X
SEEK 2
COPY X F
TJMP NOW
SEEK -6
JUMP MOV
MARK NOW
SEEK -2
COPY M F
COPY M F
HALT

MARK COUNT
SEEK 3
ADDI X 1 X
TEST EOF
FJMP COUNT
COPY X T
MARK MOV2
SEEK -3
COPY F X
SEEK 2
COPY X F
SEEK -3
COPY F X
SEEK 2
COPY X F
SEEK -3
COPY F X
SEEK 2
COPY X F
SUBI T 1 T
SEEK -6
FJMP NOW2
JUMP MOV2
MARK NOW2
COPY #DATE F
COPY M F
COPY M F


NOOP

```

### [XB](XB.exa) (global)
```asm
GRAB 300
COPY F M
COPY M F
SEEK -9999
COPY F M
COPY F M
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 533    | 93   | 8        |
