#ifndef _JOYSTICK_H
#define _JOYSTICK_H

#include <stdint.h>

// Macros to test if a button is pressed
// The 'buttons' input is returned from the getJoystickButtons() function
#define joystick2_UP(buttons)         (!((buttons) & (1U << (0))))
#define joystick1_UP(buttons)         (!((buttons) & (1U << (1))))
#define joystick2_DOWN(buttons)       (!((buttons) & (1U << (2))))
#define joystick1_DOWN(buttons)       (!((buttons) & (1U << (3))))
#define joystick2_LEFT(buttons)       (!((buttons) & (1U << (4))))
#define joystick1_LEFT(buttons)       (!((buttons) & (1U << (5))))
#define joystick2_RIGHT(buttons)      (!((buttons) & (1U << (6))))
#define joystick1_RIGHT(buttons)      (!((buttons) & (1U << (7))))
#define joystick2_BUTTON1(buttons)    (!((buttons) & (1U << (12))))
#define joystick1_BUTTON1(buttons)    (!((buttons) & (1U << (13))))
#define joystick2_BUTTON2(buttons)    (!((buttons) & (1U << (14))))
#define joystick1_BUTTON2(buttons)    (!((buttons) & (1U << (15))))

uint16_t getJoystickButtons(void); // Get state for all joy1/joy2 buttons
// BIT JOYSTICK BUTTON
//  0     2     Up
//  1     1     Up
//  2     2     Down
//  3     1     Down
//  4     2     Left
//  5     1     Left
//  6     2     Right
//  7     1     Right
//  8     -     -
//  9     -     -
// 10     -     -
// 11     -     -
// 12     2     Button 1
// 13     1     Button 1
// 14     2     Button 2
// 15     1     Button 2

void resetJoysticks(void); // Resets all joystick pins as input pin, leave other portD pins as-is

#endif
