#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD_B_W_WW vdu_audio_b_w_ww;

//	Command 5, 8: Set sample repeat length by buffer ID
//		VDU 23, 0, &85, channel, 5, 8, bufferId; repeatLength; repeatLengthHighByte
void vdp_audio_set_buffer_repeat_length( int channel, int bufferID, int repeatLength )
{
	vdu_audio_b_w_ww.sample = channel;
	vdu_audio_b_w_ww.CMD = 5;
	vdu_audio_b_w_ww.b1 = 8;
	vdu_audio_b_w_ww.w2 = bufferID;
	vdu_audio_b_w_ww.ww3 = repeatLength;
	VDP_PUTS( vdu_audio_b_w_ww );
}