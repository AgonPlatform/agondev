#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD vdu_audio;


// Command 1: Status 
// 	VDU 23, 0, &85, channel, 1
void vdp_audio_status( int channel )
{ 
	vdu_audio.channel = channel;
	vdu_audio.CMD = 1;
       	VDP_PUTS( vdu_audio ); 
}