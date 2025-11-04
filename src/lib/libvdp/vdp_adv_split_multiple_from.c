#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_ADV_CMD_W_W  vdu_adv_split_multiple_from = { 23, 0, 0xA0, 0xFA00, 17, 0, 0 };

void vdp_adv_split_multiple_from( int bufferID, int blockSize, int targetBufferID )
{
	vdu_adv_split_multiple_from.BID = bufferID;
	vdu_adv_split_multiple_from.w0 = blockSize;
	vdu_adv_split_multiple_from.w1 = targetBufferID;
	VDP_PUTS( vdu_adv_split_multiple_from );
}
