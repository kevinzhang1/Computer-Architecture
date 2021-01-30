writeint:   lodd sum:
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
            jump writeint: