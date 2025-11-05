#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD vdu_set_graphics_viewport_via_plot = { 23, 0, 0x9D };

void vdp_set_graphics_viewport_via_plot( void ) { VDP_PUTS( vdu_set_graphics_viewport_via_plot ); }
