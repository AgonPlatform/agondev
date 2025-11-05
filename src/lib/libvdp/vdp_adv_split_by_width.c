#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_ADV_CMD_W_W  vdu_adv_split_by_width = { 23, 0, 0xA0, 0xFA00, 18, 0, 0 };

void vdp_adv_split_by_width( int bufferID, int width, int blockCount )
{
	vdu_adv_split_by_width.BID = bufferID;
	vdu_adv_split_by_width.w0 = width;
	vdu_adv_split_by_width.w1 = blockCount;
	VDP_PUTS( vdu_adv_split_by_width );
}