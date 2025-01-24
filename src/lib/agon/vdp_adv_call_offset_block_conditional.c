#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_ADV_CMD_WW   vdu_adv_jump_offset;
extern VDU_ADV_CMD_WW_W vdu_adv_jump_offset_block;

void vdp_adv_call_offset_block_conditional( int bufferId, int offset, int block )
{
	if ( ! (offset & (1<<23) ) ) return; // expect top bit set
	vdu_adv_jump_offset.CMD = 12;
	vdu_adv_jump_offset_block.BID = bufferId;
	vdu_adv_jump_offset_block.ww0 = offset;
	vdu_adv_jump_offset_block.w1 = block;
	VDP_PUTS( vdu_adv_jump_offset_block );
}