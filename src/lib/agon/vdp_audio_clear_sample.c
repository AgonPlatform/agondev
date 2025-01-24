#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD_B_W vdu_audio_b;

// 	Command 5, 1: Clear sample
//		VDU 23, 0, &85, sample, 5, 1
void vdp_audio_clear_sample( int sample )
{
	vdu_audio_b.channel = sample;
	vdu_audio_b.CMD = 5;
	vdu_audio_b.b1 = 1;
       	VDP_PUTS( vdu_audio_b ); 
}