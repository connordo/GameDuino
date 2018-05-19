#pragma once
#include <Entity.h>

class BunkerBlock : public Entity{
protected:
  const unsigned char* getSpriteBmp();
  int life;

public:
  static const unsigned char PROGMEM block_whole_bmp[];
  static const unsigned char PROGMEM block_damage_1_bmp[];
  static const unsigned char PROGMEM block_damage_2_bmp[];
  BunkerBlock(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos);
  void takeDamage();
};
