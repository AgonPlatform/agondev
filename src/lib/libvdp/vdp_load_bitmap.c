#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_x_y vdu_load_bitmap = { 23, 27, 1, 0, 0 };

void vdp_load_bitmap( int width, int height, uint32_t *data )
{
	vdu_load_bitmap.x = width;
	vdu_load_bitmap.y = height;
	VDP_PUTS( vdu_load_bitmap );

	int size;
	char *ptr = (char *)data;
	for ( size = width*height*sizeof(uint32_t); size > LOAD_BMAP_BLOCK; size -= LOAD_BMAP_BLOCK ) {
		mos_puts( (char *)ptr, LOAD_BMAP_BLOCK, 0 );
		ptr += LOAD_BMAP_BLOCK;
	}
	mos_puts( (char *)ptr, size, 0 );
}
