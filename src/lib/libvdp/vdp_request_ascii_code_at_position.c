#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_x_y vdu_get_ascii_code_at_position = { 23, 0, 0x83, 0, 0 }; 

void vdp_request_ascii_code_at_position( int x, int y, bool wait )
{
	if ( wait ) sys_vars->vdp_pflags = 0;
	
	vdu_get_ascii_code_at_position.x = x;
	vdu_get_ascii_code_at_position.y = y;
	VDP_PUTS( vdu_get_ascii_code_at_position );
	if ( wait ) while ( !(sys_vars->vdp_pflags & vdp_pflag_scrchar) );
}
