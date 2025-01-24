#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_ui8x8 vdu_set_dotted_line_pattern = { 23, 6, 0, 0, 0, 0, 0, 0, 0, 0 };

void vdp_set_dotted_line_pattern( uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4, uint8_t b5, uint8_t b6, uint8_t b7 )
{
	vdu_set_dotted_line_pattern.b0 = b0;
	vdu_set_dotted_line_pattern.b1 = b1;
	vdu_set_dotted_line_pattern.b2 = b2;
	vdu_set_dotted_line_pattern.b3 = b3;
	vdu_set_dotted_line_pattern.b4 = b4;
	vdu_set_dotted_line_pattern.b5 = b5;
	vdu_set_dotted_line_pattern.b6 = b6;
	vdu_set_dotted_line_pattern.b7 = b7;
	VDP_PUTS( vdu_set_dotted_line_pattern );
}
