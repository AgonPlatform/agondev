#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern volatile SYSVAR *sys_vars;

static VDU_A_B_CMD_x_y vdu_return_ascii_code_at_graphics_position = { 23, 0, 0x93, 0, 0 }; 

uint8_t vdp_return_ascii_code_at_graphics_position( int x, int y )
{
	uint8_t code = 0;

	if ( !sys_vars ) vdp_vdu_init();
	sys_vars->vdp_pflags = 0;

	vdu_return_ascii_code_at_graphics_position.x = x;
	vdu_return_ascii_code_at_graphics_position.y = y;
	VDP_PUTS( vdu_return_ascii_code_at_graphics_position );
	while ( !(sys_vars->vdp_pflags & vdp_pflag_scrchar) );

	code = getsysvar_scrchar();
	return code;
}