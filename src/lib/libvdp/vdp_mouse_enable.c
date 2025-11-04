#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_MOUSE      vdu_mouse_enable       = { 23, 0, 0x89, 0 };

void vdp_mouse_enable( void ) { VDP_PUTS( vdu_mouse_enable ); }
