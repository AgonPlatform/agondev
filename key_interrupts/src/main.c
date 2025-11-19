/*
 Keyboard Interrupt handler
 Example of event notification and global variables with ASM data
 */
 
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <agon/vdp.h>
#include <agon/mos.h>
#include <agon/timer.h>
#include "getKbData.h"

void keyEvent(void);

struct keyPacket{                           // define a struct for keyboard events
  uint8_t asciiCode;
  uint8_t modifier;
  uint8_t fabGLCode;
  uint8_t upDownState;
};

struct keyPacket agonKeyEvent;              // create a global struct for keyboard events

int main(void)                          
{
  vdp_cursor_enable(0);
  vdp_clear_screen();
  vdp_set_text_colour( BRIGHT_RED );        // make all text birght red
  printf("Keyboard Interrupts Example");    // print some text
  vdp_set_text_colour( BRIGHT_WHITE );      // make all text bright white
  vdp_cursor_tab(0,10);

  // NOTE: event handler must be cleared before exit to MOS
  mos_setkbvector( keyEvent, 0);            // setup event handler. length: 0=24bit, 1=16bit

  while(true) {

    vdp_cursor_tab(0,4);

    // print out each indiviual global variables  
    vdp_set_text_colour( BRIGHT_WHITE );  
    printf("Global variables\n");
    vdp_set_text_colour( BRIGHT_YELLOW );
    printf("ascii code    = %d     \n", myAscii);
    printf("fabGL code    = %d     \n", myFab);
    printf("modifier key  = %d     \n", myMod);
    printf("up/down state = %d     \n", myState);    
    printf("\n\n");

    // print out each of the elements of the array
    vdp_set_text_colour( BRIGHT_WHITE );  
    printf("Array data [0] to [3]\n");
    vdp_set_text_colour( BRIGHT_YELLOW );
    for(int loop = 0; loop < sizeof(keyArray); loop++){
      printf("%d ", keyArray[loop]);
    }

    // print out each of the elements of the struct  
    printf("\n\n");
    vdp_set_text_colour( BRIGHT_WHITE );  
    printf("Struct data\n");
    vdp_set_text_colour( BRIGHT_YELLOW );
    printf("agonKeyEvent.asciiCode   = %d     \n", agonKeyEvent.asciiCode);
    printf("agonKeyEvent.modifier    = %d     \n", agonKeyEvent.modifier);
    printf("agonKeyEvent.fabGLCode   = %d     \n", agonKeyEvent.fabGLCode);
    printf("agonKeyEvent.upDownState = %d     \n", agonKeyEvent.upDownState);    

    if(vdp_getKeyCode() == 27) break;     // exit if ESC pressed
    delay(25);                            // just so not running too fast
  }

  vdp_set_text_colour( BRIGHT_WHITE );  
  mos_setkbvector(0,0);                   // clear event handler
  vdp_cursor_enable(1);
  vdp_clear_screen();
	return 0; 
}


void keyEvent(void){                      // gets called with every new keyboard data packaet

  getKbData();                            // asm routine fills global variables with new data

  // copy array data into struct

  // easy to understand method:
    // agonKeyEvent.asciiCode = keyArray[0];
    // agonKeyEvent.modifier = keyArray[1];
    // agonKeyEvent.fabGLCode = keyArray[2];
    // agonKeyEvent.upDownState = keyArray[3];

  // faster method, assuming array and struct are in same order:
  memcpy(&agonKeyEvent, keyArray, sizeof(keyArray));
}

