/*
Example of:
  1) loading simple bitmap from memory into a sprite
  2) moving sprite around screen

vdp calls used:
void vdp_select_bitmap( int n );
void vdp_load_bitmap( int width, int height, uint32_t *data );
void vdp_draw_bitmap( int x, int y );

void vdp_select_sprite( int n );
void vdp_clear_sprite( void );
void vdp_add_sprite_bitmap( int n );
void vdp_activate_sprites( int n );
void vdp_show_sprite( void );
void vdp_move_sprite_to( int x, int y );
void vdp_refresh_sprites( void );
void vdp_reset_sprites( void );
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <agon/vdp_vdu.h>
#include <agon/vdp_keyboard.h>
#include <agon/timer.h>

#include "bod0.h"


const uint8_t screen_mode = 8;
const int delay_ms = 20;
const int bitmap_ID = 0;
const int sprite_ID = 0;
const int numSprites = 1;

uint16_t x = 0;
uint16_t y = 0;
int8_t dx = 2;
int8_t dy = 1;

int main(void) {

  vdp_mode(screen_mode);
  vdp_cursor_enable(false);
  vdp_set_text_colour( 15 );
  vdp_set_text_colour( 128 + 8 );
  vdp_clear_screen();
  vdp_reset_sprites();
  printf("AgonDev Simple Sprite Example\n\n");
  printf("Press ESC to exit");


  //draw some background tringles to illustrate alpha channel
  vdp_set_graphics_fg_colour( 0, GREEN );
  vdp_filled_triangle( 0,175 ,200,230 , 260,30 );
  
  vdp_set_graphics_fg_colour( 0, YELLOW );
  vdp_filled_triangle( 50,30 ,100,220 , 280, 90 );

  vdp_set_graphics_fg_colour( 0, RED );
  vdp_filled_triangle( 120,30 ,90,150 , 300, 170 );

  // load bitmap and setup sprite
  vdp_select_bitmap(bitmap_ID);
  vdp_load_bitmap( 16, 16, bod0 );

  vdp_select_sprite(sprite_ID);
  vdp_clear_sprite();
  vdp_add_sprite_bitmap(bitmap_ID);

  vdp_show_sprite();
  vdp_activate_sprites(numSprites);

  //move sprite around until ESC key pressed
  while(true) {
    delay(delay_ms);
    vdp_move_sprite_to( x, y );
    vdp_refresh_sprites();
    x += dx;
    if (x>300) dx = -1;
    if (x<1) dx = 1;
    y += dy;
    if (y>220) dy = -1;
    if (y<1) dy = 1;
    
    if(vdp_getKeyCode() == 27) break;
  }

  vdp_set_text_colour( 128  );
  vdp_cls();
  vdp_cursor_enable(true);


  return 0; 
}
