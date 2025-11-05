#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_ADV_CMD_B_W  vdu_adv_adjust       = { 23, 0, 0xA0, 0xFA00, 5, 0, 0 };

/* Adjust - pass the necessary arguments this must then be followed
 * by data appropriate for the operation selected */
void vdp_adv_adjust( int bufferID, int operation, int offset )
{
	vdu_adv_adjust.BID = bufferID;
	vdu_adv_adjust.b0 = operation;
	vdu_adv_adjust.w1 = offset;
	VDP_PUTS( vdu_adv_adjust );
}