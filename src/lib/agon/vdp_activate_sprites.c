#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_A_B_CMD_n vdu_sprite_activate;

void vdp_activate_sprites( int n )
{
	vdu_sprite_activate.n = n;
	VDP_PUTS( vdu_sprite_activate );
}