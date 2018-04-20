#ifndef _BUTTONS_H
#define _BUTTONS_H

#include "Arduino.h"

#define BTN_UP 42
#define BTN_RIGHT 44
#define BTN_DOWN 46
#define BTN_LEFT 48
#define BTN_A 18
#define BTN_B 20

#define BITMASK_BTN_UP    0b00000001
#define BITMASK_BTN_RIGHT 0b00000010
#define BITMASK_BTN_DOWN  0b00000100
#define BITMASK_BTN_LEFT  0b00001000
#define BITMASK_BTN_A     0b00010000
#define BITMASK_BTN_B     0b00100000

uint8_t buttons_readAll();

#endif // _BUTTONS_H

