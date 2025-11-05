#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD vdu_sprite_reset = { 23, 27, 16 };

void vdp_reset_sprites( void )
{
	VDP_PUTS( vdu_sprite_reset );
}