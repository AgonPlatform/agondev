#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_a_b_c_d vdu_set_text_viewport = { 28, 0, 0, 0, 0 };

void vdp_set_text_viewport( int left, int bottom, int right, int top )
{
	vdu_set_text_viewport.a = left;
	vdu_set_text_viewport.b = bottom;
	vdu_set_text_viewport.c = right;
	vdu_set_text_viewport.d = top;
	VDP_PUTS( vdu_set_text_viewport );
}