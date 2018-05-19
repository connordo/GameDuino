#pragma once
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

enum MoveDir {UP, DOWN ,LEFT, RIGHT};

class Entity {
protected:
  Adafruit_SSD1306 *display;
  int x_pos;
  int y_pos;
  int width;
  int height;
  int bmp_width;
  int speed;
  int animationSpeed;
  int animationCounter;
  char type;
  static const unsigned char PROGMEM sprite_bmp[];
  virtual const unsigned char* getSpriteBmp();


public:
  Entity(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos);
  virtual void draw();
  virtual void move(MoveDir d);
  int get_x_pos();
  int get_y_pos();
  int get_width();
  int get_height();
  int get_bmp_width();
  char get_type();
};
