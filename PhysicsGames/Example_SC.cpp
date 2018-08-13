#include "Example_SC.h"

const unsigned char PROGMEM Example_SC::alien_up_bmp[] =
{
	0b00100000, 0b10000000, 0b00010001, 0b00000000, 0b00111111, 0b10000000, 0b01101110, 0b11000000, 0b11111111, 0b11100000, 0b10111111, 0b10100000, 0b10100000, 0b10100000, 0b00011011, 0b00000000,
};

const unsigned char PROGMEM Example_SC::alien_down_bmp[] =
{
	0b00100000, 0b10000000, 0b10010001, 0b00100000, 0b10111111, 0b10100000, 0b11101110, 0b11100000, 0b11111111, 0b11100000, 0b01111111, 0b11000000, 0b00100000, 0b10000000, 0b01000000, 0b01000000,
};

const unsigned char PROGMEM Example_SC::death_animation_bmp[] =
{
	0b10000100, 0b00100000, 0b01100100, 0b11000000, 0b00010101, 0b00000000, 0b00000000, 0b00000000, 0b11100000, 0b11100000, 0b00000000, 0b00000000, 0b01100100, 0b11000000, 0b10000100, 0b00100000,
};

unsigned const char PROGMEM Example_SC::spaceship_bmp[] =
{
	0b00000100, 0b00000000, 0b00001110, 0b00000000, 0b00001110, 0b00000000, 0b00001110, 0b00000000, 0b01111111, 0b11000000, 0b11111111, 0b11100000, 0b01101110, 0b11000000, 0b00101010, 0b10000000,
};

const unsigned char* Example_SC::getCurrentSprite()
{
	switch (currentSpriteNum) {
	case ALIEN_UP:
		return alien_up_bmp;
	case ALIEN_DOWN:
		return alien_down_bmp;
	case DEATH:
		return death_animation_bmp;
	case SPACESHIP:
		return spaceship_bmp;
	default:
		return spaceship_bmp;
	}
}

Example_SC::Example_SC(class Actor* owner, int startSprite, int numOfSprites, int animFrames, int bmpWidth)
	:SpriteComponent(owner, startSprite, numOfSprites, animFrames, bmpWidth)
{
}


Example_SC::~Example_SC()
{
}
