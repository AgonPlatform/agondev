#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_FONT vdu_font_select = { 23, 0, 0x95, 0, 0 };

void vdp_font_select( int buffer_id )
{
	vdu_font_select.buffer_id = buffer_id;
	VDP_PUTS( vdu_font_select );
}