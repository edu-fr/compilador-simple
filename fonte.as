	.text
	.file	"my cool jit"
	.globl	FUNCAO                  # -- Begin function FUNCAO
	.p2align	4, 0x90
	.type	FUNCAO,@function
FUNCAO:                                 # @FUNCAO
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	%edi, (%rsp)
	movl	%esi, 4(%rsp)
	movl	$25, %edi
	callq	imprimei
	movl	(%rsp), %edi
	callq	funcao5
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	FUNCAO, .Lfunc_end0-FUNCAO
	.cfi_endproc
                                        # -- End function
	.globl	funcao5                 # -- Begin function funcao5
	.p2align	4, 0x90
	.type	funcao5,@function
funcao5:                                # @funcao5
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	%edi, (%rsp)
	movl	$2, 4(%rsp)
	callq	imprimei
	movl	$250, (%rsp)
	movl	$250, %edi
	callq	imprimei
	movl	(%rsp), %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	funcao5, .Lfunc_end1-funcao5
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
	movl	$10, %edi
	callq	imprimei
	movl	$10, %edi
	movl	$20, %esi
	callq	FUNCAO
	movl	%eax, %edi
	callq	imprimei
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end2:
	.size	main, .Lfunc_end2-main
	.cfi_endproc
                                        # -- End function
	.section	".note.GNU-stack","",@progbits
