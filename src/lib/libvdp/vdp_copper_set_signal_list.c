#include <stdint.h>
#include <stdio.h>
#include <agon/vdp.h>

// VDU 23, 0, &C4, 3, <bufferId>;

void vdp_copper_set_signal_list(uint16_t bufferID ){

    putch(23);                   // vdu command
    putch(0);
    putch(0xC4);

    putch(3);                    // option

    putch(bufferID % 256);       // bufferID
    putch(bufferID >> 8);        // bufferID

}