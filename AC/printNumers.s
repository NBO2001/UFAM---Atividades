                .data
my_msg:         .asciiz     "-1"
matrixA:        .word32     1,2,3,4
matrix:         .space      32
ordem:          .byte       2
params_sys5:    .space      8


                .text
main:           DADDI       $s0, $s0, 0x32
                DSLL        $s0, $s0, 0x8
                DADDI       $s0, $s0, 0x32
                DSLL        $s0, $s0, 0x8
                DADDI       $s0, $s0, 0x32
                DSLL        $s0, $s0, 0x8
                DADDI       $s0, $s0, 0x32
                DSLL        $s0, $s0, 0x8
                DADDI       $s0, $s0, 0x32
                DSLL        $s0, $s0, 0x8
                DADDI       $s0, $s0, 0x32
                DSLL        $s0, $s0, 0x8
                DADDI       $s0, $s0, 0x32
                DSLL        $s0, $s0, 0x8   
                DADDI       $s0, $s0, 0x32
                
       
                
                SD          $s0, matrix($zero)
                daddi       $a0, $zero, matrix
                sw          $a0, params_sys5($zero)
                daddi       $t6, $zero, params_sys5
                syscall     5

                J           end
end:            syscall     0
