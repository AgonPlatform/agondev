#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

extern volatile SYSVAR *sys_vars;

static VDU_A_B_CMD vdu_get_scr_dims = { 23, 0, 0x86 };

void vdp_get_scr_dims( bool wait )
{
	if ( !sys_vars ) vdp_vdu_init();
	if ( wait ) sys_vars->vdp_pflags = 0;
	VDP_PUTS( vdu_get_scr_dims );
	// wait for results of mode change to be reflected in SYSVARs
	if ( wait ) while ( !(sys_vars->vdp_pflags & vdp_pflag_mode) );
}
