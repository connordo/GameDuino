#pragma once

#include <Entity.h>
#include "buttons.h"

class MrGameDuino: public Entity {
private:

public:
  static const unsigned char PROGMEM idle_1[];
  static const unsigned char PROGMEM idle_2[];
  static const unsigned char PROGMEM right_1[];
  static const unsigned char PROGMEM right_2[];
  static const unsigned char PROGMEM left_1[];
  static const unsigned char PROGMEM left_2[];

  int currentSprite;
  int deathTimerCount;

  void animate();
  void draw();
  void move(int d);
  void explode();
  const unsigned char* getSpriteBmp();

  MrGameDuino(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos);
  bool isAlive();
};
