	.text
	.intel_syntax noprefix
	.file	"testO.cpp"
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	push	r14
.Ltmp0:
	.cfi_def_cfa_offset 16
	push	rbx
.Ltmp1:
	.cfi_def_cfa_offset 24
	push	rax
.Ltmp2:
	.cfi_def_cfa_offset 32
.Ltmp3:
	.cfi_offset rbx, -24
.Ltmp4:
	.cfi_offset r14, -16
	lea	rsi, [rsp + 4]
	mov	edi, _ZSt3cin
	call	_ZNSirsERi
	lea	rsi, [rsp]
	mov	edi, _ZSt3cin
	call	_ZNSirsERi
	mov	esi, dword ptr [rsp]
	imul	esi, dword ptr [rsp + 4]
	inc	esi
	mov	edi, _ZSt4cout
	call	_ZNSolsEi
	mov	r14, rax
	mov	rax, qword ptr [r14]
	mov	rax, qword ptr [rax - 24]
	mov	rbx, qword ptr [r14 + rax + 240]
	test	rbx, rbx
	je	.LBB0_5
# BB#1:                                 # %_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit
	cmp	byte ptr [rbx + 56], 0
	je	.LBB0_3
# BB#2:
	mov	al, byte ptr [rbx + 67]
	jmp	.LBB0_4
.LBB0_3:
	mov	rdi, rbx
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	mov	rax, qword ptr [rbx]
	mov	esi, 10
	mov	rdi, rbx
	call	qword ptr [rax + 48]
.LBB0_4:                                # %_ZNKSt5ctypeIcE5widenEc.exit
	movsx	esi, al
	mov	rdi, r14
	call	_ZNSo3putEc
	mov	rdi, rax
	call	_ZNSo5flushEv
	xor	eax, eax
	add	rsp, 8
	pop	rbx
	pop	r14
	ret
.LBB0_5:
	call	_ZSt16__throw_bad_castv
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	_GLOBAL__sub_I_testO.cpp,@function
_GLOBAL__sub_I_testO.cpp:               # @_GLOBAL__sub_I_testO.cpp
	.cfi_startproc
# BB#0:
	push	rax
.Ltmp5:
	.cfi_def_cfa_offset 16
	mov	edi, _ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	mov	edi, _ZNSt8ios_base4InitD1Ev
	mov	esi, _ZStL8__ioinit
	mov	edx, __dso_handle
	pop	rax
	jmp	__cxa_atexit            # TAILCALL
.Lfunc_end1:
	.size	_GLOBAL__sub_I_testO.cpp, .Lfunc_end1-_GLOBAL__sub_I_testO.cpp
	.cfi_endproc

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.init_array,"aw",@init_array
	.align	8
	.quad	_GLOBAL__sub_I_testO.cpp

	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
