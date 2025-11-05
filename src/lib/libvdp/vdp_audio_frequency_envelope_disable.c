#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD_B vdu_audio_b;

// Command 7: Frequency envelope
//	VDU 23, 0, &85, channel, 7, type, [parameters]
// 	Type 0: None
//		VDU 23, 0, &85, channel, 7, 0
void vdp_audio_frequency_envelope_disable( int channel )
{
	vdu_audio_b.channel = channel;
	vdu_audio_b.CMD = 7;
	vdu_audio_b.b1 = 0;
       	VDP_PUTS( vdu_audio_b ); 
}
