#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_B	vdu_replace_sprite_frame = { 23, 27, 21, 0 };

//VDU 23, 27, 21, n; Replace currently selected frame of current sprite with bitmap n
void vdp_replace_sprite_frame(uint8_t bitmapID) {
    vdu_replace_sprite_frame.b0 = bitmapID;
	VDP_PUTS( vdu_replace_sprite_frame );
}





