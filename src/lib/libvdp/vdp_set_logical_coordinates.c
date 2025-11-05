#include <agon/vdp.h>

static VDU_A_B_CMD_n vdu_set_logical_coordinates = { 23, 0, 0xC0, 1 }; 

void vdp_set_logical_coordinates(void) {
    VDP_PUTS(vdu_set_logical_coordinates);
}