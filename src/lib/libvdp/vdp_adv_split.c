#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_ADV_CMD_W    vdu_adv_split        = { 23, 0, 0xA0, 0xFA00, 15, 0 };

void vdp_adv_split( int bufferID, int blockSize )
{
	vdu_adv_split.BID = bufferID;
	vdu_adv_split.w0 = blockSize;
	VDP_PUTS( vdu_adv_split );
}