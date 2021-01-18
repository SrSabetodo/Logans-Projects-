	.file	"sudoku.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "\0"
LC1:
	.ascii "color 70\0"
LC2:
	.ascii "cls\0"
	.align 4
LC3:
	.ascii "Congradulations! \12You have solved the puzzle!\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$80, %esp
	call	___main
	movl	$0, (%esp)
	call	_time
	movl	%eax, (%esp)
	call	_srand
	movl	$LC0, (%esp)
	call	_puts
	movl	$LC1, (%esp)
	call	_system
	call	_allocateArray
	movl	%eax, 76(%esp)
	movl	76(%esp), %eax
	movl	%eax, (%esp)
	call	_readFromFile
	movl	%eax, 76(%esp)
	call	_allocateArray
	movl	%eax, 72(%esp)
	movl	76(%esp), %eax
	movl	%eax, 4(%esp)
	movl	72(%esp), %eax
	movl	%eax, (%esp)
	call	_populateControlArray
	movl	%eax, 72(%esp)
	leal	56(%esp), %eax
	movl	%eax, 8(%esp)
	leal	60(%esp), %eax
	movl	%eax, 4(%esp)
	movl	76(%esp), %eax
	movl	%eax, (%esp)
	call	_setInitialPosition
	movl	60(%esp), %eax
	movl	%eax, 52(%esp)
	movl	56(%esp), %eax
	movl	%eax, 48(%esp)
	movl	76(%esp), %eax
	movl	%eax, (%esp)
	call	_findNumEmptySpaces
	movl	%eax, 44(%esp)
	movl	76(%esp), %eax
	movl	%eax, (%esp)
	call	_welcomeScreen
L17:
	movl	$LC2, (%esp)
	call	_system
	movl	76(%esp), %eax
	movl	%eax, (%esp)
	call	_display
	movl	44(%esp), %eax
	testl	%eax, %eax
	jns	L2
	movl	$LC3, (%esp)
	call	_puts
	jmp	L3
L2:
	call	_getch
	movb	%al, 71(%esp)
	movsbl	71(%esp), %eax
	movl	%eax, 64(%esp)
	cmpl	$27, 64(%esp)
	je	L19
	movl	44(%esp), %eax
	testl	%eax, %eax
	jle	L5
	cmpl	$97, 64(%esp)
	je	L6
	cmpl	$119, 64(%esp)
	je	L6
	cmpl	$100, 64(%esp)
	je	L6
	cmpl	$115, 64(%esp)
	jne	L7
L6:
	leal	48(%esp), %eax
	movl	%eax, 20(%esp)
	leal	52(%esp), %eax
	movl	%eax, 16(%esp)
	leal	56(%esp), %eax
	movl	%eax, 12(%esp)
	leal	60(%esp), %eax
	movl	%eax, 8(%esp)
	movl	64(%esp), %eax
	movl	%eax, 4(%esp)
	movl	76(%esp), %eax
	movl	%eax, (%esp)
	call	_processInput
	leal	48(%esp), %eax
	movl	%eax, 16(%esp)
	leal	52(%esp), %eax
	movl	%eax, 12(%esp)
	leal	56(%esp), %eax
	movl	%eax, 8(%esp)
	leal	60(%esp), %eax
	movl	%eax, 4(%esp)
	movl	76(%esp), %eax
	movl	%eax, (%esp)
	call	_setSpaceToX
	jmp	L14
L7:
	cmpl	$8, 64(%esp)
	jne	L9
	leal	56(%esp), %eax
	movl	%eax, 8(%esp)
	leal	60(%esp), %eax
	movl	%eax, 4(%esp)
	movl	76(%esp), %eax
	movl	%eax, (%esp)
	call	_backSpacePressed
	jmp	L17
L9:
	cmpl	$92, 64(%esp)
	jne	L10
	leal	56(%esp), %eax
	movl	%eax, 8(%esp)
	leal	60(%esp), %eax
	movl	%eax, 4(%esp)
	movl	76(%esp), %eax
	movl	%eax, (%esp)
	call	_backSlashPressed
	jmp	L17
L10:
	cmpl	$48, 64(%esp)
	jle	L11
	cmpl	$57, 64(%esp)
	jg	L11
	movsbl	71(%esp), %eax
	leal	44(%esp), %edx
	movl	%edx, 16(%esp)
	movl	%eax, 12(%esp)
	leal	56(%esp), %eax
	movl	%eax, 8(%esp)
	leal	60(%esp), %eax
	movl	%eax, 4(%esp)
	movl	76(%esp), %eax
	movl	%eax, (%esp)
	call	_numberEntered
	jmp	L14
L11:
	cmpl	$104, 64(%esp)
	jne	L12
	movl	76(%esp), %eax
	movl	%eax, (%esp)
	call	_helpKeyPressed
	jmp	L17
L12:
	cmpl	$83, 64(%esp)
	jne	L13
	movl	72(%esp), %eax
	movl	%eax, 12(%esp)
	leal	56(%esp), %eax
	movl	%eax, 8(%esp)
	leal	60(%esp), %eax
	movl	%eax, 4(%esp)
	movl	76(%esp), %eax
	movl	%eax, (%esp)
	call	_deleteMode
	jmp	L17
L13:
	cmpl	$108, 64(%esp)
	jne	L17
	movl	76(%esp), %eax
	movl	%eax, (%esp)
	call	_locateSelection
	jmp	L17
L5:
	cmpl	$48, 64(%esp)
	jle	L15
	cmpl	$57, 64(%esp)
	jg	L15
	movsbl	71(%esp), %eax
	leal	44(%esp), %edx
	movl	%edx, 16(%esp)
	movl	%eax, 12(%esp)
	leal	56(%esp), %eax
	movl	%eax, 8(%esp)
	leal	60(%esp), %eax
	movl	%eax, 4(%esp)
	movl	76(%esp), %eax
	movl	%eax, (%esp)
	call	_numberEntered
	jmp	L14
L15:
	cmpl	$104, 64(%esp)
	jne	L16
	movl	76(%esp), %eax
	movl	%eax, (%esp)
	call	_helpKeyPressed
	jmp	L17
L16:
	cmpl	$108, 64(%esp)
	jne	L17
	movl	76(%esp), %eax
	movl	%eax, (%esp)
	call	_locateSelection
L14:
	jmp	L17
L19:
	nop
L3:
	movl	76(%esp), %eax
	movl	%eax, (%esp)
	call	_deallocateStuff
	movl	72(%esp), %eax
	movl	%eax, (%esp)
	call	_deallocateStuff
	movl	$0, %eax
	leave
	ret
	.section .rdata,"dr"
	.align 4
LC4:
	.ascii "      %c | %c | %c || %c | %c | %c || %c | %c | %c  \12\0"
	.align 4
LC5:
	.ascii "     _____________________________________\0"
	.align 4
LC6:
	.ascii "     =====================================\0"
	.text
	.globl	_display
	.def	_display;	.scl	2;	.type	32;	.endef
_display:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$76, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ebx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$7, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %esi
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$6, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, -28(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$5, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	%edx, -32(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ecx
	movl	%ecx, -36(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$3, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edi
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$2, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ecx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$1, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%ebx, 36(%esp)
	movl	%esi, 32(%esp)
	movl	-28(%ebp), %ebx
	movl	%ebx, 28(%esp)
	movl	-32(%ebp), %esi
	movl	%esi, 24(%esp)
	movl	-36(%ebp), %ebx
	movl	%ebx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$LC5, (%esp)
	call	_puts
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ebx
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	addl	$7, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %esi
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	addl	$6, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, -28(%ebp)
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	addl	$5, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edi
	movl	%edi, -32(%ebp)
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	%edx, -36(%ebp)
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	addl	$3, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edi
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	addl	$2, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ecx
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	addl	$1, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%ebx, 36(%esp)
	movl	%esi, 32(%esp)
	movl	-28(%ebp), %esi
	movl	%esi, 28(%esp)
	movl	-32(%ebp), %ebx
	movl	%ebx, 24(%esp)
	movl	-36(%ebp), %esi
	movl	%esi, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$LC5, (%esp)
	call	_puts
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ebx
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	addl	$7, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %esi
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	addl	$6, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, -28(%ebp)
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	addl	$5, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ecx
	movl	%ecx, -32(%ebp)
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edi
	movl	%edi, -36(%ebp)
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	addl	$3, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edi
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	addl	$2, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ecx
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	addl	$1, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%ebx, 36(%esp)
	movl	%esi, 32(%esp)
	movl	-28(%ebp), %ebx
	movl	%ebx, 28(%esp)
	movl	-32(%ebp), %esi
	movl	%esi, 24(%esp)
	movl	-36(%ebp), %ebx
	movl	%ebx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$LC6, (%esp)
	call	_puts
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ebx
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	(%eax), %eax
	addl	$7, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %esi
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	(%eax), %eax
	addl	$6, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, -28(%ebp)
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	(%eax), %eax
	addl	$5, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	%edx, -32(%ebp)
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ecx
	movl	%ecx, -36(%ebp)
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	(%eax), %eax
	addl	$3, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edi
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	(%eax), %eax
	addl	$2, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ecx
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	(%eax), %eax
	addl	$1, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	8(%ebp), %eax
	addl	$12, %eax
	movl	(%eax), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%ebx, 36(%esp)
	movl	%esi, 32(%esp)
	movl	-28(%ebp), %esi
	movl	%esi, 28(%esp)
	movl	-32(%ebp), %ebx
	movl	%ebx, 24(%esp)
	movl	-36(%ebp), %esi
	movl	%esi, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$LC5, (%esp)
	call	_puts
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ebx
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	addl	$7, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %esi
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	addl	$6, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, -28(%ebp)
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	addl	$5, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edi
	movl	%edi, -32(%ebp)
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	%edx, -36(%ebp)
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	addl	$3, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edi
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	addl	$2, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ecx
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	addl	$1, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%ebx, 36(%esp)
	movl	%esi, 32(%esp)
	movl	-28(%ebp), %ebx
	movl	%ebx, 28(%esp)
	movl	-32(%ebp), %esi
	movl	%esi, 24(%esp)
	movl	-36(%ebp), %ebx
	movl	%ebx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$LC5, (%esp)
	call	_puts
	movl	8(%ebp), %eax
	addl	$20, %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ebx
	movl	8(%ebp), %eax
	addl	$20, %eax
	movl	(%eax), %eax
	addl	$7, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %esi
	movl	8(%ebp), %eax
	addl	$20, %eax
	movl	(%eax), %eax
	addl	$6, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, -28(%ebp)
	movl	8(%ebp), %eax
	addl	$20, %eax
	movl	(%eax), %eax
	addl	$5, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ecx
	movl	%ecx, -32(%ebp)
	movl	8(%ebp), %eax
	addl	$20, %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edi
	movl	%edi, -36(%ebp)
	movl	8(%ebp), %eax
	addl	$20, %eax
	movl	(%eax), %eax
	addl	$3, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edi
	movl	8(%ebp), %eax
	addl	$20, %eax
	movl	(%eax), %eax
	addl	$2, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ecx
	movl	8(%ebp), %eax
	addl	$20, %eax
	movl	(%eax), %eax
	addl	$1, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	8(%ebp), %eax
	addl	$20, %eax
	movl	(%eax), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%ebx, 36(%esp)
	movl	%esi, 32(%esp)
	movl	-28(%ebp), %esi
	movl	%esi, 28(%esp)
	movl	-32(%ebp), %ebx
	movl	%ebx, 24(%esp)
	movl	-36(%ebp), %esi
	movl	%esi, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$LC6, (%esp)
	call	_puts
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ebx
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	addl	$7, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %esi
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	addl	$6, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, -28(%ebp)
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	addl	$5, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	%edx, -32(%ebp)
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ecx
	movl	%ecx, -36(%ebp)
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	addl	$3, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edi
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	addl	$2, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ecx
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	addl	$1, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%ebx, 36(%esp)
	movl	%esi, 32(%esp)
	movl	-28(%ebp), %ebx
	movl	%ebx, 28(%esp)
	movl	-32(%ebp), %esi
	movl	%esi, 24(%esp)
	movl	-36(%ebp), %ebx
	movl	%ebx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$LC5, (%esp)
	call	_puts
	movl	8(%ebp), %eax
	addl	$28, %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ebx
	movl	8(%ebp), %eax
	addl	$28, %eax
	movl	(%eax), %eax
	addl	$7, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %esi
	movl	8(%ebp), %eax
	addl	$28, %eax
	movl	(%eax), %eax
	addl	$6, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, -28(%ebp)
	movl	8(%ebp), %eax
	addl	$28, %eax
	movl	(%eax), %eax
	addl	$5, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edi
	movl	%edi, -32(%ebp)
	movl	8(%ebp), %eax
	addl	$28, %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	%edx, -36(%ebp)
	movl	8(%ebp), %eax
	addl	$28, %eax
	movl	(%eax), %eax
	addl	$3, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edi
	movl	8(%ebp), %eax
	addl	$28, %eax
	movl	(%eax), %eax
	addl	$2, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ecx
	movl	8(%ebp), %eax
	addl	$28, %eax
	movl	(%eax), %eax
	addl	$1, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	8(%ebp), %eax
	addl	$28, %eax
	movl	(%eax), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%ebx, 36(%esp)
	movl	%esi, 32(%esp)
	movl	-28(%ebp), %esi
	movl	%esi, 28(%esp)
	movl	-32(%ebp), %ebx
	movl	%ebx, 24(%esp)
	movl	-36(%ebp), %esi
	movl	%esi, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$LC5, (%esp)
	call	_puts
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ebx
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	(%eax), %eax
	addl	$7, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %esi
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	(%eax), %eax
	addl	$6, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, -28(%ebp)
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	(%eax), %eax
	addl	$5, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ecx
	movl	%ecx, -32(%ebp)
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edi
	movl	%edi, -36(%ebp)
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	(%eax), %eax
	addl	$3, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edi
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	(%eax), %eax
	addl	$2, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ecx
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	(%eax), %eax
	addl	$1, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	(%eax), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%ebx, 36(%esp)
	movl	%esi, 32(%esp)
	movl	-28(%ebp), %ebx
	movl	%ebx, 28(%esp)
	movl	-32(%ebp), %esi
	movl	%esi, 24(%esp)
	movl	-36(%ebp), %ebx
	movl	%ebx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	nop
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.globl	_deallocateStuff
	.def	_deallocateStuff;	.scl	2;	.type	32;	.endef
_deallocateStuff:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$0, -12(%ebp)
	jmp	L22
L23:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	_free
	addl	$1, -12(%ebp)
L22:
	cmpl	$8, -12(%ebp)
	jle	L23
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	nop
	leave
	ret
	.globl	_allocateArray
	.def	_allocateArray;	.scl	2;	.type	32;	.endef
_allocateArray:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$36, %esp
	movl	$36, (%esp)
	call	_malloc
	movl	%eax, -24(%ebp)
	movl	$0, -12(%ebp)
	jmp	L25
L26:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-24(%ebp), %eax
	leal	(%edx,%eax), %ebx
	movl	$9, (%esp)
	call	_malloc
	movl	%eax, (%ebx)
	addl	$1, -12(%ebp)
L25:
	cmpl	$8, -12(%ebp)
	jle	L26
	movl	$0, -16(%ebp)
	jmp	L27
L30:
	movl	$0, -20(%ebp)
	jmp	L28
L29:
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-24(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	movb	$32, (%eax)
	addl	$1, -20(%ebp)
L28:
	cmpl	$8, -20(%ebp)
	jle	L29
	addl	$1, -16(%ebp)
L27:
	cmpl	$8, -16(%ebp)
	jle	L30
	movl	-24(%ebp), %eax
	addl	$36, %esp
	popl	%ebx
	popl	%ebp
	ret
	.globl	_sleep_seconds
	.def	_sleep_seconds;	.scl	2;	.type	32;	.endef
_sleep_seconds:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_Sleep@4
	subl	$4, %esp
	nop
	leave
	ret
	.globl	_processInput
	.def	_processInput;	.scl	2;	.type	32;	.endef
_processInput:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	12(%ebp), %eax
	cmpl	$100, %eax
	je	L35
	cmpl	$100, %eax
	jg	L36
	cmpl	$97, %eax
	je	L37
	jmp	L56
L36:
	cmpl	$115, %eax
	je	L38
	cmpl	$119, %eax
	je	L39
	jmp	L56
L37:
	movl	$0, -12(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	24(%ebp), %eax
	movl	%edx, (%eax)
	movl	20(%ebp), %eax
	movl	(%eax), %edx
	movl	28(%ebp), %eax
	movl	%edx, (%eax)
L43:
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L40
	movl	16(%ebp), %eax
	movl	$8, (%eax)
	jmp	L41
L40:
	movl	16(%ebp), %eax
	movl	16(%ebp), %edx
	movl	(%edx), %edx
	subl	$1, %edx
	movl	%edx, (%eax)
L41:
	addl	$1, -12(%ebp)
	cmpl	$10, -12(%ebp)
	jle	L42
	movl	20(%ebp), %edx
	movl	16(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_findOpenSpaceAorD
L42:
	movl	20(%ebp), %eax
	movl	(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$32, %al
	jne	L43
	jmp	L34
L39:
	movl	$0, -12(%ebp)
	movl	20(%ebp), %eax
	movl	(%eax), %edx
	movl	28(%ebp), %eax
	movl	%edx, (%eax)
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	24(%ebp), %eax
	movl	%edx, (%eax)
L47:
	movl	20(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L44
	movl	20(%ebp), %eax
	movl	$8, (%eax)
	jmp	L45
L44:
	movl	20(%ebp), %eax
	movl	20(%ebp), %edx
	movl	(%edx), %edx
	subl	$1, %edx
	movl	%edx, (%eax)
L45:
	addl	$1, -12(%ebp)
	cmpl	$10, -12(%ebp)
	jle	L46
	movl	20(%ebp), %edx
	movl	16(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_findOpenSpaceWorS
L46:
	movl	20(%ebp), %eax
	movl	(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$32, %al
	jne	L47
	jmp	L34
L35:
	movl	$0, -12(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	24(%ebp), %eax
	movl	%edx, (%eax)
	movl	20(%ebp), %eax
	movl	(%eax), %edx
	movl	28(%ebp), %eax
	movl	%edx, (%eax)
L51:
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$8, %eax
	jne	L48
	movl	16(%ebp), %eax
	movl	$0, (%eax)
	jmp	L49
L48:
	movl	16(%ebp), %eax
	movl	16(%ebp), %edx
	movl	(%edx), %edx
	addl	$1, %edx
	movl	%edx, (%eax)
L49:
	addl	$1, -12(%ebp)
	cmpl	$10, -12(%ebp)
	jle	L50
	movl	20(%ebp), %edx
	movl	16(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_findOpenSpaceAorD
L50:
	movl	20(%ebp), %eax
	movl	(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$32, %al
	jne	L51
	jmp	L34
L38:
	movl	$0, -12(%ebp)
	movl	20(%ebp), %eax
	movl	(%eax), %edx
	movl	28(%ebp), %eax
	movl	%edx, (%eax)
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	24(%ebp), %eax
	movl	%edx, (%eax)
L55:
	movl	20(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$8, %eax
	jne	L52
	movl	20(%ebp), %eax
	movl	$0, (%eax)
	jmp	L53
L52:
	movl	20(%ebp), %eax
	movl	20(%ebp), %edx
	movl	(%edx), %edx
	addl	$1, %edx
	movl	%edx, (%eax)
L53:
	addl	$1, -12(%ebp)
	cmpl	$10, -12(%ebp)
	jle	L54
	movl	20(%ebp), %edx
	movl	16(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_findOpenSpaceWorS
L54:
	movl	20(%ebp), %eax
	movl	(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$32, %al
	jne	L55
	nop
L34:
L56:
	nop
	leave
	ret
	.globl	_findOpenSpaceWorS
	.def	_findOpenSpaceWorS;	.scl	2;	.type	32;	.endef
_findOpenSpaceWorS:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$32, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$1, %eax
	movl	%eax, -4(%ebp)
	jmp	L58
L63:
	movl	$0, -8(%ebp)
	jmp	L59
L62:
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$32, %al
	jne	L60
	movl	16(%ebp), %eax
	movl	-8(%ebp), %edx
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%edx, (%eax)
	jmp	L57
L60:
	addl	$1, -8(%ebp)
L59:
	cmpl	$8, -8(%ebp)
	jle	L62
	addl	$1, -4(%ebp)
L58:
	cmpl	$8, -4(%ebp)
	jle	L63
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	L64
L70:
	movl	$0, -20(%ebp)
	jmp	L65
L69:
	addl	$1, -12(%ebp)
	movl	-20(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$32, %al
	jne	L66
	movl	16(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%eax)
	jmp	L57
L66:
	cmpl	$81, -12(%ebp)
	jg	L71
	addl	$1, -20(%ebp)
L65:
	cmpl	$8, -20(%ebp)
	jle	L69
	jmp	L68
L71:
	nop
L68:
	addl	$1, -16(%ebp)
L64:
	cmpl	$8, -16(%ebp)
	jle	L70
L57:
	leave
	ret
	.globl	_findOpenSpaceAorD
	.def	_findOpenSpaceAorD;	.scl	2;	.type	32;	.endef
_findOpenSpaceAorD:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$32, %esp
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	addl	$1, %eax
	movl	%eax, -4(%ebp)
	jmp	L73
L78:
	movl	$0, -8(%ebp)
	jmp	L74
L77:
	movl	-4(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$32, %al
	jne	L75
	movl	16(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	-8(%ebp), %edx
	movl	%edx, (%eax)
	jmp	L72
L75:
	addl	$1, -8(%ebp)
L74:
	cmpl	$8, -8(%ebp)
	jle	L77
	addl	$1, -4(%ebp)
L73:
	cmpl	$8, -4(%ebp)
	jle	L78
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	L79
L85:
	movl	$0, -20(%ebp)
	jmp	L80
L84:
	addl	$1, -12(%ebp)
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$32, %al
	jne	L81
	movl	16(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%eax)
	jmp	L72
L81:
	cmpl	$81, -12(%ebp)
	jg	L86
	addl	$1, -20(%ebp)
L80:
	cmpl	$8, -20(%ebp)
	jle	L84
	jmp	L83
L86:
	nop
L83:
	addl	$1, -16(%ebp)
L79:
	cmpl	$8, -16(%ebp)
	jle	L85
L72:
	leave
	ret
	.globl	_moveSelectionAfterPlacement
	.def	_moveSelectionAfterPlacement;	.scl	2;	.type	32;	.endef
_moveSelectionAfterPlacement:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$1, %eax
	movl	%eax, -4(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -8(%ebp)
	movl	$0, -12(%ebp)
L93:
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$32, %al
	jne	L88
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	movb	$88, (%eax)
	movl	16(%ebp), %eax
	movl	-8(%ebp), %edx
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%edx, (%eax)
	jmp	L87
L88:
	addl	$1, -4(%ebp)
	addl	$1, -12(%ebp)
	cmpl	$8, -4(%ebp)
	jle	L90
	movl	$0, -4(%ebp)
	addl	$1, -8(%ebp)
L90:
	cmpl	$8, -8(%ebp)
	jle	L91
	movl	$0, -8(%ebp)
	movl	$0, -4(%ebp)
L91:
	cmpl	$81, -12(%ebp)
	jg	L94
	jmp	L93
L94:
	nop
L87:
	leave
	ret
	.globl	_setSpaceToX
	.def	_setSpaceToX;	.scl	2;	.type	32;	.endef
_setSpaceToX:
	pushl	%ebp
	movl	%esp, %ebp
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movb	$88, (%eax)
	movl	24(%ebp), %eax
	movl	(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	20(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movb	$32, (%eax)
	nop
	popl	%ebp
	ret
	.globl	_numberEntered
	.def	_numberEntered;	.scl	2;	.type	32;	.endef
_numberEntered:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	20(%ebp), %eax
	movb	%al, -12(%ebp)
	movsbl	-12(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	12(%ebp), %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_isValidInSquare
	testb	%al, %al
	je	L98
	movsbl	-12(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	12(%ebp), %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_isValidUpAndAcross
	testb	%al, %al
	je	L98
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%eax, %edx
	movzbl	-12(%ebp), %eax
	movb	%al, (%edx)
	movl	24(%ebp), %eax
	movl	(%eax), %eax
	leal	-1(%eax), %edx
	movl	24(%ebp), %eax
	movl	%edx, (%eax)
	movl	16(%ebp), %edx
	movl	12(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_moveSelectionAfterPlacement
L98:
	nop
	leave
	ret
	.section .rdata,"dr"
LC7:
	.ascii "r\0"
LC8:
	.ascii "numbers.txt\0"
	.text
	.globl	_readFromFile
	.def	_readFromFile;	.scl	2;	.type	32;	.endef
_readFromFile:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$136, %esp
	movl	$LC7, 4(%esp)
	movl	$LC8, (%esp)
	call	_fopen
	movl	%eax, -28(%ebp)
	movl	$0, -16(%ebp)
	cmpl	$0, -28(%ebp)
	je	L100
	jmp	L101
L103:
	movsbl	-9(%ebp), %eax
	subl	$48, %eax
	cmpl	$9, %eax
	ja	L101
	cmpb	$48, -9(%ebp)
	jne	L102
	movb	$32, -9(%ebp)
L102:
	leal	-109(%ebp), %edx
	movl	-16(%ebp), %eax
	addl	%eax, %edx
	movzbl	-9(%ebp), %eax
	movb	%al, (%edx)
	addl	$1, -16(%ebp)
L101:
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	_getc
	movb	%al, -9(%ebp)
	cmpb	$-1, -9(%ebp)
	jne	L103
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
L100:
	movl	$0, -16(%ebp)
	movl	$0, -20(%ebp)
	jmp	L104
L107:
	movl	$0, -24(%ebp)
	jmp	L105
L106:
	movl	-20(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-24(%ebp), %eax
	addl	%eax, %edx
	leal	-109(%ebp), %ecx
	movl	-16(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
	addl	$1, -16(%ebp)
	addl	$1, -24(%ebp)
L105:
	cmpl	$8, -24(%ebp)
	jle	L106
	addl	$1, -20(%ebp)
L104:
	cmpl	$8, -20(%ebp)
	jle	L107
	movl	8(%ebp), %eax
	leave
	ret
	.globl	_backSpacePressed
	.def	_backSpacePressed;	.scl	2;	.type	32;	.endef
_backSpacePressed:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$52, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -20(%ebp)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -8(%ebp)
	movl	$0, -12(%ebp)
L115:
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$32, %al
	jne	L110
	movl	12(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%edx, (%eax)
	movl	16(%ebp), %eax
	movl	-8(%ebp), %edx
	movl	%edx, (%eax)
	movl	16(%ebp), %edx
	movl	12(%ebp), %eax
	leal	-20(%ebp), %ecx
	movl	%ecx, 16(%esp)
	leal	-16(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_setSpaceToX
	jmp	L109
L110:
	addl	$1, -12(%ebp)
	addl	$1, -4(%ebp)
	cmpl	$8, -4(%ebp)
	jle	L112
	movl	$0, -4(%ebp)
	addl	$1, -8(%ebp)
L112:
	cmpl	$8, -8(%ebp)
	jle	L113
	movl	$0, -8(%ebp)
	movl	$0, -4(%ebp)
L113:
	cmpl	$81, -12(%ebp)
	jle	L115
	movl	12(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%eax)
	movl	16(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%eax)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movb	$88, (%eax)
L109:
	leave
	ret
	.globl	_backSlashPressed
	.def	_backSlashPressed;	.scl	2;	.type	32;	.endef
_backSlashPressed:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$52, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -20(%ebp)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -8(%ebp)
	movl	$0, -12(%ebp)
L123:
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$32, %al
	jne	L118
	movl	12(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%edx, (%eax)
	movl	16(%ebp), %eax
	movl	-8(%ebp), %edx
	movl	%edx, (%eax)
	movl	16(%ebp), %edx
	movl	12(%ebp), %eax
	leal	-20(%ebp), %ecx
	movl	%ecx, 16(%esp)
	leal	-16(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_setSpaceToX
	jmp	L117
L118:
	addl	$1, -12(%ebp)
	subl	$1, -4(%ebp)
	cmpl	$0, -4(%ebp)
	jns	L120
	movl	$8, -4(%ebp)
	subl	$1, -8(%ebp)
L120:
	cmpl	$0, -8(%ebp)
	jns	L121
	movl	$8, -8(%ebp)
	movl	$8, -4(%ebp)
L121:
	cmpl	$81, -12(%ebp)
	jle	L123
	movl	12(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%eax)
	movl	16(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%eax)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movb	$88, (%eax)
L117:
	leave
	ret
	.globl	_findNumEmptySpaces
	.def	_findNumEmptySpaces;	.scl	2;	.type	32;	.endef
_findNumEmptySpaces:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$0, -4(%ebp)
	movl	$0, -8(%ebp)
	jmp	L126
L130:
	movl	$0, -12(%ebp)
	jmp	L127
L129:
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$32, %al
	jne	L128
	addl	$1, -4(%ebp)
L128:
	addl	$1, -12(%ebp)
L127:
	cmpl	$8, -12(%ebp)
	jle	L129
	addl	$1, -8(%ebp)
L126:
	cmpl	$8, -8(%ebp)
	jle	L130
	movl	-4(%ebp), %eax
	leave
	ret
	.section .rdata,"dr"
	.align 4
LC9:
	.ascii "Error: there is already a %c in column %d!\12\0"
	.align 4
LC10:
	.ascii "Error: there is already a %c in row %d!\12\0"
LC11:
	.ascii "Press enter to continue\0"
LC12:
	.ascii "%c\0"
	.text
	.globl	_isValidUpAndAcross
	.def	_isValidUpAndAcross;	.scl	2;	.type	32;	.endef
_isValidUpAndAcross:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	movl	20(%ebp), %eax
	movb	%al, -28(%ebp)
	movb	$0, -9(%ebp)
	movb	$0, -10(%ebp)
	movl	$0, -16(%ebp)
	jmp	L133
L135:
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	-28(%ebp), %al
	jne	L134
	movb	$1, -9(%ebp)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movsbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC9, (%esp)
	call	_printf
L134:
	addl	$1, -16(%ebp)
L133:
	cmpl	$8, -16(%ebp)
	jle	L135
	movl	$0, -20(%ebp)
	jmp	L136
L138:
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	-28(%ebp), %al
	jne	L137
	movb	$1, -10(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movsbl	-28(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC10, (%esp)
	call	_printf
L137:
	addl	$1, -20(%ebp)
L136:
	cmpl	$8, -20(%ebp)
	jle	L138
	cmpb	$0, -9(%ebp)
	jne	L139
	cmpb	$0, -10(%ebp)
	je	L140
L139:
	movl	$LC11, (%esp)
	call	_puts
	leal	-21(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC12, (%esp)
	call	_scanf
	movl	$0, %eax
	jmp	L141
L140:
	movl	$1, %eax
L141:
	leave
	ret
	.section .rdata,"dr"
	.align 4
LC13:
	.ascii "Error: there is already a %c in square 1\12\0"
	.align 4
LC14:
	.ascii "Error: there is already a %c in square 2\12\0"
	.align 4
LC15:
	.ascii "Error: there is already a %c in square 3\12\0"
	.align 4
LC16:
	.ascii "Error: there is already a %c in square 4\12\0"
	.align 4
LC17:
	.ascii "Error: there is already a %c in square 5\12\0"
	.align 4
LC18:
	.ascii "Error: there is already a %c in square 6\12\0"
	.align 4
LC19:
	.ascii "Error: there is already a %c in square 7\12\0"
	.align 4
LC20:
	.ascii "Error: there is already a %c in square 8\12\0"
	.align 4
LC21:
	.ascii "Error: there is already a %c in square 9\12\0"
	.text
	.globl	_isValidInSquare
	.def	_isValidInSquare;	.scl	2;	.type	32;	.endef
_isValidInSquare:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$136, %esp
	movl	20(%ebp), %eax
	movb	%al, -108(%ebp)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$2, %eax
	jg	L143
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$2, %eax
	jg	L143
	movl	$1, -12(%ebp)
L143:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$2, %eax
	jle	L144
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$5, %eax
	jg	L144
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$2, %eax
	jg	L144
	movl	$2, -12(%ebp)
L144:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$5, %eax
	jle	L145
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$2, %eax
	jg	L145
	movl	$3, -12(%ebp)
L145:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$2, %eax
	jg	L146
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$2, %eax
	jle	L146
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$5, %eax
	jg	L146
	movl	$4, -12(%ebp)
L146:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$2, %eax
	jle	L147
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$5, %eax
	jg	L147
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$2, %eax
	jle	L147
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$5, %eax
	jg	L147
	movl	$5, -12(%ebp)
L147:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$5, %eax
	jle	L148
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$2, %eax
	jle	L148
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$5, %eax
	jg	L148
	movl	$6, -12(%ebp)
L148:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$2, %eax
	jg	L149
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$5, %eax
	jle	L149
	movl	$7, -12(%ebp)
L149:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$2, %eax
	jle	L150
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$5, %eax
	jg	L150
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$5, %eax
	jle	L150
	movl	$8, -12(%ebp)
L150:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$5, %eax
	jle	L151
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$5, %eax
	jle	L151
	movl	$9, -12(%ebp)
L151:
	cmpl	$9, -12(%ebp)
	ja	L152
	movl	-12(%ebp), %eax
	sall	$2, %eax
	addl	$L154, %eax
	movl	(%eax), %eax
	jmp	*%eax
	.section .rdata,"dr"
	.align 4
L154:
	.long	L152
	.long	L153
	.long	L155
	.long	L156
	.long	L157
	.long	L158
	.long	L159
	.long	L160
	.long	L161
	.long	L162
	.text
L153:
	movl	$0, -16(%ebp)
	jmp	L163
L168:
	movl	$0, -20(%ebp)
	jmp	L164
L167:
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	-108(%ebp), %al
	jne	L165
	movsbl	-108(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC13, (%esp)
	call	_printf
	movl	$LC11, (%esp)
	call	_puts
	leal	-85(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC12, (%esp)
	call	_scanf
	movl	$0, %eax
	jmp	L166
L165:
	addl	$1, -20(%ebp)
L164:
	cmpl	$2, -20(%ebp)
	jle	L167
	addl	$1, -16(%ebp)
L163:
	cmpl	$2, -16(%ebp)
	jle	L168
	jmp	L152
L155:
	movl	$0, -24(%ebp)
	jmp	L169
L173:
	movl	$3, -28(%ebp)
	jmp	L170
L172:
	movl	-24(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-28(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	-108(%ebp), %al
	jne	L171
	movsbl	-108(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC14, (%esp)
	call	_printf
	movl	$LC11, (%esp)
	call	_puts
	leal	-86(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC12, (%esp)
	call	_scanf
	movl	$0, %eax
	jmp	L166
L171:
	addl	$1, -28(%ebp)
L170:
	cmpl	$5, -28(%ebp)
	jle	L172
	addl	$1, -24(%ebp)
L169:
	cmpl	$2, -24(%ebp)
	jle	L173
	jmp	L152
L156:
	movl	$0, -32(%ebp)
	jmp	L174
L178:
	movl	$6, -36(%ebp)
	jmp	L175
L177:
	movl	-32(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-36(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	-108(%ebp), %al
	jne	L176
	movsbl	-108(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC15, (%esp)
	call	_printf
	movl	$LC11, (%esp)
	call	_puts
	leal	-87(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC12, (%esp)
	call	_scanf
	movl	$0, %eax
	jmp	L166
L176:
	addl	$1, -36(%ebp)
L175:
	cmpl	$8, -36(%ebp)
	jle	L177
	addl	$1, -32(%ebp)
L174:
	cmpl	$2, -32(%ebp)
	jle	L178
	jmp	L152
L157:
	movl	$3, -40(%ebp)
	jmp	L179
L183:
	movl	$0, -44(%ebp)
	jmp	L180
L182:
	movl	-40(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-44(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	-108(%ebp), %al
	jne	L181
	movsbl	-108(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC16, (%esp)
	call	_printf
	movl	$LC11, (%esp)
	call	_puts
	leal	-88(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC12, (%esp)
	call	_scanf
	movl	$0, %eax
	jmp	L166
L181:
	addl	$1, -44(%ebp)
L180:
	cmpl	$2, -44(%ebp)
	jle	L182
	addl	$1, -40(%ebp)
L179:
	cmpl	$5, -40(%ebp)
	jle	L183
	jmp	L152
L158:
	movl	$3, -48(%ebp)
	jmp	L184
L188:
	movl	$3, -52(%ebp)
	jmp	L185
L187:
	movl	-48(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-52(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	-108(%ebp), %al
	jne	L186
	movsbl	-108(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC17, (%esp)
	call	_printf
	movl	$LC11, (%esp)
	call	_puts
	leal	-89(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC12, (%esp)
	call	_scanf
	movl	$0, %eax
	jmp	L166
L186:
	addl	$1, -52(%ebp)
L185:
	cmpl	$5, -52(%ebp)
	jle	L187
	addl	$1, -48(%ebp)
L184:
	cmpl	$5, -48(%ebp)
	jle	L188
	jmp	L152
L159:
	movl	$3, -56(%ebp)
	jmp	L189
L193:
	movl	$6, -60(%ebp)
	jmp	L190
L192:
	movl	-56(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-60(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	-108(%ebp), %al
	jne	L191
	movsbl	-108(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC18, (%esp)
	call	_printf
	movl	$LC11, (%esp)
	call	_puts
	leal	-90(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC12, (%esp)
	call	_scanf
	movl	$0, %eax
	jmp	L166
L191:
	addl	$1, -60(%ebp)
L190:
	cmpl	$8, -60(%ebp)
	jle	L192
	addl	$1, -56(%ebp)
L189:
	cmpl	$5, -56(%ebp)
	jle	L193
	jmp	L152
L160:
	movl	$6, -64(%ebp)
	jmp	L194
L198:
	movl	$0, -68(%ebp)
	jmp	L195
L197:
	movl	-64(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-68(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	-108(%ebp), %al
	jne	L196
	movsbl	-108(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC19, (%esp)
	call	_printf
	movl	$LC11, (%esp)
	call	_puts
	leal	-91(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC12, (%esp)
	call	_scanf
	movl	$0, %eax
	jmp	L166
L196:
	addl	$1, -68(%ebp)
L195:
	cmpl	$2, -68(%ebp)
	jle	L197
	addl	$1, -64(%ebp)
L194:
	cmpl	$8, -64(%ebp)
	jle	L198
	jmp	L152
L161:
	movl	$6, -72(%ebp)
	jmp	L199
L203:
	movl	$3, -76(%ebp)
	jmp	L200
L202:
	movl	-72(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-76(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	-108(%ebp), %al
	jne	L201
	movsbl	-108(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC20, (%esp)
	call	_printf
	movl	$LC11, (%esp)
	call	_puts
	leal	-92(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC12, (%esp)
	call	_scanf
	movl	$0, %eax
	jmp	L166
L201:
	addl	$1, -76(%ebp)
L200:
	cmpl	$5, -76(%ebp)
	jle	L202
	addl	$1, -72(%ebp)
L199:
	cmpl	$8, -72(%ebp)
	jle	L203
	jmp	L152
L162:
	movl	$6, -80(%ebp)
	jmp	L204
L208:
	movl	$6, -84(%ebp)
	jmp	L205
L207:
	movl	-80(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-84(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	-108(%ebp), %al
	jne	L206
	movsbl	-108(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC21, (%esp)
	call	_printf
	movl	$LC11, (%esp)
	call	_puts
	leal	-93(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC12, (%esp)
	call	_scanf
	movl	$0, %eax
	jmp	L166
L206:
	addl	$1, -84(%ebp)
L205:
	cmpl	$8, -84(%ebp)
	jle	L207
	addl	$1, -80(%ebp)
L204:
	cmpl	$8, -80(%ebp)
	jle	L208
	nop
L152:
	movl	$1, %eax
L166:
	leave
	ret
	.globl	_setInitialPosition
	.def	_setInitialPosition;	.scl	2;	.type	32;	.endef
_setInitialPosition:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
L212:
	call	_rand
	movl	%eax, %ecx
	movl	$954437177, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, -12(%ebp)
	call	_rand
	movl	%eax, %ecx
	movl	$954437177, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$32, %al
	jne	L212
	movl	12(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%eax)
	movl	16(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movb	$88, (%eax)
	nop
	leave
	ret
	.section .rdata,"dr"
	.align 4
LC22:
	.ascii "Welcome to the adventure Sudoku!\0"
	.align 4
LC23:
	.ascii "X marks what your current selection is.\0"
	.align 4
LC24:
	.ascii "Press 'W' to move the selection up, 'S' to move down, 'A' to move to the left, and 'D' to move to the right.\0"
	.align 4
LC25:
	.ascii "When attempting to solve the puzzle, simply press the number you'd like to put in the space.\12\0"
	.align 4
LC26:
	.ascii "Pressing BACKSPACE will allow you to cycle through all blank spaces.\12Pressing ESC will leave the game.\0"
	.align 4
LC27:
	.ascii "Pressing DELETE will activate Erase Mode, which will allow you to erase previous guesses.\0"
	.align 4
LC28:
	.ascii "Press DELETE, and navigate to the desired key, and press ENTER to erase it.\0"
	.align 4
LC29:
	.ascii "Pressing L will locate your current selection for you\0"
	.align 4
LC30:
	.ascii "You can always press 'H' to bring up the commands.\0"
LC31:
	.ascii "Press enter to continue...\0"
	.text
	.globl	_welcomeScreen
	.def	_welcomeScreen;	.scl	2;	.type	32;	.endef
_welcomeScreen:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$LC2, (%esp)
	call	_system
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_display
	movl	$LC22, (%esp)
	call	_puts
	movl	$LC23, (%esp)
	call	_puts
	movl	$LC24, (%esp)
	call	_puts
	movl	$LC25, (%esp)
	call	_puts
	movl	$LC26, (%esp)
	call	_puts
	movl	$LC27, (%esp)
	call	_puts
	movl	$LC28, (%esp)
	call	_puts
	movl	$LC29, (%esp)
	call	_puts
	movl	$LC0, (%esp)
	call	_puts
	movl	$LC30, (%esp)
	call	_puts
	movl	$LC0, (%esp)
	call	_puts
	movl	$LC31, (%esp)
	call	_puts
	leal	-9(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC12, (%esp)
	call	_scanf
	nop
	leave
	ret
	.globl	_helpKeyPressed
	.def	_helpKeyPressed;	.scl	2;	.type	32;	.endef
_helpKeyPressed:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$LC2, (%esp)
	call	_system
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_display
	movl	$LC23, (%esp)
	call	_puts
	movl	$LC24, (%esp)
	call	_puts
	movl	$LC25, (%esp)
	call	_puts
	movl	$LC26, (%esp)
	call	_puts
	movl	$LC27, (%esp)
	call	_puts
	movl	$LC28, (%esp)
	call	_puts
	movl	$LC29, (%esp)
	call	_puts
	movl	$LC0, (%esp)
	call	_puts
	movl	$LC30, (%esp)
	call	_puts
	movl	$LC0, (%esp)
	call	_puts
	movl	$LC11, (%esp)
	call	_puts
	leal	-9(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC12, (%esp)
	call	_scanf
	nop
	leave
	ret
	.globl	_populateControlArray
	.def	_populateControlArray;	.scl	2;	.type	32;	.endef
_populateControlArray:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$0, -4(%ebp)
	jmp	L217
L222:
	movl	$0, -8(%ebp)
	jmp	L218
L221:
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$32, %al
	je	L219
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	movb	$48, (%eax)
	jmp	L220
L219:
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	movb	$49, (%eax)
L220:
	addl	$1, -8(%ebp)
L218:
	cmpl	$8, -8(%ebp)
	jle	L221
	addl	$1, -4(%ebp)
L217:
	cmpl	$8, -4(%ebp)
	jle	L222
	movl	8(%ebp), %eax
	leave
	ret
	.section .rdata,"dr"
LC32:
	.ascii "Erase mode is activated\0"
	.align 4
LC33:
	.ascii "Press ENTER to erase the selected number\0"
LC34:
	.ascii "Erase mode deactivated\0"
	.text
	.globl	_deleteMode
	.def	_deleteMode;	.scl	2;	.type	32;	.endef
_deleteMode:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$72, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movb	$88, (%eax)
	movl	$0, -32(%ebp)
L237:
	movl	$LC2, (%esp)
	call	_system
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_display
	movl	$LC32, (%esp)
	call	_puts
	movl	$LC33, (%esp)
	call	_puts
	call	_getch
	movl	%eax, -36(%ebp)
	cmpl	$83, -36(%ebp)
	jne	L225
	movl	$LC2, (%esp)
	call	_system
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_display
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -24(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -28(%ebp)
L230:
	movl	-28(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-24(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$32, %al
	jne	L226
	movl	12(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	16(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%eax)
	nop
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movb	$88, (%eax)
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%eax, %edx
	movzbl	-17(%ebp), %eax
	movb	%al, (%edx)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_cleanUpDisplayArray
	movl	$LC34, (%esp)
	call	_puts
	movl	$500, (%esp)
	call	_sleep_seconds
	jmp	L238
L226:
	addl	$1, -24(%ebp)
	cmpl	$8, -24(%ebp)
	jle	L228
	movl	$0, -24(%ebp)
	addl	$1, -28(%ebp)
L228:
	cmpl	$8, -28(%ebp)
	jle	L230
	movl	$0, -24(%ebp)
	movl	$0, -28(%ebp)
	jmp	L230
L225:
	cmpl	$97, -36(%ebp)
	je	L232
	cmpl	$119, -36(%ebp)
	je	L232
	cmpl	$100, -36(%ebp)
	je	L232
	cmpl	$115, -36(%ebp)
	jne	L233
L232:
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	addl	%eax, %edx
	movzbl	-17(%ebp), %eax
	movb	%al, (%edx)
	movl	16(%ebp), %edx
	movl	12(%ebp), %eax
	movl	20(%ebp), %ecx
	movl	%ecx, 16(%esp)
	movl	-36(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_deleteMove
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -17(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movb	$88, (%eax)
	jmp	L234
L233:
	cmpl	$13, -36(%ebp)
	jne	L235
	movb	$32, -17(%ebp)
	jmp	L237
L235:
	cmpl	$8, -36(%ebp)
	jne	L236
	movsbl	-17(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	12(%ebp), %eax
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	_deleteBackSpacePressed
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	jmp	L237
L236:
	cmpl	$92, -36(%ebp)
	jne	L237
	movsbl	-17(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	12(%ebp), %eax
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	_deleteBackSlashPressed
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
L234:
	jmp	L237
L238:
	nop
	leave
	ret
	.globl	_deleteMove
	.def	_deleteMove;	.scl	2;	.type	32;	.endef
_deleteMove:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	20(%ebp), %eax
	cmpl	$100, %eax
	je	L241
	cmpl	$100, %eax
	jg	L242
	cmpl	$97, %eax
	je	L243
	jmp	L262
L242:
	cmpl	$115, %eax
	je	L244
	cmpl	$119, %eax
	je	L245
	jmp	L262
L243:
	movl	$0, -12(%ebp)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -20(%ebp)
L249:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L246
	movl	12(%ebp), %eax
	movl	$8, (%eax)
	jmp	L247
L246:
	movl	12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	(%edx), %edx
	subl	$1, %edx
	movl	%edx, (%eax)
L247:
	addl	$1, -12(%ebp)
	cmpl	$10, -12(%ebp)
	jle	L248
	movl	16(%ebp), %edx
	movl	12(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	24(%ebp), %eax
	movl	%eax, (%esp)
	call	_deleteModeFindOpenSpaceAorD
L248:
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	24(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$49, %al
	jne	L249
	jmp	L240
L245:
	movl	$0, -12(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -20(%ebp)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
L253:
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L250
	movl	16(%ebp), %eax
	movl	$8, (%eax)
	jmp	L251
L250:
	movl	16(%ebp), %eax
	movl	16(%ebp), %edx
	movl	(%edx), %edx
	subl	$1, %edx
	movl	%edx, (%eax)
L251:
	addl	$1, -12(%ebp)
	cmpl	$10, -12(%ebp)
	jle	L252
	movl	16(%ebp), %edx
	movl	12(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	24(%ebp), %eax
	movl	%eax, (%esp)
	call	_deleteModeFindOpenSpaceWorS
L252:
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	24(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$49, %al
	jne	L253
	jmp	L240
L241:
	movl	$0, -12(%ebp)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -20(%ebp)
L257:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$8, %eax
	jne	L254
	movl	12(%ebp), %eax
	movl	$0, (%eax)
	jmp	L255
L254:
	movl	12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	(%edx), %edx
	addl	$1, %edx
	movl	%edx, (%eax)
L255:
	addl	$1, -12(%ebp)
	cmpl	$10, -12(%ebp)
	jle	L256
	movl	16(%ebp), %edx
	movl	12(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	24(%ebp), %eax
	movl	%eax, (%esp)
	call	_deleteModeFindOpenSpaceAorD
L256:
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	24(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$49, %al
	jne	L257
	jmp	L240
L244:
	movl	$0, -12(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -20(%ebp)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
L261:
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$8, %eax
	jne	L258
	movl	16(%ebp), %eax
	movl	$0, (%eax)
	jmp	L259
L258:
	movl	16(%ebp), %eax
	movl	16(%ebp), %edx
	movl	(%edx), %edx
	addl	$1, %edx
	movl	%edx, (%eax)
L259:
	addl	$1, -12(%ebp)
	cmpl	$10, -12(%ebp)
	jle	L260
	movl	16(%ebp), %edx
	movl	12(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	24(%ebp), %eax
	movl	%eax, (%esp)
	call	_deleteModeFindOpenSpaceWorS
L260:
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	24(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$49, %al
	jne	L261
	nop
L240:
L262:
	nop
	leave
	ret
	.globl	_deleteModeFindOpenSpaceAorD
	.def	_deleteModeFindOpenSpaceAorD;	.scl	2;	.type	32;	.endef
_deleteModeFindOpenSpaceAorD:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$32, %esp
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	addl	$1, %eax
	movl	%eax, -4(%ebp)
	jmp	L264
L269:
	movl	$0, -8(%ebp)
	jmp	L265
L268:
	movl	-4(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$49, %al
	jne	L266
	movl	16(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	-8(%ebp), %edx
	movl	%edx, (%eax)
	jmp	L263
L266:
	addl	$1, -8(%ebp)
L265:
	cmpl	$8, -8(%ebp)
	jle	L268
	addl	$1, -4(%ebp)
L264:
	cmpl	$8, -4(%ebp)
	jle	L269
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	L270
L276:
	movl	$0, -20(%ebp)
	jmp	L271
L275:
	addl	$1, -12(%ebp)
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$49, %al
	jne	L272
	movl	16(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%eax)
	jmp	L263
L272:
	cmpl	$81, -12(%ebp)
	jg	L277
	addl	$1, -20(%ebp)
L271:
	cmpl	$8, -20(%ebp)
	jle	L275
	jmp	L274
L277:
	nop
L274:
	addl	$1, -16(%ebp)
L270:
	cmpl	$8, -16(%ebp)
	jle	L276
L263:
	leave
	ret
	.globl	_deleteModeFindOpenSpaceWorS
	.def	_deleteModeFindOpenSpaceWorS;	.scl	2;	.type	32;	.endef
_deleteModeFindOpenSpaceWorS:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$32, %esp
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	$1, %eax
	movl	%eax, -4(%ebp)
	jmp	L279
L284:
	movl	$0, -8(%ebp)
	jmp	L280
L283:
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$49, %al
	jne	L281
	movl	16(%ebp), %eax
	movl	-8(%ebp), %edx
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%edx, (%eax)
	jmp	L278
L281:
	addl	$1, -8(%ebp)
L280:
	cmpl	$8, -8(%ebp)
	jle	L283
	addl	$1, -4(%ebp)
L279:
	cmpl	$8, -4(%ebp)
	jle	L284
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	L285
L291:
	movl	$0, -20(%ebp)
	jmp	L286
L290:
	addl	$1, -12(%ebp)
	movl	-20(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$49, %al
	jne	L287
	movl	16(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%eax)
	jmp	L278
L287:
	cmpl	$81, -12(%ebp)
	jg	L292
	addl	$1, -20(%ebp)
L286:
	cmpl	$8, -20(%ebp)
	jle	L290
	jmp	L289
L292:
	nop
L289:
	addl	$1, -16(%ebp)
L285:
	cmpl	$8, -16(%ebp)
	jle	L291
L278:
	leave
	ret
	.globl	_cleanUpDisplayArray
	.def	_cleanUpDisplayArray;	.scl	2;	.type	32;	.endef
_cleanUpDisplayArray:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$0, -4(%ebp)
	jmp	L294
L298:
	movl	$0, -8(%ebp)
	jmp	L295
L297:
	movl	-4(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	subl	$48, %eax
	cmpl	$9, %eax
	jbe	L296
	movl	-4(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-8(%ebp), %eax
	addl	%edx, %eax
	movb	$32, (%eax)
L296:
	addl	$1, -8(%ebp)
L295:
	cmpl	$8, -8(%ebp)
	jle	L297
	addl	$1, -4(%ebp)
L294:
	cmpl	$8, -4(%ebp)
	jle	L298
	nop
	leave
	ret
	.globl	_locateSelection
	.def	_locateSelection;	.scl	2;	.type	32;	.endef
_locateSelection:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$172, %esp
	movl	$0, -28(%ebp)
	jmp	L300
L305:
	movl	$0, -32(%ebp)
	jmp	L301
L304:
	movl	-28(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-32(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$88, %al
	jne	L302
	movl	-28(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-32(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %ecx
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	leal	-24(%ebp), %ebx
	leal	(%ebx,%eax), %edx
	movl	-32(%ebp), %eax
	addl	%edx, %eax
	subl	$89, %eax
	movb	%cl, (%eax)
	jmp	L303
L302:
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	leal	-24(%ebp), %esi
	leal	(%esi,%eax), %edx
	movl	-32(%ebp), %eax
	addl	%edx, %eax
	subl	$89, %eax
	movb	$32, (%eax)
L303:
	addl	$1, -32(%ebp)
L301:
	cmpl	$8, -32(%ebp)
	jle	L304
	addl	$1, -28(%ebp)
L300:
	cmpl	$8, -28(%ebp)
	jle	L305
	movl	$LC2, (%esp)
	call	_system
	movzbl	-105(%ebp), %eax
	movsbl	%al, %ecx
	movzbl	-106(%ebp), %eax
	movsbl	%al, %esi
	movzbl	-107(%ebp), %eax
	movsbl	%al, %eax
	movl	%eax, -124(%ebp)
	movzbl	-108(%ebp), %eax
	movsbl	%al, %edi
	movl	%edi, -128(%ebp)
	movzbl	-109(%ebp), %eax
	movsbl	%al, %ebx
	movl	%ebx, -132(%ebp)
	movzbl	-110(%ebp), %eax
	movsbl	%al, %edi
	movzbl	-111(%ebp), %eax
	movsbl	%al, %ebx
	movzbl	-112(%ebp), %eax
	movsbl	%al, %edx
	movzbl	-113(%ebp), %eax
	movsbl	%al, %eax
	movl	%ecx, 36(%esp)
	movl	%esi, 32(%esp)
	movl	-124(%ebp), %ecx
	movl	%ecx, 28(%esp)
	movl	-128(%ebp), %esi
	movl	%esi, 24(%esp)
	movl	-132(%ebp), %ecx
	movl	%ecx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$LC5, (%esp)
	call	_puts
	movzbl	-96(%ebp), %eax
	movsbl	%al, %ecx
	movzbl	-97(%ebp), %eax
	movsbl	%al, %esi
	movzbl	-98(%ebp), %eax
	movsbl	%al, %eax
	movl	%eax, -124(%ebp)
	movzbl	-99(%ebp), %eax
	movsbl	%al, %edi
	movl	%edi, -128(%ebp)
	movzbl	-100(%ebp), %eax
	movsbl	%al, %ebx
	movl	%ebx, -132(%ebp)
	movzbl	-101(%ebp), %eax
	movsbl	%al, %edi
	movzbl	-102(%ebp), %eax
	movsbl	%al, %ebx
	movzbl	-103(%ebp), %eax
	movsbl	%al, %edx
	movzbl	-104(%ebp), %eax
	movsbl	%al, %eax
	movl	%ecx, 36(%esp)
	movl	%esi, 32(%esp)
	movl	-124(%ebp), %esi
	movl	%esi, 28(%esp)
	movl	-128(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-132(%ebp), %esi
	movl	%esi, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$LC5, (%esp)
	call	_puts
	movzbl	-87(%ebp), %eax
	movsbl	%al, %ecx
	movzbl	-88(%ebp), %eax
	movsbl	%al, %esi
	movzbl	-89(%ebp), %eax
	movsbl	%al, %eax
	movl	%eax, -124(%ebp)
	movzbl	-90(%ebp), %eax
	movsbl	%al, %edi
	movl	%edi, -128(%ebp)
	movzbl	-91(%ebp), %eax
	movsbl	%al, %ebx
	movl	%ebx, -132(%ebp)
	movzbl	-92(%ebp), %eax
	movsbl	%al, %edi
	movzbl	-93(%ebp), %eax
	movsbl	%al, %ebx
	movzbl	-94(%ebp), %eax
	movsbl	%al, %edx
	movzbl	-95(%ebp), %eax
	movsbl	%al, %eax
	movl	%ecx, 36(%esp)
	movl	%esi, 32(%esp)
	movl	-124(%ebp), %ecx
	movl	%ecx, 28(%esp)
	movl	-128(%ebp), %esi
	movl	%esi, 24(%esp)
	movl	-132(%ebp), %ecx
	movl	%ecx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$LC6, (%esp)
	call	_puts
	movzbl	-78(%ebp), %eax
	movsbl	%al, %ecx
	movzbl	-79(%ebp), %eax
	movsbl	%al, %esi
	movzbl	-80(%ebp), %eax
	movsbl	%al, %eax
	movl	%eax, -124(%ebp)
	movzbl	-81(%ebp), %eax
	movsbl	%al, %edi
	movl	%edi, -128(%ebp)
	movzbl	-82(%ebp), %eax
	movsbl	%al, %ebx
	movl	%ebx, -132(%ebp)
	movzbl	-83(%ebp), %eax
	movsbl	%al, %edi
	movzbl	-84(%ebp), %eax
	movsbl	%al, %ebx
	movzbl	-85(%ebp), %eax
	movsbl	%al, %edx
	movzbl	-86(%ebp), %eax
	movsbl	%al, %eax
	movl	%ecx, 36(%esp)
	movl	%esi, 32(%esp)
	movl	-124(%ebp), %esi
	movl	%esi, 28(%esp)
	movl	-128(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-132(%ebp), %esi
	movl	%esi, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$LC5, (%esp)
	call	_puts
	movzbl	-69(%ebp), %eax
	movsbl	%al, %ecx
	movzbl	-70(%ebp), %eax
	movsbl	%al, %esi
	movzbl	-71(%ebp), %eax
	movsbl	%al, %eax
	movl	%eax, -124(%ebp)
	movzbl	-72(%ebp), %eax
	movsbl	%al, %edi
	movl	%edi, -128(%ebp)
	movzbl	-73(%ebp), %eax
	movsbl	%al, %ebx
	movl	%ebx, -132(%ebp)
	movzbl	-74(%ebp), %eax
	movsbl	%al, %edi
	movzbl	-75(%ebp), %eax
	movsbl	%al, %ebx
	movzbl	-76(%ebp), %eax
	movsbl	%al, %edx
	movzbl	-77(%ebp), %eax
	movsbl	%al, %eax
	movl	%ecx, 36(%esp)
	movl	%esi, 32(%esp)
	movl	-124(%ebp), %ecx
	movl	%ecx, 28(%esp)
	movl	-128(%ebp), %esi
	movl	%esi, 24(%esp)
	movl	-132(%ebp), %ecx
	movl	%ecx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$LC5, (%esp)
	call	_puts
	movzbl	-60(%ebp), %eax
	movsbl	%al, %ecx
	movzbl	-61(%ebp), %eax
	movsbl	%al, %esi
	movzbl	-62(%ebp), %eax
	movsbl	%al, %eax
	movl	%eax, -124(%ebp)
	movzbl	-63(%ebp), %eax
	movsbl	%al, %edi
	movl	%edi, -128(%ebp)
	movzbl	-64(%ebp), %eax
	movsbl	%al, %ebx
	movl	%ebx, -132(%ebp)
	movzbl	-65(%ebp), %eax
	movsbl	%al, %edi
	movzbl	-66(%ebp), %eax
	movsbl	%al, %ebx
	movzbl	-67(%ebp), %eax
	movsbl	%al, %edx
	movzbl	-68(%ebp), %eax
	movsbl	%al, %eax
	movl	%ecx, 36(%esp)
	movl	%esi, 32(%esp)
	movl	-124(%ebp), %esi
	movl	%esi, 28(%esp)
	movl	-128(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-132(%ebp), %esi
	movl	%esi, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$LC6, (%esp)
	call	_puts
	movzbl	-51(%ebp), %eax
	movsbl	%al, %ecx
	movzbl	-52(%ebp), %eax
	movsbl	%al, %esi
	movzbl	-53(%ebp), %eax
	movsbl	%al, %eax
	movl	%eax, -124(%ebp)
	movzbl	-54(%ebp), %eax
	movsbl	%al, %edi
	movl	%edi, -128(%ebp)
	movzbl	-55(%ebp), %eax
	movsbl	%al, %ebx
	movl	%ebx, -132(%ebp)
	movzbl	-56(%ebp), %eax
	movsbl	%al, %edi
	movzbl	-57(%ebp), %eax
	movsbl	%al, %ebx
	movzbl	-58(%ebp), %eax
	movsbl	%al, %edx
	movzbl	-59(%ebp), %eax
	movsbl	%al, %eax
	movl	%ecx, 36(%esp)
	movl	%esi, 32(%esp)
	movl	-124(%ebp), %ecx
	movl	%ecx, 28(%esp)
	movl	-128(%ebp), %esi
	movl	%esi, 24(%esp)
	movl	-132(%ebp), %ecx
	movl	%ecx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$LC5, (%esp)
	call	_puts
	movzbl	-42(%ebp), %eax
	movsbl	%al, %ecx
	movzbl	-43(%ebp), %eax
	movsbl	%al, %esi
	movzbl	-44(%ebp), %eax
	movsbl	%al, %eax
	movl	%eax, -124(%ebp)
	movzbl	-45(%ebp), %eax
	movsbl	%al, %edi
	movl	%edi, -128(%ebp)
	movzbl	-46(%ebp), %eax
	movsbl	%al, %ebx
	movl	%ebx, -132(%ebp)
	movzbl	-47(%ebp), %eax
	movsbl	%al, %edi
	movzbl	-48(%ebp), %eax
	movsbl	%al, %ebx
	movzbl	-49(%ebp), %eax
	movsbl	%al, %edx
	movzbl	-50(%ebp), %eax
	movsbl	%al, %eax
	movl	%ecx, 36(%esp)
	movl	%esi, 32(%esp)
	movl	-124(%ebp), %esi
	movl	%esi, 28(%esp)
	movl	-128(%ebp), %ecx
	movl	%ecx, 24(%esp)
	movl	-132(%ebp), %esi
	movl	%esi, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$LC5, (%esp)
	call	_puts
	movzbl	-33(%ebp), %eax
	movsbl	%al, %ecx
	movzbl	-34(%ebp), %eax
	movsbl	%al, %esi
	movzbl	-35(%ebp), %eax
	movsbl	%al, %eax
	movl	%eax, -124(%ebp)
	movzbl	-36(%ebp), %eax
	movsbl	%al, %edi
	movl	%edi, -128(%ebp)
	movzbl	-37(%ebp), %eax
	movsbl	%al, %edx
	movl	%edx, -132(%ebp)
	movzbl	-38(%ebp), %eax
	movsbl	%al, %edi
	movzbl	-39(%ebp), %eax
	movsbl	%al, %ebx
	movzbl	-40(%ebp), %eax
	movsbl	%al, %edx
	movzbl	-41(%ebp), %eax
	movsbl	%al, %eax
	movl	%ecx, 36(%esp)
	movl	%esi, 32(%esp)
	movl	-124(%ebp), %ecx
	movl	%ecx, 28(%esp)
	movl	-128(%ebp), %esi
	movl	%esi, 24(%esp)
	movl	-132(%ebp), %ecx
	movl	%ecx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$500, (%esp)
	call	_sleep_seconds
	nop
	addl	$172, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.globl	_deleteBackSpacePressed
	.def	_deleteBackSpacePressed;	.scl	2;	.type	32;	.endef
_deleteBackSpacePressed:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$36, %esp
	movl	24(%ebp), %eax
	movb	%al, -36(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	20(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -20(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	20(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -8(%ebp)
	movl	$0, -12(%ebp)
L312:
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$49, %al
	jne	L307
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$88, %al
	je	L307
	movl	16(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%edx, (%eax)
	movl	20(%ebp), %eax
	movl	-8(%ebp), %edx
	movl	%edx, (%eax)
	movl	20(%ebp), %eax
	movl	(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movb	$88, (%eax)
	movl	-20(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-16(%ebp), %eax
	addl	%eax, %edx
	movzbl	-36(%ebp), %eax
	movb	%al, (%edx)
	jmp	L306
L307:
	addl	$1, -12(%ebp)
	addl	$1, -4(%ebp)
	cmpl	$8, -4(%ebp)
	jle	L309
	movl	$0, -4(%ebp)
	addl	$1, -8(%ebp)
L309:
	cmpl	$8, -8(%ebp)
	jle	L310
	movl	$0, -8(%ebp)
	movl	$0, -4(%ebp)
L310:
	cmpl	$81, -12(%ebp)
	jg	L313
	jmp	L312
L313:
	nop
L306:
	leave
	ret
	.globl	_deleteBackSlashPressed
	.def	_deleteBackSlashPressed;	.scl	2;	.type	32;	.endef
_deleteBackSlashPressed:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$36, %esp
	movl	24(%ebp), %eax
	movb	%al, -36(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	20(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -20(%ebp)
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	20(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -8(%ebp)
	movl	$0, -12(%ebp)
L320:
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$49, %al
	jne	L315
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$88, %al
	je	L315
	movl	16(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%edx, (%eax)
	movl	20(%ebp), %eax
	movl	-8(%ebp), %edx
	movl	%edx, (%eax)
	movl	20(%ebp), %eax
	movl	(%eax), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movb	$88, (%eax)
	movl	-20(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-16(%ebp), %eax
	addl	%eax, %edx
	movzbl	-36(%ebp), %eax
	movb	%al, (%edx)
	jmp	L314
L315:
	subl	$1, -12(%ebp)
	subl	$1, -4(%ebp)
	cmpl	$0, -4(%ebp)
	jns	L317
	movl	$8, -4(%ebp)
	subl	$1, -8(%ebp)
L317:
	cmpl	$0, -8(%ebp)
	jns	L318
	movl	$8, -8(%ebp)
	movl	$8, -4(%ebp)
L318:
	cmpl	$81, -12(%ebp)
	jg	L321
	jmp	L320
L321:
	nop
L314:
	leave
	ret
	.ident	"GCC: (tdm-1) 5.1.0"
	.def	_time;	.scl	2;	.type	32;	.endef
	.def	_srand;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_system;	.scl	2;	.type	32;	.endef
	.def	_getch;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_Sleep@4;	.scl	2;	.type	32;	.endef
	.def	_fopen;	.scl	2;	.type	32;	.endef
	.def	_getc;	.scl	2;	.type	32;	.endef
	.def	_fclose;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_rand;	.scl	2;	.type	32;	.endef
