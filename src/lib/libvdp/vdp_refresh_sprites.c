#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD vdu_sprite_update = { 23, 27, 15 };

void vdp_refresh_sprites( void )
{
	VDP_PUTS( vdu_sprite_update );
}