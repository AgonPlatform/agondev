#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_CMD_x_y vdu_filled_rect = { 25, 0x65, 0, 0 };

void vdp_filled_rect( int x, int y )
{
	vdu_filled_rect.x = x;
	vdu_filled_rect.y = y;
	VDP_PUTS( vdu_filled_rect );
}
