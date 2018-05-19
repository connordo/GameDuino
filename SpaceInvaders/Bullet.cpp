#include "Bullet.h"

const unsigned char PROGMEM Bullet::bullet_bmp[] =
{
0b10000000, 0b10000000, 0b10000000, 0b10000000,
};

const unsigned char * Bullet::getSpriteBmp()
{
	return bullet_bmp;
}

Bullet::Bullet(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos) :CollideSensor(display, init_x_pos, init_y_pos) {
	height = 4;
	width = 1;
	bmp_width = 8;
	speed = 3;
	type = 'b';
}

void Bullet::forceMove(int x, int y) {
	display->drawBitmap(x_pos, y_pos, getSpriteBmp(), width, height, BLACK);
	x_pos = x;
	y_pos = y;
	display->drawBitmap(x_pos, y_pos, getSpriteBmp(), width, height, WHITE);
}

void Bullet::onCollide(Entity * e)
{
	display->drawBitmap(x_pos, y_pos, getSpriteBmp(), width, height, BLACK);
	y_pos = -10;
	switch (e->get_type()) {
	case 'a':
	{
		// Bullet hit an alien
		Alien * alien = static_cast<Alien*>(e);
		alien->explode();
	}
	break;
	case 'b':
	{
		BunkerBlock * bunkerBlock = static_cast<BunkerBlock*>(e);
		bunkerBlock->takeDamage();
	}
	default:
		break;
	}
}

void Bullet::onCollide(EntityGroup * eg)
{
	// For entities in eg, do collided
	Entity ** entities = eg->getEntities();
	for (int i = 0; i < eg->get_arr_length(); i++) {
		if (collided(entities[i])) {
			onCollide(entities[i]);
		}
	}
}
