#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_AUDIO_LOAD_SAMPLE vdu_audio_load_sample = { 23, 0, 0x85, 0, 5, 0, 0 };

// Command 5: Sample management
// 	VDU 23, 0, &85, channelOrSample, 5, sampleCommand, [parameters]
//	Command 5, 0: Load sample
//		VDU 23, 0, &85, sample, 5, 0, length; lengthHighByte, <sampleData>
//		the sample data is assumed to be 8-bit signed PCM samples at 16kHz
void vdp_audio_load_sample( int sample, int length, uint8_t *data)
{
	vdu_audio_load_sample.sample = sample;
	vdu_audio_load_sample.length = length;
	VDP_PUTS( vdu_audio_load_sample );

	int size;
	char *ptr = (char *)data;
	for ( size = length; size > LOAD_BMAP_BLOCK; size -= LOAD_BMAP_BLOCK ) {
		mos_puts( (char *)ptr, LOAD_BMAP_BLOCK, 0 );
		ptr += LOAD_BMAP_BLOCK;
	}
	mos_puts( (char *)ptr, size, 0 );
}
