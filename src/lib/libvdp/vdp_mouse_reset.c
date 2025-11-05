#include <agon/vdp.h>
#include <stdio.h>
#include <agon/mos.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_MOUSE      vdu_mouse_reset        = { 23, 0, 0x89, 2 };

void vdp_mouse_reset( void ) { VDP_PUTS( vdu_mouse_reset ); }
