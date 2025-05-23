#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_ADV_CMD_W    vdu_adv_split_multiple  = { 23, 0, 0xA0, 0xFA00, 16, 0 };

// can make this a var args command as arguments are all 16-bit
void vdp_adv_split_multiple( int bufferId, int blockSize, int num_buffers, ... )
{
	va_list args;
	uint16_t buffer_list[num_buffers+1];
	vdu_adv_split_multiple.BID = bufferId;
	vdu_adv_split_multiple.w0 = blockSize;
	va_start( args, num_buffers );
	for (int b = 0; b < num_buffers; b++)
	{
		buffer_list[b] = va_arg( args, int );
	}
	va_end( args );
	buffer_list[num_buffers] = -1; // Terminate the list
	VDP_PUTS( vdu_adv_split_multiple );
	mos_puts( (char*)buffer_list, (num_buffers+1)*2, 0 );
}
