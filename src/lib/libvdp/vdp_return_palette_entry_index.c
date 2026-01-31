#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_B vdu_return_palette_entry_index = { 23, 0, 0x94, 0 };

uint8_t vdp_return_palette_entry_index( int n )
{
	sys_vars->vdp_pflags = 0;

	vdu_return_palette_entry_index.b0 = n;
	VDP_PUTS( vdu_return_palette_entry_index );

	while ( !(sys_vars->vdp_pflags & vdp_pflag_point) )
    ;
  return sys_vars->scrpixelIndex;
}
