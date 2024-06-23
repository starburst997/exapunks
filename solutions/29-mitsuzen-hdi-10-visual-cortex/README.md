# 29: Mitsuzen HDI-10 (Visual Cortex)

<div align="center"><img src="EXAPUNKS - Mitsuzen HDI-10 (512, 66, 15, 2023-12-01-13-39-00).gif" /></div>

## Instructions
> Read a value from each of the optic nerves present and write the correct value to the nerve that runs deeper into your visual cortex (V-CTX). To determine the value that should be written, count the number of values read that are greater than -55, multiply that count by 5, and then subtract 75. Repeat _ad infinitum_.
> 
> It is not necessary to leave no trace. Your EXAs should be written to operate indefinitely.
> 
> For more information see "Debugging the Phage" in the first issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
LINK 800
LINK 1
LINK 3
COPY 10 T
MARK WAIT
NOOP
SUBI T 1 T
TJMP WAIT
VOID M
MARK LO
COPY 0 X
@REP 9
ADDI X M X
@END
SUBI X 75 #NERV
JUMP LO
```

### [XB](XB.exa) (global)
```asm
LINK 800
MARK LO
COPY 2 T
REPL A
SUBI T 1 T
REPL A
SUBI T 1 T
REPL A
LINK 1
JUMP LO

MARK A
FJMP HOLD
LINK -3
SUBI T 1 T
JUMP A

MARK HOLD
TEST MRD
FJMP HOLD
MARK READ
TEST #NERV > -55
TJMP TRUE
COPY 0 X
JUMP SEND
MARK TRUE
COPY 5 X
JUMP SEND
MARK SEND
COPY X M
@REP 9
NOOP
@END

JUMP READ
```

### [XC](XC.exa) (global)
```asm
COPY 10 T
MARK LO
NOOP
SUBI T 1 T
TJMP LO
COPY 0 M
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 512    | 66   | 15       |
