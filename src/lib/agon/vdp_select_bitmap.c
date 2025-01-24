#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_n vdu_select_bitmap = { 23, 27, 0, 0 };

void vdp_select_bitmap( int n )
{
	vdu_select_bitmap.n = n;
	VDP_PUTS( vdu_select_bitmap );
}
