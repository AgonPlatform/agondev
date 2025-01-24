#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_CMD_x_y vdu_circle = { 25, 0x94, 0, 0 };

void vdp_circle( int x, int y )
{
	vdu_circle.x = x;
	vdu_circle.y = y;
	VDP_PUTS( vdu_circle );
}