                .data
error_3:        .asciiz     "Error while reading from file"
ok_message:     .asciiz     "All right"
params_sys3:    .space      8
params_sys5:    .space      8
ind_value:      .space      8
                .word64     16


value:          .space      30

                .text
read:           daddi       $t6, $zero, params_sys3
                sw          $s2, params_sys3($zero)
                daddi       $s1, r0, value
                sw          $s1, ind_value($zero)
                syscall 3
                daddi       $s0, r0, -1
                daddi       $a0, r0,ok_message
                bne         r1, $s0,print
                daddi       $a0, r0,error_3

print:          add         $a1, $zero, $s1
                sw          $a1, params_sys5($zero)
                syscall 5
                bne         r1, $s0,end
end:            syscall 0