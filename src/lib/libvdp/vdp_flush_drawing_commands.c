#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A_B_CMD vdu_flush_drawing_commands = { 23, 0, 0xCA };

void vdp_flush_drawing_commands( void ) { VDP_PUTS( vdu_flush_drawing_commands ); }
