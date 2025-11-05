#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

volatile SYSVAR *sys_vars = NULL;

volatile SYSVAR *vdp_vdu_init( void )
{
	sys_vars = (SYSVAR *)mos_sysvars();
	return (SYSVAR *)sys_vars;
}
