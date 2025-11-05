#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_B vdu_legacy_modes = { 23, 0, 0xC1, 0 };

void vdp_legacy_modes( bool on )
{
	vdu_legacy_modes.b0 = on;
	VDP_PUTS( vdu_legacy_modes );
}