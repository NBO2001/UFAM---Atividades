            .data


            .text

            addi    $a3, $zero, 54
            addi    $s7, $zero, 0x4

            l.d     f0, MP($zero)
            l.d     f1, const1($zero)
            l.d     f4, Fact($zero)  ; coloca o fator de multiplicacao no f4
            mul.d   f2, f0, f1
            l.d     f0, PF($zero)
            add.d   f2, f0, f2
            l.d     f1, const2($zero)
            div.d   f2, f2, f1
            cvt.w.d f3, f2
            mul.d   f2, f2, f4
            dmfc1   r6, f2
            s.d     f2, vector($zero) 
            addi    $a3, $zero, 0x7
            LB      $s1, vector($a3)
            SLLV    $s1, $s1, $s7
            addi    $a3, $zero, 0x6
            LB      $s3, vector($a3)
            andi    $s3, $s3, 0x0ff
            SRLV    $s3, $s3, $s7

            add     $s2, $s1, $s3
            addi    $s6, $s2, -1023
            addi    $s5, $zero, 0xc
            addi    $s6, $s2, -1023
            sub     $s6, $s5, $s6


            addi    $a3, $zero, 0x6
            LB      $s3, vector($a3)
            andi    $s3, $s3, 0x0f
            addi    $s7, $zero, 0x8
            SLLV    $s3, $s3, $s7

            addi    $a3, $zero, 0x5
            LB      $s1, vector($a3)
            add     $s2, $s1, $s3
            addi    $s3, $zero, 0x1
            addi    $s7, $zero, 0xc
            SLLV    $s3, $s3, $s7
            add     $s2, $s2, $s3
            SRLV    $s2, $s2, $s6

            addi    $s7, $zero, 0x8

            addi    $t0, $zero, 10
            div     $s2, $t0     
            MFHI    $s1
            MFLO    $s2
            addi    $s1, $s1, 48
            SLLV    $s0, $s0, $s7
            add     $s0, $s0, $s1

            div     $s2, $t0
            MFHI    $s1
            MFLO    $s2
            addi    $s1, $s1, 48
            SLLV    $s0, $s0, $s7
            add     $s0, $s0, $s1  

            SLLV    $s0, $s0, $s7
            addi     $s0, $s0, 0x2e 
            SLLV    $s0, $s0, $s7
            add     $s0, $s0, $s2 
            sw      $s0, notaas($zero)
            J       print

            
print:          daddi     $a1, $zero, str
                sw        $a1, str_addr($zero)
                daddi     $a0, $zero, notaas
                sw        $a0, params_formt($zero)

                daddi $t6, $zero, str_addr
                syscall 5
                J   end

end:                syscall         0

