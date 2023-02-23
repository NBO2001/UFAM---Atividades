    data r0,vec
    data r2,9
    move r0,r3
    add r2,r3
loop:
    clf
    ld r0,r1
    ld r3,r2
    st r0,r2
    st r3,r1
    data r2,-1
    add r2,r3
    data r2,1
    clf
    add r2,r0
    clf
    cmp r0,r3
    jae return
    jmp loop
return:
    data r1,0x01
    ld r1,r0
    halt
vec:
    .word 1
    .word 2
    .word 3
    .word 4
    .word 5
    .word 6
    .word 7
    .word 8
    .word 9
    .word 10