#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD vdu_sprite_only_reset = { 23, 27, 17 };

void vdp_reset_sprites_only( void )
{
	VDP_PUTS( vdu_sprite_only_reset );
}
