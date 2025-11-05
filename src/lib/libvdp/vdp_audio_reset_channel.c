#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD vdu_audio;

// Command 10: Reset Channel
//  	VDU 23, 0, &85, channel, 10
void vdp_audio_reset_channel( int channel )
{ 
	vdu_audio.channel = channel;
	vdu_audio.CMD = 10;
       	VDP_PUTS( vdu_audio ); 
}