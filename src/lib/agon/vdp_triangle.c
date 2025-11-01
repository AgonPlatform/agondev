#include <agon/vdp_vdu.h>

void vdp_triangle( int x1, int y1, int x2, int y2, int x3, int y3 ) {
    vdp_move_to(x1,y1);
    vdp_line_to(x2,y2);
    vdp_line_to(x3,y3);
    vdp_line_to(x1,y1);
}
