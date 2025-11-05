#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD_B_WW vdu_audio_b_ww;

//	Command 5, 7: Set sample repeat length
//		VDU 23, 0, &85, sample, 5, 7, repeatLength; repeatLengthHighByte
void vdp_audio_set_sample_repeat_length( int sample, int repeatLength )
{
	vdu_audio_b_ww.sample = sample;
	vdu_audio_b_ww.CMD = 5;
	vdu_audio_b_ww.b1 = 7;
	vdu_audio_b_ww.ww2 = repeatLength;
	VDP_PUTS( vdu_audio_b_ww );
}