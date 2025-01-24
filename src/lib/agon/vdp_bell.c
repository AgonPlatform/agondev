#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A vdu_bell = { 7 };

void vdp_bell( void ) { VDP_PUTS( vdu_bell ); }
