/*
Example of:
  1) sending strings/char out USB serial port for debugging

Uses:
	void vdp_send_to_printer( char ch );
	void vdp_enable_printer( void );
	void vdp_disable_printer( void );
*/

#include <stdint.h>
#include <stdio.h>
#include <agon/vdp_vdu.h>
#include <agon/vdp_keyboard.h>

char debug = 'C';

int main(void) {

	vdp_cursor_enable(false);
	vdp_clear_screen();
	vdp_set_pixel_coordinates();
	printf("AgonDev 'Enable Printer' Debugging Example\n\n");
	printf("Press P to Print to VDU Only\n");
	printf("Press S to Send to VDU & Serial Port\n");
	printf("Press C to Send Char to Serial Port Only\n\n");
	printf("Press ESC to Exit\n\n");

  while(true) {

	// Screen Only
    if(vdp_getKeyCode() == 112) {
		printf("Pressed P\n");
      	vdp_waitKeyUp();
	};
	
	// Debug string and to screen
    if(vdp_getKeyCode() == 115) {
		vdp_enable_printer();
		printf("Pressed S\n");

		vdp_disable_printer();
		vdp_waitKeyUp();
	};

	// Debug single char only
    if(vdp_getKeyCode() == 99) {
		
		vdp_enable_printer();
		vdp_send_to_printer( debug);

		vdp_disable_printer();
		vdp_waitKeyUp();
	};

    if(vdp_getKeyCode() == 27) break;
  }

  vdp_clear_screen();
  vdp_cursor_enable(true);

  return 0; 
}

