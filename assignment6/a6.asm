start:      lodd on:
            stod 4095
            call xbsywt:
            loco str1:
   	    call writestr:
            call readint:
            lodd binarynum:
            stod sum:
            loco str1:
            call writestr:
            call readint:	    
            lodd binarynum:
            jump addints:
AddInput:   loco str2:
            call writestr:
    	    lodd on:
            stod 4095
            lodd n:
            push
            lodd mask:
            push
	    jump writeint:
crnl:       lodd cr:
            stod 4094
            call xbsywt:
            lodd nl:
            stod 4094
            call xbsywt:
            retn
endnum:     pop
            stod binarynum:
            lodd 4092
            loco 0
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
            call writestr:
h:          halt