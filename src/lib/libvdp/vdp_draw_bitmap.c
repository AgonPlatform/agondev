#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_x_y vdu_draw_bitmap = { 23, 27, 3, 0, 0 };

void vdp_draw_bitmap( int x, int y )
{
	vdu_draw_bitmap.x = x;
	vdu_draw_bitmap.y = y;
	VDP_PUTS( vdu_draw_bitmap );
}