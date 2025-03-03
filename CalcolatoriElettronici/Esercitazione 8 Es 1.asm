			.data

uscita:		.byte 18 14
X:			.byte 1
Y:			.byte 40
ingresso:	.byte 12 47	
	.text
	.globl main
	.ent main	
	
main: 
		la $a0, ingresso
		la $a1, uscita
		lb $a2, X
		lb $a3, Y
		
		jal costoParcheggio
		
		move $a0, $v0
		li $v0, 1
		syscall
		
		

	li $v0, 10
	syscall
	.end main

	.ent costoParcheggio
costoParcheggio:

	lb $t0,0($a0)
	lb $t1,1($a0)
	mul $t0, $t0, 60
	add $t0, $t0, $t1
	
	lb $t1,0($a1)
	lb $t2,1($a1)
	mul $t1, $t1, 60
	add $t1, $t1, $t2
	
	sub $t0, $t1, $t0
	div $t0, $a3
	
	mflo $t0
	mfhi $t1
	
	beq $t1, $0, salta
	addi $t0, $t0, 1
salta: mul $t0, $t0, $a2
	mflo $v0	
	jr $ra

	.end costoParcheggio