// An example sketch that makes use of the protothread library
// to run two processes in parallel.
// Take in account that local vars WILL NOT WORK in conjunction
// with pt.h, neither will of course for loops with local
// iterators. This is nasty but probably worth it.

#include <pt.h>
#include "ledArray.h"

static struct pt pt1, pt2;
int i = 0;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED10, OUTPUT);
  PT_INIT(&pt1);
  PT_INIT(&pt2);
}

static int protothread1(struct pt *pt) {
  static unsigned long timestamp = 0;
  PT_BEGIN(pt);
  while(1) {
    timestamp = millis();
    PT_WAIT_UNTIL(pt, millis() - timestamp > 250);
    digitalWrite(LED1, HIGH);
    timestamp = millis();
    PT_WAIT_UNTIL(pt, millis() - timestamp > 250);
    digitalWrite(LED1, LOW);
  }
  PT_END(pt);
}

static int protothread2(struct pt *pt) {
  static unsigned long timestamp = 0;
  PT_BEGIN(pt);
  while(1) {
    for (i = 0; i < 10; i++) {
      timestamp = millis();
      PT_WAIT_UNTIL(pt, millis() - timestamp > 100);
      digitalWrite(LED10, HIGH);
      timestamp = millis();
      PT_WAIT_UNTIL(pt, millis() - timestamp > 100);
      digitalWrite(LED10, LOW);
    }
    PT_WAIT_UNTIL(pt, millis() - timestamp > 1000);
  }
  PT_END(pt);
}

void loop() {
  protothread1(&pt1);
  protothread2(&pt2);
}
