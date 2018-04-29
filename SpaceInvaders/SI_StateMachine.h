#ifndef _SI_STATE_MACHINE_H
#define _SI_STATE_MACHINE_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Spaceship.h"

class SI_StateMachine{
public:
  Spaceship *user;

  enum SI_state{
    init_st,
    idle_st
  }currentState;

  SI_StateMachine();
  tick(Adafruit_SSD1306 display);
};

#endif // _SI_STATE_MACHINE_H
