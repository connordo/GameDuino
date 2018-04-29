#pragma once
#include <Entity.h>

class Spaceship: public Entity {
public:
  static const unsigned char PROGMEM sprite_bmp[];
  Spaceship(int init_x_pos, int init_y_pos);

  void draw(Adafruit_SSD1306 display);
  void move(Adafruit_SSD1306 display, int d);
};
