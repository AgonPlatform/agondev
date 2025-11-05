#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A vdu_cursor_down = { 10 };

void vdp_cursor_down( void ) { VDP_PUTS( vdu_cursor_down ); }
