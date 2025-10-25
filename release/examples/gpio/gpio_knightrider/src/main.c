/*
 * Demonstration of the (much) faster PinID functions, that combine the PortID with Pin using a single parameter
 * All ports defined in agon/gpio.h
 *
 */

#include <stdint.h>
#include <agon/timer.h>
#include <agon/gpio.h>

int main(void)
{
  uint16_t pins[] = {PC0, PC1, PC2, PC3, PC4, PC5, PC6, PC7};

  // One can use a single PINID, or combine them using an OR statement
  // They need to be on the same Port (B / C / D)
  outputModePinID(PC0 | PC1 | PC2 | PC3 | PC4 | PC5 | PC6 | PC7); // All pins of port C in output mode

  outputLowPinID(PC0 | PC1 | PC2 | PC3 | PC4 | PC5 | PC6 | PC7); // All output pins to low voltage

  while(1) {
    // Forward
    for(int n = 0; n < 8; n++) {
      outputHighPinID(pins[n]);
      delay(150);
      outputLowPinID(pins[n]);
      delay(150);
    }
    // Back
    for(int n = 6; n > 0; n--) {
      outputHigh(PORTC, n);
      delay(150);
      outputLowPinID(pins[n]);
      delay(150);
    }
  }
	return 0; 
}
