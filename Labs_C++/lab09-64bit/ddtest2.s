	.text
	.intel_syntax noprefix
	.file	"ddtest2.cpp"
	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	__cxx_global_var_init,@function
__cxx_global_var_init:                  # @__cxx_global_var_init
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
	sub	rsp, 16
	movabs	rdi, _ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	movabs	rdi, _ZNSt8ios_base4InitD1Ev
	movabs	rsi, _ZStL8__ioinit
	movabs	rdx, __dso_handle
	call	__cxa_atexit
	mov	dword ptr [rbp - 4], eax # 4-byte Spill
	add	rsp, 16
	pop	rbp
	ret
.Lfunc_end0:
	.size	__cxx_global_var_init, .Lfunc_end0-__cxx_global_var_init
	.cfi_endproc

	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
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
	sub	rsp, 32
	mov	dword ptr [rbp - 4], 0
	call	rand
	mov	ecx, 2
	cdq
	idiv	ecx
	mov	dword ptr [rbp - 8], edx
	cmp	dword ptr [rbp - 8], 0
	je	.LBB1_2
# BB#1:
	mov	eax, 1
	mov	edi, eax
	call	_Znwm
	mov	qword ptr [rbp - 16], rax
	jmp	.LBB1_3
.LBB1_2:
	mov	eax, 1
	mov	edi, eax
	call	_Znwm
	mov	qword ptr [rbp - 24], rax
.LBB1_3:
	mov	rdi, qword ptr [rbp - 16]
	call	_ZN1A3fooEv
	xor	eax, eax
	add	rsp, 32
	pop	rbp
	ret
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc

	.section	.text._ZN1A3fooEv,"axG",@progbits,_ZN1A3fooEv,comdat
	.weak	_ZN1A3fooEv
	.align	16, 0x90
	.type	_ZN1A3fooEv,@function
_ZN1A3fooEv:                            # @_ZN1A3fooEv
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
	sub	rsp, 16
	movabs	rax, _ZSt4cout
	movabs	rsi, .L.str
	mov	qword ptr [rbp - 8], rdi
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movabs	rsi, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	rdi, rax
	call	_ZNSolsEPFRSoS_E
	mov	qword ptr [rbp - 16], rax # 8-byte Spill
	add	rsp, 16
	pop	rbp
	ret
.Lfunc_end2:
	.size	_ZN1A3fooEv, .Lfunc_end2-_ZN1A3fooEv
	.cfi_endproc

	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	_GLOBAL__sub_I_ddtest2.cpp,@function
_GLOBAL__sub_I_ddtest2.cpp:             # @_GLOBAL__sub_I_ddtest2.cpp
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp9:
	.cfi_def_cfa_offset 16
.Ltmp10:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp11:
	.cfi_def_cfa_register rbp
	call	__cxx_global_var_init
	pop	rbp
	ret
.Lfunc_end3:
	.size	_GLOBAL__sub_I_ddtest2.cpp, .Lfunc_end3-_GLOBAL__sub_I_ddtest2.cpp
	.cfi_endproc

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"A method"
	.size	.L.str, 9

	.section	.init_array,"aw",@init_array
	.align	8
	.quad	_GLOBAL__sub_I_ddtest2.cpp

	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
