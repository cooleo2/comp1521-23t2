main:
N_ELEMENTS =  5
	# $t0 : i
f_i_init:
	li	$t0,	0
f_i_cond:
	bge	$t0,	N_ELEMENTS, f__epi
	
	# $t1: base address
	# $t2: offset
	# $t3: address of array[i]
	# $t4: value array[i]

	# Access array[i] 
	# get base address
	la	$t1, array
	# calculate offset
	mul	$t2, $t0, 4
	# base address + offset
	add	$t3, $t2, $t1

	lw	$t4, ($t3)
	
	li	$v0, 1
	move	$a0, $t4
	syscall			# printf("%d", )


	li	$v0, 11	
	li	$a0, '\n'
	syscall


f_i_step:
	addi	$t0, $t0, 1 # i++
	j	f_i_cond
f_i_false:
f__epi:

	li	$v0, 0
	jr	$ra			# return 0;


	.data
array:
	.word	10, 104, 1004, 2299, 9933
