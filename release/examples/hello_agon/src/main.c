/*
 Hello World - C example
 with bonus Agon colours
 */
 
#include <stdio.h>
#include <stdint.h>
#include <agon/vdp.h>

int main(void)
{
    vdp_set_text_colour( BRIGHT_RED );    // make all text birght red
    printf("Hello, ");                    // print some text

    vdp_set_text_colour( BRIGHT_YELLOW ); // make all text bright yellow
    vdp_set_text_colour( 128 + BLUE );    // make text background (add 128) blue
    printf("Agon!\n");                    // print some text, followed by return character

    vdp_set_text_colour( BRIGHT_WHITE );  // make text white and...
    vdp_set_text_colour( 128 );           // text background black before returning to MOS

	return 0; 
}
