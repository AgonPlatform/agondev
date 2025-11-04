#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A vdu_write_at_text_cursor = { 4 };

void vdp_write_at_text_cursor( void ) { VDP_PUTS( vdu_write_at_text_cursor ); }
