	.assume	adl=1
	.section	.text
	.global	_strcasecmp
	.global	_strncasecmp
	.extern	_tolower.internal
	.local	_strcasecmp.mismatch
	.local	_strcasecmp.done

_strcasecmp:
	pop	iy
	pop	de
	ex	(sp), hl
	push	de
	ld	b, 1+'z'-'a'
	ld	c, 'a'-'A'
	jr	.loop_entry
.loop:
	cp	a, (hl)
	jr	z, _strcasecmp.done
.loop_nonnull:
	inc	hl
	inc	de
.loop_entry:
	ld	a, (de)
	xor	a, (hl)
	jr	z, .loop
	cp	a, c
	jr	nz, _strcasecmp.mismatch
	or	a, (hl)
	sub	a, 'a'
	cp	a, b
	jr	c, .loop_nonnull

_strcasecmp.mismatch:
	ld	l, (hl)
	call	_tolower.internal
	ex	de, hl
	ld	l, (hl)
	call	_tolower.internal
	ld	a, l
	sub	a, e
_strcasecmp.done:
	sbc	hl, hl
	ld	l, a
	jp	(iy)

_strncasecmp:
	pop	iy
	pop	de
	pop	hl
	pop	bc
	push	bc
	push	de
	push	hl

	scf
	sbc	hl, hl
	add	hl, bc
	ex	(sp), hl

	call	c, .loop_entry2
	jr	c, _strcasecmp.mismatch
	sbc	hl, hl
	jp	(iy)

.checkcase:
	or	a, (hl)
	sub	a, 'a'
	add	a, -(1+'z'-'a')
	ret	c
.loop2:
	cpi
	ret	po
	ret	z
	inc	de
.loop_entry2:
	ld	a, (de)
	xor	a, (hl)
	jr	z, .loop2
	cp	a, 'a'-'A'
	jr	z, .checkcase
	scf
	ret
