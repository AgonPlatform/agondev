#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_a_b_c_d vdu_scroll_screen_extent = { 23, 7, 1, 0, 0};

// extent 0 = current text viewport, 1 = whole screen, 2 = current graphics viewport, 3 = active viewport 
void vdp_scroll_screen_extent( int extent, int direction, int speed )
{
	vdu_scroll_screen_extent.b = extent;
	vdu_scroll_screen_extent.c = direction;
	vdu_scroll_screen_extent.d = speed;
	VDP_PUTS( vdu_scroll_screen_extent );
}