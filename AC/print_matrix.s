                .data
format_msg:     .asciiz     "Hello %s\n"
matrix:            .space     32
my_msg:         .asciiz     "Hello people!!!"
params_format:  .space      8
params_sys5:    .space      8

                .code

main:           ADDI        $s1, $zero, -548
                JAL         conv_for_ascii
                JAL         func_add_wd
                JAL         verify_is_full

                ADDI        $v0, $zero, 0x20
                ADDI        $v1, $zero, 0x8
                JAL         func_add_wd
                JAL         verify_is_full

                ADDI        $s1, $zero, 0x20
                JAL         conv_for_ascii
                JAL         func_add_wd
                JAL         verify_is_full

                ADDI        $v0, $zero, 0x20
                ADDI        $v1, $zero, 0x8
                JAL         func_add_wd
                JAL         verify_is_full
                

                ADDI        $s1, $zero, 0x20
                JAL         conv_for_ascii
                JAL         func_add_wd
                JAL         verify_is_full

                ADDI        $v0, $zero, 0x20
                ADDI        $v1, $zero, 0x8
                JAL         func_add_wd
                JAL         verify_is_full

                JAL         func_add_wd
                JAL         move_restante
                
                daddi       $a3, $zero, matrix
                sw          $a3, params_sys5($zero)
                daddi       $t6, $zero, params_sys5
                syscall     5

      
                syscall     0


move_restante:      SD  $s6, matrix($s5)
                    XOR             $s6,$s6,$s6
                    XOR             $s7,$s7,$s7
                    JALR            $ra


; guarda em $s5 o index do vetor de caracteres
verify_is_full:     SLTI            $t0, $s7, 0x40
                    BNEZ            $t0, end_the_func
                    SD              $s6, matrix($s5)
                    ADDI            $s5, $s5, 0x8
                    XOR             $s6,$s6,$s6
                    XOR             $s7,$s7,$s7
end_the_func:       JALR            $ra

; A funcao usa o registrador $s7 para manter o tamanho da palavra e $s6 para a palavra
; E pega o valor de $v0 e $v1
func_add_wd:        ADDI        $t0, $zero, 0x40 ; maximo de uma palavra
                    DSUB        $t1, $t0, $s7   
                    ADDI        $t1, $t1, 0x1 
                    SLT         $t2, $v1, $t1
                    BEQZ        $t2, nao_tem_spaco
                    DSLLV       $v0, $v0, $s7
                    DADD        $s6, $s6, $v0
                    DADD        $s7, $s7, $v1
                    XOR         $v0,$v0,$v0
                    XOR         $v0,$v0,$v0
                    JALR        $ra
                    
nao_tem_spaco:      DSUB        $t3, $v1, $t1
                    DADD        $t4, $zero, $v0
                    DSLLV       $t4, $v0, $s7
                    DADD        $s6, $s6, $t4
                    DADD        $v1, $zero, $t3
                    DSRLV       $v0, $v0, $t1
                    DADD        $s7, $zero, $t0
                    JALR        $ra




; convert o que estar em $s1 para codigo asciiz
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

