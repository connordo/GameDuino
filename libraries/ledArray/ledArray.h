#ifndef _LED_ARRAY_H
#define _LED_ARRAY_H
#include "Arduino.h"

#define LED1 8
#define LED2 7
#define LED3 6
#define LED4 5
#define LED5 4
#define LED6 3
#define LED7 2
#define LED8 1
#define LED9 0
#define LED10 14

#define BITMASK_LED_1  0b0000000001
#define BITMASK_LED_2  0b0000000010
#define BITMASK_LED_3  0b0000000100
#define BITMASK_LED_4  0b0000001000
#define BITMASK_LED_5  0b0000010000
#define BITMASK_LED_6  0b0000100000
#define BITMASK_LED_7  0b0001000000
#define BITMASK_LED_8  0b0010000000
#define BITMASK_LED_9  0b0100000000
#define BITMASK_LED_10 0b1000000000

void ledArray_init();

void ledArray_writeLeds(uint16_t leds_enabled);

#endif // _LED_ARRAY_H
