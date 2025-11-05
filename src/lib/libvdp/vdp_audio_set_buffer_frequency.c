#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD_B_W_W vdu_audio_b_w_w;

//	Command 5, 4: Set sample frequency for a sample by buffer ID
//		VDU 23, 0, &85, channel, 5, 4, bufferId; frequency;
void vdp_audio_set_buffer_frequency( int channel, int bufferID, int frequency )
{
	vdu_audio_b_w_w.channel = channel;
	vdu_audio_b_w_w.CMD = 5;
	vdu_audio_b_w_w.b1 = 4;
	vdu_audio_b_w_w.w2 = bufferID;
	vdu_audio_b_w_w.w3 = frequency;
	VDP_PUTS( vdu_audio_b_w_w );
}
