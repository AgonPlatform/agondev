#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_W_W_B vdu_adv_bitmap_from_buffer = { 23, 27, 0x21, 0, 0, 0 };

void vdp_adv_bitmap_from_buffer( int width, int height, int format )
{
	vdu_adv_bitmap_from_buffer.w0 = width;
	vdu_adv_bitmap_from_buffer.w1 = height;
	vdu_adv_bitmap_from_buffer.b2 = format;
	VDP_PUTS( vdu_adv_bitmap_from_buffer );
}
