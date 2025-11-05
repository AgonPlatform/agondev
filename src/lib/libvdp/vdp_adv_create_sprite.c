#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_A_B_CMD_n vdu_sprite_select;
extern VDU_A_B_CMD vdu_sprite_clear;
extern VDU_A_B_CMD_n vdu_sprite_activate;

// create a sprite using absolute numbered bitmaps (24-bit)
void vdp_adv_create_sprite( int sprite, int bitmap_num, int frames )
{
	vdu_sprite_select.n = sprite;
	VDP_PUTS( vdu_sprite_select );
	VDP_PUTS( vdu_sprite_clear );
	for ( int i = 0; i < frames; i++ ) {
		vdp_adv_add_sprite_bitmap( bitmap_num++ );
	}
	vdu_sprite_activate.n = sprite;
	VDP_PUTS( vdu_sprite_activate );
}
