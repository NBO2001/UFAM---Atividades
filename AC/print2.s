                .data
my_msg:         .asciiz     "Hello people!!!"
matrixA:        .word32     1,2,3,4
matrix:         .space      32
ordem:          .byte       2
params_sys5:    .space      8


                .text
main:           LB          $s0, ordem($zero) ; ordem da matrix
                MULT        $s0, $s0
                MFLO        $s1
                ADDI        $s3, $s3, 0x2
                MULT        $s1,$s3
                MFLO        $s1

                ADDI        $t0, $zero, 0x0 ; contador

                ADDI        $s4, $zero, 0x65
                DSLL        $s4, $s4, 0x8
                ADDI        $s5, $zero, 0x6c
                ADD        $s4, $s4, $s5

                SW          $s4, matrix($t0) 

                ADDI        $t0, $t0, 0x4
                SW          $s4, matrix($t0) 

                J           end
end:            syscall     0
