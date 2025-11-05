#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_CONTEXT vdu_context_restore_all = { 23, 0, 0xC8, 6 };

void vdp_context_restore_all( void )
{
	VDP_PUTS( vdu_context_restore_all );
}