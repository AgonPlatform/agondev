#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_ADV_CMD_W    vdu_adv_spread_multiple_from = { 23, 0, 0xA0, 0xFA00, 22, 0 };

void vdp_adv_spread_multiple_from( int bufferID, int targetBufferID )
{
	vdu_adv_spread_multiple_from.BID = bufferID;
	vdu_adv_spread_multiple_from.w0 = targetBufferID;
	VDP_PUTS( vdu_adv_spread_multiple_from );
}
