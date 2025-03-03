.data
var1: .word 1
var2: .word 3
var3: .word 2
.text
.globl main
.ent main
main:
lw $t0, var1
lw $t1, var2
lw $t2, var3

bgt $t0, $t1, amaggioreb
passaggio2: bgt $t0, $t2, amaggiorec
passaggio3: bgt $t1, $t2, bmaggiorec
j fine

amaggioreb: move $t3, $t0
move $t0, $t1
move $t1, $t3
j passaggio2

amaggiorec: move $t3, $t0
move $t0, $t2
move $t2, $t3
j passaggio3

bmaggiorec: move $t3, $t1
move $t1, $t2
move $t2, $t3

fine: move $a0, $t0
li $v0, 1
syscall

move $a0, $t1
li $v0, 1
syscall

move $a0, $t2
li $v0, 1
syscall

li $v0, 10
syscall

.end main