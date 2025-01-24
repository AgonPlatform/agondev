#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD vdu_move_graphics_origin_and_viewport = { 23, 0, 0x9C };

void vdp_move_graphics_origin_and_viewport( void ) { VDP_PUTS( vdu_move_graphics_origin_and_viewport ); }
