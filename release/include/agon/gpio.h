#ifndef _GPIO_H
#define _GPIO_H

#include <stdint.h>
#include <stdbool.h>
#include <ez80f92.h>

void outputMode(uint8_t portID, uint8_t pinnumber); // Set one numbered pin (0-7) of a specified port as output pin
void outputModePinID(uint16_t pinID); // FAST - Set one, or multiple (or-ed) pinIDs from the same port (B / C or D) as output pin

void inputMode(uint8_t portID, uint8_t pinnumber); // Set one numbered pin (0-7) of a specified port as input pin
void inputModePinID(uint16_t pinID); // FAST - Set one, or multiple (or-ed) pinIDs from the same port (B / C or D) as input pin

void outputHigh(uint8_t portID, uint8_t pinnumber); // Set one numbered pin (0-7) of a specified port as High (1)
void outputHighPinID(uint16_t pinID); // FAST - Set one, or multiple (or-ed) pinIDs from the same port (B / C or D) as High (1)

void outputLow(uint8_t portID, uint8_t pinnumber); // Set one numbered pin (0-7) of a specified port as Low (0)
void outputLowPinID(uint16_t pinID); // FAST - Set one, or multiple (or-ed) pinIDs from the same port (B / C or D) as Low (0)

bool input(uint8_t portID, uint8_t pinnumber); // Read logical state from a numbered pin (0-7) of a specified port
bool inputPinID(uint16_t pinID); // FAST - Read logical state from a single pinID

uint8_t inputPort(uint8_t port); // Read the entire port from B (PB_DR), C (PB_DR) or D (PB_DR)

// portIDs
#define PORTB PB_DR
#define PORTC PC_DR
#define PORTD PD_DR

// pinIDs for the FAST single parameter xxxPinID calls
#define PB0 ((PB_DR << 8) | 0x01)
#define PB1 ((PB_DR << 8) | 0x02)
#define PB2 ((PB_DR << 8) | 0x04)
#define PB3 ((PB_DR << 8) | 0x08)
#define PB4 ((PB_DR << 8) | 0x10)
#define PB5 ((PB_DR << 8) | 0x20)
#define PB6 ((PB_DR << 8) | 0x40)
#define PB7 ((PB_DR << 8) | 0x80)
#define PC0 ((PC_DR << 8) | 0x01)
#define PC1 ((PC_DR << 8) | 0x02)
#define PC2 ((PC_DR << 8) | 0x04)
#define PC3 ((PC_DR << 8) | 0x08)
#define PC4 ((PC_DR << 8) | 0x10)
#define PC5 ((PC_DR << 8) | 0x20)
#define PC6 ((PC_DR << 8) | 0x40)
#define PC7 ((PC_DR << 8) | 0x80)
#define PD0 ((PD_DR << 8) | 0x01)
#define PD1 ((PD_DR << 8) | 0x02)
#define PD2 ((PD_DR << 8) | 0x04)
#define PD3 ((PD_DR << 8) | 0x08)
#define PD4 ((PD_DR << 8) | 0x10)
#define PD5 ((PD_DR << 8) | 0x20)
#define PD6 ((PD_DR << 8) | 0x40)
#define PD7 ((PD_DR << 8) | 0x80)

#endif
