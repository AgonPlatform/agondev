#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD_WW vdu_audio_ww;

// Command 11: Seek to position
// 	VDU 23, 0, &85, channel, 11, position; positionHighByte
void vdp_audio_sample_seek( int channel, int position )
{
	vdu_audio_ww.channel = channel;
	vdu_audio_ww.CMD = 11;
	vdu_audio_ww.ww1 = position;
       	VDP_PUTS( vdu_audio_ww ); 
}