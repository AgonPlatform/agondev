/*
Example of:
  1) drawing primitive graphics
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <agon/vdp_vdu.h>
#include <agon/vdp_keyboard.h>

const uint8_t screen_mode = 8;

int main(void) {
  vdp_mode(screen_mode);
  vdp_cursor_enable(false);
  vdp_clear_screen();
  vdp_set_pixel_coordinates();
  printf("AgonDev Primative Graphics Examples\n\n");
  printf("Press ESC to Exit\n\n");

  //pixels-yellow
  vdp_set_graphics_fg_colour( 0, YELLOW );
  vdp_point(30,90);

  //lines-blue
  vdp_set_graphics_fg_colour( 0, BLUE );
  vdp_line(120,120,34,145);

  //tringles-red
  vdp_set_graphics_fg_colour( 0, RED );
  vdp_filled_triangle( 260,60 ,260,80 , 300, 40 );
  vdp_triangle( 150,150 ,180,180 , 190,155 );

  //parallelogram-cyan
  vdp_set_graphics_fg_colour( 0, CYAN );
  vdp_filled_parallelogram(200,200,220,220,300,150);
  vdp_parallelogram(0,200,40,220,70,180);

  // rectangles-green
  vdp_set_graphics_fg_colour( 0, GREEN );
  vdp_filled_rectangle( 100,200, 120,230 );
  vdp_rectangle( 100,50, 170,80 );

  // circles-magenta
  vdp_set_graphics_fg_colour( 0, MAGENTA );
  vdp_filled_circle( 200,150 ,10 );
  vdp_circle( 30,50 ,15 );
  
  while(true) {
    if(vdp_getKeyCode() == 27) break;
  }

  vdp_clear_screen();
  vdp_cursor_enable(true);

  return 0; 
}

