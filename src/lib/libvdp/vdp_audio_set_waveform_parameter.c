#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD_B_B vdu_audio_b_b;
extern VDU_AUDIO_CMD_B_W vdu_audio_b_w;

// Command 14: Set channel waveform parameters
// 	VDU 23, 0, &85, channel, 14, parameter, value
void vdp_audio_set_waveform_parameter( int channel, int parameter, int value )
{
	if ( parameter & 0x80 )
	{
		// send 16-bit value
		vdu_audio_b_w.channel = channel;
		vdu_audio_b_w.CMD = 14;
		vdu_audio_b_w.b1 = parameter;
		vdu_audio_b_w.w2 = value;
		VDP_PUTS( vdu_audio_b_w ); 

	} else {
		// send 8-bit value
		vdu_audio_b_b.channel = channel;
		vdu_audio_b_b.CMD = 14;
		vdu_audio_b_b.b1 = parameter;
		vdu_audio_b_b.b2 = value;
		VDP_PUTS( vdu_audio_b_b ); 
	}
}
