#include "Entity.h"

static const unsigned char PROGMEM Entity::sprite_bmp[]=
{0b00011100,};

Entity::Entity(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos){
  this->display = display;
  x_pos = init_x_pos;
  y_pos = init_y_pos;
}

void Entity::move(int d){
  display->drawBitmap(x_pos, y_pos, sprite_bmp, width, height, BLACK);
  switch(d){
    case 0:
    display->drawBitmap(x_pos, --y_pos, sprite_bmp, width, height, WHITE);
    break;
    case 1:
    display->drawBitmap(x_pos, ++y_pos, sprite_bmp, width, height, WHITE);
    break;
    case 2:
    display->drawBitmap(--x_pos, y_pos, sprite_bmp, width, height, WHITE);
    break;
    case 3:
    display->drawBitmap(++x_pos, y_pos, sprite_bmp, width, height, WHITE);
    break;
  }
}

void Entity::draw(){
  display->drawBitmap(x_pos, y_pos, sprite_bmp, width, height, WHITE);
}

int Entity::get_x_pos(){
  return x_pos;
}
int Entity::get_y_pos(){
  return y_pos;
}
int Entity::get_width(){
  return width;
}
int Entity::get_height(){
  return height;
}
