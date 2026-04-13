#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

extern VDU_AUDIO_CMD_B vdu_audio_b;

// Command 6: Volume envelope. Type 2: Multi-phase ADSR
// VDU 23, 0, &85, channel, 6, 2, attackCount, [level, duration;]*, sustainCount, [level, duration;]*, releaseCount, [level, duration;]*
// define number of Attack, Sustain, and Releases
// provide array of data in the form [level,duration] as 16bit, for each of numAttack, numSustain, and numRelease
// array data will be read item at a time and sent after each Attack, Sustain, or Releases definition
void vdp_audio_volume_envelope_multiphase_ADSR( uint8_t channel,uint8_t numAttack,uint8_t numSustain ,uint8_t numRelease, int16_t* envelopeData )
{
	vdu_audio_b.channel = channel;
	vdu_audio_b.CMD = 6;
	vdu_audio_b.b1 = 2;
       	VDP_PUTS( vdu_audio_b ); 

  VDP_PUTS(numAttack);   // set number of attack to send
  uint8_t count = 0;     // set to start of data to be sent
  for(uint8_t x = 0; x < numAttack; x++){
    uint8_t c = (uint8_t) envelopeData[count];  // only want byte
    VDP_PUTS(c);
    count ++;
    VDP_PUTS(envelopeData[count]);              // this is a word
    count ++;
  }

  VDP_PUTS(numSustain);   // set number of sustains to send
  for(uint8_t x = 0; x < numSustain; x++){
    uint8_t c = (uint8_t) envelopeData[count];
    VDP_PUTS(c);
    count ++;
    VDP_PUTS(envelopeData[count]);
    count ++;
  }

  VDP_PUTS(numRelease);   // set number of releases to send
  for(uint8_t x = 0; x < numRelease; x++){
    uint8_t c = (uint8_t) envelopeData[count];
    VDP_PUTS(c);
    count ++;
    VDP_PUTS(envelopeData[count]);
    count ++;
  }





	
}
