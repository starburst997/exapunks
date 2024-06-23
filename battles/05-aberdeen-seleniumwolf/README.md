# 5: Aberdeen (selenium_wolf)

<div align="center"><img src="EXAPUNKS - Aberdeen (2023-12-01-13-43-05).gif" /></div>

## Instructions
> To win this battle you must occupy a majority of the hosts for as long as possible. You occupy a host if you have more EXAs in it than your opponent.
> 
>      Gain one point every cycle you occupy more hosts than your opponent.
> 
>      Lose one point every time one of your EXAs executes a KILL instruction.
> 
> Writing any value to the #NUKE register will destroy all EXAs in that host, including the EXA that triggered it.
> 
> For more information see "Hacker Battle Domination" in the second issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
LINK 800
LINK 801
LINK 799
MARK STAY
JUMP STAY
```

### [XB](XB.exa) (global)
```asm
LINK 800
MARK LO
REPL SPAWN1
REPL SPAWN2
REPL SPAWN3
REPL SPAWN4

MARK SPAWN1
LINK 800
JUMP LO
MARK SPAWN2
LINK 801
JUMP LO
MARK SPAWN3
LINK 802
JUMP LO
MARK SPAWN4
LINK -1
JUMP LO
MARK SPAWN5

```

