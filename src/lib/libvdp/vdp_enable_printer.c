#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A vdu_enable_printer = { 2 };

void vdp_enable_printer( void ) { VDP_PUTS( vdu_enable_printer ); }
