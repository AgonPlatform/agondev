#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_AUDIO_CMD_B_W_B vdu_audio_b_w_b = { 23, 0, 0x85, 0, 0, 0, 0, 0 };

//	Command 5, 2: Create a sample from a buffer
//		VDU 23, 0, &85, channel, 5, 2, bufferId; format, [sampleRate;]
void vdp_audio_create_sample_from_buffer( int channel, int bufferID, int format)
{
	vdu_audio_b_w_b.channel = channel;
	vdu_audio_b_w_b.CMD = 5;
	vdu_audio_b_w_b.b1 = 2;
	vdu_audio_b_w_b.w2 = bufferID;
	vdu_audio_b_w_b.b3 = format;
	VDP_PUTS( vdu_audio_b_w_b );
}
