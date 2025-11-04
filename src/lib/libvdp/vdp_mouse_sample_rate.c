#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_MOUSE_B    vdu_mouse_sample_rate  = { 23, 0, 0x89, 6, 0 };

void vdp_mouse_sample_rate( int sampleRate )
{
	vdu_mouse_sample_rate.b0 = sampleRate;
	VDP_PUTS( vdu_mouse_sample_rate );
}
