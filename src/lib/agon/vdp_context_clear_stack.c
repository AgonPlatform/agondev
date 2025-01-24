#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_CONTEXT vdu_context_clear_stack = { 23, 0, 0xC8, 7 };

void vdp_context_clear_stack( void )
{
	VDP_PUTS( vdu_context_clear_stack );
}