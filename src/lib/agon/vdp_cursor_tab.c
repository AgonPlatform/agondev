#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_c_r vdu_cursor_tab = { 31, 0, 0 };

// rg: fixed this so it is X, Y
void vdp_cursor_tab( int col, int row )
{
	vdu_cursor_tab.c = col;
	vdu_cursor_tab.r = row;
	VDP_PUTS( vdu_cursor_tab );
}
