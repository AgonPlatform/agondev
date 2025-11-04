#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD vdu_terminal_mode = { 23, 0, 0xFF };

void vdp_terminal_mode( void ) { VDP_PUTS( vdu_terminal_mode ); }
