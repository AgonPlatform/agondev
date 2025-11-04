#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_ADV_CMD      vdu_adv_call_buffer;

void vdp_adv_jump_buffer( int bufferID )
{
	vdu_adv_call_buffer.CMD = 7;
	vdu_adv_call_buffer.BID = bufferID;
	VDP_PUTS( vdu_adv_call_buffer );
}