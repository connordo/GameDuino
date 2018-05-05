#ifndef _SI_STATE_MACHINE_H
#define _SI_STATE_MACHINE_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Spaceship.h"
#include "Bullet.h"
#include "Alien.h"

#define BULLETCOUNT 10

class SI_StateMachine{
public:
  Adafruit_SSD1306 *display;
  Spaceship *user;
  Bullet *userShot;
  Alien *testbug;
  int bulletIndex;
  enum SI_state{
    init_st,
    idle_st
  }currentState;

  SI_StateMachine::SI_StateMachine(Adafruit_SSD1306 *display);
  void tick();
};

#endif // _SI_STATE_MACHINE_H
