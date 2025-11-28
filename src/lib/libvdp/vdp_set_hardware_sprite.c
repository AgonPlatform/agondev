#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD	vdu_set_hardware_sprite = { 23, 27, 19 };

//VDU 23, 27, 19: Set sprite to be a hardware sprite
void vdp_set_hardware_sprite(void) {
	VDP_PUTS( vdu_set_hardware_sprite );
}


