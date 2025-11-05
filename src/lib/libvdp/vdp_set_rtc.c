#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_ui8x8 vdu_set_rtc = { 23, 0, 0x87, 1, 0, 0, 0, 0, 0, 0 };

void vdp_set_rtc( int year, int month, int day, int hours, int minutes, int seconds )
{
	vdu_set_rtc.b2 = year;
	vdu_set_rtc.b3 = month;
	vdu_set_rtc.b4 = day;
	vdu_set_rtc.b5 = hours;
	vdu_set_rtc.b6 = minutes;
	vdu_set_rtc.b7 = seconds;
	VDP_PUTS( vdu_set_rtc );
}