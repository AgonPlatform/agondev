/*
Example of:
  1) loading simple bitmap from memory into a sprite
  2) moving sprite around screen
  3) animating sprite frames

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
void vdp_next_sprite_frame( void );
void vdp_create_sprite( int sprite, int bitmap_num, int frames );
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <agon/vdp_vdu.h>
#include <agon/vdp_keyboard.h>
#include <agon/timer.h>

#include "man.h"
#include "gem.h"

const uint8_t screen_mode = 8;
const int delay_ms = 20;
const int man_bitmap_ID = 10;
const int gem_sprite_start_bitmap_ID = 0;
const int man_sprite_ID = 0;
const int gem_sprite_ID = 1;
const int numSprites = 2;
const int gem_frames = 6;


uint16_t x = 0;
uint16_t y = 0;
int8_t dx = 2;
int8_t dy = 1;
int8_t gem_anim_count = 0;


int main(void) {

  vdp_mode(screen_mode);
  vdp_set_pixel_coordinates();
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

  // load man bitmap and setup sprite
  vdp_select_bitmap(man_bitmap_ID);
  vdp_load_bitmap( 16, 16, man_bitmap );

  vdp_select_sprite(man_sprite_ID);
  vdp_clear_sprite();
  vdp_add_sprite_bitmap(man_bitmap_ID);
  vdp_show_sprite();

  // load bitmaps for animated gem sprite, all in gem.h file
  vdp_select_bitmap(gem_sprite_start_bitmap_ID);
  vdp_load_bitmap( 16, 16, blue1 );
  vdp_select_bitmap(gem_sprite_start_bitmap_ID + 1);
  vdp_load_bitmap( 16, 16, blue2 );
  vdp_select_bitmap(gem_sprite_start_bitmap_ID + 2);
  vdp_load_bitmap( 16, 16, blue3 );
  vdp_select_bitmap(gem_sprite_start_bitmap_ID + 3);
  vdp_load_bitmap( 16, 16, blue4 );
  vdp_select_bitmap(gem_sprite_start_bitmap_ID + 4);
  vdp_load_bitmap( 16, 16, blue5 );
  vdp_select_bitmap(gem_sprite_start_bitmap_ID + 5);
  vdp_load_bitmap( 16, 16, blue6 );

  // create sprite with 6 frames of loaded bitmaps
  vdp_select_sprite(gem_sprite_ID);
  vdp_clear_sprite();
  vdp_create_sprite( gem_sprite_ID, gem_sprite_start_bitmap_ID, 6 );
  vdp_move_sprite_to( 150,110 );
  vdp_show_sprite();

  // activate the sprites
  vdp_activate_sprites(numSprites);

  //move sprite around until ESC key pressed
  while(true) {
    delay(delay_ms);
    vdp_select_sprite(man_sprite_ID);
    vdp_move_sprite_to( x, y );

    x += dx;
    if (x>300) dx = -1;
    if (x<1) dx = 1;
    y += dy;
    if (y>220) dy = -1;
    if (y<1) dy = 1;
   
    // uses a counter so animation is not as fast as man moving
    gem_anim_count++;
    if(gem_anim_count > 10){
      vdp_select_sprite(gem_sprite_ID);
      vdp_next_sprite_frame();
      gem_anim_count=0;
    }

    vdp_refresh_sprites();

    if(vdp_getKeyCode() == 27) break;
  }

  vdp_set_text_colour( 128  );
  vdp_cls();
  vdp_cursor_enable(true);


  return 0; 
}
