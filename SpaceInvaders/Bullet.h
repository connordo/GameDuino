#pragma once
#include <Entity.h>

class Bullet: public Entity {
private:
	const unsigned char * getSpriteBmp();
public:
  static const unsigned char PROGMEM bullet_bmp[];
  Bullet(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos);
  void Bullet::forceMove(int x, int y);
};
