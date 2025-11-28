#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD	vdu_set_software_sprite = { 23, 27, 20 };

//VDU 23, 27, 20: Set sprite to be a software sprite
void vdp_set_software_sprite(void) {
	VDP_PUTS( vdu_set_software_sprite );
}
