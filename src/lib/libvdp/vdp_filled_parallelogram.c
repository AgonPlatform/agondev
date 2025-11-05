#include <agon/vdp.h>

static VDU_A_CMD_x_y vdu_filled_parallelogram = { 25, 0x75, 0, 0 };

void vdp_filled_parallelogram( int x1, int y1, int x2, int y2, int x3, int y3) {
    vdp_move_to(x1, y1);
    vdp_move_to(x2, y2);
	vdu_filled_parallelogram.x = x3;
	vdu_filled_parallelogram.y = y3;
	VDP_PUTS( vdu_filled_parallelogram );
}
