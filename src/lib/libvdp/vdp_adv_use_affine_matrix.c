#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>


// VDU 23, 0, &96, <flags>, <bufferId>;: Set an affine transform matrix §§§§§§
// set flags to enable feature
void vdp_adv_use_affine_matrix(uint8_t flags, uint16_t affineID){

	putch(23);                    // vdu buffer command
	putch(0);
	putch(0x96);

	putch(flags);                   // bit 0 apply matrix

	putch(affineID % 256);		// buffer ID to use
	putch(affineID >> 8);

}