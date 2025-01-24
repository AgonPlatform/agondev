#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_MOUSE_W_W  vdu_mouse_set_position = { 23, 0, 0x89, 4, 0, 0 };


void vdp_mouse_set_position( int X, int Y )
{
	vdu_mouse_set_position.w0 = X;
	vdu_mouse_set_position.w1 = Y;
	VDP_PUTS( vdu_mouse_set_position );
}
