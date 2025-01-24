#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A vdu_enable_printer = { 2 };

void vdp_enable_printer( void ) { VDP_PUTS( vdu_enable_printer ); }
