	.file	"daxpy.c"
	.text
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"Faltan argumentos de entrada (n. componentes, alpha)"
	.align 8
.LC2:
	.string	"/ alpha*x[%d]+y[%d]=z[%d](%8.6f*%8.6f+%8.6f=%8.6f) /\n"
	.align 8
.LC3:
	.string	"Tiempo:%11.9f\t / Tama\303\261o Vectores:%d\t/ alpha*x[0]+y[0]=z[0](%8.6f*%8.6f+%8.6f=%8.6f) / / alpha*x[%d]+y[%d]=z[%d](%8.6f*%8.6f+%8.6f=%8.6f) /\n"
	.align 8
.LC4:
	.string	"Tiempo:%11.9f\t / Tama\303\261o Vectores:%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB39:
	.cfi_startproc
	endbr64
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	subq	$64, %rsp
	.cfi_def_cfa_offset 112
	movq	%fs:40, %rax
	movq	%rax, 56(%rsp)
	xorl	%eax, %eax
	cmpl	$2, %edi
	jle	.L24
	movq	%rsi, %rbx
	movq	8(%rsi), %rdi
	movl	$10, %edx
	movl	$0, %esi
	call	strtol@PLT
	movq	%rax, %r12
	movl	%eax, %ebp
	movq	16(%rbx), %rdi
	movl	$0, %esi
	call	strtod@PLT
	movsd	%xmm0, 8(%rsp)
	cmpl	$33554432, %r12d
	jg	.L15
	cmpl	$8, %r12d
	jg	.L3
	testl	%r12d, %r12d
	jle	.L4
	pxor	%xmm1, %xmm1
	cvtsi2sdl	%r12d, %xmm1
	mulsd	.LC1(%rip), %xmm1
	movl	$0, %eax
	movsd	.LC1(%rip), %xmm3
	leaq	x(%rip), %rcx
	leaq	y(%rip), %rdx
.L5:
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	mulsd	%xmm3, %xmm0
	movapd	%xmm1, %xmm2
	addsd	%xmm0, %xmm2
	movsd	%xmm2, (%rcx,%rax,8)
	movapd	%xmm1, %xmm4
	subsd	%xmm0, %xmm4
	movsd	%xmm4, (%rdx,%rax,8)
	addq	$1, %rax
	cmpl	%eax, %ebp
	jg	.L5
	jmp	.L6
.L24:
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	call	__printf_chk@PLT
	movl	$-1, %edi
	call	exit@PLT
.L15:
	movl	$33554432, %ebp
.L3:
	movl	$0, %ebx
	leaq	x(%rip), %r13
	leaq	y(%rip), %r12
.L7:
	call	drand48@PLT
	movsd	%xmm0, 0(%r13,%rbx,8)
	call	drand48@PLT
	movsd	%xmm0, (%r12,%rbx,8)
	addq	$1, %rbx
	cmpl	%ebx, %ebp
	jg	.L7
.L6:
	leaq	16(%rsp), %rsi
	movl	$0, %edi
	call	clock_gettime@PLT
	movl	$0, %eax
	leaq	z(%rip), %rsi
	leaq	x(%rip), %rcx
	leaq	y(%rip), %rdx
.L8:
	movsd	8(%rsp), %xmm0
	mulsd	(%rcx,%rax,8), %xmm0
	addsd	(%rdx,%rax,8), %xmm0
	movsd	%xmm0, (%rsi,%rax,8)
	addq	$1, %rax
	cmpl	%eax, %ebp
	jg	.L8
	leaq	32(%rsp), %rsi
	movl	$0, %edi
	call	clock_gettime@PLT
	movq	40(%rsp), %rax
	subq	24(%rsp), %rax
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	divsd	.LC5(%rip), %xmm0
	movq	32(%rsp), %rax
	subq	16(%rsp), %rax
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	addsd	%xmm1, %xmm0
	cmpl	$10, %ebp
	jle	.L12
	leal	-1(%rbp), %ecx
	movslq	%ecx, %rax
	subq	$8, %rsp
	.cfi_def_cfa_offset 120
	leaq	z(%rip), %rdx
	pushq	(%rdx,%rax,8)
	.cfi_def_cfa_offset 128
	leaq	y(%rip), %rdx
	movsd	(%rdx,%rax,8), %xmm7
	leaq	x(%rip), %rdx
	movsd	(%rdx,%rax,8), %xmm6
	movsd	24(%rsp), %xmm5
	movl	%ecx, %r9d
	movl	%ecx, %r8d
	movsd	z(%rip), %xmm4
	movsd	y(%rip), %xmm3
	movsd	x(%rip), %xmm2
	movapd	%xmm5, %xmm1
	movl	%ebp, %edx
	leaq	.LC3(%rip), %rsi
	movl	$1, %edi
	movl	$8, %eax
	call	__printf_chk@PLT
	addq	$16, %rsp
	.cfi_def_cfa_offset 112
.L11:
	movq	56(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L25
	movl	$0, %eax
	addq	$64, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
.L12:
	.cfi_restore_state
	movl	%ebp, %edx
	leaq	.LC4(%rip), %rsi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk@PLT
	movl	$0, %ebx
	leaq	z(%rip), %r14
	leaq	y(%rip), %r13
	leaq	x(%rip), %r12
.L10:
	movsd	(%r14,%rbx,8), %xmm3
	movsd	0(%r13,%rbx,8), %xmm2
	movsd	(%r12,%rbx,8), %xmm1
	movsd	8(%rsp), %xmm0
	movl	%ebx, %r8d
	movl	%ebx, %ecx
	movl	%ebx, %edx
	leaq	.LC2(%rip), %rsi
	movl	$1, %edi
	movl	$4, %eax
	call	__printf_chk@PLT
	addq	$1, %rbx
	cmpl	%ebx, %ebp
	jg	.L10
	jmp	.L11
.L4:
	leaq	16(%rsp), %rsi
	movl	$0, %edi
	call	clock_gettime@PLT
	leaq	32(%rsp), %rsi
	movl	$0, %edi
	call	clock_gettime@PLT
	movq	40(%rsp), %rax
	subq	24(%rsp), %rax
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	divsd	.LC5(%rip), %xmm0
	movq	32(%rsp), %rax
	subq	16(%rsp), %rax
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	addsd	%xmm1, %xmm0
	movl	%r12d, %edx
	leaq	.LC4(%rip), %rsi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk@PLT
	jmp	.L11
.L25:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE39:
	.size	main, .-main
	.comm	z,268435456,32
	.comm	y,268435456,32
	.comm	x,268435456,32
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	2576980378
	.long	1069128089
	.align 8
.LC5:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
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
