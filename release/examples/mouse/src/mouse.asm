	.assume	adl =1
	.include "agon/mos.inc"

	.section .text
	.global  _getsysvar_mouseX
	.global  _getsysvar_mouseY
	.global  _getsysvar_mouseButtons
	.global  _getsysvar_mouseWheel
	.global  _getsysvar_mouseXDelta
	.global  _getsysvar_mouseYDelta

sysvar_mouseX          :=  29h ; 2: Mouse X position
sysvar_mouseY          :=  2Bh ; 2: Mouse Y position
sysvar_mouseButtons    :=  2Dh ; 1: Mouse left+right+middle buttons (bits 0-2, 0=up, 1=down)
sysvar_mouseWheel      :=  2Eh ; 1: Mouse wheel delta
sysvar_mouseXDelta     :=  2Fh ; 2: Mouse X delta
sysvar_mouseYDelta     :=  31h ; 2: Mouse Y delta

_getsysvar_mouseX:
	push	ix
	ld	a, mos_sysvars
	rst.lil	08h
	ld hl,0
	ld	a, (ix+sysvar_mouseX)
	ld l, a
	ld	a, (ix+sysvar_mouseX+1)
	ld h, a
	pop	ix
	ret

_getsysvar_mouseY:
	push	ix
	ld	a, mos_sysvars
	rst.lil	08h
	ld hl,0
	ld	a, (ix+sysvar_mouseY)
	ld l, a
	ld	a, (ix+sysvar_mouseY+1)
	ld h, a
	pop	ix
	ret

_getsysvar_mouseButtons:
	push	ix
	ld	a, mos_sysvars
	rst.lil	08h
	ld	a, (ix+sysvar_mouseButtons)
	ld hl,0
	ld l, a
	pop	ix
	ret

_getsysvar_mouseWheel:
	push	ix
	ld	a, mos_sysvars
	rst.lil	08h
	ld	a, (ix+sysvar_mouseWheel)
	ld hl,0
	ld l, a
	pop	ix
	ret

_getsysvar_mouseXDelta:
	push	ix
	ld	a, mos_sysvars
	rst.lil	08h
	ld hl,0
	ld	a, (ix+sysvar_mouseXDelta)
	ld l, a
	ld	a, (ix+sysvar_mouseXDelta+1)
	ld h, a
	pop	ix
	ret

_getsysvar_mouseYDelta:
	push	ix
	ld	a, mos_sysvars
	rst.lil	08h
	ld hl,0
	ld	a, (ix+sysvar_mouseYDelta)
	ld l, a
	ld	a, (ix+sysvar_mouseYDelta+1)
	ld h, a
	pop	ix
	ret

