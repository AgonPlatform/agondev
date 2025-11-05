#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD_B_W_WW vdu_audio_b_w_ww;

//	Command 5, 6: Set sample repeat start point by buffer ID
//		VDU 23, 0, &85, channel, 5, 6, bufferId; repeatStart; repeatStartHighByte
void vdp_audio_set_buffer_repeat_start( int channel, int bufferID, int repeatStart )
{
	vdu_audio_b_w_ww.sample = channel;
	vdu_audio_b_w_ww.CMD = 5;
	vdu_audio_b_w_ww.b1 = 6;
	vdu_audio_b_w_ww.w2 = bufferID;
	vdu_audio_b_w_ww.ww3 = repeatStart;
	VDP_PUTS( vdu_audio_b_w_ww );
}
