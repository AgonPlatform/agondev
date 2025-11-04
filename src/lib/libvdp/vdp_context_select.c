#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_CONTEXT_B vdu_context_select = { 23, 0, 0xC8, 0, 0 };

void vdp_context_select( int context_id )
{
	vdu_context_select.b0 = context_id;
	VDP_PUTS( vdu_context_select );
}
