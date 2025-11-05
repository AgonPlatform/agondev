#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_ADV_CMD_WW   vdu_adv_jump_offset;
extern VDU_ADV_CMD_WW_W vdu_adv_jump_offset_block;

void vdp_adv_call_offset_block( int bufferId, int offset, int block )
{
	if ( ! (offset & (1<<23) ) ) return; // expect top bit set
	vdu_adv_jump_offset.CMD = 11;
	vdu_adv_jump_offset_block.BID = bufferId;
	vdu_adv_jump_offset_block.ww0 = offset;
	vdu_adv_jump_offset_block.w1 = block;
	VDP_PUTS( vdu_adv_jump_offset_block );
}