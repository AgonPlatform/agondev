#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_FONT vdu_font_copy   = { 23, 0, 0x95, 5, 0 };

void vdp_font_copy( int buffer_id )
{
	vdu_font_copy.buffer_id = buffer_id;
	VDP_PUTS( vdu_font_copy );
}
