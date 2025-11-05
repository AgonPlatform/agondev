#include <agon/vdp_vdu.h>

static VDU_A_CMD_x_y vdu_fill_path = { 25, 0xDD, 0, 0 };

void vdp_fill_path(const int* path, int pathsize) {
    pathsize = pathsize / sizeof(int);
    if (pathsize & 1) {
        // uneven number of X,Y coordinates
        return;
    }
    if(pathsize < 6) {
        // Need at least 3 X,Y coordinates
        return;
    }
    vdp_move_to(path[0], path[1]);
    vdp_move_to(path[2], path[3]);

    for(int id = 4; id < pathsize; id += 2) {
        vdu_fill_path.x = path[id];
        vdu_fill_path.y = path[id + 1];
        VDP_PUTS( vdu_fill_path);
    }
    return;
}