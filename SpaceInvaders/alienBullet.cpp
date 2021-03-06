#include "AlienBullet.h"

const unsigned char PROGMEM AlienBullet::alien_bullet_bmp[] =
{
	0b00100000, 0b01000000, 0b10000000, 0b01000000, 0b00100000, 0b01000000, 0b10000000,
};

static const unsigned char PROGMEM AlienBullet::alternateBullet[] =
{
	0b10000000, 0b01000000, 0b00100000, 0b01000000, 0b10000000, 0b01000000, 0b00100000,
};

const unsigned char * AlienBullet::getSpriteBmp()
{
	// Serial.begin(9600);
	// Serial.println("--");
	// Serial.println(animationCounter);
	// Serial.println(currentSprite);
	if(currentSprite == 1){
		return alien_bullet_bmp;
	}
	else{
		return alternateBullet;
	}
}

void AlienBullet::explode()
{

}

AlienBullet::AlienBullet(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos) :Bullet(display, init_x_pos, init_y_pos) {
	height = 7;
	width = 3;
	bmp_width = 8;
	speed = 1;
	type = 'b';
	animationSpeed = 3;
	animationCounter = 0;
	currentSprite = 1;
}

void AlienBullet::onCollide(Entity * e)
{
	display->drawBitmap(x_pos, y_pos, getSpriteBmp(), width, height, BLACK);
	y_pos = -10;
	switch (e->get_type()) {
		case 's':
		{
			// Bullet hit the player
			Spaceship * user = static_cast<Spaceship*>(e);
			user->explode();
		}
		break;
		case 'b':
		{
			Bullet* bullet = (Bullet*)e;
			bullet->forceMove(0, -10);
		}
		case 'c':
		{
			BunkerBlock * bunkerBlock = static_cast<BunkerBlock*>(e);
			bunkerBlock->takeDamage();
		}
		default:
		break;
	}
}

void AlienBullet::onCollide(EntityGroup * eg)
{
	// For entities in eg, do collided
	Entity ** entities = eg->getEntities();
	for (int i = 0; i < eg->get_arr_length(); i++) {
		if (collided(entities[i])) {
			onCollide(entities[i]);
		}
	}
}

void AlienBullet::animate(){
  if(animationCounter++ >= animationSpeed){
    display->fillRect(x_pos, y_pos, width, height, BLACK);
    // currentSprite == 1 ? currentSprite = 2 : currentSprite = 1;
		if(currentSprite == 1){
			currentSprite = 2;
		}
		else {
			currentSprite = 1;
		}

    display->drawBitmap(x_pos, y_pos, getSpriteBmp(), width, height, WHITE);
    animationCounter = 0;
  }
}
