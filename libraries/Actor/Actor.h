#pragma once
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Actor {
protected:
  int x_pos;
  int y_pos;
  int width;
  int height;
  Component *componentArray;

public:
  Actor(int init_x_pos, int init_y_pos);
  void set_position(int new_x_pos, int new_y_pos);
  int get_x_pos();
  int get_y_pos();
  int get_width();
  int get_height();
};
