#include "Spaceship.h"

unsigned const char PROGMEM Spaceship::spaceship_bmp[] =
{
0b00000100, 0b00000000, 0b00001110, 0b00000000, 0b00001110, 0b00000000, 0b00001110, 0b00000000, 0b01111111, 0b11000000, 0b11111111, 0b11100000, 0b01101110, 0b11000000, 0b00101010, 0b10000000,
};

unsigned const char * Spaceship::getSpriteBmp()
{
	return spaceship_bmp;
}

Spaceship::Spaceship(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos)
	:Entity(display, init_x_pos, init_y_pos) {
	height = 8;
	width = 16;
	bmp_width = 16;
	speed = 1;
	type = 's';
}

void Spaceship::explode()
{
	display->drawBitmap(x_pos, y_pos, getSpriteBmp(), bmp_width, height, BLACK);
}
