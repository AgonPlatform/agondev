#include <agon/vdp_vdu.h>

static VDU_A_CMD_x_y vdu_filled_rectangle = { 25, 0x65, 0, 0 };

void vdp_filled_rectangle( int x1, int y1, int x2, int y2 ) {
    vdp_move_to(x1, y1);
	vdu_filled_rectangle.x = x2;
	vdu_filled_rectangle.y = y2;
	VDP_PUTS( vdu_filled_rectangle );
}
