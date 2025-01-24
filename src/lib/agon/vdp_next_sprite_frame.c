#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD vdu_sprite_next_frame = { 23, 27, 8 };

void vdp_next_sprite_frame( void )
{
	VDP_PUTS( vdu_sprite_next_frame );
}
