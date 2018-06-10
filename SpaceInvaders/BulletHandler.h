#pragma once
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Bullet.h"
#include "AlienBullet.h"
#include "Bunker.h"
#include "AlienHolder.h"
#include "Spaceship.h"
#define SHOTRATE 35
#define ALIEN_ROW_LEN 7

class BulletHandler {
private:
	Adafruit_SSD1306 * display;
	Bunker * bunker1;
	Bunker * bunker2;
	Bunker * bunker3;
	AlienHolder * alienHolder;
	Spaceship * userShip;
	Bullet * userShot;
	AlienBullet *alienShot;
	int alienShotRate;
	int shotCountUp;
	Alien *pickAlien();
	int alienBelow(int index);
public:
	BulletHandler(Adafruit_SSD1306 * display, Bunker** bunkers, AlienHolder * ah, Spaceship* us);
	void moveBullets();
	void shootUserBullet();
	void checkCollisions();
	void fireAlienBullet();
};
