#include <agon/vdp.h>

static VDU_A_CMD_x_y vdu_sector = { 25, 0xB5, 0, 0 };

void vdp_sector( int centre_x, int centre_y, int x1, int y1, int x2, int y2) {
    vdp_move_to(centre_x, centre_y);
    vdp_move_to(x1, y1);
	vdu_sector.x = x2;
	vdu_sector.y = y2;
	VDP_PUTS( vdu_sector );
}
