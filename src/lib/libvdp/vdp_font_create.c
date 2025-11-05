#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_FONT_B_B_B_B vdu_font_create = { 23, 0, 0x95, 1, 0, 0, 0, 0, 0 };

void vdp_font_create( int buffer_id, int width, int height, int ascent, int flags )
{
	vdu_font_create.buffer_id = buffer_id;
	vdu_font_create.b0 = width;
	vdu_font_create.b1 = height;
	vdu_font_create.b2 = ascent;
	vdu_font_create.b3 = flags;
	VDP_PUTS( vdu_font_create );
}