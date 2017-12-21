	.text
	.intel_syntax noprefix
	.file	"ddtest.cpp"
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
	mov	eax, 8
	mov	edi, eax
	call	_Znwm
	xor	esi, esi
	mov	ecx, 8
	mov	edx, ecx
	mov	rdi, rax
	mov	qword ptr [rbp - 24], rax # 8-byte Spill
	call	memset
	mov	rdi, qword ptr [rbp - 24] # 8-byte Reload
	call	_ZN1AC2Ev
	mov	rax, qword ptr [rbp - 24] # 8-byte Reload
	mov	qword ptr [rbp - 16], rax
	jmp	.LBB1_3
.LBB1_2:
	mov	eax, 8
	mov	edi, eax
	call	_Znwm
	xor	esi, esi
	mov	ecx, 8
	mov	edx, ecx
	mov	rdi, rax
	mov	qword ptr [rbp - 32], rax # 8-byte Spill
	call	memset
	mov	rdi, qword ptr [rbp - 32] # 8-byte Reload
	call	_ZN1BC2Ev
	mov	rax, qword ptr [rbp - 32] # 8-byte Reload
	mov	qword ptr [rbp - 16], rax
.LBB1_3:
	mov	rax, qword ptr [rbp - 16]
	mov	rcx, qword ptr [rax]
	mov	rdi, rax
	call	qword ptr [rcx]
	xor	eax, eax
	add	rsp, 32
	pop	rbp
	ret
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc

	.section	.text._ZN1AC2Ev,"axG",@progbits,_ZN1AC2Ev,comdat
	.weak	_ZN1AC2Ev
	.align	16, 0x90
	.type	_ZN1AC2Ev,@function
_ZN1AC2Ev:                              # @_ZN1AC2Ev
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
	movabs	rax, _ZTV1A
	add	rax, 16
	mov	qword ptr [rbp - 8], rdi
	mov	rdi, qword ptr [rbp - 8]
	mov	qword ptr [rdi], rax
	pop	rbp
	ret
.Lfunc_end2:
	.size	_ZN1AC2Ev, .Lfunc_end2-_ZN1AC2Ev
	.cfi_endproc

	.section	.text._ZN1BC2Ev,"axG",@progbits,_ZN1BC2Ev,comdat
	.weak	_ZN1BC2Ev
	.align	16, 0x90
	.type	_ZN1BC2Ev,@function
_ZN1BC2Ev:                              # @_ZN1BC2Ev
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
	sub	rsp, 16
	mov	qword ptr [rbp - 8], rdi
	mov	rdi, qword ptr [rbp - 8]
	mov	rax, rdi
	mov	qword ptr [rbp - 16], rdi # 8-byte Spill
	mov	rdi, rax
	call	_ZN1AC2Ev
	movabs	rax, _ZTV1B
	add	rax, 16
	mov	rdi, qword ptr [rbp - 16] # 8-byte Reload
	mov	qword ptr [rdi], rax
	add	rsp, 16
	pop	rbp
	ret
.Lfunc_end3:
	.size	_ZN1BC2Ev, .Lfunc_end3-_ZN1BC2Ev
	.cfi_endproc

	.section	.text._ZN1A3fooEv,"axG",@progbits,_ZN1A3fooEv,comdat
	.weak	_ZN1A3fooEv
	.align	16, 0x90
	.type	_ZN1A3fooEv,@function
_ZN1A3fooEv:                            # @_ZN1A3fooEv
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp12:
	.cfi_def_cfa_offset 16
.Ltmp13:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp14:
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
.Lfunc_end4:
	.size	_ZN1A3fooEv, .Lfunc_end4-_ZN1A3fooEv
	.cfi_endproc

	.section	.text._ZN1B3fooEv,"axG",@progbits,_ZN1B3fooEv,comdat
	.weak	_ZN1B3fooEv
	.align	16, 0x90
	.type	_ZN1B3fooEv,@function
_ZN1B3fooEv:                            # @_ZN1B3fooEv
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp15:
	.cfi_def_cfa_offset 16
.Ltmp16:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp17:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	movabs	rax, _ZSt4cout
	movabs	rsi, .L.str.1
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
.Lfunc_end5:
	.size	_ZN1B3fooEv, .Lfunc_end5-_ZN1B3fooEv
	.cfi_endproc

	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	_GLOBAL__sub_I_ddtest.cpp,@function
_GLOBAL__sub_I_ddtest.cpp:              # @_GLOBAL__sub_I_ddtest.cpp
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp18:
	.cfi_def_cfa_offset 16
.Ltmp19:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp20:
	.cfi_def_cfa_register rbp
	call	__cxx_global_var_init
	pop	rbp
	ret
.Lfunc_end6:
	.size	_GLOBAL__sub_I_ddtest.cpp, .Lfunc_end6-_GLOBAL__sub_I_ddtest.cpp
	.cfi_endproc

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	_ZTV1A,@object          # @_ZTV1A
	.section	.rodata._ZTV1A,"aG",@progbits,_ZTV1A,comdat
	.weak	_ZTV1A
	.align	8
_ZTV1A:
	.quad	0
	.quad	_ZTI1A
	.quad	_ZN1A3fooEv
	.size	_ZTV1A, 24

	.type	_ZTS1A,@object          # @_ZTS1A
	.section	.rodata._ZTS1A,"aG",@progbits,_ZTS1A,comdat
	.weak	_ZTS1A
_ZTS1A:
	.asciz	"1A"
	.size	_ZTS1A, 3

	.type	_ZTI1A,@object          # @_ZTI1A
	.section	.rodata._ZTI1A,"aG",@progbits,_ZTI1A,comdat
	.weak	_ZTI1A
	.align	8
_ZTI1A:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTS1A
	.size	_ZTI1A, 16

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"A method"
	.size	.L.str, 9

	.type	_ZTV1B,@object          # @_ZTV1B
	.section	.rodata._ZTV1B,"aG",@progbits,_ZTV1B,comdat
	.weak	_ZTV1B
	.align	8
_ZTV1B:
	.quad	0
	.quad	_ZTI1B
	.quad	_ZN1B3fooEv
	.size	_ZTV1B, 24

	.type	_ZTS1B,@object          # @_ZTS1B
	.section	.rodata._ZTS1B,"aG",@progbits,_ZTS1B,comdat
	.weak	_ZTS1B
_ZTS1B:
	.asciz	"1B"
	.size	_ZTS1B, 3

	.type	_ZTI1B,@object          # @_ZTI1B
	.section	.rodata._ZTI1B,"aG",@progbits,_ZTI1B,comdat
	.weak	_ZTI1B
	.align	16
_ZTI1B:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS1B
	.quad	_ZTI1A
	.size	_ZTI1B, 24

	.type	.L.str.1,@object        # @.str.1
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str.1:
	.asciz	"B method"
	.size	.L.str.1, 9

	.section	.init_array,"aw",@init_array
	.align	8
	.quad	_GLOBAL__sub_I_ddtest.cpp

	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
