#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_CMD_x_y vdu_circle_radius = { 25, 0x90, 0, 0 };

void vdp_circle_radius( int x, int y )
{
	vdu_circle_radius.x = x;
	vdu_circle_radius.y = y;
	VDP_PUTS( vdu_circle_radius );
}
