
#ifndef GETKBDATA_H
#define GETKBDATA_H

extern void getKbData(void);
extern volatile uint8_t myAscii;
extern volatile uint8_t myState;
extern volatile uint8_t myFab;
extern volatile uint8_t myMod;
extern volatile uint8_t keyArray[4];

#endif
