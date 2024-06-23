# 27: TEC EXA-Blaster Modem (Dataphone Network)

<div align="center"><img src="EXAPUNKS - TEC EXA-Blaster™ Modem (2057, 66, 34, 2023-12-01-13-34-17).gif" /></div>

## Instructions
> Using your modem, connect to each dataphone so that EMBER-2 will have a list of valid phone numbers.
> 
> Each dataphone contains a list of the owner's contacts (file 200). The phone number of one of these dataphones is in your host (file 300), while the rest are in the contact list of another dataphone.
> 
> Note that each dataphone (aside from the first) will appear in exactly one other dataphone's contact list, in such a way that you can find them all without getting stuck in a loop.
> 
> For more information see "Hacker Skills: Modem Control at the Direct Level" in the second issue of the zine.

## Solution

### [XA](XA.exa) (global)
```asm
GRAB 300
LINK 800
DROP
MAKE
COPY 8 F
DROP
GRAB 300
MARK DIAL
SEEK -9999
MULI X 11 T
SEEK T
COPY 11 T
MARK DLO
COPY F #DIAL
SUBI T 1 T
TJMP DLO
ADDI X 1 X
REPL FETCH
JUMP DIAL

MARK RESP
GRAB 300
SEEK 9999
MARK WRI
COPY M T
FJMP NEXT
COPY 11 T
MARK WLO
COPY M F
SUBI T 1 T
TJMP WLO
JUMP WRI
MARK NEXT
MULI X -11 T
SEEK T
COPY -1 #DIAL
JUMP DIAL

MARK FETCH
GRAB 400
COPY F T
FJMP KILL
LINK 800
LINK -1
KILL
REPL RESP
SUBI T 1 T
SEEK -1
COPY T F
DROP
LINK 800
GRAB 200
MARK FLO
COPY 1 M
SEEK 1
COPY 11 T
MARK NLO
COPY F M
SUBI T 1 T
TJMP NLO
TEST EOF
FJMP FLO
COPY 0 M

MARK KILL
WIPE
KILL
GRAB 300
WIPE 

```

#### Results
| Cycles | Size | Activity |
|--------|------|----------|
| 2057   | 66   | 34       |
