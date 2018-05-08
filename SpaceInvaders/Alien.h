#pragma once
#include <Entity.h>
//#include "Bullet.h"

class Alien: public Entity {
public:
  static unsigned char sprite_bmp[];
  uint16_t alien1[16]=
  {
    0b00100000, 0b10000000, 0b00010001, 0b00000000, 0b00111111, 0b10000000, 0b01101110, 0b11000000, 0b11111111, 0b11100000, 0b10111111, 0b10100000, 0b10100000, 0b10100000, 0b00011011, 0b00000000,
  };

  uint16_t alien2[16]=
  {
    0b00100000, 0b10000000, 0b10010001, 0b00100000, 0b10111111, 0b10100000, 0b11101110, 0b11100000, 0b11111111, 0b11100000, 0b01111111, 0b11000000, 0b00100000, 0b10000000, 0b01000000, 0b01000000,
  };

  int currentSprite;
  //Bullet *alienbullet;
  int fireCounter;
  int FireMax;
  
  void animate();
  void draw();
  void move(int d);
  void explode();

  Alien(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos);
  
};
