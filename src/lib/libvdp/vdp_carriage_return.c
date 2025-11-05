#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A vdu_carriage_return = { 13 };

void vdp_carriage_return( void ) { VDP_PUTS( vdu_carriage_return ); }
