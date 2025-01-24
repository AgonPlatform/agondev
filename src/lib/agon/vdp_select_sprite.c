#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_A_B_CMD_n vdu_sprite_select;

void vdp_select_sprite( int n )
{
	vdu_sprite_select.n = n;
	VDP_PUTS( vdu_sprite_select );
}
