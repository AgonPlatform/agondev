#include <stdint.h>
#include <stdio.h>
#include <agon/vdp.h>

// VDU 23, 0, &C4, 2, <paletteID>; <index>, <red>, <green>, <blue>

void vdp_copper_set_palette_entry(uint16_t paletteID, uint8_t indx, uint8_t red, uint8_t green, uint8_t blue ){

    putch(23);                    // vdu command
    putch(0);
    putch(0xC4);

    putch(2);                    // option

    putch(paletteID % 256);      // palette ID
    putch(paletteID >> 8);       // palette ID

    putch(indx);                 // index

    putch(red);                  // colour value
    putch(green);                // colour value
    putch(blue);                 // colour value

}