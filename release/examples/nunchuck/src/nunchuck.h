
#ifndef NUNCHUCK_H
#define NUNCHUCK_H

// functions
extern uint8_t getDisplayMode(void);
extern uint24_t nunchuck_exists(void);
extern void i2c_open(void);
extern void nunchuck_open(void);
extern void nunchuck_update(void);
extern void i2c_close(void);

// variables
extern volatile uint8_t nunchuck_btnC;
extern volatile uint8_t nunchuck_btnZ;
extern volatile uint8_t nunchuck_joyX;
extern volatile uint8_t nunchuck_joyY;
extern volatile uint8_t nunchuck_joyD;
extern volatile uint8_t nunchuck_angleX;
extern volatile uint8_t nunchuck_angleY;
extern volatile uint8_t nunchuck_velocityZ;

#endif
