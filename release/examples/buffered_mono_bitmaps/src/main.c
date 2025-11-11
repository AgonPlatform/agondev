/*
Example of:
  1) using a buffer to create a large monochrome bitmap of any colour
  2) re-using data stored in a buffer on ESP to reduce transfer time from ez80 -> ESP
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <agon/vdp.h>
#include "rock.h"

void makeBitmap(uint8_t newColour);

const uint8_t  screen_mode =    8;
const uint16_t originalDataID = 64000;
const uint16_t bitmap_ID =      64001;
const uint8_t  max_colours  =   64;          // max 64 colours in screen mode 8
uint8_t        current_colour = 1;

int main(void) {

  vdp_mode(screen_mode);
  vdp_cursor_enable(false);
  vdp_clear_screen();
  vdp_set_pixel_coordinates();

  // first load the bitmap into a 'originalDataID' buffer, so it is stored on ESP
  vdp_adv_clear_buffer(originalDataID);                    // clear the buffer
  vdp_adv_write_block_data(originalDataID, 9600, rock);    // write data to buffer

  // draw the new screen
  makeBitmap( current_colour);

  // loop here
  while(true) {
    if(vdp_getKeyCode() == 99) {    // if C pressed, create new colour bitmap and draw screen 
      vdp_waitKeyUp();              // wait until key up so no auto-repeat
      current_colour++;             // increase colour count
      if(current_colour == max_colours) current_colour = 1; //loop if end of colour list
      makeBitmap(current_colour);   // create new screen

    };
    if(vdp_getKeyCode() == 27) break;   // exit if ESC pressed
  }

  vdp_cls();
  vdp_cursor_enable(true);

  return 0;     // exit to MOS
}

void makeBitmap(uint8_t newColour){

  vdp_adv_select_bitmap(bitmap_ID);                   // select bitmap ID
  vdp_adv_clear_buffer(bitmap_ID);                    // clear the buffer

  // copy data from 'originalDataID' buffer to bitmap ID buffer
  // should be faster than sending data from ez80 -> ESP over uart0
  vdp_adv_copy_multiple( bitmap_ID, 1, originalDataID);

  // set the colour to use
  vdp_set_graphics_fg_colour( 0, newColour );     

  // create a monochrome bitmap from data loaded into a buffer
  vdp_adv_bitmap_from_buffer(320, 240, 2);        

  /*
  make sure bitmap is selected first, done above, then:
  vdp plot bitmap
  VDU 25, 237, x; y;
  */
  vdp_plot_bitmap(0,0);

  vdp_cursor_tab(0, 0);
  printf("AgonDev Monochrome Bitmap Example");
  vdp_cursor_tab(0, 29);
  printf("Press C to change colour, ESC to exit");
}
