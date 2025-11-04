#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_CMD_x_y vdu_move_to = { 25, 0x04, 0, 0 };

void vdp_move_to( int x, int y )
{
	vdu_move_to.x = x;
	vdu_move_to.y = y;
	VDP_PUTS( vdu_move_to );
}
