# 2: Valhalla (=Plastered)

<div align="center"><img src="EXAPUNKS - Valhalla (2023-12-01-13-21-11).gif" /></div>

## Instructions
> To win this battle you must control a majority of the hosts for as long as possible. 
> 
> To take control of a host, write any value to its #CTRL register. Reading from a #CTRL register will tell if you (1) or your opponent (-1) controls the host.
> 
>      Gain one point every cycle you control more hosts than your opponent.
> 
>      Lose one point every time one of your EXAs executes a KILL instruction.
> 
> For more information see "Hacker Battle Domination" in the second issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
LINK 800
MARK LO
COPY 1 #CTRL
REPL UP
REPL DOWN
HALT

MARK UP
REPL UP
MARK FORW
LINK 800
COPY 1 #CTRL
JUMP FORW

MARK DOWN
REPL DOWN
MARK BACKW
LINK -1
COPY 1 #CTRL
JUMP BACKW

```

