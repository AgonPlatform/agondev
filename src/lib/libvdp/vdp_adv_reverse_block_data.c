#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_ADV_CMD_B    vdu_adv_reverse_block_data  = { 23, 0, 0xA0, 0xFA00, 24, 0 };
static VDU_ADV_CMD_B_W  vdu_adv_reverse_block_data_add1  = { 23, 0, 0xA0, 0xFA00, 24, 0, 0 };
static VDU_ADV_CMD_B_W_W vdu_adv_reverse_block_data_add2  = { 23, 0, 0xA0, 0xFA00, 24, 0, 0, 0 };

// note valueSize and chunkSize are only used for certain values of options
void vdp_adv_reverse_block_data( int bufferID, int options, int valueSize, int chunkSize )
{
	bool need_valueSize = false;
	bool need_chunkSize = false;
	if ( ( options | 0x3 ) == 0x3 ) need_valueSize = true;
	if ( ( options | 0x4 ) == 0x4 ) need_chunkSize = true;

	if ( !need_valueSize && !need_chunkSize )
	{
		vdu_adv_reverse_block_data.BID = bufferID;
		vdu_adv_reverse_block_data.b0 = options;
		VDP_PUTS( vdu_adv_reverse_block_data );
	} else if ( need_valueSize && !need_chunkSize  ) {
		vdu_adv_reverse_block_data_add1.BID = bufferID;
		vdu_adv_reverse_block_data_add1.b0 = options;
		vdu_adv_reverse_block_data_add1.w1 = valueSize;
		VDP_PUTS( vdu_adv_reverse_block_data_add1 );
	} else if ( !need_valueSize && need_chunkSize  ) {
		vdu_adv_reverse_block_data_add1.BID = bufferID;
		vdu_adv_reverse_block_data_add1.b0 = options;
		vdu_adv_reverse_block_data_add1.w1 = chunkSize;
		VDP_PUTS( vdu_adv_reverse_block_data_add1 );
	} else { // need both
		vdu_adv_reverse_block_data_add2.BID = bufferID;
		vdu_adv_reverse_block_data_add2.b0 = options;
		vdu_adv_reverse_block_data_add2.w1 = valueSize;
		vdu_adv_reverse_block_data_add2.w2 = chunkSize;
		VDP_PUTS( vdu_adv_reverse_block_data_add2 );
	}
}
