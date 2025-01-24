	.assume	adl=1

	.section	.text
	.global	_toupper

_toupper:
	pop	de
	ex	(sp), hl
	push	de
	.extern	_toupper.internal

	.section	.text
	.global	_toupper.internal
	; ASM interface: input/output char in L, destroys AF
.internal:
	ld	a, l
	sub	a, 'a'
	cp	a, 1+'z'-'a'
	ret	nc

	res	5, l
	ret
