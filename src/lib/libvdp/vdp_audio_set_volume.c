#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD_B vdu_audio_b;

// Command 2: Set volume
// 	VDU 23, 0, &85, channel, 2, volume
void vdp_audio_set_volume( int channel, int volume )
{ 
	vdu_audio_b.channel = channel;
	vdu_audio_b.CMD = 2;
	vdu_audio_b.b1 = volume;
       	VDP_PUTS( vdu_audio_b ); 
}
