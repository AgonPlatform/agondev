#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_FONT_B_B vdu_font_set_property = { 23, 0, 0x95, 2, 0, 0, 0 };

void vdp_font_set_property( int buffer_id, int field, int value )
{
	vdu_font_set_property.buffer_id = buffer_id;
	vdu_font_set_property.b0 = field;
	vdu_font_set_property.b1 = value;
	VDP_PUTS( vdu_font_set_property );
}