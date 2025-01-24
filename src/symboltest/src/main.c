#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <agon/vdp_vdu.h>

int main(void) {
    vdp_vdu_init();
    vdp_get_scr_dims(true);
    return 0;
}
