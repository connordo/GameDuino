#pragma once
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Entity {
protected:
  Adafruit_SSD1306 *display;
  int x_pos;
  int y_pos;
  int width;
  int height;
  static const unsigned char PROGMEM sprite_bmp[];


public:
  Entity(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos);
  virtual void draw();
  virtual void move(int d);
  int get_x_pos();
  int get_y_pos();
  int get_width();
  int get_height();
};
