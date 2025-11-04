/*
Example of:
  1) displaying a simple bitmap from memory

vdp calls used:
void vdp_select_bitmap( int n );
void vdp_load_bitmap( int width, int height, uint32_t *data );
void vdp_draw_bitmap( int x, int y );

*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <agon/vdp_vdu.h>
#include <agon/vdp_keyboard.h>

#include "bod0.h"

const uint8_t screen_mode = 8;

int main(void) {

  vdp_mode(screen_mode);
  vdp_cursor_enable(false);
  vdp_clear_screen();

  printf("AgonDev Simple Bitmap Example\n\n");
  printf("Press ESC to exit");

  //draw a background tringle to illustrate alpha channel
  vdp_set_graphics_fg_colour( 0, YELLOW );
  vdp_filled_triangle( 50,30 ,100,220 , 280, 90 );

  vdp_select_bitmap(0);
  vdp_load_bitmap( 16, 16, bod0 );

  //draw grid of our bitmap
  for (uint16_t x = 0; x < 300; x += 32){
    for (uint16_t y = 40; y < 220; y += 32){
      vdp_draw_bitmap( x,y );
    }
  }

  while(true) {
    if(vdp_getKeyCode() == 27) break;
  }

  vdp_cls();
  vdp_cursor_enable(true);


  return 0; 
}
