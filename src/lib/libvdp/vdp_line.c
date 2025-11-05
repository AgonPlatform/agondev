#include <agon/vdp.h>

static VDU_A_CMD_x_y vdu_line = { 25, 0x05, 0, 0 };

void vdp_line(int x1, int y1, int x2, int y2) {
    vdp_move_to(x1, y1);
	vdu_line.x = x2;
	vdu_line.y = y2;
	VDP_PUTS( vdu_line );
}