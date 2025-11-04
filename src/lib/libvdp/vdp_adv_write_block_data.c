#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_ADV_CMD_W    vdu_adv_write_block;

void vdp_adv_write_block_data( int bufferID, int length, char *data )
{
	vdu_adv_write_block.BID = bufferID;
	vdu_adv_write_block.w0 = length;
	VDP_PUTS( vdu_adv_write_block );
	mos_puts( data, length, 0 );
}
