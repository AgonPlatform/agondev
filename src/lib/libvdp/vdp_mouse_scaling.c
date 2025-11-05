#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_MOUSE_B    vdu_mouse_scaling      = { 23, 0, 0x89, 8, 0 };

void vdp_mouse_scaling( int scaling )
{
	vdu_mouse_scaling.b0 = scaling;
	VDP_PUTS( vdu_mouse_scaling );
}