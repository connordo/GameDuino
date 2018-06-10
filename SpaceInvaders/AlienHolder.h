#pragma once

#include "EntityGroup.h"
#include "Alien.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ALIENCOUNT 14
#define MOVEMENT_COUNTER_MAX 30

class AlienHolder: public EntityGroup{
private:
  Adafruit_SSD1306 *display;
  int movementCounter;
  int directionOfMovement; //positive or negative
public:
  AlienHolder(Adafruit_SSD1306 *display);
  void initilizeAliens();
  void iterateThroughAliens();
  bool allDead();
};
