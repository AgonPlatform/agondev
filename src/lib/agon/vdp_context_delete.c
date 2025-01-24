#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_CONTEXT_B vdu_context_delete = { 23, 0, 0xC8, 1, 0 };

void vdp_context_delete( int context_id )
{
	vdu_context_delete.b0 = context_id;
	VDP_PUTS( vdu_context_delete );
}