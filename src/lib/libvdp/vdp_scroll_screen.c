#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_a_b_c_d vdu_scroll_screen = { 23, 7, 1, 0, 0};

void vdp_scroll_screen( int direction, int speed )
{
	vdu_scroll_screen.b = 1; // whole screen
	vdu_scroll_screen.c = direction;
	vdu_scroll_screen.d = speed;
	VDP_PUTS( vdu_scroll_screen );
}