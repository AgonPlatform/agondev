#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A vdu_disable_printer = { 3 };

void vdp_disable_printer( void ) { VDP_PUTS( vdu_disable_printer ); }
