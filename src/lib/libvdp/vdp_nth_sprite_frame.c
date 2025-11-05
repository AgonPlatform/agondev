#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_n vdu_sprite_nth_frame = { 23, 27, 10, 0 };

void vdp_nth_sprite_frame( int n )
{
	vdu_sprite_nth_frame.n = n;
	VDP_PUTS( vdu_sprite_nth_frame );
}
