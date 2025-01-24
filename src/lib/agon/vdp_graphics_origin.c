#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_x_y vdu_graphics_origin = { 29, 0, 0 };

void vdp_graphics_origin( int x, int y )
{
	vdu_graphics_origin.x = x;
	vdu_graphics_origin.y = y;
	VDP_PUTS( vdu_graphics_origin );
}
