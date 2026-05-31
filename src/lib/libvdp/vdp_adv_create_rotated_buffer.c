#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

void vdp_adv_create_rotated_buffer( uint16_t transformID, uint16_t angle ){
	// create a transform matrix
	// VDU 23, 0, &A0, bufferId; 32, operation, [<format>, <arguments...>]
	putch(23);                      // vdu buffer command
	putch(0);
	putch(0xA0);

	putch(transformID % 256);
	putch(transformID >> 8);

	putch(32);                    // command no 32 Create or manipulate a 2D affine transformation matrix
	putch(2);                     // operation 2=rotate in degrees

	putch(0x00 | 0x40 | 0x80);    // format fixed point, 16 bit

	putch(angle % 256);
	putch(angle >> 8);

}