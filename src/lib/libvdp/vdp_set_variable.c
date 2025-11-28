#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD_W_W	vdu_set_variable = { 23, 0, 0xF8, 0, 0 };

// VDU 23, 0, &F8, variableId; value;: Set a VDP Variable
void vdp_set_variable(uint16_t variableId, uint16_t value) {
	vdu_set_variable.w0 = variableId;
    vdu_set_variable.w1 = value;
	VDP_PUTS( vdu_set_variable );
}