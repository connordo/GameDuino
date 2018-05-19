#pragma once
#include <CollideSensor.h>
#include "Alien.h"
#include "BunkerBlock.h"

class Bullet: public CollideSensor {
private:
	const unsigned char * getSpriteBmp();
public:
  static const unsigned char PROGMEM bullet_bmp[];
  Bullet(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos);
  void Bullet::forceMove(int x, int y);
  void onCollide(Entity* e);
  void onCollide(EntityGroup* eg);
};
