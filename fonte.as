	.text
	.file	"my cool jit"
	.globl	procedimento1           # -- Begin function procedimento1
	.p2align	4, 0x90
	.type	procedimento1,@function
procedimento1:                          # @procedimento1
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	%edi, 4(%rsp)
	movl	$2, (%rsp)
	callq	imprimei
	movl	$250, 4(%rsp)
	movl	$250, %edi
	callq	imprimei
	movl	(%rsp), %edi
	callq	imprimei
	movl	$10, %edi
	movl	$20, %esi
	callq	funcao1
	movl	%eax, (%rsp)
	movl	%eax, %edi
	callq	imprimei
	popq	%rax
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
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	%edi, 4(%rsp)
	movl	%esi, (%rsp)
	movl	$123456789, %edi        # imm = 0x75BCD15
	callq	imprimei
	movl	(%rsp), %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	funcao1, .Lfunc_end1-funcao1
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
	movl	$5, %edi
	callq	procedimento1
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end2:
	.size	main, .Lfunc_end2-main
	.cfi_endproc
                                        # -- End function
	.section	".note.GNU-stack","",@progbits
