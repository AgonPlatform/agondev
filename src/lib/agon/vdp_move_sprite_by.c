#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_x_y vdu_sprite_moveby = { 23, 27, 14, 0, 0 };

void vdp_move_sprite_by( int x, int y )
{
	vdu_sprite_moveby.x = x;
	vdu_sprite_moveby.y = y;
	VDP_PUTS( vdu_sprite_moveby );
}