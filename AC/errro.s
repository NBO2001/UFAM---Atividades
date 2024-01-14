            .data
matrixA:    .word32     1,1,1, 1,1,1, 1,1,1
matrixB:    .word32     1,1,1, 1,1,1, 1,1,1
matrixR:    .word32     0,0,0,0,0,0,0,0,0
ordem:      .byte       3

            .code
LB          $s0,        ordem($zero) ; ordem da matrix
ADDI        $t0, $zero, 0x12

LB          $a2,        matrixA($t0)
ADD         $a2,        $a2, $a1
SW          $a2,        matrixR($t0) 