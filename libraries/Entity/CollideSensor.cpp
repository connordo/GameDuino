#include "CollideSensor.h"



bool CollideSensor::collided(Entity* e)
{
	int xDiff = this->get_x_pos() - e->get_x_pos();
	int yDiff = this->get_y_pos() - e->get_y_pos();

	return (xDiff > 0 - this->get_true_width() && xDiff < this->get_true_width() + e->get_true_width() - 1) &&
			(yDiff > 0 - this->get_height() - e->get_height() && yDiff < this->get_height() + e->get_height());
}

CollideSensor::CollideSensor(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos)
	:Entity(display, init_x_pos, init_y_pos)
{
}



CollideSensor::~CollideSensor()
{
}
