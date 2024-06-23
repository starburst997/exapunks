# 14: Mitsuzen HDI-10 (Heart)

<div align="center"><img src="EXAPUNKS - Mitsuzen HDI-10 (88, 31, 7, 2023-12-01-13-10-33).gif" /></div>

## Instructions
> Read a value from the nerve connected to your central nervous system (CNS) and make your heart beat by writing a sequence of values to your sinoatrial (SA-N) and atrioventricular (AV-N) nodes as indicated in the HDI-10 I/O log when holding the "SHOW GOAL" button. The length of each sequence of values should be equal to the value from the CNS divided by -10. Repeat _ad infinitum_.
> 
> It is not necessary to leave no trace. Your EXAs should be written to operate indefinitely.
> 
> For more information see "Debugging the Phage" in the first issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
LINK 800

MARK LOOP
COPY #NERV T
DIVI T -10 T
SUBI T 2 M
SUBI T 2 M
JUMP LOOP

```

### [XB](XB.exa) (global)
```asm
LINK 800
LINK 1
LINK 1
MARK SALO
COPY M T
COPY 40 #NERV
COPY -70 #NERV
MARK LSA
COPY -70 #NERV
SUBI T 1 T
TJMP LSA
JUMP SALO

```

### [XC](XC.exa) (global)
```asm
LINK 800
LINK 3
LINK 3
MARK AVLO
COPY M T
COPY -70 #NERV
COPY 40 #NERV
MARK LAV
COPY -70 #NERV
SUBI T 1 T
TJMP LAV
JUMP AVLO

```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 88     | 31   | 7        |
