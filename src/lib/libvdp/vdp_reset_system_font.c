#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD vdu_reset_system_font = { 23, 0, 0x91 };

void vdp_reset_system_font( void ) { VDP_PUTS( vdu_reset_system_font ); }
