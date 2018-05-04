#pragma once
#include <Entity.h>

class Bullet: public Entity {
public:
  static const unsigned char PROGMEM sprite_bmp[];
  Bullet(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos);
  void Bullet::forceMove(int x, int y);
  void draw();
  void move(int d);
};
