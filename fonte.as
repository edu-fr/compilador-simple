	.text
	.file	"my cool jit"
	.globl	procedimento1           # -- Begin function procedimento1
	.p2align	4, 0x90
	.type	procedimento1,@function
procedimento1:                          # @procedimento1
	.cfi_startproc
# %bb.0:                                # %entry
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movl	%edi, 12(%rsp)
	movl	%esi, 16(%rsp)
	movl	$2, 20(%rsp)
	movl	$4, %edi
	movl	$4, %esi
	callq	funcao1
	movl	%eax, 12(%rsp)
	addq	$24, %rsp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	procedimento1, .Lfunc_end0-procedimento1
	.cfi_endproc
                                        # -- End function
	.globl	funcao1                 # -- Begin function funcao1
	.p2align	4, 0x90
	.type	funcao1,@function
funcao1:                                # @funcao1
	.cfi_startproc
# %bb.0:                                # %entry
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movl	%edi, 16(%rsp)
	movl	%esi, 20(%rsp)
	movl	$2, 12(%rsp)
	movl	$2, %edi
	callq	funcao5
	movl	%eax, %edi
	callq	imprimei
	movl	$2, 12(%rsp)
	movl	$2, %edi
	callq	imprimei
	movl	$2, %eax
	addq	$24, %rsp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	funcao1, .Lfunc_end1-funcao1
	.cfi_endproc
                                        # -- End function
	.globl	funcao5                 # -- Begin function funcao5
	.p2align	4, 0x90
	.type	funcao5,@function
funcao5:                                # @funcao5
	.cfi_startproc
# %bb.0:                                # %entry
	movl	%edi, -8(%rsp)
	movl	$1, -4(%rsp)
	movl	$5, %eax
	retq
.Lfunc_end2:
	.size	funcao5, .Lfunc_end2-funcao5
	.cfi_endproc
                                        # -- End function
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	movl	$3, %esi
	callq	procedimento1
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end3:
	.size	main, .Lfunc_end3-main
	.cfi_endproc
                                        # -- End function
	.section	".note.GNU-stack","",@progbits
