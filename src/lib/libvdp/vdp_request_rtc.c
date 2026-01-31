#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_n vdu_get_rtc = { 23, 0, 0x87, 0 }; 

void vdp_request_rtc( bool wait )
{
	if ( wait ) sys_vars->vdp_pflags = 0;
	VDP_PUTS( vdu_get_rtc );
	if ( wait ) while ( !(sys_vars->vdp_pflags & vdp_pflag_rtc) );
}
