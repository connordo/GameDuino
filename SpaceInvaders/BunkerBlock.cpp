#include "BunkerBlock.h"

const unsigned char PROGMEM BunkerBlock::block_whole_bmp[] = {
  0b11110000, 0b11110000, 0b11110000, 0b11110000,
};

const unsigned char PROGMEM BunkerBlock::block_damage_1_bmp[] = {
  0b01110000, 0b10110000, 0b11100000, 0b10110000,
};

const unsigned char PROGMEM BunkerBlock::block_damage_2_bmp[] = {
  0b01000000, 0b10110000, 0b11000000, 0b00110000,
};

unsigned const char * BunkerBlock::getSpriteBmp()
{
	switch (life) {
	case 3:
		return block_whole_bmp;
		break;
	case 2:
		return block_damage_1_bmp;
		break;
	case 1:
		return block_damage_2_bmp;
		break;
	default:
		break;
	}
}

BunkerBlock::BunkerBlock(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos) : Entity(display, init_x_pos, init_y_pos) {
	type = 'b';
	life = 3;
	height = 4;
	width = 4;
	bmp_width = 8;
	draw();
}

void BunkerBlock::takeDamage() {
	display->drawBitmap(x_pos, y_pos, block_whole_bmp, width, height, BLACK);
	if (--life == 0) {
		x_pos = -10;
	}
	draw();
}
