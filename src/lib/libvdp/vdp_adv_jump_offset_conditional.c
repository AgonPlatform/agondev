#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_ADV_CMD_WW   vdu_adv_jump_offset;

void vdp_adv_jump_offset_conditional( int bufferId, int offset )
{
	if ( offset & (1<<23) ) return; // if top bit is set, expect a block
	vdu_adv_jump_offset.CMD = 10;
	vdu_adv_jump_offset.BID = bufferId;
	vdu_adv_jump_offset.ww0 = offset;
	VDP_PUTS( vdu_adv_jump_offset );
}