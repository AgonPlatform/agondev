#include <agon/vdp_vdu.h>

static VDU_A_CMD_x_y vdu_line_fill_right_to_bg = { 25, 0x5D, 0, 0 };

void vdp_line_fill_right_to_bg( int x, int y ) {
	vdu_line_fill_right_to_bg.x = x;
	vdu_line_fill_right_to_bg.y = y;
	VDP_PUTS( vdu_line_fill_right_to_bg );
}
