#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_B vdu_control_keys = { 23, 0, 0x98, 0 };

void vdp_control_keys( bool on )
{
	vdu_control_keys.b0 = on;
	VDP_PUTS( vdu_control_keys );
}
