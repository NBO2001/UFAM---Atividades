                .data
matrixA:    .word32     4, 2, -3, -1
matrixB:    .word32     -3,1,4,-2
matrixR:    .word32     0,0,0,0
ordem:      .byte       2
matrix:         .space    64
params_format:  .space      8
params_sys5:    .space      8

                .code
LB          $s0,        ordem($zero) ; ordem da matrix
ADDI        $t1,        $zero, 0x4
MULT        $s0,        $t1
MFLO        $t1

MULT        $s0,        $s0
MFLO        $s0

ADDI        $s2,        $zero, 0x4
MULT        $s0,        $s2          ; Tamanho total da matriz
MFLO        $s1                      ; tam==s1
ADD         $s2,        $zero, $zero ; so para dizer  q (column_control==s2) recebe zero
ADD         $s3,        $zero, $t1 ; loop_control==s3
ADD         $s4,        $zero, $zero ; so para dizer  q (i_start==s4) recebe zero
ADD         $s5,        $zero, $zero ; so para dizer  q (b_control==s5) recebe zero
ADD         $s6,        $zero, $zero ; so para dizer  q (a_control==s6) recebe zero

tercWhileStart:
SLT         $a0,        $s2, $t1     ;  column_control < ordem
BEQZ        $a0,        tercWhileEnd    ;  while

secondWhileStart:
SLT         $a0,        $s6, $s1     ; a_control < tam
BEQZ        $a0,        secondWhileEnd    ; while

ADD         $t0,        $zero, $s4  ; i = i_start

fistWhileStart:
SLT         $a0,        $t0, $s3     ; i < loop_control
BEQZ        $a0,        firstWhileEnd    ; while

LB          $a1,        matrixA($s6)    ; matrixA[a_control]
LB          $a2,        matrixB($s5)    ; matrixB[b_control]
MULT        $a1, $a2
MFLO        $a1
LB          $a2,        matrixR($t0)
ADD         $a2,        $a2, $a1
SW          $a2,        matrixR($t0) 

ADDI        $s6,        $s6, 0x4 ; a_control += 4
ADDI        $t0,        $t0, 0x4 ; i += 4

B           fistWhileStart

firstWhileEnd:
ADDI        $s5,        $s5, 0x4;  b_control += 1
B           secondWhileStart

secondWhileEnd: 
ADD         $s3,        $s3, $t1    ; loop_control += ordem


ADD         $s4,        $s4, $t1   ; i_start += ordem

ADD         $s6,        $zero, $zero  ; a_control = 0
ADDI        $s2,        $s2, 0x4    ; column_control += 4
B           tercWhileStart
tercWhileEnd: B print_f

final_code: SYSCALL 0



print_f:        XOR        $s5,$s5,$s5 
                ADD        $s0, $zero, $zero ; i = 0
                ADDI       $s2, $zero, 0x4
                LB         $s4,        ordem($zero) ; ordem da matrix
                MULT       $s4,$s4
                MFLO       $t5
                

start_loop_1:   SLT         $t0, $s0, $s4    ;  i < ordem
                BEQZ        $t0, finalLoop
                ADD         $s3, $zero, $s0

start_loop_2:   SLT        $t0, $s3, $t5    ;  i < ordem
                BEQZ        $t0, final_loop_2

                MULT       $s3, $s2
                MFLO       $t0


                LB         $s1, matrixR($t0)
                JAL         conv_for_ascii
                JAL         func_add_wd
                JAL         verify_is_full 

                XOR         $v0, $v0,$v0
                XOR         $v1, $v1,$v1
                ADDI        $v0, $zero, 0x20
                ADDI        $v1, $zero, 0x8
                JAL         func_add_wd
                JAL         verify_is_full 
      

                ADD   $s3, $s3, $s4
                B       start_loop_2
final_loop_2:   
                ADDI   $s0, $s0, 0x1

                XOR         $v0, $v0,$v0
                XOR         $v1, $v1,$v1
                ADDI        $v0, $zero, 0xa
                ADDI        $v1, $zero, 0x8
                JAL         func_add_wd
                JAL         verify_is_full  

                B       start_loop_1

finalLoop:      JAL         func_add_wd
                JAL         move_restante 

                daddi       $a3, $zero, matrix
                sw          $a3, params_sys5($zero)
                daddi       $t6, $zero, params_sys5
                syscall     5   

                B           final_code
      
                


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
                    SLT         $t2, $v1, $t1
                    BEQZ        $t2, nao_tem_spaco
                    DSLLV       $v0, $v0, $s7
                    DADD        $s6, $s6, $v0
                    DADD        $s7, $s7, $v1
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

