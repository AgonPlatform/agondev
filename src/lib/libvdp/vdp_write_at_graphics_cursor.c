#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A vdu_write_at_graphics_cursor = { 5 };

void vdp_write_at_graphics_cursor( void ) { VDP_PUTS( vdu_write_at_graphics_cursor ); }
