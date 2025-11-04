#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD_B_W vdu_audio_b_w;

//	Command 5, 3: Set sample base frequency
//		VDU 23, 0, &85, sample, 5, 3, frequency;
void vdp_audio_set_sample_frequency( int sample, int frequency )
{
	vdu_audio_b_w.channel = sample;
	vdu_audio_b_w.CMD = 5;
	vdu_audio_b_w.b1 = 3;
	vdu_audio_b_w.w2 = frequency;
	VDP_PUTS( vdu_audio_b_w );
}