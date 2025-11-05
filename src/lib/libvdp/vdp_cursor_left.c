#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A vdu_cursor_left = { 8 };

void vdp_cursor_left( void ) { VDP_PUTS( vdu_cursor_left ); }
