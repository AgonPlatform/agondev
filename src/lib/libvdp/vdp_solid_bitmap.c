#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_x_y_rgba vdu_solid_bitmap = { 23, 27, 2, 0, 0, 0, 0, 0, 0 };

void vdp_solid_bitmap( int width, int height, int r, int g, int b, int a )
{
	vdu_solid_bitmap.x = width;
	vdu_solid_bitmap.y = height;
	vdu_solid_bitmap.r = r;
	vdu_solid_bitmap.g = g;
	vdu_solid_bitmap.b = b;
	vdu_solid_bitmap.a = a;
	VDP_PUTS( vdu_solid_bitmap );
}