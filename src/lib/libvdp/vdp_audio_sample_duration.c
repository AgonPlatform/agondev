#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD_WW vdu_audio_ww;

// Command 12: Set duration
// 	VDU 23, 0, &85, channel, 12, duration; durationHighByte
void vdp_audio_sample_duration( int channel, int duration )
{
	vdu_audio_ww.channel = channel;
	vdu_audio_ww.CMD = 12;
	vdu_audio_ww.ww1 = duration;
       	VDP_PUTS( vdu_audio_ww ); 
}