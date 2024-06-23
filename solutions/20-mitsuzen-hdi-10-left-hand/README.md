# 20: Mitsuzen HDI-10 (Left Hand)

<div align="center"><img src="EXAPUNKS - Mitsuzen HDI-10 (155, 24, 114, 2023-12-01-13-22-01).gif" /></div>

## Instructions
> There are three nerve signals that need to be relayed: muscle control (M), which runs from your central nervous system (CNS) to your hand (HND), and heat (H) and pressure (P), which run the other direction.
> 
> For each signal, read a value from the input nerve and relay it to the output nerve. Repeat _ad infinitum_.
> 
> It is not necessary to leave no trace. Your EXAs should be written to operate indefinitely.
> 
> For more information see "Debugging the Phage" in the first issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
LINK 800
LINK -3
LINK -3
MARK LO
COPY #NERV M
LINK -3
COPY M #NERV
LINK -3
COPY M #NERV
LINK 3
LINK 3
JUMP LO
```

### [XB](XB.exa) (global)
```asm
LINK 800
LINK 3
LINK 3
MARK LO
COPY M #NERV
LINK 3
COPY #NERV M
LINK 3
COPY #NERV M
LINK -3
LINK -3
JUMP LO
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 155    | 24   | 114      |
