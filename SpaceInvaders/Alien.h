#pragma once
#include <Entity.h>
//#include "Bullet.h"

class Alien: public Entity {
private:
  bool alive;

public:
  static const unsigned char PROGMEM alien_up_bmp[];
  static const unsigned char PROGMEM alien_down_bmp[];

  int currentSprite;
  int fireCounter;
  int FireMax;

  void animate();
  void draw();
  void move(int d);
  void explode();
  const unsigned char* getSpriteBmp();


  Alien(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos);
  bool isAlive();
};
