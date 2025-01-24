#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_ui16x4 vdu_set_graphics_viewport = { 24, 0, 0, 0, 0 };

void vdp_set_graphics_viewport( int left, int bottom, int right, int top )
{
	vdu_set_graphics_viewport.w0 = left;
	vdu_set_graphics_viewport.w1 = bottom;
	vdu_set_graphics_viewport.w2 = right;
	vdu_set_graphics_viewport.w3 = top;
	VDP_PUTS( vdu_set_graphics_viewport );
}