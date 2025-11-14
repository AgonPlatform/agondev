;	get current screen mode from sysvars

	.global _i2c_sendAdcConfig
	.global _i2c_readAdc
	.assume ADL=1
	.text

; ------------------------------------------------
; define configuration defaults. See later notes for bits used for each setting

i2c_address:        equ $48           ; either: $48, $49, $4A or $4B

ADS_input_channel:  .db 0b01000000     ; either: 01000000b, 01010000b, 01100000b, 01110000b for A0-A3 single inputs

ADS_channel0:       equ 0b01000000     ; defined here for use later is needed
ADS_channel1:       equ 0b01010000     ; these values are for sinlge channel reads
ADS_channel2:       equ 0b01100000
ADS_channel3:       equ 0b01110000

ADS_adc_gain:       equ 0b00000010     ; this is the range of the read result
                                      ; assuming 3.3v   value is from $00-$XX (MSB)
                                      ; 00000000b, scale = 6.1v scale $00-$43 (at full turn)
                                      ; 00000010b, scale = 4.1v scale $00-$65 (at full turn)
                                      ; 00000100b, scale = 2.0v scale $00-$7F (max at about 2/3 turn)
                                      ; 00000110b, scale = 1.0v scale $00-$7F (max at about 1/3 turn)
                                      ; or possible but not useful: 00001000b, 00001010b, 00001100b or 00001110b

ADS_sample_rate:    equ 0b10100000     ; either: 000 to 111 at bits 7-5

ADS_comparitor:     equ 0b00000011     ; from: 00-11. 11 is turned off

ADS_configReg:      equ 0b00000001     ; command to set configuration register
    
ADS_conversionReg:  equ 0b00000000     ; memory address for conversion register (readings)

; ------------------------------------------------

_i2c_sendAdcConfig:

	push ix 			; push ix onto the stack and allocate local frame
	ld ix, 0 			;	
	add ix, sp 			; set ix to sp


  	ld hl, i2c_write_buffer         ; the data to send is stored at HL

    ; We send 3 configuration bytes, which are stored at 'i2c_write_buffer', pointed to by HL
    ; 1st byte says we are writing to the Config register
    ; 2nd and 3rd bytes are the actual configuration data


    ; 1st Byte
    ld (hl), ADS_configReg	        ; state that we are sending to config register   
    inc hl                          ; point HL ready for next storage byte

    ; 2nd Byte - Write the MSB of Config Register Bits 15:8
    ; Bit  15      0=No effect, 1=Begin Single Conversion (in power down mode)
    ; Bits 14:12   Input channel: How to configure A0 to A3 (comparitor or single ended)
    ; Bits 11:9    Programmable Gain 000=6.144v 001=4.096v 010=2.048v.. 111=0.256v
    ; Bit  8       0=Continuous conversion mode, 1=Power down single shot

    ld a, (ADS_input_channel)       ; input value
    or ADS_adc_gain                 ; add the gain value
    ld (hl), a                      ; 2nd byte is MSB of Config reg to write 
    inc hl                          ; point HL ready for next storage byte

    ; 3rd Byte - Write the LSB of Config Register Bits 7:
    ; Bits 7:5 Data Rate (Samples per second) 000=8, 001=16, 010=32, 011=64
    ;          100=128, 101=250, 110=475, 111=860
    ; Bit  4   Comparitor Mode 0=Traditional, 1=Window
    ; Bit  3   Comparitor Polarity 0=low, 1=high
    ; Bit  2   Latching 0=No, 1=Yes
    ; Bits 1:0 Comparitor # before Alert pin goes high
    ;          00=1, 01=2, 10=4, 11=Disable this feature

    ld a, ADS_sample_rate           ; set to sample rate
    or ADS_comparitor               ; add compartor (disable)
                                    ; ignore bits 2-4, leave at 0
    ld (hl), a                      ; 3rd byte is LSB of Config reg to write

                                    ; send the 3 bytes
    ld c, i2c_address               ; i2c address ($48 is default)
    ld b, 3                         ; number of bytes to send
    ld hl, i2c_write_buffer         ; set HL to start of data to send
	
	ld a, $21			; $21 is moscall for i2c send
	rst.lil $08			; do moscall


	ld sp, ix 			; set sp to ix
	pop ix 				; restore ix from stack
	ret 				; return

; ------------------------------------------------

_i2c_readAdc:
	push ix 			; push ix onto the stack and allocate local frame
	ld ix, 0 			;	
	add ix, sp 			; set ix to sp
	push ix 
	
	                                    ; first, write to the Address Pointer register
    ld c, i2c_address               ; i2c address (default $48)
    ld b, 1                         ; number of bytes to send
    ld hl, i2c_write_buffer         ; 'i2c_write_buffer' is where data to be sent is stored
    ld (hl), ADS_conversionReg      ; sending $00 says we want to read from the conversion register

	ld a, $21						; $21 is moscall for i2c send
	rst.lil $08						; do moscall

    ld a, 0b00000100                     
    call multiPurposeDelay          ; wait a bit or results tend to be incorrect

    ld c, i2c_address   		    ; i2c address (default $48)
    ld b,2			                ; number of bytes to receive
    ld hl, i2c_read_buffer          ; results to get stored here

	ld a, $22						; $22 is moscall for read i2c
	rst.lil $08						; do moscall

	ld a, (i2c_read_buffer)
	ld h, a
	ld a, (i2c_read_buffer + 1)
	ld l, a							; et values into HL for return
   
	pop ix
	ld sp, ix 			; set sp to ix
	pop ix 				; restore ix from stack
	ret 				; return

; ---------------------------------------------

; routine waits a fixed time, then returns

multiPurposeDelay:	            		
	push bc 

				; arrive with A =  the delay byte. One bit to be set only.
	ld b, a 
	ld a, $08			; $08 is moscall for get sysvars
	rst.lil $08			; do moscall
	;MOSCALL $08             ; get IX pointer to sysvars

waitLoop:

	ld a, (ix + 0)          ; ix+0h is lowest byte of clock timer

				; need to check if bit set is same as last time we checked.
				;   bit 0 - changes 128 times per second
				;   bit 1 - changes 64 times per second
				;   bit 2 - changes 32 times per second
				;   bit 3 - changes 16 times per second

				;   bit 4 - changes 8 times per second
				;   bit 5 - changes 4 times per second
				;   bit 6 - changes 2 times per second
				;   bit 7 - changes 1 times per second
				; eg. and 00000010b           ; check 1 bit only
	and b 
	ld c,a 
   	ld a, (oldTimeStamp)
  	cp c                    ; is A same as last value?
	jr z, waitLoop   	; loop here if it is
 	ld a, c 
 	ld (oldTimeStamp), a    ; set new value

 	pop bc
 	ret

oldTimeStamp:   .db 00h

; ------------------------------------------------
; reserved data here

i2c_read_buffer:		            ; to store data sent and recieved to i2c
    .ds 32,0

i2c_write_buffer:
    .ds 32,0

