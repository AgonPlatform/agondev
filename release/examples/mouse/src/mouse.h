
#ifndef MOUSE_H
#define MOUSE_H

extern uint16_t getsysvar_mouseX(void);
extern uint16_t getsysvar_mouseY(void);
extern uint8_t getsysvar_mouseButtons(void);
extern uint8_t getsysvar_mouseWheel(void);
extern uint16_t getsysvar_mouseXDelta(void);
extern uint16_t getsysvar_mouseYDelta(void);

#endif
