#include <agon/vdp.h>
#include <stdint.h>

static VDU_A_c_r vdu_set_graphics_fg_colour = { 18, 0, 0 };

void vdp_set_graphics_fg_colour( uint8_t mode, uint8_t colour )
{
	vdu_set_graphics_fg_colour.c = mode;
	vdu_set_graphics_fg_colour.r = colour;
	VDP_PUTS( vdu_set_graphics_fg_colour );
}
