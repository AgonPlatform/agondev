#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include <agon/vdp_vdu.h>
#include <agon/vdp_keyboard.h>
#include <agon/timer.h>

void print_bits(uint8_t input) {
    for (int i = 7; i >= 0; i--) {
        putchar((input & (1 << i)) ? '1' : '0');
        putchar(' ');
    }
    putchar('\n');
}

int main(void) {
  vdp_cursor_enable(false);
  vdp_clear_screen();
  printf("Agon Keyboard Matrix\n\n");
  printf("Press CTRL-L & CTRL-R to Exit\n\n");
  printf("bits 7 6 5 4 3 2 1 0");
  while(true) {
    vdp_cursor_tab(0,6);
    for(int i = 0; i < 16; i++) {
      uint8_t m = vdp_getKeyMap(i);
      printf("0x%02X ", i);
      print_bits(m);
    }
    delay(50);
    if (vdp_getKeyMap(0) == 0b10010000) break;
  }
  vdp_cursor_enable(true);
  return 0; 
}
