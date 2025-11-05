#include <agon/vdp.h>

static VDU_A_CMD_x_y vdu_line_fill_leftright_to_fg = { 25, 0x6D, 0, 0 };

void vdp_line_fill_leftright_to_fg( int x, int y ) {
	vdu_line_fill_leftright_to_fg.x = x;
	vdu_line_fill_leftright_to_fg.y = y;
	VDP_PUTS( vdu_line_fill_leftright_to_fg );
}
