start:      lodd on:
            stod 4095
            call xbsywt:
            loco str1:
AddInput:   call nextw:
            call bgndig:
            lodd binarynum:
            stod sum:
            loco str1:
            call nextw:
            call bgndig:
            lodd binarynum:
            addd sum:
            stod sum:
            jneg flow:
            loco str2:
            call nextw:
    	    lodd on:
            stod 4095
            lodd n:
            push
            lodd mask:
            push
output:     lodd sum:
            jzer print:
            lodd mask:
            push
            lodd sum:
            push
            div
            pop
            stod sum:
            pop
            insp 2
            addd numoff:
            push
            jump output:
nextw:      pshi
            addd c1:
            stod pstr1:
            pop
            jzer crnl:
            stod 4094
            push
            subd c255:
            jneg crnl:
            call sb:
            insp 1
            push
            call xbsywt:
            pop
            stod 4094
            call xbsywt:
            lodd pstr1:
            jump nextw:
crnl:       lodd cr:
            stod 4094
            call xbsywt:
            lodd nl:
            stod 4094
            call xbsywt:
            retn
bgndig:     lodd on:
            stod 4093
            call rbsywt:
            lodd 4092
            subd numoff:
            push
nxtdig:     call rbsywt:
            lodd 4092
            stod nxtchr:
            subd nl:
            jzer endnum:
            mult 10
            lodd nxtchr:
            subd numoff:
            addl 0
            stol 0
            jump nxtdig:
endnum:     pop
            stod binarynum:
            lodd 4092
            loco 0
            retn
xbsywt:     lodd 4095
            subd mask:
            jneg xbsywt:
            retn
rbsywt:     lodd 4093
            subd mask:
            jneg rbsywt:
            retn
sb:         loco 8
loop1:      jzer finish:
            subd c1:
            stod lpcnt:
            lodl 1
            jneg add1:
            addl 1
            stol 1
            lodd lpcnt:
            jump loop1:
add1:       addl 1
            addd c1:
            stol 1
            lodd lpcnt:
            jump loop1:
finish:     lodl 1
	    retn
print:      pop
            jneg h:
            stod 4094
            call xbsywt:
            jump print:
flow:       loco str3:
            call nextw:
h:          halt
numoff:      48
nxtchr:      0
binarynum:   0
lpcnt:       0
mask:        10
on:          8
nl:          10
cr:          13
c1:          1
c10:	     10
c255:        255
sum:         0
pstr1:       0
str1:  " PLEASE ENTER AN INTEGER BETWEEN 1 AND 32767: "
str2:    "SUM OF NUMBERS IS:"
str3:  "OVERFLOW, NO SUM POSSIBLE"
z:           0
n:           -1