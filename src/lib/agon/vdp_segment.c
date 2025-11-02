#include <agon/vdp_vdu.h>

static VDU_A_CMD_x_y vdu_segment = { 25, 0xAD, 0, 0 };

void vdp_segment( int centre_x, int centre_y, int x1, int y1, int x2, int y2) {
    vdp_move_to(centre_x, centre_y);
    vdp_move_to(x1, y1);
	vdu_segment.x = x2;
	vdu_segment.y = y2;
	VDP_PUTS( vdu_segment );
}
