#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_FONT_B_B vdu_font_adjust = { 23, 0, 0x95, 2, 0, 0, 0};

 // VDU 23, 0, &95, 2, bufferId; field, value;: Set or adjust font property
void vdp_font_adjust( int buffer_id, int field, int value ) {
	vdu_font_adjust.buffer_id = buffer_id;
	vdu_font_adjust.b0 = field;
	vdu_font_adjust.b1 = value;
	VDP_PUTS( vdu_font_adjust );
}
