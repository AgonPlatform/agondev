/*
Example of creating User Defined Graphics
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <agon/vdp_vdu.h>
#include <agon/vdp_keyboard.h>

const uint8_t alien1 = 130;
const uint8_t alien2 = 131;

int main(void) {

  vdp_redefine_character_special(alien1,
    0b00000000,
    0b00000000,
    0b00111000,
    0b01111100,
    0b11010110,
    0b01111100,
    0b01010100,
    0b10000010);

    vdp_redefine_character_special(alien2,
    0b00000000,
    0b00000000,
    0b00111000,
    0b01111100,
    0b11010110,
    0b01111100,
    0b01010100,
    0b00101000);

  vdp_mode(8);
  vdp_cursor_enable(false);
  vdp_clear_screen();

  printf("AgonDev User Defined Graphic Example\n\n");
  printf("Press ESC Exit");

 
  for (int x = 0; x < 40; x += 4){
    for (int y = 6; y < 13; y += 2){
      vdp_cursor_tab(x, y);
      printf("%c %c ",alien1, alien2);
    }
  }

  while(true) {
    if(vdp_getKeyCode() == 27) break;
  }

  vdp_cursor_enable(true);
  vdp_clear_screen();
  return 0; 
}
