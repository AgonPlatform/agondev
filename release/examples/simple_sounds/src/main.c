/*
Example of:
  1) 'bell' sound
  2) sinewave tone
  3) white noise while key pressed
  4) sound with volume envelope by key press
  5) sampled sound from memory
  6) sampled sound from a local file

The main audio vdp calls used are:

void vdp_audio_play_note( int channel, int volume, int frequency, int duration);
void vdp_audio_set_waveform( int channel, int waveform );
void vdp_audio_set_volume( int channel, int volume );
void vdp_audio_load_sample( int sample, int length, uint8_t *data);
void vdp_audio_volume_envelope_ADSR( int channel, int attack, int decay, int sustain, int release );
void vdp_audio_enable_channel( int channel );

uint24_t getfilesize(FILE *fh); is a call in an external library to get the size of data in the sound file

*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <agon/vdp.h>
#include <agon/vdp_keyboard.h>
#include <stdlib.h>
#include <agon/mos.h>
#include "boing.h"

uint24_t getfilesize(FILE *fh);

int main(void) {

  vdp_cursor_enable(false);
  vdp_clear_screen();
  vdp_set_pixel_coordinates();

  vdp_audio_enable_channel( 3 ); // channels 0-2 are enabled by default

  printf("AgonDev Simple Sounds\n\n");
  printf("Press:\n\n");
  printf("1. bell (default beep)\n");
  printf("2. sinewave tone fixed length\n");
  printf("3. white noise while pressed\n");
  printf("4. envelope by keypress\n");
  printf("5. sampled sound from memory\n");
  printf("6. sampled sound from local file\n\n");

  printf("Press ESC to Exit\n\n");

  while(true){

    if(vdp_getKeyCode() == 49){
      vdp_waitKeyUp();
      printf("pressed 1\n");
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

      vdp_audio_set_waveform( 3,  0 );    
      vdp_audio_volume_envelope_ADSR( 3, 30, 120, 64, 600 );
      vdp_audio_play_note( 3, 127, 200, -1);

      vdp_waitKeyUp();
      vdp_audio_set_volume( 3, 0 );

    }

    if(vdp_getKeyCode() == 53){
      printf("pressed 5\n");
      vdp_waitKeyUp();
    
      vdp_audio_load_sample( -1, 9588, boing);
      vdp_audio_set_waveform( 3,  -1);    // set channel 3 to sample type
      vdp_audio_play_note( 3, 127, 1000, 0); //freq '1000' ignored for samples
    }

    if(vdp_getKeyCode() == 54){
      printf("pressed 6\n");
      vdp_waitKeyUp();

      FILE *fh = fopen("letsgo.raw", "rb+");
      if(!fh) {
        printf("Unable to open sound file\n");
        exit(0);
      }
      uint24_t filesize = getfilesize(fh);

      uint8_t *memptr = malloc(filesize);
      if(memptr == 0) {
        printf("Unable to allocate memory for sound file\n");
        exit(0);
      }

      if(fread(memptr, 1, filesize, fh) != filesize) {
        printf("Unable to read sound file\n");
        exit(0);
      }
      vdp_audio_load_sample( -1, filesize, memptr); // First, load the audio sample (in the letsgo array here) to the VDP.
                                                    // -1 indicates the bufferID 64256 is used 
      vdp_audio_set_waveform( 3,  -1); // set sample in bufferID 64256 (-1) to channel 3
      vdp_audio_play_note( 3, 127, 0, 0);
      fclose(fh);
      free(memptr);
    }

    if(vdp_getKeyCode() == 27) break;

  } 
  vdp_clear_screen();
  vdp_cursor_enable(true);

  return 0; 
}

