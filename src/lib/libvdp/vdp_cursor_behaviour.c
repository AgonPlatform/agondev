#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_CMD_a_b vdu_cursor_behaviour = { 23, 16, 0, 0 };

void vdp_cursor_behaviour( int setting, int mask )
{
	vdu_cursor_behaviour.a = setting;
	vdu_cursor_behaviour.b = mask;
	VDP_PUTS( vdu_cursor_behaviour );
}
