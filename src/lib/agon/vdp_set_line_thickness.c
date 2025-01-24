#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_CMD_n vdu_set_line_thickness = { 23, 23, 0 };

void vdp_set_line_thickness( int pixels )
{
	vdu_set_line_thickness.CMD = pixels;
	VDP_PUTS( vdu_set_line_thickness );
}
