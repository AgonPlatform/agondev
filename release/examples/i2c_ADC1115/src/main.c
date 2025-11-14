/*
Illustrates example of a small external ASM library to:
1. Open i2c bus (standrd MOS call).
2. Configure i2c module (external ASM library).
3. Read i2c data (external ASM library).
4. Close i2c bus (standrd MOS call).

This example displays two bytes read from an ADC1115 converter module.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <agon/vdp.h>
#include <agon/timer.h>
#include "i2c_adc1115.h"

uint16_t ADC_reading = 0;
uint8_t bytes[2];

int main(void) {

  vdp_cursor_enable(false);
  vdp_clear_screen();

  mos_i2c_open(3);                                           // open i2c port. 3 is standard fast speed setting
  i2c_sendAdcConfig();                                       // external function to configure i2c module

  printf("AgonDev Analog to Digital Example\n\n");
  printf("With i2c ADS1115 15bit module\n\n");
  printf("Press ESC to exit");

  vdp_cursor_tab(0,8);
  printf("             MSB LSB");

  while(true) {
    ADC_reading = i2c_readAdc();                              // external function to read ADC data
    bytes[0] = ADC_reading >> 8;                              // high byte
    bytes[1] = ADC_reading & 0x00FF;                          // low byte
    vdp_cursor_tab(0,10);
    printf("ADC Reading: %02X  %02X  ",bytes[0],bytes[1]);
    delay(50);                                                // just a little delay so not running too fast
    if(vdp_getKeyCode() == 27) break;                         // exit if ESC pressed
  }

  vdp_cursor_enable(true);
  vdp_clear_screen();

  mos_i2c_close();                                            // close i2c port
  return 0; 
}
