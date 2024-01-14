                .data
my_msg:         .asciiz     "Hello people!!!"
matrixA:        .word32     1,2,3,4
matrix:         .space      32
ordem:          .byte       2
params_sys5:    .space      8


                .text
main:           LB          $s0, ordem($zero) ; ordem da matrix
                ADDI        $t0, $t0, 0x4
                MULT        $s0, $s0
                MFLO        $s1
                ADDI        $s3, $s3, 0x2
                MULT        $s1,$s3
                MFLO        $s1

                ADDI        $s6, $s0, -1  ; Onde por o \n

                ADDI        $t1, $zero, 0x0 ; contador


                MULT        $t0, $t1
                MFLO        $a1
                LB          $s3, matrixA($a1)
                DSLL        $s4, $s4, 0x8
                ADD         $s4, $s4, $s3

                DSLL        $s4, $s4, 0x8
                XOR         $a0, $s6, $t1
                BNEZ        $a0, insetSpace
                ADDI        $s4, $s4, 0x10
                ADD         $s6, $s6, $s0
                J           apoisSpace        
insetSpace:     ADDI        $s4, $s4, 0x20        
apoisSpace:     ADDI        $t1, $t1, 0x1
                MULT        $t0, $t1
                MFLO        $a1
                LB          $s3, matrixA($a1)
                DSLL        $s4, $s4, 0x8
                ADD         $s4, $s4, $s3
                
                DSLL        $s4, $s4, 0x8
                XOR         $a0, $s6, $t1
                BNEZ        $a0, insetSpace2
                ADDI        $s4, $s4, 0x10
                ADD         $s6, $s6, $s0
                J           apoisSpace2        
insetSpace2:     ADDI        $s4, $s4, 0x20        
apoisSpace2:     ADDI        $t1, $t1, 0x1
                   

                J           end
end:            syscall     0
