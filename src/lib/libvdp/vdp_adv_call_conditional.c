#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_ADV_CMD_B_W_W vdu_adv_call_conditional;

void vdp_adv_call_conditional( int bufferId, int operation, int checkBufferId, int checkOffset )
{
	vdu_adv_call_conditional.CMD = 6;
	vdu_adv_call_conditional.BID = bufferId;
	vdu_adv_call_conditional.b0 = operation;
	vdu_adv_call_conditional.w1 = checkBufferId;
	vdu_adv_call_conditional.w2 = checkOffset;
	VDP_PUTS( vdu_adv_call_conditional );
}
