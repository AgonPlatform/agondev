#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_MOUSE_B    vdu_mouse_resolution   = { 23, 0, 0x89, 7, 0 };

void vdp_mouse_resolution( int resolution )
{
	vdu_mouse_resolution.b0 = resolution;
	VDP_PUTS( vdu_mouse_resolution );
}