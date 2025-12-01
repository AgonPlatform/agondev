/*
; ---------------------------------------------------------------------------
;
; Example of using an ASM Nunchuck i2c library
; Richard Turnnidge 2025. cLib v0.1
;
; ---------------------------------------------------------------------------

; call 'nunchuck_exists' to check for nunchuck
; call 'i2c_open'        to open i2c port
; call 'nunchuck_open'   to configure nunchuck
; call 'nunchuck_update' to retrieve fresh data
; call 'i2c_close'       to close the i2c connection
;
; NOTE: Various i2c function calls are also available in mos.h
;
; Available variables:
; 
; nunchuck_btnC:       1 off, 0 pressed
; nunchuck_btnZ:       1 off, 0 pressed

; nunchuck_joyX:       0 - 255. 128 is centre
; nunchuck_joyY:       0 - 255. 128 is centre
; nunchuck_joyD:       Digital version joystick directions, as per Console8 01010101b, 0 is pressed, 1 is not

; nunchuck_angleX:     0 - 255. 128 is centre
; nunchuck_angleY:     0 - 255. 128 is centre
; nunchuck_velocityZ:  0 - 255. 128 is centre. NOTE above may not get full range of 0 - 255
;
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <agon/vdp.h>
#include <agon/timer.h>
#include "nunchuck.h"

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"   // hacky way to print a binary number
#define BYTE_TO_BINARY(uint8_t)  \
  ((uint8_t) & 0x80 ? '1' : '0'), \
  ((uint8_t) & 0x40 ? '1' : '0'), \
  ((uint8_t) & 0x20 ? '1' : '0'), \
  ((uint8_t) & 0x10 ? '1' : '0'), \
  ((uint8_t) & 0x08 ? '1' : '0'), \
  ((uint8_t) & 0x04 ? '1' : '0'), \
  ((uint8_t) & 0x02 ? '1' : '0'), \
  ((uint8_t) & 0x01 ? '1' : '0') 

 void print_byte(unsigned char b);

int main(void) {

  vdp_cursor_enable(false);                // hide cursor so it doesn't flicker
  vdp_clear_screen();                      // clear the screen

  printf("AgonDev i2c Nunchuck Example\n\n");
  printf("Press ESC to return to MOS\n\n");
  printf("Running in display mode %d\n", getDisplayMode()); 

  i2c_open();                             // open the port
  uint24_t ee = nunchuck_exists();        // check we have nunchuck attached, error code is returned, or 0 if OK
        
  if(ee == 0){                            // if no error code

    vdp_cursor_tab(0,8);
    nunchuck_open();                      // initialise nunchuck controller

    while(true) {
      if(vdp_getKeyCode() == 27) break;

      nunchuck_update();                  // get latest data into global variables
      vdp_cursor_tab(0,8);
      printf("nunchuck_btnC      %d   \n", nunchuck_btnC);    // display all nunchuck variables
      printf("nunchuck_btnZ      %d   \n", nunchuck_btnZ); 
      printf("nunchuck_joyX      %d   \n", nunchuck_joyX); 
      printf("nunchuck_joyY      %d   \n", nunchuck_joyY); 
      printf("nunchuck_joyD      "); 
      print_byte(nunchuck_joyD);
      printf("\nnunchuck_angleX    %d   \n", nunchuck_angleX); 
      printf("nunchuck_angleY    %d   \n", nunchuck_angleY); 
      printf("nunchuck_velocityZ %d   \n", nunchuck_velocityZ); 

      delay(100);                         // just so we are not going too fast
    }
  } else {                                // got error code
    printf("Sorry, no nunchuck found\n"); 
  }

  vdp_cursor_enable(true);                // show cursor
  i2c_close();                            // close the i2c port

  return 0; 
}

void print_byte(unsigned char b)
{
    unsigned char mask = 0x80;   // 1000 0000

    while (mask) {
        putchar( (b & mask) ? '1' : '0' );
        mask >>= 1;              // shift mask right by one bit
    }
}