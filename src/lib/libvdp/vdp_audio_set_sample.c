#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD_B_W vdu_audio_b_w;

// Command 4 (type 8): Set sample
void vdp_audio_set_sample( int channel, int bufferID )
{
	// only for waveforms 8,-1, use vdp_audio_set_waveform otherwise
	vdu_audio_b_w.channel = channel;
	vdu_audio_b_w.CMD = 4;
	vdu_audio_b_w.b1 = 8; // waveform=8 is sample
	vdu_audio_b_w.w2 = bufferID;
       	VDP_PUTS( vdu_audio_b_w ); 
}