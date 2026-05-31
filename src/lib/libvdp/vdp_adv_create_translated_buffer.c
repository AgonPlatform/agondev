#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>


void vdp_adv_create_translated_buffer( uint16_t transformID, int16_t x, int16_t y ){
	// create a transform matrix
	// VDU 23, 0, &A0, bufferId; 32, operation, [<format>, <arguments...>]
	putch(23);                      // vdu buffer command
	putch(0);
	putch(0xA0);

	putch(transformID % 256);
	putch(transformID >> 8);

	putch(32);                    // command no 32 Create or manipulate a 2D affine transformation matrix
	putch(6);                     // operation 6=translate

	putch(0x00 | 0x40 | 0x80);    // format fixed point, 16 bit, shift point x 0.

	putch(x % 256);
	putch(x >> 8);

	putch(y % 256);
	putch(x >> 8);

}

 