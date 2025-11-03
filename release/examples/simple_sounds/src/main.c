/*
Example of:
  1) 'bell' sound
  2) sinewave tone
  3) white noise while key pressed
  4) sampled sound
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <agon/vdp_vdu.h>
#include <agon/vdp_keyboard.h>
#include "letsgo.h"
//#include "boing.h"

int main(void) {

  vdp_cursor_enable(false);
  vdp_clear_screen();
  vdp_set_pixel_coordinates();
  printf("AgonDev Simple Sounds\n\n");
  printf("Press:\n\n");
  printf("1. bell (default beep)\n");
  printf("2. sinewave tone\n");
  printf("3. white noise\n");
  printf("4. sampled sound\n\n");

  printf("Press ESC to Exit\n\n");

  while(true){

    if(vdp_getKeyCode() == 49){
      vdp_waitKeyUp();
      printf("pressed 1\n");
      vdp_audio_set_waveform( 0,  1);    // set to waveform
      vdp_bell();
    }

    if(vdp_getKeyCode() == 50){
      vdp_waitKeyUp();
      printf("pressed 2\n");
      vdp_audio_set_waveform( 1,  3 );    // set to sinewave
      vdp_audio_play_note( 1, 127, 2000, 1000);
    }
  
    if(vdp_getKeyCode() == 51){
      printf("pressed 3\n");
      vdp_audio_set_waveform( 2,  4 );    // set to white noise
      vdp_audio_play_note( 2, 127, 1000, 1000);
      vdp_waitKeyUp();
      vdp_audio_set_volume( 2, 0 );
    }

    if(vdp_getKeyCode() == 52){
      printf("pressed 4\n");
      vdp_waitKeyUp();
      vdp_audio_set_waveform( 0,  -1);    // set to sample
      vdp_audio_load_sample( -1, 15279, letsgo);

      vdp_audio_play_note( 0, 127, 100, 125); //last 2 ignored for samples
    }

    if(vdp_getKeyCode() == 27) break;

  } 
  vdp_clear_screen();
  vdp_cursor_enable(true);

  return 0; 
}

