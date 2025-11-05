#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_MOUSE_W    vdu_mouse_acceleration = { 23, 0, 0x89, 9, 0 };

void vdp_mouse_acceleration( int acceleration )
{
	vdu_mouse_acceleration.w0 = acceleration;
	VDP_PUTS( vdu_mouse_acceleration );
}