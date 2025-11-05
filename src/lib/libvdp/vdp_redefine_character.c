#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_ui8x8 vdu_redefine_character = { 23, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void vdp_redefine_character( int char_num, uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4, uint8_t b5, uint8_t b6, uint8_t b7 )
{
	if ( char_num > 255 ) return;
	if ( char_num < 32 ) vdp_redefine_character_special( char_num, b0, b1, b2, b3, b4, b5, b6, b7 );
	vdu_redefine_character.B = char_num;
	vdu_redefine_character.b0 = b0;
	vdu_redefine_character.b1 = b1;
	vdu_redefine_character.b2 = b2;
	vdu_redefine_character.b3 = b3;
	vdu_redefine_character.b4 = b4;
	vdu_redefine_character.b5 = b5;
	vdu_redefine_character.b6 = b6;
	vdu_redefine_character.b7 = b7;
	VDP_PUTS( vdu_redefine_character );
}