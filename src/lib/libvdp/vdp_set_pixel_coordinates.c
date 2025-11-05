#include <agon/vdp.h>

static VDU_A_B_CMD_n vdu_set_pixel_coordinates = { 23, 0, 0xC0, 0 }; 

void vdp_set_pixel_coordinates(void) {
    VDP_PUTS(vdu_set_pixel_coordinates);
}