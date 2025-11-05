#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_n vdu_set_logical_scr_dims = { 23, 0, 0xC0, 0 }; 

void vdp_logical_scr_dims( bool flag )
{
	vdu_set_logical_scr_dims.n = 0;
	if ( flag ) vdu_set_logical_scr_dims.n = 1;
	VDP_PUTS( vdu_set_logical_scr_dims );
}