#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD_B_WW vdu_audio_b_ww;

//	Command 5, 5: Set sample repeat start point
//		VDU 23, 0, &85, sample, 5, 5, repeatStart; repeatStartHighByte
void vdp_audio_set_sample_repeat_start( int sample, int repeatStart )
{
	vdu_audio_b_ww.sample = sample;
	vdu_audio_b_ww.CMD = 5;
	vdu_audio_b_ww.b1 = 5;
	vdu_audio_b_ww.ww2 = repeatStart;
	VDP_PUTS( vdu_audio_b_ww );
}