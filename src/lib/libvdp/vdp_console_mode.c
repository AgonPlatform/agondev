#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_B vdu_console_mode = { 23, 0, 0xFE, 0 };

void vdp_console_mode( bool on )
{
	vdu_console_mode.b0 = on;
	VDP_PUTS( vdu_console_mode );
}