#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_ADV_CMD_W    vdu_adv_create       = { 23, 0, 0xA0, 0xFA00, 3, 0 };

void vdp_adv_create( int bufferID, int length )
{
	vdu_adv_create.BID = bufferID;
	vdu_adv_create.w0 = length;
	VDP_PUTS( vdu_adv_create );
}
