#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_c_r vdu_set_graphics_colour = { 18, 0, 0 };

void vdp_set_graphics_colour( uint8_t mode, uint8_t colour )
{
	vdu_set_graphics_colour.c = mode;
	vdu_set_graphics_colour.r = colour;
	VDP_PUTS( vdu_set_graphics_colour );
}
