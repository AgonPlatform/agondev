#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>


void vdp_adv_apply_transformation_with_stride(uint16_t sourceID, uint16_t destID, uint16_t transformID, uint16_t offset, uint16_t stride){

	// Command 41: Apply a transform matrix to data in a buffer
	// VDU 23, 0, &A0, bufferId; 41, options, format, transformBufferId; sourceBufferId; [<arguments>]
	// This command is specifically to transform PLOT commands which need an offset and stride, normally 2 and 6 resprectively

	putch(23);                      // vdu buffer command
	putch(0);
	putch(0xA0);

	putch(destID % 256);
	putch(destID >> 8);

	putch(41);                      // command
	putch(6);                       // options; 2 has ofset, 4 has stride 

	putch(0x00 | 0x40 | 0x80);      // format fixed point, 16 bit, shift point x 0.

	putch(transformID % 256);
	putch(transformID >> 8);

	putch(sourceID % 256);
	putch(sourceID >> 8);

	putch(offset % 256);
	putch(offset >> 8);

	putch(stride % 256);
	putch(stride >> 8);

}
