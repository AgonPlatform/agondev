	.assume ADL=1
	.global _getKbData
	.global _myAscii
	.global _myState
	.global _myFab
	.global _myMod
	.global _keyArray

	.text

_getKbData:
	push ix
	push de
    pop ix  					; put DE into IX for easier reading

	ld a, (ix+0)        		; ascii code
	ld (_myAscii),a 
	ld (_keyArray),a 

	ld a, (ix+1)        		; mod code
	ld (_myMod),a 
	ld (_keyArray + 1),a 

	ld a, (ix+2)        		; fab code
	ld (_myFab),a 
	ld (_keyArray + 2),a 

	ld a, (ix+3)        		; state code
	ld (_myState),a 
	ld (_keyArray + 3),a 

	pop ix
	ld HL, 0					; return 0 code in HL

	ret 	

  .data

; global variables
_myAscii: .db 0
_myState: .db 0
_myFab:   .db 0
_myMod:   .db 0

; global array
_keyArray: .ds 4, 0
