#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_ADV_CMD_W_W_W vdu_adv_split_by_width_multiple_from = { 23, 0, 0xA0, 0xFA00, 20, 0, 0, 0 };

void vdp_adv_split_by_width_multiple_from( int bufferID, int width, int blockCount, int targetBufferID )
{
	vdu_adv_split_by_width_multiple_from.BID = bufferID;
	vdu_adv_split_by_width_multiple_from.w0 = width;
	vdu_adv_split_by_width_multiple_from.w1 = blockCount;
	vdu_adv_split_by_width_multiple_from.w2 = targetBufferID;
	VDP_PUTS( vdu_adv_split_by_width_multiple_from );
}