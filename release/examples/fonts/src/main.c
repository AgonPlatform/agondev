/*
Example of:
  1) Defining 3 differnt sized user fonts
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <agon/vdp.h>
#include <agon/vdp_keyboard.h>
#include <agon/timer.h>
#include "user_fonts.h"
#include "arial_bold.h"

const int smallFontBufferID = 1;
const int tallFontBufferID = 2;
const int megaFontBufferID = 3;
const int fontDataSize = 2048;
const int tallFontDataSize = 4096;
const int megaFontDataSize = 8192;


int main(void) {

// setup fonts
  vdp_adv_clear_buffer(-1);

// make digital_8x8 font
  vdp_adv_write_block_data(smallFontBufferID, fontDataSize, digital_8x8);
  vdp_font_create( smallFontBufferID, 8, 8, 8, 0 );

// make tremolo_8x16 font
  vdp_adv_write_block_data(tallFontBufferID, tallFontDataSize, tremolo_8x16);
  vdp_font_create( tallFontBufferID, 8, 16, 16, 0 );

// make 16x16 arial_bold font, but use 14 pixels for width
  vdp_adv_write_block_data(megaFontBufferID, megaFontDataSize, arial_bold);
  vdp_font_create( megaFontBufferID, 14, 16, 16, 0 ); 
  
// start program here

  vdp_font_select( -1 ,0); // make sure on default system font
  vdp_cursor_enable(false);
  vdp_clear_screen();

  printf("AgonDev User Font Example\n\n"); 
  printf("Press ESC to Exit\n");

// select small user font and print something
  vdp_font_select( smallFontBufferID ,0);
  vdp_cursor_tab(10,15);
  printf("This is a retro 8x8 futuristic font"); 

// select tall user font and print something
  vdp_font_select( tallFontBufferID,0 );
  vdp_cursor_tab(10,10);  
  printf("This is a TALL 8x16 sketchy font"); 


// select tall user font and print something
  vdp_font_select( megaFontBufferID ,0);
  vdp_cursor_tab(5,14); 
  printf("This is 16x16 Arial Bold Style");  


  while(true) {
    if(vdp_getKeyCode() == 27) break;
  }

  // reset everything
  vdp_font_select( -1 ,0);
  vdp_cursor_enable(true);
  vdp_clear_screen();
  return 0; 
}

