# 34: Mitsuzen HDI-10 (Cerebral Cortex)

<div align="center"><img src="EXAPUNKS - Mitsuzen HDI-10 (778, 116, 18, 2023-12-01-13-56-03).gif" /></div>

## Instructions
> Create a file in your host containing the hostname and hardware register value of each neuron exactly once, sorted as pairs from lowest to highest hostname.
> 
> Note that each test run has its own unique network layout.
> 
> For more information see "Debugging the Phage" in the first issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
MAKE
MARK LO
COPY M F
JUMP LO

```

### [XB](XB.exa) (global)
```asm
LINK 800
COPY 1 X
MARK LO
MAKE
MULI X -1 F
@REP 4
COPY @{-3,2} X
SEEK -1
TEST X = F
TJMP NOT@{0,1}
COPY 10 T
REPL AGENT
MARK NOT@{0,1}
@END
WIPE
COPY #NERV T
HOST M
COPY 52 T
MARK SLEEP
SUBI T 1 T
TJMP SLEEP
MARK RESP
HOST T
COPY M X
TEST X = T
TJMP ANS
COPY X M
COPY 14 T
MARK RSL
SUBI T 1 T
TJMP RSL
JUMP RESP

MARK ANS
COPY #NERV M
HALT

MARK AGENT
LINK X
JUMP LO
```

### [XC](XC.exa) (local)
```asm
COPY 90 T
MARK SLEEP
SUBI T 1 T
TJMP SLEEP
KILL
GRAB 400
REPL TARGET

MARK SORT

COPY F X
TEST EOF
TJMP END
MARK SLO
TEST X < F
TJMP KEEP
SEEK -1
COPY F X
MARK KEEP
TEST EOF
FJMP SLO

MARK EXTR
SEEK -9999
MARK ELO
TEST X = F
TJMP HIT
JUMP ELO

MARK HIT
COPY X M
SEEK -1
VOID F
SEEK -9999
JUMP SORT

MARK END
SEEK -9999
COPY X M
COPY X M
WIPE
KILL
HALT


MARK TARGET
MAKE
MARK WLO
COPY M X
MODE
COPY X M
COPY X F
MARK REP
COPY M X
TEST X < 9999
TJMP VALUE
COPY X M
JUMP REP

MARK VALUE
COPY X F
MODE
JUMP WLO

```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 778    | 116  | 18       |
