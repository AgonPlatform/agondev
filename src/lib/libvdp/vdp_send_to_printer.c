#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_n vdu_send_to_printer = { 1, 0 };

void vdp_send_to_printer( char ch )
{
	vdu_send_to_printer.n = ch;
	VDP_PUTS( vdu_send_to_printer );
}
