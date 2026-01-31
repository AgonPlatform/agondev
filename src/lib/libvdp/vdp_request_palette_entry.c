#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_B vdu_request_palette_entry = { 23, 0, 0x94, 0 };

void vdp_request_palette_entry( int n, bool wait )
{
	if ( wait ) sys_vars->vdp_pflags = 0;

	vdu_request_palette_entry.b0 = n;
	VDP_PUTS( vdu_request_palette_entry );

	if ( wait ) while ( !(sys_vars->vdp_pflags & vdp_pflag_point) );
}
