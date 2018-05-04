#ifndef _SI_STATE_MACHINE_H
#define _SI_STATE_MACHINE_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Spaceship.h"
#include "Bullet.h"

#define BULLETCOUNT 10

class SI_StateMachine{
public:
  Adafruit_SSD1306 *display;
  Spaceship *user;
  Bullet shot[BULLETCOUNT] = {
    Bullet(display, 0, -10),
    Bullet(display, 10, -10),
    Bullet(display, 20, -10),
    Bullet(display, 30, -10),
    Bullet(display, 40, -10),
    Bullet(display, 0, -10),
    Bullet(display, 10, -10),
    Bullet(display, 20, -10),
    Bullet(display, 30, -10),
    Bullet(display, 40, -10)
};
  int bulletIndex;
  enum SI_state{
    init_st,
    idle_st
  }currentState;

  SI_StateMachine::SI_StateMachine(Adafruit_SSD1306 *display);
  tick();
};

#endif // _SI_STATE_MACHINE_H
