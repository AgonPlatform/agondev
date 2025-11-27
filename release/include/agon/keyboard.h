#ifndef KEYBOARD_BUFFER_H
#define KEYBOARD_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

struct __attribute__((packed)) keyboard_event_t {
	uint8_t ascii;
	uint8_t kmod;
	uint8_t vkey;
	uint8_t isdown;
};

extern void kbuf_init(uint8_t buf_len);
extern bool kbuf_poll_event(struct keyboard_event_t *e);
extern void kbuf_clear(void);
extern void kbuf_deinit();

#endif /* KEYBOARD_BUFFER_H */
