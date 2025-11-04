#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_n vdu_set_text_colour = { 17, 0 };

void vdp_set_text_colour( int colour )
{
	vdu_set_text_colour.n = colour;
	VDP_PUTS( vdu_set_text_colour );
}
