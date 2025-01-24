#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_x_y vdu_load_bitmap_file = { 23, 27, 1, 0, 0 };

int vdp_load_bitmap_file( const char *fname, int width, int height )
{
	FILE *fp;
	char *buffer;
	int exit_code = 0;

	if ( !(buffer = (char *)malloc( LOAD_BMAP_BLOCK ) ) ) return -1;
	if ( !(fp = fopen( fname, "rb" ) ) ) return -1;

	vdu_load_bitmap_file.x = width;
	vdu_load_bitmap_file.y = height;
	VDP_PUTS( vdu_load_bitmap_file );

	int block_size = LOAD_BMAP_BLOCK;
	int size = width * height * sizeof(uint32_t);
	if ( size < block_size ) block_size = size;

	for ( ; size > block_size; size -= block_size ) {
		if ( fread( buffer, 1, block_size, fp ) != (size_t)block_size ) exit_code = -1;
		mos_puts( buffer, block_size, 0 );
	}
	if ( size > 0) {
		if ( fread( buffer, 1, size, fp ) != (size_t)size ) exit_code = -1;
		mos_puts( buffer, size, 0 );
	}
	fclose( fp );
	free( buffer );
	return exit_code;
}