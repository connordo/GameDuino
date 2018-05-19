#include "CollideSensor.h"



bool CollideSensor::collided(Entity* e)
{
	int xDiff = this->get_x_pos() - e->get_x_pos();
	int yDiff = this->get_y_pos() - e->get_y_pos();

	return (yDiff < e->get_height() && yDiff > 0 - this->get_height()) &&
			(xDiff < e->get_bmp_width() && xDiff > 0 - this->get_bmp_width());
}

bool CollideSensor::collided(EntityGroup * eg)
{
	int xDiff = this->get_x_pos() - eg->get_x_pos();
	int yDiff = this->get_y_pos() - eg->get_y_pos();

	return (yDiff < eg->get_height() && yDiff > 0 - this->get_height()) &&
		(xDiff < eg->get_width() && xDiff > 0 - this->get_bmp_width());
}

CollideSensor::CollideSensor(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos)
	:Entity(display, init_x_pos, init_y_pos)
{
}



CollideSensor::~CollideSensor()
{
}
