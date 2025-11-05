#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

extern volatile SYSVAR *sys_vars;

static VDU_A_B_CMD_x_y vdu_request_pixel_colour = { 23, 0, 0x84, 0, 0 }; 

void vdp_request_pixel_colour( int x, int y, bool wait )
{
	if ( !sys_vars ) vdp_vdu_init();
	if ( wait ) sys_vars->vdp_pflags = 0;

	vdu_request_pixel_colour.x = x;
	vdu_request_pixel_colour.y = y;
	VDP_PUTS( vdu_request_pixel_colour );
	if ( wait ) while ( !(sys_vars->vdp_pflags & vdp_pflag_point) );
}