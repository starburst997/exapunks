# 4: The Wormhole (X10X10X)

<div align="center"><img src="EXAPUNKS - The Wormhole (2023-12-01-13-32-38).gif" /></div>

## Instructions
> To win this battle you must fill the network's hosts with as many of your EXAs as you can. Note that each pair of test runs has its own unique network layout, with bi-directional links between hosts that use the prime numbers between 2 and 13 as link IDs (2, 3, 5, 7, 11, and 13).
> 
>      Gain one point for every EXA you control in the network at the end of the battle.
> 
>      Lose one point every time one of your EXAs executes a KILL instruction.
> 
> For more information see "Hacker Battle Domination" in the second issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
LINK 800
MARK LO
@REP 5
REPL @{1,1}
REPL @{6,-1}
@END
JUMP LO

MARK 1
LINK 2
JUMP LO
MARK 2
LINK 3
JUMP LO
MARK 3
LINK 5
JUMP LO
MARK 4
LINK 7
JUMP LO
MARK 5
LINK 11
JUMP LO
MARK 6
LINK 13
JUMP LO
```

### [XB](XB.exa) (global)
```asm
LINK 800
MARK LO
@REP 5
REPL @{1,1}
REPL @{6,-1}
@END
JUMP LO

MARK 1
LINK 11
JUMP LO
MARK 2
LINK 13
JUMP LO
MARK 3
LINK 2
JUMP LO
MARK 4
LINK 3
JUMP LO
MARK 5
LINK 5
JUMP LO
MARK 6
LINK 7
JUMP LO
```

