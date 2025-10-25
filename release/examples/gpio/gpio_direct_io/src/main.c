/*
 * Title:			io example
 * Author:			Jeroen Venema
 * Created:			10/04/2025
 * Last Updated:	10/04/2025 
 *
 * Modinfo:
 */
 
#include <stdint.h>

#define IO(addr) (*((volatile uint8_t __attribute__((address_space(3)))*)(addr)))

int main( void )
{
    // useless code
    uint8_t x = IO(0x0A); // Produces IN0
    IO(0x16) = 0x02; // Produces OUT0
    return 0;
} 

