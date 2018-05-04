#pragma once
#include <Entity.h>

class Spaceship: public Entity {
public:
  static const unsigned char PROGMEM sprite_bmp[];
  Spaceship(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos);

  void draw();
  void move(int d);
};
