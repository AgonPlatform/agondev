#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_B vdu_set_cursor_end_column = { 23, 0, 0x8B, 0 }; 

void vdp_set_cursor_end_column( int n )
{
	vdu_set_cursor_end_column.b0 = n;
	VDP_PUTS( vdu_set_cursor_end_column );
}