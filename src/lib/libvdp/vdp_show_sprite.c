#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD vdu_sprite_show = { 23, 27, 11 };

void vdp_show_sprite( void )
{
	VDP_PUTS( vdu_sprite_show );
}
