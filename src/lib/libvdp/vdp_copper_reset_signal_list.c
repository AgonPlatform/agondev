#include <stdint.h>
#include <stdio.h>
#include <agon/vdp.h>

// VDU 23, 0, &C4, 4

void vdp_copper_reset_signal_list(void){

    putch(23);                    // vdu buffer command
    putch(0);
    putch(0xC4);

    putch(4);                    // option

}