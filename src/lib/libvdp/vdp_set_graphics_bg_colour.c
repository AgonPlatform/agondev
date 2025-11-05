#include <agon/vdp_vdu.h>
#include <stdint.h>

static VDU_A_c_r vdu_set_graphics_bg_colour = { 18, 0, 0 };

void vdp_set_graphics_bg_colour( uint8_t mode, uint8_t colour )
{
	vdu_set_graphics_bg_colour.c = mode;
	vdu_set_graphics_bg_colour.r = colour + 128;
	VDP_PUTS( vdu_set_graphics_bg_colour );
}
