#pragma once
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define MAX_COMPONENTS

class Actor {
protected:
  int x_pos;
  int y_pos;
  int width;
  int height;
  int componentArrayLength;
  Component *componentArray[10];


public:
  Actor(int init_x_pos, int init_y_pos, int init_width, int init_height);
  void set_position(int new_x_pos, int new_y_pos);
  int get_x_pos();
  int get_y_pos();
  int get_width();
  int get_height();
  void add_component(Component *new_component);
  void update();
};
