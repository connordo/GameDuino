#pragma once
#include <Entity.h>

class Spaceship : public Entity {
private:
	const unsigned char* getSpriteBmp();
	bool alive;
public:
	static const unsigned char PROGMEM spaceship_bmp[];
	Spaceship(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos);
	void explode();
	bool isAlive();
};
