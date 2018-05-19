#pragma once
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Entity.h"

class EntityGroup
{
protected:
	Adafruit_SSD1306 * display;
	Entity** entities;
	int array_length;
	int x_pos;
	int y_pos;
	int width;
	int height;
public:
	//virtual void move() = 0;
	virtual int get_x_pos();
	virtual int get_y_pos();
	virtual int get_width();
	virtual int get_height();
	virtual int get_arr_length();
	virtual Entity** getEntities();
	EntityGroup();
	~EntityGroup();
};

