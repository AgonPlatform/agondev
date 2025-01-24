#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD_B vdu_audio_b;

// Command 6: Volume envelope. Type 0: Disable
//	VDU 23, 0, &85, channel, 6, type, [parameters]
void vdp_audio_volume_envelope_disable( int channel )
{
	vdu_audio_b.channel = channel;
	vdu_audio_b.CMD = 6;
	vdu_audio_b.b1 = 0;
       	VDP_PUTS( vdu_audio_b ); 
}