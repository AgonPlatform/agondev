#include <agon/vdp.h>

static VDU_A_CMD_x_y vdu_arc = { 25, 0xA5, 0, 0 };

void vdp_arc( int centre_x, int centre_y, int x1, int y1, int x2, int y2) {
    vdp_move_to(centre_x, centre_y);
    vdp_move_to(x1, y1);
	vdu_arc.x = x2;
	vdu_arc.y = y2;
	VDP_PUTS( vdu_arc );
}
