                .data
format_msg:     .asciiz     "Hello %s\n"
matrix:            .space     32
my_msg:         .asciiz     "Hello people!!!"
params_format:  .space      8
params_sys5:    .space      8

                .code

main:           ADDI        $s1, $zero, -548
                JAL         conv_for_ascii

                DADD       $s2, $zero, $v0

                ADDI        $s1, $zero, 0x20
                JAL         conv_for_ascii

                
                SD          $s2, matrix($zero)
                daddi       $a3, $zero, matrix
                sw          $a3, params_sys5($zero)
                daddi       $t6, $zero, params_sys5
                syscall     5

      
                syscall     0


conv_for_ascii:     ADDI     $t0, $zero, 0xa
                    DADDI    $v1, $zero, 0x0
                    DADD     $v0, $zero, $zero 
                    ANDI     $a1, $s1, 0x80
                    ADDI     $t7, $zero, 0x0 ; numero positivo
                    
                    BEQZ    $a1, eh_positivo
                    ADDI    $a1, $zero, -1
                    MULT    $s1, $a1
                    MFLO    $s1
                    ADDI    $t7, $zero, 0x1 ; numero negativo

eh_positivo:        DSLL    $v0, $v0, 0x8
                    DADDI   $v1, $v1, 0x8
                    DIV     $s1, $t0
                    MFHI    $a2
                    DADDI   $a2, $a2, 0x30
                    DADD    $v0, $v0, $a2
                    MFLO    $s1
                    BNEZ    $s1, eh_positivo
                    BEQZ    $t7, final_func
                    DSLL    $v0, $v0, 0x8
                    DADDI   $v1, $v1, 0x8
                    DADDI   $v0, $v0, 0x2d

final_func:         JALR    $ra

