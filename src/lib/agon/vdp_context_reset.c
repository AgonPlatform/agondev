#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_CONTEXT_B vdu_context_reset = { 23, 0, 0xC8, 2, 0 };

void vdp_context_reset( int flags )
{
	vdu_context_reset.b0 = flags;
	VDP_PUTS( vdu_context_reset );
}