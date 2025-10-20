#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_c_r vdu_cursor_tab = { 31, 0, 0 };

// rg: fixed this so it is X, Y
// jv: fixed the naming of the input variables to reflect x,y
void vdp_cursor_tab( int xpos, int ypos )
{
	vdu_cursor_tab.c = xpos;
	vdu_cursor_tab.r = ypos;
	VDP_PUTS( vdu_cursor_tab );
}
