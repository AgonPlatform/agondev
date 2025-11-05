#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_ADV_CMD      vdu_adv_reverse_block_order  = { 23, 0, 0xA0, 0xFA00, 23 };

void vdp_adv_reverse_block_order( int bufferID )
{
	vdu_adv_reverse_block_order.BID = bufferID;
	VDP_PUTS( vdu_adv_reverse_block_order );
}
