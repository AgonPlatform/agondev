#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <mos_api.h>
#include <agon/vdp_vdu.h>
#include "agon/timer.h"
#include "agon/joystick.h"

void print_bits(uint8_t input) {
    for (int i = 7; i >= 0; i--) {
        putchar((input & (1 << i)) ? '1' : '0');
        putchar(' ');
    }
}

int main(void) {
  bool done = false;
  resetJoysticks(); // reset all joystick ports to their input state
  vdp_clear_screen();
  printf("Press button1 on Joystick 1");
  while(!(joystick1_BUTTON1(getJoystickButtons()))); // wait for press
  delay(300); // a little debounce to wait for the button to settle back down
  while(!done) {
    vdp_cursor_tab(0,0);
    uint16_t joy = getJoystickButtons(); // get the state of all buttons
    printf("Press button1 on Joystick 1 to exit\n\n");
    printf("FIRE status       DIRECTION status\n");
    print_bits(joy >> 8);
    putchar('-');
    putchar(' ');
    print_bits(joy);
    putchar('\n');
    done = joystick1_BUTTON1(joy);
    delay(100);
  }
  return 0; 
}
