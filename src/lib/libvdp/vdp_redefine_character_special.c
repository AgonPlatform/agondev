#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_n_ui8x8 vdu_redefine_character_special = { 23, 0, 0x90, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void vdp_redefine_character_special( int char_num, uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4, uint8_t b5, uint8_t b6, uint8_t b7 )
{
	vdu_redefine_character_special.n = char_num;
	vdu_redefine_character_special.b0 = b0;
	vdu_redefine_character_special.b1 = b1;
	vdu_redefine_character_special.b2 = b2;
	vdu_redefine_character_special.b3 = b3;
	vdu_redefine_character_special.b4 = b4;
	vdu_redefine_character_special.b5 = b5;
	vdu_redefine_character_special.b6 = b6;
	vdu_redefine_character_special.b7 = b7;
	VDP_PUTS( vdu_redefine_character_special );
}