#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_n  vdu_outchar = { 27, 0 };

//VDU 27, char: Output character to screen
void vdp_outchar(uint8_t c) {
    vdu_outchar.n = c;
	VDP_PUTS( vdu_outchar );
}


