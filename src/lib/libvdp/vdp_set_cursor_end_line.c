#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_B vdu_set_cursor_end_line = { 23, 0, 0x0B, 0 }; 

void vdp_set_cursor_end_line( int n )
{
	vdu_set_cursor_end_line.b0 = n;
	VDP_PUTS( vdu_set_cursor_end_line );
}