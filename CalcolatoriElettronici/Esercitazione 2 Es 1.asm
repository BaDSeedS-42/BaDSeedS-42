.data
str1: .asciiz "inserire un intero positivo: "
str2: .asciiz "e' pari"
str3: .asciiz "e' dispari"
.text
.globl main
.ent main
main:
la $a0, str1
li $v0, 4
syscall

li $v0, 5
syscall

move $t7, $v0
#li $t1, 2
#div $v0, $t1
#mfhi $t0
andi $t0, $t7, 1
bne $t0, $0, dispari
la $a0, str2
li $v0, 4
syscall
li $v0, 10
syscall
dispari: la $a0, str3
li $v0, 4
syscall
li $v0, 10
syscall
.end main