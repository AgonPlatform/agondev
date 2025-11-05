#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_MOUSE_WW   vdu_mouse_wheel_accel  = { 23, 0, 0x89, 10, 0 };

void vdp_mouse_wheel_accel( int wheelAccel )
{
	vdu_mouse_wheel_accel.ww0 = wheelAccel;
	VDP_PUTS( vdu_mouse_wheel_accel );
}
