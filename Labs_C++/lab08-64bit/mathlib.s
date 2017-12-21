;;; Trevor Bedsaul
;;; tdb7mw
;;; mathlib.s

	;; Parameter 1 (in rdi) is first int a
	;; Parameter 2 (in rsi) is second int b
	
	global product

	section .text

product:
	;; Prologue
	xor rax, rax		; zero out return register
	xor r10, r10 		; zero out counter i
start:
	cmp	r10,  rdi	; does i == a?
	je 	done		; if so, we are done with the loop
	add	rax, rsi	; adds b
	inc     r10
	jmp	start
done:
	ret


	

	;; Parameter 1 (in rdi) is base int x
	;; Parameter 2 (in rsi) is power int y

	global power
	
power:
	;; Prologue
	xor rax, rax
_start:
	cmp 	rsi, 0		; if exp is 0, return 1
        je      _zero
	cmp	rsi, 1		; if exp is 1, return base
	je	_one
	push	rsi		; save rsi
	mov	rsi, rdi	; rsi = base
	call 	product		; product(base, base)
	mov	rdx, rax	; save rax in rdx for later
	pop     rsi		; retrieve rsi (exponent)
	dec     rsi		; exponent -= 2
	dec     rsi
	call    power		; power(base, exp-2)
	mov 	rsi, rax	; set parameters for product to:
	mov	rdi, rdx 
	call 	product		; product( product(base, exp-2) , base^2 )
_done:
	ret
_zero:
	mov rax, 1 		; return 1
	jmp _done
_one:
	mov rax, rdi 		; return base
	jmp _done
