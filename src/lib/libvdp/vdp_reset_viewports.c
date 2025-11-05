#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A vdu_reset_viewports = { 26 };

void vdp_reset_viewports( void ) { VDP_PUTS( vdu_reset_viewports ); }
