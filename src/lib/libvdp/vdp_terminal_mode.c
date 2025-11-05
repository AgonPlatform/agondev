#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD vdu_terminal_mode = { 23, 0, 0xFF };

void vdp_terminal_mode( void ) { VDP_PUTS( vdu_terminal_mode ); }
