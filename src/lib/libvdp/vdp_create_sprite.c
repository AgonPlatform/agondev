#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_A_B_CMD_n vdu_sprite_select;
extern VDU_A_B_CMD vdu_sprite_clear;
extern VDU_A_B_CMD_n vdu_sprite_add_bitmap;
extern VDU_A_B_CMD_n vdu_sprite_activate;

void vdp_create_sprite( int sprite, int bitmap_num, int frames )
{
	vdu_sprite_select.n = sprite;
	VDP_PUTS( vdu_sprite_select );
	VDP_PUTS( vdu_sprite_clear );
	for ( int i = 0; i < frames; i++ ) {
		vdu_sprite_add_bitmap.n = bitmap_num++;
		VDP_PUTS( vdu_sprite_add_bitmap );
	}
	vdu_sprite_activate.n = sprite;
	VDP_PUTS( vdu_sprite_activate );
}
