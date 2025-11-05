#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_CMD_x_y vdu_line_to = { 25, 0x05, 0, 0 };

void vdp_line_to( int x, int y )
{
	vdu_line_to.x = x;
	vdu_line_to.y = y;
	VDP_PUTS( vdu_line_to );
}
