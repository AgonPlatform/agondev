#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern volatile SYSVAR *sys_vars;

static VDU_A_B_CMD_B vdu_request_palette_entry = { 23, 0, 0x94, 0 };

void vdp_request_palette_entry( int n, bool wait )
{
	if ( !sys_vars ) vdp_vdu_init();
	if ( wait ) sys_vars->vdp_pflags = 0;

	vdu_request_palette_entry.b0 = n;
	VDP_PUTS( vdu_request_palette_entry );

	if ( wait ) while ( !(sys_vars->vdp_pflags & vdp_pflag_point) );
}