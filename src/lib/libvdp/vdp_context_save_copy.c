#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_CONTEXT_B vdu_context_save_copy = { 23, 0, 0xC8, 5, 0 };

void vdp_context_save_copy( int context_id )
{
	vdu_context_save_copy.b0 = context_id;
	VDP_PUTS( vdu_context_save_copy );
}
