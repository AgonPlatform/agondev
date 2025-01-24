#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern volatile SYSVAR *sys_vars;

static VDU_A_B_CMD_B vdu_return_palette_entry_colour = { 23, 0, 0x94, 0 };

uint24_t vdp_return_palette_entry_colour( int n )
{
	uint24_t pixel = 0;
	if ( !sys_vars ) vdp_vdu_init();
	sys_vars->vdp_pflags = 0;

	vdu_return_palette_entry_colour.b0 = n;
	VDP_PUTS( vdu_return_palette_entry_colour );

	while ( !(sys_vars->vdp_pflags & vdp_pflag_point) );
	pixel = getsysvar_scrpixel();
	return pixel;
}