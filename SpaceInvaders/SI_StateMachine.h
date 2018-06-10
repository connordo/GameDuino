#ifndef _SI_STATE_MACHINE_H
#define _SI_STATE_MACHINE_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//#include <vector>
#include "Spaceship.h"
#include "Bullet.h"
#include "Alien.h"
#include "AlienHolder.h"
#include "Bunker.h"
#include "BulletHandler.h"

#define BULLETCOUNT 10

class SI_StateMachine {
private:
	//std::vector<CollideSensor*> collideSensors;
	void checkCollisions();

public:
	int level;
	int movementCounterMax;
	Adafruit_SSD1306 * display;
	Spaceship *user;
	Bullet *userShot;
	Alien *testbug;
	AlienHolder *alienholder;
	Bunker *bunker1;
	Bunker *bunker2;
	Bunker *bunker3;
	BulletHandler *bulletHandler;
	int bulletIndex;
	enum SI_state {
		init_st,
		idle_st,
		level_increment_st,
		game_over_st,
		victory_st
	}currentState;

	SI_StateMachine::SI_StateMachine(Adafruit_SSD1306 *display);
	void tick();
};

#endif // _SI_STATE_MACHINE_H
