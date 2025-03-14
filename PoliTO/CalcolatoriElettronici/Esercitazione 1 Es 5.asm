.data

.text
.globl main
.ent main
main:
li $v0, 5
syscall
move $t1, $v0

li $v0, 5
syscall
move $t2, $v0

add $t2, $t2, $t1
#sub $t1, $t2, $t1

#add $t1, $t2, $t1
#sra $t1, $t1, 2
#sub $t2, $t2, $t1

sub $t1, $t2, $t1
sub $t2, $t2, $t1

li $v0, 1
move $a0, $t1
syscall

li $v0, 1
move $a0, $t2
syscall


li $v0, 10
syscall

