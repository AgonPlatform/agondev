		.assume	adl = 1	
		.text
		.global _kbuf_init
		.global _kbuf_deinit
		.global _kbuf_event_handler
		.global _kbuf_poll_event
		.global _kbuf_clear
		.xref _mos_setkbvector

_kbuf_init:
    pop de
    ex (sp), hl
    push de
    ld a, l
		; alloc 1 more buffer item than requested, since a sentinel index is used
		inc a
		ld (kbbuf_len),a
		; malloc len*4 bytes for buffer
		ld hl,0
		ld l,a
		add hl,hl
		add hl,hl
		push hl
		call _malloc
		ld (kbbuf_data),hl
		pop hl

		ld hl,0
		push hl
		ld hl,kbuf_event_handler
		push hl
		call _mos_setkbvector
		pop hl
		pop hl

		ret

_kbuf_deinit:
		ld hl,0
		push hl
		push hl
		call _mos_setkbvector
		pop hl
		pop hl

		ld hl,(kbbuf_data)
		push hl
		call _free
		pop hl

		ret

_kbuf_poll_event:
    pop de
    ex (sp), hl
    push de
    ex de, hl
		call kbuf_remove	
		ld a,0
		jr nz,.success
		ret
	.success:
		inc a
		ret

kbuf_event_handler:
		; keyboard packet address in `de`. (de+0) = ascii
		push af
		push bc
		push hl
		call kbuf_append
		pop hl
		pop bc
		pop af
		ret

kbuf_append:	; 4-byte value to append in (de). set `z` if no space
		; put (de)..(de+3) to (*kbbuf_data)[kbbuf_end_idx*4]
		ld hl,0
		ld a,(kbbuf_end_idx)
		ld l,a
		add hl,hl
		add hl,hl
		ld bc,(kbbuf_data)
		add hl,bc

		ex de,hl
		ld bc,4
		ldir

		ld a,(kbbuf_end_idx)
		inc a
		ld hl,kbbuf_len
		cp (hl)
		jr nz,1f
		xor a
	1:
		ld c,a

		ld a,(kbbuf_start_idx)
		cp c

		; if kbbuf_start_idx==kbbuf_end_idx+1 then no space for appending
		ret z
		
		; otherwise write new kbbuf_end_idx
		ld a,c
		ld (kbbuf_end_idx),a
		ret

; Take 1 event from the keyboard buffer (store to (de) struct keyboard_event_t*)
kbuf_remove:	; remove 4-byte value into (de)..(de+3). `z` flag set if no bytes in fifo
		call kbuf_isempty
		ret z

		add hl,hl
		add hl,hl
		ld bc,(kbbuf_data)
		add hl,bc
		ld bc,4
		ldir

		ld a,(kbbuf_start_idx)
		inc a
		ld hl,kbbuf_len
		cp (hl)
		jr nz,1f
		xor a
	1:
		ld (kbbuf_start_idx),a

		or 1		; clear `z` flag
		ret

kbuf_isempty:	; 'z' flag set if key buffer is empty
		ld hl,0
		ld a,(kbbuf_start_idx)
		ld l,a
		ld a,(kbbuf_end_idx)
		cp l
		ret

; Clear (flush) the keyboard buffer
_kbuf_clear:
		ld a,(kbbuf_end_idx)
		ld (kbbuf_start_idx),a
		ret

		.bss
kbbuf_len:		db 0
kbbuf_start_idx:	db 0
kbbuf_end_idx: 		db 0
kbbuf_data:		ds 3
