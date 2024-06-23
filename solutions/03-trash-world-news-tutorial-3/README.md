# 3: Trash World News (Tutorial 3)

<div align="center"><img src="EXAPUNKS - TRASH WORLD NEWS (9, 13, 4, 2023-12-01-13-00-51).gif" /></div>

## Instructions
> File 199 contains exactly two values: a keyword and a number. Create a new file in the *outbox* and copy those two values to it, swapping their order so that the number is first. When you are finished, delete file 199.
> 
> For help completing this task see "Ghast Walks U Thru It" in the first issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
LINK 800
LINK 799
GRAB 199
COPY F M
COPY F M
WIPE
```

### [XB](XB.exa) (global)
```asm
NOOP
LINK 800
LINK 800
MAKE
COPY M X
COPY M F
COPY X F

```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 9      | 13   | 4        |
