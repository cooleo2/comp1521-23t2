main:
        
        
f_i_init:
	li	$t0,	0
f_i_cond:
	bge	$t0,	10, f__epi
	
	# $t0: i
	# $t1: base address
	# $t2: offset
	# $t3: address of numbers[i]
	# $t4: value we scanned in


	la	$t1, numbers 	# base address
	mul	$t2, $t0, 4	# offset
	add	$t3, $t2, $t1

	li	$v0, 5
	syscall
	move	$t4, $v0	# scanf

	sw	$t4, ($t3)


f_i_step:
	addi	$t0, $t0, 1 # i++
	j	f_i_cond
f_i_false:
f__epi:


      
f_i_print_init:
	li	$t0,	0
f_i_print_cond:
	bge	$t0,	10, f__print_epi
	# $t1: &array[i]
	mul	$t3, $t0, 4 # i * size of word
	addi	$t1, $t3, numbers # &array + i

	lw	$t2, ($t1)


	li	$v0, 1
	move	$a0, $t2
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall
	

	


f_i_print_step:
	addi	$t0, $t0, 1 # i++
	j	f_i_print_cond
f_i_print_false:
f__print_epi:


        jr	$ra # return
        

        .data
numbers:
        .word 0:10 # 10x words initalised to 0
