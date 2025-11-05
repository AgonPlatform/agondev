#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_ADV_CMD      vdu_adv_stream       = { 23, 0, 0xA0, 0xFA00, 4 };

void vdp_adv_stream( int bufferID )
{
	vdu_adv_stream.BID = bufferID;
	VDP_PUTS(vdu_adv_stream);
}