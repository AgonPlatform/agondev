#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD_W vdu_audio_w;

// Command 13: Set sample rate
// 	VDU 23, 0, &85, channel, 13, sampleRate;
void vdp_audio_sample_rate( int channel, int rate )
{
	vdu_audio_w.channel = channel;
	vdu_audio_w.CMD = 13;
	vdu_audio_w.w1 = rate;
       	VDP_PUTS( vdu_audio_w ); 
}