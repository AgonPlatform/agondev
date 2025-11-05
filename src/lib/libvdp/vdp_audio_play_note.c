#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD_B_W_W vdu_audio_b_w_w;


// Command 0: Play note 
// 	VDU 23, 0, &85, channel, 0, volume, frequency; duration;
void vdp_audio_play_note( int channel, int volume, int frequency, int duration)
{
	vdu_audio_b_w_w.channel = channel;
	vdu_audio_b_w_w.CMD = 0;
	vdu_audio_b_w_w.b1 = volume;
	vdu_audio_b_w_w.w2 = frequency;
	vdu_audio_b_w_w.w3 = duration;
       	VDP_PUTS( vdu_audio_b_w_w ); 
}
