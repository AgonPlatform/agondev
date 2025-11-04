#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD vdu_sprite_update = { 23, 27, 15 };

void vdp_refresh_sprites( void )
{
	VDP_PUTS( vdu_sprite_update );
}