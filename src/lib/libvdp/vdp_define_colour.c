#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_l_p_r_g_b vdu_define_colour = { 19, 0, 0, 0, 0, 0 };

void vdp_define_colour(int logical, int physical, int red, int green, int blue )
{
	vdu_define_colour.l = logical;
	vdu_define_colour.p = physical;
	vdu_define_colour.r = red;
	vdu_define_colour.g = green;
	vdu_define_colour.b = blue;
	VDP_PUTS( vdu_define_colour );
}
