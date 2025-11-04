#include <agon/vdp_vdu.h>

static VDU_A_CMD_x_y vdu_move_rectangle = { 25, 0xBD, 0, 0 };

void vdp_move_rectangle( int src_x1, int src_y1, int src_x2, int src_y2, int dest_x, int dest_y ) {
	vdp_move_to(src_x1, src_y1);
	vdp_move_to(src_x2, src_y2);
	vdu_move_rectangle.x = dest_x;
	vdu_move_rectangle.y = dest_y;
	VDP_PUTS( vdu_move_rectangle );
}
