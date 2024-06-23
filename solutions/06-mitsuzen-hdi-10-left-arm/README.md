# 6: Mitsuzen HDI-10 (Left Arm)

<div align="center"><img src="EXAPUNKS - Mitsuzen HDI-10 (196, 26, 6, 2023-12-01-13-04-27).gif" /></div>

## Instructions
> Read a value from the nerve connected to your central nervous system (CNS) and relay it to the nerve connected to your arm (ARM), clamping the value so that it never goes below -120 or above 50. Repeat _ad infinitum_.
> 
> Since this task takes place inside a network you control— that is, your own body— it is not necessary to leave no trace. Your EXAs should be written to operate indefinitely.
> 
> Note that #NERV is a _hardware register_, not a file. You can use it directly in your code like any other register.
> 
> For more information about the phage see "Debugging the Phage" in the first issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
LINK 800
MARK LOOP
COPY #NERV X
TEST X < -120
TJMP MIN
COPY X M
JUMP LOOP

MARK MIN
COPY -120 M
JUMP LOOP
```

### [XB](XB.exa) (global)
```asm
LINK 800
COPY 4 X
MARK M_LOOP
LINK 1
SUBI X 1 X
TEST X > 0
TJMP M_LOOP
MARK LOOP
COPY M X
TEST X > 50
TJMP MAX
COPY X #NERV
JUMP LOOP
MARK MAX
COPY 50 #NERV
JUMP LOOP
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 196    | 26   | 6        |
