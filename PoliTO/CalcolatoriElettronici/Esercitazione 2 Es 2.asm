.data
str1: .asciiz "Inserire due numeri interi positivi: "
str2: .asciiz "numeri troopo grandi!"
.text
.globl main
.ent main
main:
la $a0, str1
li $v0, 4
syscall

li $v0, 5
syscall
move $t0, $v0

li $v0, 5
syscall
move $t1, $t0

li $t2, 256
blt $t0, $t2, ok
la $a0, str2
li $v0, 4
syscall
li $v0, 10
syscall

blt $t1, $t2, ok
la $a0, str2
li $v0, 4
syscall
li $v0, 10
syscall

ok: nor $t2, $t0, $t1
and $t2, $t0, $t2
nor $t2, $t2, $0
xor $t3, $t0, $t1
or $t2, $t2, $t3

move $a0, $t2

li $v0, 1 
syscall

li $v0, 10
syscall
.end main