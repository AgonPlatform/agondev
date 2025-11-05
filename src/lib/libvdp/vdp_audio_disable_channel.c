#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD vdu_audio;

// Command 9: Disable Channel
//  	VDU 23, 0, &85, channel, 9
void vdp_audio_disable_channel( int channel )
{ 
	vdu_audio.channel = channel;
	vdu_audio.CMD = 9;
       	VDP_PUTS( vdu_audio ); 
}