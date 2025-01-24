#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD_B vdu_audio_b;

// Command 4 (types 0-5): Set waveform
//	VDU 23, 0, &85, channel, 4, waveformOrSample, [bufferId;]
void vdp_audio_set_waveform( int channel, int waveform )
{
	// only for waveforms 0-5, use vdp_audio_set_sample for 8,-1
	vdu_audio_b.channel = channel;
	vdu_audio_b.CMD = 4;
	vdu_audio_b.b1 = waveform;
       	VDP_PUTS( vdu_audio_b ); 
}