#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_x_y vdu_sprite_moveto = { 23, 27, 13, 0, 0 };

void vdp_move_sprite_to( int x, int y )
{
	vdu_sprite_moveto.x = x;
	vdu_sprite_moveto.y = y;
	VDP_PUTS( vdu_sprite_moveto );
}