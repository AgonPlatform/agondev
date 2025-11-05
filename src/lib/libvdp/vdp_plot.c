#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_CMD_x_y vdu_plot = { 25, 0, 0, 0 };

// generic plot command - needs plot-mode
void vdp_plot( int plot_mode, int x, int y )
{
	vdu_plot.CMD = plot_mode;
	vdu_plot.x = x;
	vdu_plot.y = y;
	VDP_PUTS( vdu_plot );
}
