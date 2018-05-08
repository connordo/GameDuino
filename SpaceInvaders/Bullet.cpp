#include "Bullet.h"

const unsigned char PROGMEM Bullet::bullet_bmp[]=
{
0b10000000, 0b10000000, 0b10000000, 0b10000000,
};

const unsigned char * Bullet::getSpriteBmp()
{
	return bullet_bmp;
}

Bullet::Bullet(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos):Entity(display, init_x_pos,init_y_pos){
  height = 4;
  width = 8;
  speed = 2;
}

void Bullet::forceMove(int x, int y){
  display->drawBitmap(x_pos, y_pos, getSpriteBmp(), width, height, BLACK);
  x_pos = x;
  y_pos = y;
  display->drawBitmap(x_pos, y_pos, getSpriteBmp(), width, height, WHITE);
}
