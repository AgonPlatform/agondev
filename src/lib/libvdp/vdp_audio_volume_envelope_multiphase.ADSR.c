#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD_B vdu_audio_b;

// Command 6: Volume envelope. Type 2: Multi-phase ADSR
// 	VDU 23, 0, &85, channel, 6, 2, attackCount, [level, duration;]*, sustainCount, [level, duration;]*, releaseCount, [level, duration;]*
// 	variable length parameters - leave to user to send separately
void vdp_audio_volume_envelope_multiphase_ADSR( int channel )
{
	vdu_audio_b.channel = channel;
	vdu_audio_b.CMD = 6;
	vdu_audio_b.b1 = 2;
       	VDP_PUTS( vdu_audio_b ); 
}