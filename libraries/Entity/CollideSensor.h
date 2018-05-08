#pragma once
#include "Entity.h"
class CollideSensor :
	public Entity
{
public:
	virtual void onCollide(Entity* e) = 0;
	virtual bool collided(Entity* e);
	CollideSensor(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos);
	~CollideSensor();
};

