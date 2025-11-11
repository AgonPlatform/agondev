#include <agon/vdp.h>

static VDU_A_CMD_x_y vdu_plot_bitmap = { 25, 0xED, 0, 0 };

void vdp_plot_bitmap( int x, int y ) {
	vdu_plot_bitmap.x = x;
	vdu_plot_bitmap.y = y;
	VDP_PUTS( vdu_plot_bitmap );
}
