#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_W_W	vdu_capture_bitmap = { 23, 27, 1, 0, 0 };

// VDU 23, 27, 1, n, 0, 0;: Capture screen data into bitmap n
void vdp_capture_bitmap(uint16_t top, uint16_t left, uint16_t bottom, uint16_t right, uint8_t bitmapID) {
    vdp_move_to(left, top);
    vdp_move_to(right, bottom);
    vdu_capture_bitmap.w0 = bitmapID; // VDP API only used LSB
	VDP_PUTS( vdp_capture_bitmap );
}





