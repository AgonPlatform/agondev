#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_A vdu_page_mode_off = { 15 };

void vdp_page_mode_off( void ) { VDP_PUTS( vdu_page_mode_off ); }
