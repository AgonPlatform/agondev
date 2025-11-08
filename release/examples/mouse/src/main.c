/*
Example of:
  1) displaying mouse information
  2) setting mouse icon
  3) setting custom mouse icon from bitmap

vdp_mouse_set_cursor( int cursorId );
default is 0

; 0 CursorPointerAmigaLike  
; 11x11 Amiga like colored mouse pointer

; 1 CursorPointerSimpleReduced  
; 10x15 mouse pointer

; 2 CursorPointerSimple     
; 11x19 mouse pointer

; 3 CursorPointerShadowed   
; 11x19 shadowed mouse pointer

; 4 CursorPointer   
; 12x17 mouse pointer

; 5 CursorPen   
; 16x16 pen

; 6 CursorCross1    
; 9x9 cross

; 7 CursorCross2    
; 11x11 cross

; 8 CursorPoint     
; 5x5 point

; 9 CursorLeftArrow     
; 11x11 left arrow

; 10 CursorRightArrow   
; 11x11 right arrow

; 11 CursorDownArrow    
; 11x11 down arrow

; 12 CursorUpArrow  
; 11x11 up arrow

; 13 CursorMove     
; 19x19 move

; 14 CursorResize1  
; 12x12 resize orientation 1

; 15 CursorResize2  
; 12x12 resize orientation 2

; 16 CursorResize3  
; 11x17 resize orientation 3

; 17 CursorResize4  
; 17x11 resize orientation 4

; 18 CursorTextInput    
; 7x15 text input

*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <agon/vdp.h>
#include "mouse.h"
#include "mouseIcons.h"

const uint8_t cursorBitmapID = 0;
const uint8_t screen_mode = 8;
const uint8_t maxIcons = 18;
uint8_t curIcon = 0;


int main(void) {

  vdp_mode(screen_mode);
  vdp_cursor_enable(false);
  vdp_set_pixel_coordinates();
  vdp_clear_screen();
  vdp_mouse_enable();

  vdp_select_bitmap(cursorBitmapID);
  vdp_load_bitmap( 16, 16, mouse_bod );

  // define bitmap as a cursor
  // VDU 23, 27, &40, hotX, hotY: Setup a mouse cursor
  // *** needs to be added to vdp.h and function made
  putch(23);
  putch(27);
  putch(0x40);
  putch(8);
  putch(8);
  //

  vdp_mouse_set_cursor( 64000 + cursorBitmapID); 

  printf("AgonDev Mouse Example\n\n");
  printf("Press ESC to exit\n\n");
  printf("Press S to step through standard icons\n\n");
  printf("Press C to show custom icon\n\n");

  while(true) {

    int mouseX = getsysvar_mouseX();
    int mouseY = getsysvar_mouseY();
    int mouseButtons = getsysvar_mouseButtons();
    int mouseWheel = getsysvar_mouseWheel();
    int mouseXDelta = getsysvar_mouseXDelta();
    int mouseYDelta = getsysvar_mouseYDelta();

    vdp_cursor_tab(0,10);
    printf("mouseX = %d     \n", mouseX );
    printf("mouseY = %d     \n", mouseY );
    printf("mouseButtons = %d     \n", mouseButtons );
    printf("mouseWheel = %d     \n", mouseWheel );
    printf("mouseXDelta = %d     \n", mouseXDelta );
    printf("mouseYDelta = %d     \n", mouseYDelta );
    printf("standard mouse icon = %d     \n", curIcon );

    // swap to custom mouseicon
    if(vdp_getKeyCode() == 99) {
      vdp_mouse_set_cursor( 64000 + cursorBitmapID);     
      vdp_waitKeyUp();
    };
    //step through standard icons
    if(vdp_getKeyCode() == 115) {
      curIcon ++;
      if (curIcon > maxIcons) curIcon = 0;
      vdp_mouse_set_cursor( curIcon); 
      vdp_waitKeyUp();
    };
    if(vdp_getKeyCode() == 27) break;
  }

  vdp_cls();
  vdp_cursor_enable(true);
  vdp_mouse_disable();

  return 0; 
}
