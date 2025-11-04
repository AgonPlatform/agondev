#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_AUDIO_CMD_B_W_W_B_W vdu_audio_b_w_w_b_w = { 23, 0, 0x85, 0, 0, 0, 0, 0, 0, 0 };

// Command 6: Volume envelope. Type 1: ADSR
// 	VDU 23, 0, &85, channel, 6, 1, attack; decay; sustain, release;
void vdp_audio_volume_envelope_ADSR( int channel, int attack, int decay, int sustain, int release )
{
	vdu_audio_b_w_w_b_w.channel = channel;
	vdu_audio_b_w_w_b_w.CMD = 6;
	vdu_audio_b_w_w_b_w.b1 = 1;
	vdu_audio_b_w_w_b_w.w2 = attack;
	vdu_audio_b_w_w_b_w.w3 = decay;
	vdu_audio_b_w_w_b_w.b4 = sustain;
	vdu_audio_b_w_w_b_w.w5 = release;
	VDP_PUTS( vdu_audio_b_w_w_b_w );
}