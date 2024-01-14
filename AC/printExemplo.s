	.data
format_str:	.asciiz	"%i "

sys5:		.space	8
menor:	.space	8
	

    .code

DADDUI      $s7, $zero, 15; valor
J       print


print:          daddi     $a0, $zero, format_str
                sw        $a0, sys5($zero)
                sw        $s7, menor($zero)
                daddi $t6, $zero, sys5
                syscall 5
                J   end
                

end: syscall 0
