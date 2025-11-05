#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

extern volatile SYSVAR *sys_vars;

static VDU_A_B_CMD_x_y vdu_get_ascii_code_at_graphics_position = { 23, 0, 0x93, 0, 0 }; 

void vdp_request_ascii_code_at_graphics_position( int x, int y, bool wait )
{
	if ( !sys_vars ) vdp_vdu_init();
	if ( wait ) sys_vars->vdp_pflags = 0;

	vdu_get_ascii_code_at_graphics_position.x = x;
	vdu_get_ascii_code_at_graphics_position.y = y;
	VDP_PUTS( vdu_get_ascii_code_at_graphics_position );
	if ( wait ) while ( !(sys_vars->vdp_pflags & vdp_pflag_scrchar) );
}