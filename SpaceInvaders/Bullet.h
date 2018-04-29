#pragma once
#include <Entity.h>

class Bullet: public Entity {
public:
  static const unsigned char PROGMEM sprite_bmp[];
  Bullet(int init_x_pos, int init_y_pos);
  void Bullet::forceMove(Adafruit_SSD1306 display, int x, int y);
  void draw(Adafruit_SSD1306 display);
  void move(Adafruit_SSD1306 display, int d);
};
