#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_ADV_CMD_W    vdu_adv_compress_buffer = { 23, 0, 0xA0, 0xFA00, 64, 0 };

void vdp_adv_compress_buffer( int targetBufferID, int sourceBufferId )
{
	vdu_adv_compress_buffer.BID = targetBufferID;
	vdu_adv_compress_buffer.w0 = sourceBufferId;
	VDP_PUTS( vdu_adv_compress_buffer );
}