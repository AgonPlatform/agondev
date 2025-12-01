; ---------------------------------------------------------------------------
;
; Nunchuck i2c library
; Richard Turnnidge 2025. v cLib 0.1
; Adapted for use with Agondev C
;
; ---------------------------------------------------------------------------

; call 'nunchuck_exists' to check for nunchuck
; call 'i2c_open'        to open i2c port
; call 'nunchuck_open'   to configure nunchuck
; call 'nunchuck_update' to retrieve fresh data
; call 'i2c_close'       to close the i2c connection
;
; Available byte info:
; 
; nunchuck_btnC:       1 off, 0 pressed
; nunchuck_btnZ:       1 off, 0 pressed

; nunchuck_joyX:       0 - 255. 128 is centre
; nunchuck_joyY:       0 - 255. 128 is centre
; nunchuck_joyD:       Digital version joystick directions, as per Console8 01010101b, 0 is pressed, 1 is not

; nunchuck_angleX:     0 - 255. 128 is centre
; nunchuck_angleY:     0 - 255. 128 is centre
; nunchuck_velocityZ:  0 - 255. 128 is centre. NOTE above may not get full range of 0 - 255

; ---------------------------------------------------------------------------

; nunchuck functions
	.global _nunchuck_exists
	.global _i2c_open
	.global _nunchuck_open
	.global _nunchuck_update
	.global _i2c_close

; nunchuck global variables
	.global _nunchuck_btnC
	.global _nunchuck_btnZ

	.global _nunchuck_joyX
	.global _nunchuck_joyY
	.global _nunchuck_joyD

	.global _nunchuck_angleX
	.global _nunchuck_angleY
	.global _nunchuck_velocityZ

; other
	.global _getDisplayMode
	.assume ADL=1
	.text

; ---------------------------------------------------------------------------
;
;   OPEN I2C PORT
;
; ---------------------------------------------------------------------------

_i2c_open:
	push ix
	push af
	push bc

    ld c, 3             ; fast speed
	ld a, $1F			; open i2c 
	rst.lil $08			; do moscall

	pop bc
	pop af
	pop ix
    ret

; ---------------------------------------------------------------------------
;
; 	CHECK IF NUNCHUCK IS CONNECTED
;
;   will return error code in A, 0 if all OK
;
; ---------------------------------------------------------------------------

_nunchuck_exists:
	push ix
	push af
	push bc

    ld c, nunchuck_addr                 ; i2c address
    ld b, 1                             ; number of bytes to send
    ld hl, nunchuck_write_buffer

    ld (hl), $00                        ; reset memory read address to $00

	ld a, $21			; 
	rst.lil $08			; do moscall

	ld hl, 0			; clear HL before returning value
	ld l, a 			; store A in L (lowest byte of UHL)

	pop bc
	pop af
	pop ix
    ret

; ---------------------------------------------------------------------------
;
;   OPEN NUNCHUCK I2C CONNECTION
;
; ---------------------------------------------------------------------------

_nunchuck_open:

	push ix
	push af
	push bc

    ld c, nunchuck_addr  		         ; i2c address
    ld b, 2                     	     ; number of bytes to send
    ld hl, nunchuck_write_buffer

    ld (hl), $F0
    inc hl 
    ld (hl), $55
    dec hl

	ld a, $21			; 
	rst.lil $08			; do moscall

    ld c, nunchuck_addr                   ; i2c address
    ld b, 2                     	      ; number of bytes to send
    ld hl, nunchuck_write_buffer

    ld (hl), $FB
    inc hl 
    ld (hl), $00
    dec hl

	ld a, $21			; 
	rst.lil $08			; do moscall

    ld c, nunchuck_addr                    ; i2c address
    ld b, 1                     	       ; number of bytes to send
    ld hl, nunchuck_write_buffer     	   ; send a $00 to restet i2c data position

    ld (hl), $00			


	ld a, $21			; reset memory read address to $00 
	rst.lil $08			; do moscall

    pop bc
	pop af
	pop ix

    ret 

; ---------------------------------------------------------------------------
;
; 	UPDATE NUNCHUCK POSITION / BUTTON DATA
;   Reads 6 bytes of data from nunchuck, as follows
;
;   byte 1 : Joystick x position
;   byte 2 : Joystick y position
;   byte 3 : Y accelerometer bits 9 to 2
;   byte 4 : Y accelerometer bits 9 to 2
;   byte 5 : Z accelerometer bits 9 to 2
;   byte 6 : Z accelerometer bits 7 & 6
;            Y accelerometer bits 5 & 4
;            Y accelerometer bits 3 & 2
;            C button status bit 1
;            Z button status bit 0
;
; ---------------------------------------------------------------------------

_nunchuck_update:

	push ix
    push iy
	push af
	push bc

    ld c, nunchuck_addr                     ; i2c address
    ld b, 1                     	        ; number of bytes to send
    ld hl, nunchuck_write_buffer     	    ; send a $00 to restet i2c data position
    ld (hl), $00
		                
	ld a, $21			; reset memory read address to $00 
	rst.lil $08			; do moscall

    ld c, nunchuck_addr
    ld b,6                    		        ; number of bytes to read
    ld hl, nunchuck_read_buffer

	ld a, $22			; 
	rst.lil $08			; do moscall

    ld iy, nunchuck_read_buffer		        ; contains 6 bytes of data, using index reg IY just for lazyness

    ld a, (iy + 0)
    ld (_nunchuck_joyX), a

    ld a, (iy + 1)
    ld (_nunchuck_joyY), a

    ld a, (iy + 2)
    sub 64
    sla a
    ld (_nunchuck_angleX), a

    ld a, (iy + 3)
    sub 64
    sla a
    ld (_nunchuck_angleY), a

    ld a, (iy + 4)
    ld (_nunchuck_velocityZ), a

    ld a, (iy + 5)
    and 1
    ld (_nunchuck_btnZ), a

    ld a, (iy + 5)
    sra a
    and 1
    ld (_nunchuck_btnC), a

    ; create binary version of joystick in nunchuck_joyD
    ; bits for Console8 joystick compatability

    ld d, 255                       ; reset before we start. Tied high, so a direction will set to 0
    
    ld a, (_nunchuck_joyX)
    cp 110
    jr nc, j1                       ; if less than 110 then assume LEFT
    res 5,d 
j1:
    ld a, (_nunchuck_joyX)
    cp 140
    jr c, j2                        ; if bigger than 140 then assume RIGHT
    res 7,d 
j2:
    ld a, (_nunchuck_joyY)
    cp 110
    jr nc, j3                       ; if less than 110 then assume DOWN
    res 3,d 
j3:
    ld a, (_nunchuck_joyY)
    cp 140
    jr c, j4                        ; if bigger than 140 then assume UP
    res 1,d 
j4:
    ld a, d 
    ld (_nunchuck_joyD), a

	pop bc
	pop af
    pop iy
	pop ix

    ret 

; ---------------------------------------------------------------------------
;
; 	CLOSE NUNCHUCK I2C CONNECTION
;
; ---------------------------------------------------------------------------

_i2c_close:
	push af

	ld a, $20			; 
	rst.lil $08			; do moscall

    pop af
    ret 

; ---------------------------------------------------------------------------
;
; 	NUNCHUCK DATA
;
; ---------------------------------------------------------------------------

nunchuck_addr: 	equ $52     ; i2c bus address, default for most nunchuck devices

nunchuck_read_buffer:       ; max number of bytes read is 6
	.ds 6,0

nunchuck_write_buffer:       ; max number of bytes written is 2
	.ds 2,0


; global variables, thse can be read directly from C

_nunchuck_btnC:       .db     0
_nunchuck_btnZ:       .db     0

_nunchuck_joyX:       .db     0
_nunchuck_joyY:       .db     0

_nunchuck_joyD:       .db     0

_nunchuck_angleX:     .db     0
_nunchuck_angleY:     .db     0
_nunchuck_velocityZ:  .db     0

; ---------------------------------------------------------------------------
;
;   Useful extra routine for getting current screen display mode
;   But not needed for Nunchuck directly
;
; ---------------------------------------------------------------------------

_getDisplayMode:
	push ix 			; push ix onto the stack and allocate local frame
	push af

	ld hl, 0			; clear HL before returning value
	ld a, $08			; $08 is moscall for get sysvars pointer in IX
	rst.lil $08			; do moscall
	ld a, (ix + $27)	; screen mode sysvar
	ld l, a 			; store mode in L (lowest byte of UHL)

    pop af
	pop ix 				; restore ix from stack
	ret 				; return

; ---------------------------------------------------------------------------
;
; 	END
;
; ---------------------------------------------------------------------------







