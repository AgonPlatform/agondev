#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_ADV_CMD_W    vdu_adv_write_block;

void vdp_adv_write_block( int bufferID, int length )
{
	vdu_adv_write_block.BID = bufferID;
	vdu_adv_write_block.w0 = length;
	VDP_PUTS( vdu_adv_write_block );
}