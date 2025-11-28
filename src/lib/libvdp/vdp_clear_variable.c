#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_W	vdu_clear_variable = { 23, 0, 0xF9, 0 };

// VDU 23, 0, &F9, variableId;: Clear a VDP Variable
void vdp_clear_variable(uint16_t variableId) {
	vdu_clear_variable.w0 = variableId;
	VDP_PUTS( vdu_clear_variable );
}