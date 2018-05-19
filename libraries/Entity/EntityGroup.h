#pragma once
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class EntityGroup
{
protected:
	Adafruit_SSD1306 * display;
	int x_pos;
	int y_pos;
	int width;
	int height;
public:
	//virtual void move() = 0;
	virtual int getXPos();
	virtual int getYPos();
	virtual int getWidth();
	virtual int getHeight();
	EntityGroup();
	~EntityGroup();
};

