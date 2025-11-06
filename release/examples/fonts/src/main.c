/*
Example of:
  1) creating User Fonts
  
  
  // VDU 23, 0, &95, 0, bufferId; flags: Select font
void vdp_font_select( int buffer_id );
// VDU 23, 0, &95, 1, bufferId; width, height, ascent, flags: Create font from buffer
void vdp_font_create( int buffer_id, int width, int height, int ascent, int flags );

void vdp_adv_write_block(int bufferID, int length);
void vdp_adv_write_block_data(int bufferID, int length, char *data);

void vdp_adv_call_buffer(int bufferID);
// Command 2: Clear a buffer
// 	VDU 23, 0 &A0, bufferId; 2
void vdp_adv_clear_buffer(int bufferID);
// Command 3: Create a writeable buffer
// 	VDU 23, 0 &A0, bufferId; 3, length;
void vdp_adv_create(int bufferID, int length);
// VDU 23, 0, &95, 5, bufferId;: Copy system font to buffer
void vdp_font_copy( int buffer_id );
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <agon/vdp.h>
#include <agon/vdp_keyboard.h>

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

// make digital_8x8 font
  vdp_adv_create(smallFontBufferID, fontDataSize);
  vdp_adv_clear_buffer(smallFontBufferID);
  vdp_adv_write_block_data(smallFontBufferID, fontDataSize, digital_8x8);
  vdp_font_create( smallFontBufferID, 8, 8, 8, 0 );

// make tremolo_8x16 font
  vdp_adv_create(tallFontBufferID, fontDataSize);
  vdp_adv_clear_buffer(tallFontBufferID);
  vdp_adv_write_block_data(tallFontBufferID, tallFontDataSize, tremolo_8x16);
  vdp_font_create( tallFontBufferID, 8, 16, 16, 0 );

// make 16x16 arial_bold font
  vdp_adv_create(megaFontBufferID, megaFontDataSize);
  vdp_adv_clear_buffer(megaFontBufferID);
  vdp_adv_write_block_data(megaFontBufferID, megaFontDataSize, arial_bold);
  vdp_font_create( megaFontBufferID, 12, 16, 16, 0 );
  

  // start program here

  vdp_font_select( -1 ); // make sure on default system font

  vdp_cursor_enable(false);
  vdp_clear_screen();

  printf("AgonDev User Font Example\n\n"); // this prints at top of screen ok
  printf("Press ESC to Exit\n");


  vdp_cursor_tab(30,5);
  printf("First msg\n");        // this works

  // select small user font and print something
  vdp_font_select( smallFontBufferID );
  vdp_cursor_tab(5,20);
  printf("This is a retro 8x8 futuristic font"); // this fails to go to correct position

 // select tall user font and print something
  vdp_font_select( tallFontBufferID );
  printf("This is a TALL 8x16 sketchy font"); // this loses first char

 // select tall user font and print something
  vdp_font_select( megaFontBufferID );
  printf("This is Mega Arial Bold");        // this loses first char


  vdp_font_select( -1 ); // reset to system font

  // testing positions
  vdp_cursor_tab(5,5);  // this fails to go to correct position
  printf("msg at 5,5");

  vdp_cursor_tab(10,20); // this works
  printf("msg at 10,20");

  vdp_cursor_tab(20,30); // this works
  printf("msg  at 20,30");

  while(true) {
    if(vdp_getKeyCode() == 27) break;
  }

  // reset everything
  vdp_font_select( -1 );
  vdp_cursor_enable(true);
  vdp_clear_screen();
  return 0; 
}

