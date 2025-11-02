#include <agon/vdp_vdu.h>

static VDU_A_CMD_x_y vdu_filled_triangle = { 25, 0x55, 0, 0 };

void vdp_filled_triangle( int x1, int y1, int x2, int y2, int x3, int y3 ) {
	vdp_move_to(x1, y1);
	vdp_move_to(x2, y2);
	vdu_filled_triangle.x = x3;
	vdu_filled_triangle.y = y3;
	VDP_PUTS( vdu_filled_triangle );
}
