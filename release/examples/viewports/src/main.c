/*
Example of:
  1) drawing primative graphics inside viewport
  2) constraining text to a viewport

  void vdp_set_graphics_viewport( int left, int bottom, int right, int top ); // pixel coordinates
  void vdp_set_text_viewport( int left, int bottom, int right, int top ); // text coordinates
  void vdp_reset_viewports( void );
*/

#include <stdint.h>
#include <stdio.h>
#include <agon/vdp_vdu.h>
#include <agon/vdp_keyboard.h>

const uint8_t screen_mode = 8;

int main(void) {
  vdp_mode(screen_mode);
  vdp_cursor_enable(false);
  vdp_set_text_colour( 128 + 8 );
  vdp_clear_screen();
  vdp_set_pixel_coordinates();
  printf("AgonDev Viewports Example\n\n");
  printf("Press ESC to Exit\n\n");

  vdp_set_graphics_viewport( 160, 200, 300, 40 );
  
  //vdp_clear_screen();
  vdp_clear_graphics();

  //tringles-red.yellow
  vdp_set_graphics_fg_colour( 0, BRIGHT_YELLOW );
  vdp_filled_triangle( 260,60 ,260,80 , 320, 40 );
  vdp_set_graphics_fg_colour( 0, BRIGHT_RED );
  vdp_triangle( 150,150 ,180,180 , 190,155 );

  //parallelogram-cyan
  vdp_set_graphics_fg_colour( 0, BRIGHT_CYAN );
  vdp_filled_parallelogram(200,200,220,220,340,150);

  // rectangles-green
  vdp_set_graphics_fg_colour( 0, GREEN );
  vdp_filled_rectangle( 100,100, 220,130 );

  // circles-magenta
  vdp_set_graphics_fg_colour( 0, BRIGHT_MAGENTA );
  vdp_filled_circle( 220,130 ,10 );

   //lines-blue
  vdp_set_graphics_fg_colour( 0, BRIGHT_BLUE );
  vdp_line(180,30,160,125);

  vdp_set_dotdash_line_pattern( 0b10101010,0,0,0,0,0,0,0 ); 
  vdp_set_dotdash_pattern_length( 8 ); 
  vdp_dotdash_line(180, 30, 260, 50);

  vdp_set_dotdash_line_pattern( 0b00111100,0b00011000,0,0,0,0,0,0 ); 
  vdp_set_dotdash_pattern_length( 16 );
  vdp_dotdash_line(180, 30, 260, 130);

  vdp_set_text_viewport( 1, 20, 16, 5 );
  vdp_set_text_colour( BLUE );
  printf("An example of text being constrained inside a rectangular region instead of the full screen, and graphics constrained to a region.\nThere is no automatic word wrapping in this example!");


  while(true) {
    if(vdp_getKeyCode() == 27) break;
  }
  vdp_reset_viewports(  );
  vdp_set_text_colour( 128  );
  vdp_set_text_colour( BRIGHT_WHITE  );
  vdp_clear_screen();
  vdp_cursor_enable(true);

  return 0; 
}

