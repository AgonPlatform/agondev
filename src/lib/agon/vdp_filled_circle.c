#include <agon/vdp_vdu.h>

static VDU_A_CMD_x_y vdu_filled_circle = { 25, 0x9C, 0, 0 }; // Move to absolute coordinate, use a circle center, filled circle
static VDU_A_CMD_x_y vdu_filled_radius = { 25, 0x99, 0, 0 }; // Use relative coordinate on circumference, draw foreground color on filled circle

void vdp_filled_circle( int x, int y, int radius ) {
	vdu_filled_circle.x = x;
	vdu_filled_circle.y = y;
	vdu_filled_radius.x = radius;
    vdu_filled_radius.y = 0;
	VDP_PUTS( vdu_filled_circle );
	VDP_PUTS( vdu_filled_radius );
}