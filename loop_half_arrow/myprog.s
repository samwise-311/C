	.file	"main.c"
	.text
	.section	.rodata
.LC0:
	.string	"Enter arrow base height:"
.LC1:
	.string	"%d"
.LC2:
	.string	"Enter arrow base width:"
.LC3:
	.string	"Enter arrow head width:"
	.align 8
.LC4:
	.string	"Error: Unrecognized input, please enter only integer values."
	.align 8
.LC5:
	.string	"Error: Arrow head width must be greater than base width!\nTry Again..."
.LC6:
	.string	"\nEnter arrow head width:"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -48(%rbp)
	movl	$0, -44(%rbp)
	movl	$0, -40(%rbp)
	movl	$0, -20(%rbp)
	movl	$0, -16(%rbp)
	movl	$0, -12(%rbp)
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	leaq	-48(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	%eax, -20(%rbp)
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	leaq	-44(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	%eax, -16(%rbp)
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
	leaq	-40(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	%eax, -12(%rbp)
	movl	$10, %edi
	call	putchar@PLT
	cmpl	$0, -20(%rbp)
	je	.L2
	cmpl	$0, -16(%rbp)
	je	.L2
	cmpl	$0, -12(%rbp)
	jne	.L3
.L2:
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
.L3:
	movl	-40(%rbp), %edx
	movl	-44(%rbp), %eax
	cmpl	%eax, %edx
	jg	.L4
	leaq	.LC5(%rip), %rdi
	call	puts@PLT
	movl	$0, -40(%rbp)
	leaq	.LC6(%rip), %rdi
	call	puts@PLT
	leaq	-40(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	%eax, -12(%rbp)
	movl	$10, %edi
	call	putchar@PLT
.L4:
	movl	$0, -36(%rbp)
	jmp	.L5
.L8:
	movl	$0, -32(%rbp)
	jmp	.L6
.L7:
	movl	$42, %edi
	call	putchar@PLT
	addl	$1, -32(%rbp)
.L6:
	movl	-44(%rbp), %eax
	cmpl	%eax, -32(%rbp)
	jl	.L7
	movl	$10, %edi
	call	putchar@PLT
	addl	$1, -36(%rbp)
.L5:
	movl	-48(%rbp), %eax
	cmpl	%eax, -36(%rbp)
	jl	.L8
	movl	$0, -28(%rbp)
	jmp	.L9
.L12:
	movl	$0, -24(%rbp)
	jmp	.L10
.L11:
	movl	$42, %edi
	call	putchar@PLT
	addl	$1, -24(%rbp)
.L10:
	movl	-40(%rbp), %eax
	subl	-28(%rbp), %eax
	cmpl	%eax, -24(%rbp)
	jl	.L11
	movl	$10, %edi
	call	putchar@PLT
	addl	$1, -28(%rbp)
.L9:
	movl	-40(%rbp), %eax
	cmpl	%eax, -28(%rbp)
	jl	.L12
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L14
	call	__stack_chk_fail@PLT
.L14:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
