#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD vdu_sprite_prev_frame = { 23, 27, 9 };

void vdp_prev_sprite_frame( void )
{
	VDP_PUTS( vdu_sprite_prev_frame );
}
