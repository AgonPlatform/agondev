#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_W	vdu_adv_add_sprite_bitmap = { 23, 27, 0x26, 0xFA00 };

// select bitmap for sprite using absolute numbered bitmaps (24-bit)
void vdp_adv_add_sprite_bitmap( int bitmap_num )
{
	vdu_adv_add_sprite_bitmap.w0 = bitmap_num;
	VDP_PUTS( vdu_adv_add_sprite_bitmap );
}