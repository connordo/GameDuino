#pragma once
#include <Entity.h>

class Alien: public Entity {
public:
  static const unsigned char PROGMEM alien1[];
  static const unsigned char PROGMEM alien2[];
  Alien(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos);

  void draw();
  void move(int d);
};
