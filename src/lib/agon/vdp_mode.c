#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_n vdu_mode = { 22, 0 };

int vdp_mode( int mode )
{
	if ( mode < 0 || mode >= 255 ) return -1;
	vdu_mode.n = mode;
	VDP_PUTS( vdu_mode );
	return mode;
}
