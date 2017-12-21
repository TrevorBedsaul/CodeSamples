	.text
	.intel_syntax noprefix
	.file	"obj.cpp"
	.section	.rodata.cst4,"aM",@progbits,4
	.align	4
.LCPI0_0:
	.long	1065353216              # float 1
	.text
	.globl	_ZN3ObjC2Ev
	.align	16, 0x90
	.type	_ZN3ObjC2Ev,@function
_ZN3ObjC2Ev:                            # @_ZN3ObjC2Ev
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
.Ltmp1:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp2:
	.cfi_def_cfa_register rbp
	movss	xmm0, dword ptr [.LCPI0_0] # xmm0 = mem[0],zero,zero,zero
	mov	qword ptr [rbp - 8], rdi
	mov	rdi, qword ptr [rbp - 8]
	mov	dword ptr [rdi], 5
	mov	byte ptr [rdi + 4], 65
	mov	byte ptr [rdi + 5], 1
	mov	dword ptr [rdi + 8], 3
	movss	dword ptr [rdi + 12], xmm0
	pop	rbp
	ret
.Lfunc_end0:
	.size	_ZN3ObjC2Ev, .Lfunc_end0-_ZN3ObjC2Ev
	.cfi_endproc

	.globl	_ZN3Obj4getDEv
	.align	16, 0x90
	.type	_ZN3Obj4getDEv,@function
_ZN3Obj4getDEv:                         # @_ZN3Obj4getDEv
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp3:
	.cfi_def_cfa_offset 16
.Ltmp4:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp5:
	.cfi_def_cfa_register rbp
	mov	qword ptr [rbp - 8], rdi
	mov	rdi, qword ptr [rbp - 8]
	mov	eax, dword ptr [rdi + 8]
	pop	rbp
	ret
.Lfunc_end1:
	.size	_ZN3Obj4getDEv, .Lfunc_end1-_ZN3Obj4getDEv
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp6:
	.cfi_def_cfa_offset 16
.Ltmp7:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp8:
	.cfi_def_cfa_register rbp
	sub	rsp, 32
	lea	rdi, [rbp - 16]
	call	_ZN3ObjC1Ev
	lea	rdi, [rbp - 16]
	call	_ZN3Obj4getDEv
	xor	ecx, ecx
	mov	dword ptr [rbp - 20], eax # 4-byte Spill
	mov	eax, ecx
	add	rsp, 32
	pop	rbp
	ret
.Lfunc_end2:
	.size	main, .Lfunc_end2-main
	.cfi_endproc


	.globl	_ZN3ObjC1Ev
	.type	_ZN3ObjC1Ev,@function
_ZN3ObjC1Ev = _ZN3ObjC2Ev
	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
