#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD vdu_get_text_cursor_position = { 23, 0, 0x82 }; 

extern volatile SYSVAR *sys_vars;

void vdp_request_text_cursor_position( bool wait )
{
	if ( !sys_vars ) vdp_vdu_init();
	if ( wait ) sys_vars->vdp_pflags = 0;

	VDP_PUTS( vdu_get_text_cursor_position );
	// wait for results to be reflected in SYSVARs
	if ( wait ) while ( !(sys_vars->vdp_pflags & vdp_pflag_cursor) );
}