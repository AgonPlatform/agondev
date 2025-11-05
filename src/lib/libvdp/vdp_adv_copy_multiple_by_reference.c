#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_ADV_CMD      vdu_adv_copy_multiple_by_reference = { 23, 0, 0xA0, 0xFA00, 25 };

void vdp_adv_copy_multiple_by_reference( int bufferId, int num_buffers, ... )
{
	va_list args;
	uint16_t buffer_list[num_buffers+1];
	vdu_adv_copy_multiple_by_reference.BID = bufferId;
	va_start( args, num_buffers );
	for (int b = 0; b < num_buffers; b++)
	{
		buffer_list[b] = va_arg( args, int );
	}
	va_end( args );
	buffer_list[num_buffers] = -1; // Terminate the list
	VDP_PUTS( vdu_adv_copy_multiple_by_reference );
	mos_puts( (char*)buffer_list, (num_buffers+1)*2, 0 );
}
