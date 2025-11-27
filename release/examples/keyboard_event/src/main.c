#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <agon/keyboard.h>
#include <agon/vdp.h>

int main(void) {
  vdp_cls();
	struct keyboard_event_t e;

	printf("agon/keyboard.h demo. Press 'q' to exit.\n");

	/* Initialize keyboard buffer to store 16 events (key up and down) */
	kbuf_init(16);

	do {
		// Wait for an event. In a game loop you would just
		// poll for events until there is none, and stop.
		// But here we want the next key.
		while (!kbuf_poll_event(&e)) {}

		printf("Asci: %c, Vkey: %d State: %s\r\n", e.ascii ? e.ascii : ' ', e.vkey, e.isdown ? "down" : "up");
	} while (e.ascii != 'q');

	/* Must deinit, or the MOS key event vector is not unset (also frees buffer)  */
	kbuf_deinit();

	return 0;
}
