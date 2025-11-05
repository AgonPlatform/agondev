#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A vdu_clear_graphics = { 16 };

void vdp_clear_graphics( void ) { VDP_PUTS( vdu_clear_graphics ); }
