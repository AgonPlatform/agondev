#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD vdu_set_text_viewport_via_plot = { 23, 0, 0x9C };

void vdp_set_text_viewport_via_plot( void ) { VDP_PUTS( vdu_set_text_viewport_via_plot ); }
