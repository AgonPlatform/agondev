#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A vdu_enable_screen = { 6 };

void vdp_enable_screen( void ) { VDP_PUTS( vdu_enable_screen ); }
