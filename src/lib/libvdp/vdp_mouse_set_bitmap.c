#include <agon/vdp.h>

static VDU_MOUSE_B   vdu_mouse_set_bitmap  = { 23, 27, 0x40, 0, 0 };

void vdp_mouse_set_bitmap(int hotx, int hoty) {
	vdu_mouse_set_bitmap.SUBCMD = hotx;
    vdu_mouse_set_bitmap.b0 = hoty;
	VDP_PUTS( vdu_mouse_set_bitmap );
}
