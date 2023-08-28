	.file	"dma3.c"
	.text
	.globl	_modifyArray
	.def	_modifyArray;	.scl	2;	.type	32;	.endef
_modifyArray:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	$28, 4(%esp)
	movl	%eax, (%esp)
	call	_realloc
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$20, %eax
	movl	$252, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	$24, %eax
	movl	$32, (%eax)
	movl	$0, -12(%ebp)
	jmp	L2
L3:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%eax, %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	movl	(%eax), %eax
	addl	%eax, %eax
	movl	%eax, (%edx)
	addl	$1, -12(%ebp)
L2:
	cmpl	$4, -12(%ebp)
	jle	L3
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "Memory allocation failed\0"
LC1:
	.ascii "Enter %d integers:\12\0"
LC2:
	.ascii "%d\0"
LC3:
	.ascii "Modified array:\0"
LC4:
	.ascii "%d \0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB15:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$5, 20(%esp)
	movl	20(%esp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, 16(%esp)
	movl	16(%esp), %eax
	testl	%eax, %eax
	jne	L5
	movl	$LC0, (%esp)
	call	_puts
	movl	$1, %eax
	jmp	L11
L5:
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	$0, 28(%esp)
	jmp	L7
L8:
	movl	16(%esp), %eax
	movl	28(%esp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_scanf
	addl	$1, 28(%esp)
L7:
	movl	28(%esp), %eax
	cmpl	20(%esp), %eax
	jl	L8
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	leal	16(%esp), %eax
	movl	%eax, (%esp)
	call	_modifyArray
	movl	$LC3, (%esp)
	call	_puts
	movl	$0, 24(%esp)
	jmp	L9
L10:
	movl	16(%esp), %eax
	movl	24(%esp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	addl	$1, 24(%esp)
L9:
	cmpl	$6, 24(%esp)
	jle	L10
	movl	$10, (%esp)
	call	_putchar
	movl	16(%esp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	$0, %eax
L11:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE15:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_realloc;	.scl	2;	.type	32;	.endef
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
