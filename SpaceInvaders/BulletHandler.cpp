#include "BulletHandler.h"


Alien * BulletHandler::pickAlien()
{
	int pickedIndex;
	Alien* pickedAlien;
	bool aliveAlien = false;
	while (!aliveAlien && !alienHolder->allDead()) {
		pickedIndex = random(0, alienHolder->get_arr_length());
		pickedAlien = (Alien*)alienHolder->getEntities()[pickedIndex];
		aliveAlien = pickedAlien->isAlive();
	}

	// We got an alive alien, now lets see if there is an alive alien below him
	int below = alienBelow(pickedIndex);
	if (below < 0) {
		// No alien below
		return (Alien*)pickedAlien;
	}
	else {
		return (Alien*)alienHolder->getEntities()[below];
	}
}

int BulletHandler::alienBelow(int index)
{
	int newAlienInd = index + ALIEN_ROW_LEN;
	if (newAlienInd < alienHolder->get_arr_length()) {
		Alien* newAlien = (Alien*)alienHolder->getEntities()[newAlienInd];
		if (newAlien->isAlive()) {
			return newAlienInd;
		}
	}

	return -1;

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

BulletHandler::~BulletHandler(){
	alienShot->forceMove(0,70);
	userShot->forceMove(0,-10);
}
void BulletHandler::moveBullets()
{
	if (userShot->get_y_pos() > -4) {
		userShot->move(UP);
	}
	if (alienShot->get_y_pos() > -4) {
		alienShot->animate();
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

	if (alienShot->collided(userShot)) {
		alienShot->onCollide(userShot);
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
