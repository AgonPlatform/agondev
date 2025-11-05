#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_CMD_x_y vdu_point = { 25, 0x45, 0, 0 };

void vdp_point( int x, int y )
{
	vdu_point.x = x;
	vdu_point.y = y;
	VDP_PUTS( vdu_point );
}
