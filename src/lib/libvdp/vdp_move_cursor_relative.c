#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_x_y vdu_move_cursor_relative = { 23, 0, 0x8C, 0, 0 };

void vdp_move_cursor_relative( int x, int y )
{
	vdu_move_cursor_relative.x = x;
	vdu_move_cursor_relative.y = y;
	VDP_PUTS( vdu_move_cursor_relative );
}
