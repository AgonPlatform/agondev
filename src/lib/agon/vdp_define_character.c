#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_B vdu_define_character = { 23, 0, 0x90, 0 };

void vdp_define_character( int char_num, uint8_t *data )
{
	if ( !data ) return;
	vdu_define_character.b0 = char_num;
	VDP_PUTS( vdu_define_character );
	mos_puts( (char*)data, 8, 0 );
}
