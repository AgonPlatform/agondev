#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_A_B_CMD vdu_sprite_clear;

void vdp_clear_sprite( void )
{
	VDP_PUTS( vdu_sprite_clear );
}
