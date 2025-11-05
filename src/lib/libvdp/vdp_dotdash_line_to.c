#include <agon/vdp.h>

static VDU_A_CMD_x_y vdu_dotdash_line_to = { 25, 0x15, 0, 0 };

void vdp_dotdash_line_to( int x, int y ) {
	vdu_dotdash_line_to.x = x;
	vdu_dotdash_line_to.y = y;
	VDP_PUTS( vdu_dotdash_line_to );
}
