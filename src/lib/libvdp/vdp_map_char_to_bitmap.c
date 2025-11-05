#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_B_W vdu_map_char_to_bitmap = { 23, 0, 0x92, 0, 0 };

void vdp_map_char_to_bitmap( int char_num, int bitmap_num )
{
	vdu_map_char_to_bitmap.b0 = char_num;
	vdu_map_char_to_bitmap.w1 = bitmap_num;
	VDP_PUTS( vdu_map_char_to_bitmap );
}
