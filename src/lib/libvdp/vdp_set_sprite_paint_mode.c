#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_n vdu_set_sprite_paint_mode = { 23, 27, 18, 0 };

void vdp_set_sprite_paint_mode( int n )
{
	vdu_set_sprite_paint_mode.n = n;
	VDP_PUTS( vdu_set_sprite_paint_mode );
}
