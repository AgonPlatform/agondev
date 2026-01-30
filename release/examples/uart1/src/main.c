// Example of sending and receiving single bytes on UART1
// This uses a non-blocking mos call
//
// mos_uputc(uint8_t) will send a single byte out the uart1 port
// mos_ugetc_nb() will return one byte received 0-255, or -1 if no data
// alternatively, mos_ugetc() could be used, but is blocking and therefore will not  
// return until there is data, so is not used in this example

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <agon/vdp.h>
#include <agon/mos.h>

int main(void)

{
	UART uart1Settings;									// 'UART' struct is defined in mos.h
		
	uart1Settings.baudRate = 9600;						// define UART1 port settings
	uart1Settings.dataBits = 8;
	uart1Settings.stopBits = 1;
	uart1Settings.parity = 0;
	uart1Settings.flowcontrol= 0;
	uart1Settings.eir = 0;

	mos_uopen(&uart1Settings);							// pass address of struct to open UART1 port

	vdp_cls();											// clear the screen
    printf("AgonDev UART1 non-blocking example\n\n");	// print title caption
    printf("Press keys to send data\n\n");
	printf("Or ESC to exit\n\n");

    while(1){											// loop forever
		
		uint8_t k = vdp_getKeyCode();					// get key pressed code, or 0 for none

		// check if ESC key
		if (k == 27) break;
		
		// send the code if we type something
		if (k !=0 ){								
			mos_uputc(k);								// send the char via UART1
			vdp_cursor_tab(0,6);
			printf("Sent: %c", k);						// display the char we typed
			vdp_waitKeyUp();							// wait until we release the key
		}

		// check for received data
		int24_t uartChar = mos_ugetc_nb();				// read UART1 port buffer
		if (uartChar != -1){							// -1 means no data or error
			vdp_cursor_tab(0,8);
			printf("received: %c", uartChar);			// print char received, will only be 0-255
		}
	}

	mos_uclose();										// close UART1 port
	vdp_clear_screen();									// clear screen to tidy up
	return 0; 											// return to MOS
}


