#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_ADV_CMD      vdu_adv_clear_buffer = { 23, 0, 0xA0, 0xFA00, 2 };

void vdp_adv_clear_buffer( int bufferID )
{
	vdu_adv_clear_buffer.BID = bufferID;
	VDP_PUTS( vdu_adv_clear_buffer );
}
