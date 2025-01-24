#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_AUDIO_CMD_B_B_B_W vdu_audio_b_b_b_w = { 23, 0, 0x85, 0, 7, 1, 0, 0, 0 };

//	Type 1: Stepped frequency envelope
//		VDU 23, 0, &85, channel, 7, 1, phaseCount, controlByte, stepLength; [phase1Adjustment; phase1NumberOfSteps; phase2Adjustment; phase2NumberOfSteps; ...]
void vdp_audio_frequency_envelope_stepped( int channel, int phaseCount, int controlByte, int stepLength )
{
	vdu_audio_b_b_b_w.channel = channel;
	vdu_audio_b_b_b_w.CMD = 7;
	vdu_audio_b_b_b_w.b1 = 1;
	vdu_audio_b_b_b_w.b2 = phaseCount;
	vdu_audio_b_b_b_w.b3 = controlByte;
	vdu_audio_b_b_b_w.w4 = stepLength;
       	VDP_PUTS( vdu_audio_b_b_b_w ); 
}