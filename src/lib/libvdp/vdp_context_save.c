#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_CONTEXT vdu_context_save = { 23, 0, 0xC8, 3 };

void vdp_context_save( void )
{
	VDP_PUTS( vdu_context_save );
}
