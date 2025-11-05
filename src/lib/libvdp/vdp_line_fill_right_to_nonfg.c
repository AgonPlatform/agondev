#include <agon/vdp.h>

static VDU_A_CMD_x_y vdu_line_fill_right_to_nonfg = { 25, 0x7D, 0, 0 };

void vdp_line_fill_right_to_nonfg( int x, int y ) {
	vdu_line_fill_right_to_nonfg.x = x;
	vdu_line_fill_right_to_nonfg.y = y;
	VDP_PUTS( vdu_line_fill_right_to_nonfg );
}
