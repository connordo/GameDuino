#include "ledArray.h"
#include "Arduino.h"

void ledArray_init(){
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(LED9, OUTPUT);
  pinMode(LED10,OUTPUT);
}

void ledArray_writeLeds(uint16_t leds_enabled){
digitalWrite(LED1, leds_enabled&BITMASK_LED_1);
digitalWrite(LED2, leds_enabled&BITMASK_LED_2);
digitalWrite(LED3, leds_enabled&BITMASK_LED_3);
digitalWrite(LED4, leds_enabled&BITMASK_LED_4);
digitalWrite(LED5, leds_enabled&BITMASK_LED_5);
digitalWrite(LED6, leds_enabled&BITMASK_LED_6);
digitalWrite(LED7, leds_enabled&BITMASK_LED_7);
digitalWrite(LED8, leds_enabled&BITMASK_LED_8);
digitalWrite(LED9, leds_enabled&BITMASK_LED_9);
digitalWrite(LED10,leds_enabled&BITMASK_LED_10);
}
