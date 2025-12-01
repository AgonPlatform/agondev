### Example of i2c Nunchuck library

Example of how to create a small library with i2c communications.

Provides the following functions:

extern void i2c_open(void);
extern uint24_t nunchuck_exists(void);
extern void nunchuck_open(void);
extern void nunchuck_update(void);
extern void i2c_close(void);
extern uint8_t getDisplayMode(void);

Provides the following global variables:
nunchuck_btnC:       1 off, 0 pressed
nunchuck_btnZ:       1 off, 0 pressed
nunchuck_joyX:       0 - 255. 128 is centre
nunchuck_joyY:       0 - 255. 128 is centre
nunchuck_joyD:       Digital version joystick directions, as per Console8 01010101b, 0 is pressed, 1 is not
nunchuck_angleX:     0 - 255. 128 is centre
nunchuck_angleY:     0 - 255. 128 is centre
nunchuck_velocityZ:  0 - 255. 128 is centre. NOTE above may not get full range of 0 - 255

Calling nunchuck_update(); will refresh the nunchuck data in the global variables.

Press ESC to exit the program.
