	.data
anni: .word 1945, 2008, 1800, 2006, 1748, 1600
risultati: .space 6
lunghezza: .byte 6
	.text
	.globl main
	.ent main
		
main:
		la $a0, anni
		la $a1, risultati
		lb $a2, lunghezza
		
		jal bisestile
		
	la $a0 risultati
	li $v0, 1
	syscall

	li $v0, 10
	syscall
	.end main
	
	.ent bisestile
bisestile:
		move $t0, $0
	ciclo: lw $t1, 0($a0)


	.end bisestile