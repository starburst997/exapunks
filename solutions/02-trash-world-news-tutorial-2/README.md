# 2: Trash World News (Tutorial 2)

<div align="center"><img src="EXAPUNKS - TRASH WORLD NEWS (7, 6, 2, 2023-12-01-13-00-38).gif" /></div>

## Instructions
> Add the first two values of file 200, multiply the result by the third value, and then subtract the fourth value. Append the result to the end of the file and then move it to the *outbox*.
> 
> You can press the "SHOW GOAL" button (or F1) at any time to see a preview of the completed task.
> 
> For help completing this task see "Ghast Walks U Thru It" in the first issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
LINK 800
GRAB 200
ADDI F F X
MULI X F X
SUBI X F F
LINK 800
```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 7      | 6    | 2        |
