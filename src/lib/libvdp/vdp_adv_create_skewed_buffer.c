#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

#define FIXED_POINT_FRACTIONAL_BITS 8
uint16_t skewed_float_to_fixed(double input){
  return (uint16_t)(round(input * (1 << FIXED_POINT_FRACTIONAL_BITS))); 
}

void vdp_adv_create_skewed_buffer( uint16_t transformID, float scaleX, float scaleY){
	// create a transform matrix
	// VDU 23, 0, &A0, bufferId; 32, operation, [<format>, <arguments...>]
	putch(23);                      // vdu buffer command
	putch(0);
	putch(0xA0);

	putch(transformID % 256);
	putch(transformID >> 8);

	putch(32);                    // command no 32 Create or manipulate a 2D affine transformation matrix
	putch(8);                     // operation 5=scale

	putch(0x08 | 0x40 | 0x80);    // format fixed point, 16 bit, shift point x 8.

	putch(skewed_float_to_fixed(scaleX) % 256);   // x scale
	putch(skewed_float_to_fixed(scaleX) >> 8);   // x scale

	putch(skewed_float_to_fixed(scaleY) % 256);   // y scale
	putch(skewed_float_to_fixed(scaleY) >> 8);   // y scale

}