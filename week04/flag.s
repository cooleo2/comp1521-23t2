N_COLS = 12
N_ROWS = 6

################################################################################
# .TEXT <main>
	.text
main:
	# Subset:   1
	#
	# Args:     void
	#
	# Returns:
	#    - $v0: int
	#
	# Frame:    [...]
	# Uses:     [...]
	# Clobbers: [...]
	#
	# Locals:
	#   - $t0: row
	#   - $t1: col
	#
	# Structure:
	#   main
	#   -> [prologue]
	#       -> body
	#   -> [epilogue]

main__prologue:
	# TODO: put your prologue for main here

main__body:
	
f_row_init:
    	li	$t0, 0
f_row_cond:
    	bge	$t0, 6, f_row_false


f_col_init:
    	li	$t1, 0
f_col_cond:
    	bge	$t1, 12, f_col_false # if (col >= 12) goto f_col_false;

    	# Access flag[row][col]
	# get base address
	la	$t2, flag
	# calculate row offset (row * N_COLS)
	mul	$t3, $t0, N_COLS
	# add our column offset to row offset
	add	$t4, $t3, $t1
	# mulitply by size of element
	mul	$t4, $t4, 1
	
	# add to base address
	add	$t4, $t4, $t2

	lb	$t5, ($t4)



    	li	$v0, 11		# printf("%c", flag[row][col]);
	move	$a0, $t5
	syscall
f_col_step:
    	add	$t1, $t1, 1
    	b f_col_cond
f_col_false:

    	li	$v0, 11 # printf("\n");
    	li	$a0, '\n'
    	syscall
f_row_step:
    	add	$t0, $t0, 1
    	b f_row_cond
f_row_false:


main__epilogue:
	# TODO: put your epilogue for main here

	jr	$ra
	
	
	.data
flag:

        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
