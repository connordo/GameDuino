#include "Entity.h"

const unsigned char PROGMEM Entity::sprite_bmp[]=
{0b00011100,}; // Should never display

// Should be overridden
const unsigned char* Entity::getSpriteBmp()
{
	return sprite_bmp;
}

Entity::Entity(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos){
  this->display = display;
  x_pos = init_x_pos;
  y_pos = init_y_pos;
}

void Entity::move(MoveDir d){
  display->drawBitmap(x_pos, y_pos, getSpriteBmp(), width, height, BLACK);
  switch(d){
    case UP:
    display->drawBitmap(x_pos, y_pos-=speed, getSpriteBmp(), width, height, WHITE);
    break;
    case DOWN:
    display->drawBitmap(x_pos, y_pos+=speed, getSpriteBmp(), width, height, WHITE);
    break;
    case LEFT:
    display->drawBitmap(x_pos-=speed, y_pos, getSpriteBmp(), width, height, WHITE);
    break;
    case RIGHT:
    display->drawBitmap(x_pos+=speed, y_pos, getSpriteBmp(), width, height, WHITE);
    break;
  }
}

//void Entity::onColide(Entity* otherEntity)
//{
//}

void Entity::draw(){
  display->drawBitmap(x_pos, y_pos, getSpriteBmp(), width, height, WHITE);
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

int Entity::get_bmp_width()
{
	return bmp_width;
}

char Entity::get_type()
{
	return type;
}
