#include "BulletHandler.h"


Alien * BulletHandler::pickAlien()
{
	return (Alien*) alienHolder->getEntities()[11];
}

BulletHandler::BulletHandler(Adafruit_SSD1306 * display, Bunker ** bunkers, AlienHolder * ah, Spaceship * us)
{
	this->display = display;
	bunker1 = bunkers[0];
	bunker2 = bunkers[1];
	bunker3 = bunkers[2];

	alienHolder = ah;
	userShip = us;

	userShot = new Bullet(display, 0, -10);
	alienShot = new AlienBullet(display, 0, -10);

	alienShotRate = SHOTRATE;
	shotCountUp = 0;
}

void BulletHandler::moveBullets()
{
	if (userShot->get_y_pos() > -4) {
		userShot->move(UP);
	}
	if (alienShot->get_y_pos() > -4) {
		alienShot->move(DOWN);
	}
}

void BulletHandler::shootUserBullet()
{
	if (userShot->get_y_pos() < 0) {
		userShot->forceMove(userShip->get_x_pos() + 5, userShip->get_y_pos() - 4);
	}
}

void BulletHandler::checkCollisions()
{
	if (userShot->collided(alienHolder)) {
		userShot->onCollide(alienHolder);
	}
	if (userShot->collided(bunker1)) {
		userShot->onCollide(bunker1);
	}
	if (userShot->collided(bunker2)) {
		userShot->onCollide(bunker2);
	}
	if (userShot->collided(bunker3)) {
		userShot->onCollide(bunker3);
	}
	
	if (alienShot->collided(bunker1)) {
		alienShot->onCollide(bunker1);
	}
	if (alienShot->collided(bunker2)) {
		alienShot->onCollide(bunker2);
	}
	if (alienShot->collided(bunker3)) {
		alienShot->onCollide(bunker3);
	}

	if (alienShot->collided(userShip)) {
		alienShot->onCollide(userShip);
	}
}

void BulletHandler::fireAlienBullet()
{
	if (++shotCountUp >= alienShotRate) {
		if (alienShot->get_y_pos() > 80 || alienShot->get_y_pos() < 0) {
			Alien * fireAlien = pickAlien();
			alienShot->forceMove(fireAlien->get_x_pos() + 5, fireAlien->get_y_pos() + 8);
		}
	
		shotCountUp = 0;
	}
}
