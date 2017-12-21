;;; Trevor Bedsaul
;;; tdb7mw
;;; threexplusone.s

	global threexplusone

	section .text


	;; Optimized by changing code around to remove all pushes and pops from the program.
	
threexplusone:
	;; Prologue
	xor rax, rax		; zero out return register
	xor rdx, rdx
	xor rsi, rsi
	xor rcx, rcx
	xor r10, r10
start:
	cmp 	rdi, 1		; if x = 1, return 1
	je	one		; return one
	mov	rsi, 2 		; moves 2 into rsi to use to check if even
	mov     rax, rdi	; move x into rax
	mov	r10, rdi
	div	rsi		; rdx = x % 2, rax = x / 2
	cmp	rdx, 1		; if x%2 = 1, do 3x+1
	je	odd
	mov	rdi, rax 	; else, call again with x = x / 2
	call	threexplusone
	inc	rax
	ret
	
one:
	ret

odd:
	mov	rax, r10	; retrieving original x
	mov	rsi, 3
	mul	rsi		; x = 3x
	inc	rax		; x = x + 1
	mov	rdi, rax
	call	threexplusone	; call again with x = 3x+1
	inc	rax
	ret


