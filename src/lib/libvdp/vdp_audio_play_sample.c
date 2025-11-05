#include <agon/vdp.h>

extern VDU_AUDIO_CMD_B_W_W vdu_audio_b_w_w;

// Command 0: Play sample (using 'play note' VDU command - frequency and duration to 0 / sample length) 
// 	VDU 23, 0, &85, channel, 0, volume, 0; 0;
void vdp_audio_play_sample( int channel, int volume) {
	vdu_audio_b_w_w.channel = channel;
	vdu_audio_b_w_w.CMD = 0;
	vdu_audio_b_w_w.b1 = volume;
	vdu_audio_b_w_w.w2 = 0;
	vdu_audio_b_w_w.w3 = 0;
       	VDP_PUTS( vdu_audio_b_w_w ); 
}
