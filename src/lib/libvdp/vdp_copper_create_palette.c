#include <stdint.h>
#include <stdio.h>
#include <agon/vdp.h>

// VDU 23, 0, &C4, 0, <paletteID>;

void vdp_copper_create_palette(uint16_t paletteID){

    putch(23);                   // vdu command
    putch(0);
    putch(0xC4);

    putch(0);                    // command

    putch(paletteID % 256);          // palette ID
    putch(paletteID >> 8);          // palette ID

}