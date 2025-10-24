#ifndef _VDP_KEYBOARD_H
#define _VDP_KEYBOARD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/* Index rows for use with vdp_getKeyMap(uint8_t index)
+--------+--------+--------+-----------+-----------+----------+----------+-----------+-----------+
|     Bit|   7    |   6    |     5     |     4     |    3     |    2     |     1     |     0     |
|Index   |        |        |           |           |          |          |           |           |        
+--------+--------+--------+-----------+-----------+----------+----------+-----------+-----------+
| 00     | CTRL R | SHIFT R| ALT L     | CTRL L    | SHIFT L  |          |           | ALT R     |
| 01     |        |        |           |           |          |          |           |           |
| 02     | -      | F7     | 8         | F4        | 5        | 4        | 3         | q         |
| 03     | Scroll | F10    | F12       | F11       | 7 (pad)  | 6 (pad)  |           | ⇐         |
| 04     | 0      | 9      | I         | 7         | T        | E        | W         | PRT SCR   |
| 05     | BK SPC | ` ~    |           | 9 (pad)   | 8 (pad)  |          |           | ⇓         |
| 06     | P      | O      | U         | 6         | R        | D        | 2         | 1         |
| 07     | PageUp | Home   | Insert    | Enter(pad)| - (pad)  | + (pad)  | ⇧         | [         |
| 08     | ‘(@)   | K      | J         | Y         | F        | X        | A         | CAPS LK   |
| 09     | PageDn | NUM LK | ./del(pad)| / (pad)   |          |          |           | ENTER     |
| 0A     | ;      | L      | N         | H         | G        | C        | S         |           |
| 0B     |        | - (+)  |           | *(pad)    |          |          |           | DELETE    |
| 0C     | . >    | , <    | M         | B         | V        | SPACE    | Z         | TAB       |
| 0D     |        |        | 3(pad)    | 1(pad)    | 0(pad)   | End      | / ?       |           |
| 0E     | F9     | F8     | F6        | F5        | F3       | F2       | F1        | ESC       |
| 0F     | WIN R  | WIN L  | 2(pad)    | 5(pad)    | 4(pad)   |          |           | ⇨         |
+--------+--------+--------+-----------+-----------+----------+----------+-----------+-----------+
*/

extern uint8_t vdp_getKeyMap(uint8_t index); // pass in index offset to keyboard matrix and return its (bitfield) value
extern void    vdp_waitKeyUp(void); // wait for key up state before returning (blocking)
extern void    vdp_waitKeyDown(void); // wait for key down state before returning (blocking)
extern uint8_t vdp_getKeyCode(void); // return ascii code of single key being pressed, or 0 if none (non-blocking)

#ifdef __cplusplus
}
#endif

#endif