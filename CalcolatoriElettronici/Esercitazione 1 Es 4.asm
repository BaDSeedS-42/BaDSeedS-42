.data

var: .word 0x3FFFFFF0

.text
.globl main
.ent main
main:
lw $t0, var
add $t1, $t0, $t0
move $a0, $t1
li $v0 1
syscall

addi $t4, $t1, 40
move $a0, $t1
li $v0 1
syscall

li $t2, 40
add $t3, $t2, $t1
move $a0, $t1
li $v0 1
syscall

li $v0, 10
syscall