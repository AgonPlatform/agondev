#include <stdint.h>
#include <stdio.h>
#include <agon/vdp.h>

// VDU 23, 0, &F8, &310; 0;

void vdp_copper_disable(void){

    putch(23);            // vdu command
    putch(0);
    putch(0xF9);

    putch(0x10);          // 0x0310
    putch(0x03);          // 

}