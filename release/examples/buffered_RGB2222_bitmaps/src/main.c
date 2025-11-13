/*
Example of:
  1) using a buffer to store a large RGBA2222 colour bitmap 
  2) load in chunks as size is > 64k upload limitation
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <agon/vdp.h>
#include <agon/timer.h>

#include "rockRGB2.h" // image data

const uint8_t  screen_mode = 8;
const uint8_t  RGBA2222_format = 1;

const uint16_t bitmapID = 32;
const uint16_t bitmapWidth = 320;
const uint16_t bitmapHeight = 240;
const uint24_t chunkSize = 16386;

uint24_t lenArray = 0;
uint24_t arrayOffset = 0;
uint24_t maxWhileRange = 0;
uint24_t remainingData  = 0;

void printtext(void);

int main(void) {

  vdp_mode(screen_mode);
  vdp_cursor_enable(false);
  vdp_clear_screen();
  vdp_set_pixel_coordinates();

  vdp_adv_clear_buffer(bitmapID);                         // clear the buffer

  lenArray = bitmapWidth * bitmapHeight;                  // 1 byte per pixel in RGBA2222
  maxWhileRange = lenArray - chunkSize;                   // range of while loop

  if (sizeof(rockRGB2) != lenArray) return 2;             // exit: data doesn't match expected image size

  // load all data into a buffer, in chunks
  while(arrayOffset < maxWhileRange){                     // loop round sending 'chunkSize' pieces of array data 
    vdp_adv_write_block_data(bitmapID, chunkSize, &rockRGB2[arrayOffset]);
    arrayOffset += chunkSize;
  }
  remainingData  = lenArray - arrayOffset;                // the leftover array data remaining
  vdp_adv_write_block_data(bitmapID, remainingData, &rockRGB2[arrayOffset]);

  vdp_adv_consolidate(bitmapID);                          // consolidate all uploaded chunks into single buffer
  vdp_adv_select_bitmap(bitmapID);                        // select bitmap ID

  // create an RGBA2222 colour bitmap from data loaded into a buffer. Size needs to be byte accurate.
  vdp_adv_bitmap_from_buffer(bitmapWidth, bitmapHeight, RGBA2222_format);      

  // scroll image on, just for fun.
  uint8_t ypos = 240;
  for (uint8_t y = 0; y <25; y ++){
    vdp_plot_bitmap(0,ypos);
    printtext();
    delay(50);
    ypos -=10;
  } 

 printtext();

  // loop here
  while(true) {
    if(vdp_getKeyCode() == 114) {       // Rotate
      vdp_waitKeyUp();
      vdp_adv_select_bitmap(bitmapID);
      
      // rotate the data 
      vdp_adv_reverse_block_data( bitmapID, 0, 0, 0 );
      vdp_plot_bitmap(0,0);
      printtext();
    };  
    
    if(vdp_getKeyCode() == 104) {      // flip H axis
      vdp_waitKeyUp();
      vdp_adv_select_bitmap(bitmapID);    

      // flipping data about H axis.
      vdp_adv_reverse_block_data( bitmapID, 3, bitmapWidth, 0 );    
      vdp_plot_bitmap(0,0);
      printtext();
    };   

    if(vdp_getKeyCode() == 118) {       // flip V axis
      vdp_waitKeyUp();
      vdp_adv_select_bitmap(bitmapID);  

      // flipping data about V axis.
      vdp_adv_reverse_block_data( bitmapID, 4, 0, bitmapWidth );    
      vdp_plot_bitmap(0,0);
      printtext();
    };   

    if(vdp_getKeyCode() == 27) break;   // exit if ESC pressed
  }

  vdp_cls();
  vdp_cursor_enable(true);

  return 0;     // exit to MOS
}


void printtext(void){
  vdp_cursor_tab(0, 0);
  printf("AgonDev Colour Bitmap Example");
  vdp_cursor_tab(0, 1);
  printf("Press H or V to flip image, R to rotate");
  vdp_cursor_tab(0, 29);
  printf("Press ESC to exit");
}