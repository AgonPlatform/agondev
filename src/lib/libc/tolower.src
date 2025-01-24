	.assume	adl=1

	.section	.text
	.global	_tolower

_tolower:
	pop	de
	ex	(sp), hl
	push	de
	.extern	_tolower.internal

	.section	.text
	.global	_tolower.internal
	; ASM interface: input/output char in L, destroys AF
_tolower.internal:
	ld	a, l
	sub	a, 'A'
	cp	a, 1+'Z'-'A'
	ret	nc

	set	5, l
	ret
