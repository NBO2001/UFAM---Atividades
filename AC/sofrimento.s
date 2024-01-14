	                .data
vetor:	            .byte		    9,8,7,6,5,4,3,2	;maior 7, menor 2

format_str:	        .asciiz	        "O maior numero primo eh %i.\nO menor numero primo eh %i.\n"

sys5:		        .space	        8
maior:	            .space	        8
menor:	            .space	        8
	
	                .code
                    DADDUI          $s6, $zero, -1 ; maior primo
                    DADDUI          $s7, $zero, 0x7f ; menor primo
                    DADDUI          $a3, $zero, 0x8 ; Vector tam
                    DADDUI          $v1, $zero, 0x1 ; Inicializa o retorno i_plus_plus
                    LB              $a0, vetor($a2)   ; Carrega o primeiro valor do vector
loopVec:            JAL             isPrime
                    
                    BEQZ            $v0, i_plus_plus ; incrementa se n for primo
                    BEQZ            $v1, print    ; verify if vector esta no fim
                    BEQZ            $v0, loopVec ; se nao or primo volta ao loop
                    
                    JAL             ifIsBigger
                    JAL             ifIsLess
                    
                    J               i_plus_plus ; incrementa se n for primo
                    BEQZ            $v1, print    ; verify if vector esta no fim
                    J               loopVec ; se nao or primo volta ao loop

jump_for_ra:        JR              $ra

isPrime:            DADDUI          $s0, $zero, 0x2 ; divisor
                    DADDUI          $v0, $zero, 0x1 ; retorno, por padrao o numero eh primo
                    SLTI            $t0, $a0, 0x3
                    BNEZ            $t0, jump_for_ra

loop:               BEQ             $a0, $s0, jump_for_ra
                    SLT             $t0, $a0, $s0
                    BNEZ            $t0, jump_for_ra
                    DIV             $a0, $s0
                    MFHI            $t1                         ; guarda o resto
                    MOVZ            $v0, $zero, $t1             ; Se o resto for zero, move zero para $v0
                    BEQZ            $t1, jump_for_ra
                    ADDIU           $s0, $s0, 0x1
                    J               loop

ifIsBigger:         SLT             $t0, $a0, $s6
                    BNEZ            $t0, jump_for_ra
                    ADD             $s6, $zero, $a0
                    JR              $ra

ifIsLess:           SLT             $t0, $s7, $a0
                    BNEZ            $t0, jump_for_ra
                    ADD             $s7, $zero, $a0
                    JR              $ra

i_plus_plus:        ADDI            $ra, $ra, 0x4
                    ADDI            $a2, $a2, 0x1
                    SLT             $v1, $a2, $a3
                    BEQZ            $v1, jump_for_ra            
                    LB              $a0, vetor($a2)
                    JR              $ra

print:          daddi     $a1, $zero, format_str
                sw        $a1, sys5($zero)
                sw        $s6, maior($zero)
                sw        $s7, menor($zero)
                daddi $t6, $zero, sys5
                syscall 5
                J   end

end:                syscall         0

