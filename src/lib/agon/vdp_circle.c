#include <agon/vdp_vdu.h>

static VDU_A_CMD_x_y vdu_circle = { 25, 0x94, 0, 0 }; // Move to absolute coordinate, use a circle center, outline circle
static VDU_A_CMD_x_y vdu_radius = { 25, 0x91, 0, 0 }; // Use relative coordinate on circumference, draw foreground color on outline circle

void vdp_circle( int x, int y, int radius ) {
	vdu_circle.x = x;
	vdu_circle.y = y;
	vdu_radius.x = radius;
	vdu_radius.y = radius;
	VDP_PUTS( vdu_circle );
	VDP_PUTS( vdu_radius );
}