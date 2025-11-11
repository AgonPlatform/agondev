#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static char sprite_fname_adv[32];

// helper function
// load images using absolute numbered bitmaps (24-bit)
int vdp_adv_load_sprite_bitmaps( const char *fname_prefix, const char *fname_format,
						int width, int height, int num, int bitmap_num )
{
	uint32_t *img_buf;
	FILE *fp;
	int cnt = 0;

	if ( !(img_buf = (uint32_t *)malloc( width*height*sizeof(uint32_t) ) ) ) return cnt;

	for ( int i = 0; i < num; i++ ) {
		sprintf( sprite_fname_adv, fname_format, fname_prefix, i );
		if ( !(fp = fopen( sprite_fname_adv, "rb" ) ) ) return cnt;

		size_t pixel_cnt = fread( (void *)img_buf, sizeof(uint32_t), width*height, fp );
		fclose( fp );
		if ( pixel_cnt != (size_t)(width*height) ) return cnt;
		
		vdp_adv_select_bitmap( bitmap_num++ );
		vdp_load_bitmap( width, height, (uint8_t *)img_buf );
		cnt++;
	}
	free( img_buf);
	return cnt;
}
