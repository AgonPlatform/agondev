/*
Example of using:
  vdp_waitKeyDown();   wait until a key is pressed
  vdp_waitKeyUp();     wait until no key is pressed
  vdp_getKeyCode();    return ascii code of current single key
                        or 0 if none
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <agon/vdp_vdu.h>
#include <agon/vdp_keyboard.h>

int main(void) {
  vdp_cursor_enable(false);
  vdp_clear_screen();
  printf("Agon Keyboard Up/Down Example\n\n");
  printf("Press ESC Exit\n\n");

  while(true) {
    vdp_cursor_tab(0,6);
    printf("Press any key ");
    vdp_waitKeyDown();
    if(vdp_getKeyCode() == 27) break;
    vdp_cursor_tab(0,6);
    printf("OK, now let go");
    vdp_waitKeyUp();
  }

  vdp_cursor_enable(true);
  vdp_clear_screen();
  return 0; 
}
