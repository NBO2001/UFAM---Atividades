	.data
format_str:	.asciiz	"O maior numero primo eh %i.\nO menor numero primo eh %i.\n"
vetor:	.byte		9,8,7,6,5,4,3,2	;maior 7, menor 2

sys5:		.space	8
maior:	.space	8
menor:	.space	8
	

    .code
DADDUI      $a0, $zero, 0xfff
DADDUI      $a2, $zero,0x0 ; index i
DADDUI      $a3, $zero,0x8 ; index i
DADDUI      $s6, $zero, -1 ; maior primo
DADDUI      $s7, $zero, 0x7f ; menor primo
LB      $a1, vetor($a2)
J       buscaprimo


inclemento_vetor:   ADDIU       $a2, $a2, 1
                    LB      $a1, vetor($a2)
                    J       buscaprimo


buscaprimo: DADDUI      $s0, $zero, 0x2 ; divisor
            DADDUI      $s1, $zero, 0x0 ; total de divisoes alem dele e de zero
            J loop

naoEhPrimo:     ADDIU       $a2, $a2, 1
                LB      $a1, vetor($a2)
                
                J buscaprimo

alteraMenor:    SLT    $s5, $a1, $s7
                BEQZ    $s5, alteraMaior
                ADD    $s7, $zero, $a1
                J       alteraMaior

alteraMaior:    SLT    $s5, $a1, $s6
                BNEZ    $s5, inclemento_vetor
                ADD    $s6, $zero, $a1
                J       inclemento_vetor


loop:           BEQ      $a3, $a2, print
                DIVU        $a1, $s0
                MFHI        $s2
                BEQ         $s0, $a1, alteraMenor
                ADDIU       $s0, $s0, 1
                BEQZ        $s2, naoEhPrimo
                bne         $s0, $a1, loop
                J alteraMenor

print:          daddi     $a0, $zero, format_str
                sw        $a0, sys5($zero)
                sw        $s6, maior($zero)
                sw        $s7, menor($zero)
                daddi $t6, $zero, sys5
                syscall 5
                J   end
                

end: syscall 0
