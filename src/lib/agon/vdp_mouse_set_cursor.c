#include <agon/vdp_vdu.h>
#include <stdio.h>
#include <mos_api.h>
#include <stdbool.h>
#include <stdlib.h>

static VDU_MOUSE_W    vdu_mouse_set_cursor   = { 23, 0, 0x89, 3, 0 };

void vdp_mouse_set_cursor( int cursorId )
{
	vdu_mouse_set_cursor.w0 = cursorId;
	VDP_PUTS( vdu_mouse_set_cursor );
}
