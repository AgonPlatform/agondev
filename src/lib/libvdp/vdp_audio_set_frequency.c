#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD_W vdu_audio_w;

// Command 3: Set frequency
//	VDU 23, 0, &85, channel, 3, frequency;
void vdp_audio_set_frequency( int channel, int frequency )
{ 
	vdu_audio_w.channel = channel;
	vdu_audio_w.CMD = 3;
	vdu_audio_w.w1 = frequency;
       	VDP_PUTS( vdu_audio_w ); 
}
