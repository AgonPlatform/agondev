#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_CMD_n vdu_cursor_enable = { 23, 1, 0 };

void vdp_cursor_enable( bool flag )
{
	vdu_cursor_enable.n = 0;
	if ( flag ) vdu_cursor_enable.n = 1;
	VDP_PUTS( vdu_cursor_enable );
}
