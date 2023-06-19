main:

	# $t0: i
	# $t1: base address
	# $t2: offset
	# $t3: address of numbers[i]
	# $t4: x or numbers[i]
	# $t6: address of numbers[9-i]
	# $t7: y or numbers[9-i]


f_i_init:
    li	$t0, i
f_i_cond:
    	bge $t0, 5, f_i_false	# if (i >= 5) goto f_i_false;

	la	$t1, numbers 	# base address
	mul	$t2, $t0, 4	# offset
	add	$t3, $t2, $t1	# address of numbers[i]
	lw	$t4, ($t3)

	sub	$t5, 9, $t0	# 9 - i
	mul	$t5, $t5, 4	# (9 - i) * 4
	add	$t6, $t5, $t1	# address of numbers[9-i]
	lw	$t7, ($t6)

	sw	$t4, ($t6)
	sw	$t7, ($t3)


    

f_i_step:
    	add	$t0, $t0, 1
	j	f_i_cond
f_i_false:

	li	$v0, 0
	jr	$ra	# return 0;

        .data
numbers:
        .word   0, 1, 2, 3, 4, 5, 6, 7, 8, 9
