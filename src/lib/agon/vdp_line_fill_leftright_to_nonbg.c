#include <agon/vdp_vdu.h>

static VDU_A_CMD_x_y vdu_line_fill_leftright_to_nonbg = { 25, 0x4D, 0, 0 };

void vdp_line_fill_leftright_to_nonbg( int x, int y ) {
	vdu_line_fill_leftright_to_nonbg.x = x;
	vdu_line_fill_leftright_to_nonbg.y = y;
	VDP_PUTS( vdu_line_fill_leftright_to_nonbg );
}
