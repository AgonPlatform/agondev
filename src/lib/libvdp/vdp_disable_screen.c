#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A vdu_disable_screen = { 21 };

void vdp_disable_screen( void ) { VDP_PUTS( vdu_disable_screen ); }
