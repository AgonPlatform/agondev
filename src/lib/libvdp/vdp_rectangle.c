#include <agon/vdp.h>

void vdp_rectangle( int x1, int y1, int x2, int y2 ) {
    vdp_move_to(x1, y1);
    vdp_line_to(x2, y1);
    vdp_line_to(x2, y2);
    vdp_line_to(x1, y2);
    vdp_line_to(x1, y1);
}
