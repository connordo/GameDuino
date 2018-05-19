#include "alienBullet.h"

static const unsigned char PROGMEM alienBullet::alien_bullet_bmp[]=
{
0b00100000, 0b01000000, 0b10000000, 0b01000000, 0b00100000, 0b01000000, 0b10000000,
};

const unsigned char * alienBullet::getSpriteBmp()
{
	return alien_bullet_bmp;
}

alienBullet::  alienBullet(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos):Bullet(display, init_x_pos, init_y_pos){
  height = 7;
  width = 8;
  true_width = 3;
  speed = 1;
  type = 'b';
}
