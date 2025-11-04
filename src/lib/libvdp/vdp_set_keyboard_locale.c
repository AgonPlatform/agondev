#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_B vdu_set_keyboard_locale = { 23, 0, 0x81, 0 }; 

void vdp_set_keyboard_locale( int locale )
{
	vdu_set_keyboard_locale.b0 = locale;
	VDP_PUTS( vdu_set_keyboard_locale );
}