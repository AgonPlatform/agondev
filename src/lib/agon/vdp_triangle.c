#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_CMD_x_y vdu_triangle = { 25, 0x50, 0, 0 };

void vdp_triangle( int x, int y )
{
	vdu_triangle.x = x;
	vdu_triangle.y = y;
	VDP_PUTS( vdu_triangle );
}
