#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_n vdu_send_to_screen = { 27, 0 };

void vdp_send_to_screen( char ch )
{
	vdu_send_to_screen.n = ch;
	VDP_PUTS( vdu_send_to_screen );
}
