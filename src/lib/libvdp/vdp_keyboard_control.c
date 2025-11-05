#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_W_W_B vdu_keyboard_control = { 23, 0, 0x88, 0, 0, 0 };

void vdp_keyboard_control( int delay, int rate, int led )
{
	vdu_keyboard_control.w0 = delay;
	vdu_keyboard_control.w1 = rate;
	vdu_keyboard_control.b2 = led;
	VDP_PUTS( vdu_keyboard_control );
}