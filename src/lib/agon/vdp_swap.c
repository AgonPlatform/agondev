#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD vdu_swap = { 23, 0, 0xC3 };

void vdp_swap( void ) { VDP_PUTS( vdu_swap ); }
