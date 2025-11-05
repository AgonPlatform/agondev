#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_W	vdu_adv_select_bitmap = { 23, 27, 0x20, 0xFA00 };

void vdp_adv_select_bitmap( int bufferID )
{
	vdu_adv_select_bitmap.w0 = bufferID;
	VDP_PUTS( vdu_adv_select_bitmap );
}
