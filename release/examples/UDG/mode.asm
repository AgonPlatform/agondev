;	get current screen mode from sysvars

	.global _getMode
	.assume ADL=1
	.text

_getMode:
	push ix 			; push ix onto the stack and allocate local frame
	ld ix, 0 			;	
	add ix, sp 			; set ix to sp
	push ix 			; push again as we are going to use ix

						; main function code starts here
	ld hl, 0			; clear HL before returning value
	ld a, $08			; $08 is moscall for get sysvars
	rst.lil $08			; do moscall
	ld a, (ix + $27)	; screen mode sysvar
	ld l, a 			; store mode in L (lowest byte of UHL)

	pop ix				; get ix back again
	ld sp, ix 			; set sp to ix
	pop ix 				; restore ix from stack
	ret 				; return


