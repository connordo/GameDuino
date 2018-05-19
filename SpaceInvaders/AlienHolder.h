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
  Alien alienArray[ALIENCOUNT]={
    Alien(display, 0, 0),
    Alien(display, 15, 0),
    Alien(display, 30, 0),
    Alien(display, 45, 0),
    Alien(display, 60, 0),
    Alien(display, 75, 0),
    Alien(display, 90, 0),
    Alien(display, 0, 10),
    Alien(display, 15, 10),
    Alien(display, 30, 10),
    Alien(display, 45, 10),
    Alien(display, 60, 10),
    Alien(display, 75, 10),
    Alien(display, 90, 10)
  };
  int movementCounter;
  int directionOfMovement; //positive or negative
public:
  AlienHolder(Adafruit_SSD1306 *display);
  void initilizeAliens();
  void iterateThroughAliens();
};
