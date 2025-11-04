#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A vdu_reset_graphics = { 20 };

void vdp_reset_graphics( void ) { VDP_PUTS( vdu_reset_graphics ); }
