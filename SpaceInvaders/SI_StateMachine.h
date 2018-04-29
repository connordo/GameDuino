#ifndef _SI_STATE_MACHINE_H
#define _SI_STATE_MACHINE_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Spaceship.h"
#include "Bullet.h"

class SI_StateMachine{
public:
  Spaceship *user;
  Bullet shot[5] = {
 Bullet(0,-10),
 Bullet(10,-10),
 Bullet(20,-10),
 Bullet(30,-10),
 Bullet(40,-10)
};
  int bulletIndex;
  enum SI_state{
    init_st,
    idle_st
  }currentState;

  SI_StateMachine();
  tick(Adafruit_SSD1306 display);
};

#endif // _SI_STATE_MACHINE_H
