/*
 * Title:         Arduino-like blink example			
 * Author:        Jeroen Venema
 * Created:		    25/10/2025
 * Last Updated:	25/10/2025
 *
 * Example usage of the agon/gpio library using the easiest, but 'slowest' outputMode/outputHigh functions
 * Agon has three 8-bit ports - PORTB / PORTC / PORTD
 * The first argument to these functions is the port, the second is the bitnumber (0-7)
 * For example, if the physical pin has the label 'PC0' - this is pin 0 on PORTC
 *
 * For this example:
 * Connect a LED with it's anode (positive side) to PC0, and connect a 470ohm - 1Kohm resistor between GND and the LEDs cathode (negative side)
 * The LED should blink every second
 *
 */

#include <agon/timer.h>
#include <agon/gpio.h>

int main(void)
{
  outputMode(PORTC, 0);
  while(1) {
    outputHigh(PORTC, 0);
    delay(500);
    outputLow(PORTC, 0);
    delay(500);
  }
  
	return 0; 
}
