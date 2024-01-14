                .data
my_msg:         .asciiz     "Hello people!!!"
params_sys5:    .space      8

                .text
main:           daddi       $a0, $zero, my_msg
                sw          $a0, params_sys5($zero)
                daddi       $t6, $zero, params_sys5
                syscall     5
                J           end
end:            syscall     0
