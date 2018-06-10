#include "SI_StateMachine.h"
#include <buttons.h>
#include "ledArray.h"

void SI_StateMachine::checkCollisions()
{
	bulletHandler->checkCollisions();
}

void(* resetFunc) (void) = 0; //declare reset function @ address 0

SI_StateMachine::SI_StateMachine(Adafruit_SSD1306 *display) {
	this->display = display;
	currentState = init_st;
	user = new Spaceship(display, (128 / 2) - 4, 64 - 8);
	// testbug = new Alien(display, 30, 10);
	alienholder = new AlienHolder(display, movementCounterMax);
	bunker1 = new Bunker(display, 10, 45);
	bunker2 = new Bunker(display, 55, 45);
	bunker3 = new Bunker(display, 100, 45);
	bulletHandler = new BulletHandler(display, new Bunker*[3]{ bunker1, bunker2, bunker3 }, alienholder, user);
	movementCounterMax = 30;
	ledArray_writeLeds(0);
	digitalWrite(LED1, HIGH);
}

void SI_StateMachine::tick() {
	//Mealey Actions
	switch (currentState) {
		case init_st:
		user->draw();
		// testbug->draw();
		alienholder->initilizeAliens();
		break;
		case idle_st:
		// testbug->animate();
		alienholder->iterateThroughAliens();
		bulletHandler->fireAlienBullet();
		bulletHandler->moveBullets();
		//if (userShot->get_y_pos() > -4) {
		//	userShot->move(UP);
		//}
		break;

		case level_increment_st:
		movementCounterMax -= 3;
		level++;
		if(level == 2)
		digitalWrite(LED2, HIGH);
		if(level == 3)
		digitalWrite(LED3, HIGH);
		if(level == 4)
		digitalWrite(LED4, HIGH);
		if(level == 5)
		digitalWrite(LED5, HIGH);
		if(level == 6)
		digitalWrite(LED6, HIGH);
		if(level == 7)
		digitalWrite(LED7, HIGH);
		if(level == 8)
		digitalWrite(LED8, HIGH);
		if(level == 9)
		digitalWrite(LED9, HIGH);
		if(level == 10)
		digitalWrite(LED10, HIGH);

		delete alienholder;
		alienholder = new AlienHolder(display, movementCounterMax);
		delete bulletHandler;
		bulletHandler = new BulletHandler(display, new Bunker*[3]{ bunker1, bunker2, bunker3 }, alienholder, user);

		break;

		case game_over_st:
		delay(500);
		display->clearDisplay();
		display->setCursor(10, 10);
		display->setTextSize(2);
		display->setTextColor(WHITE);
		display->println("Game Over");
		display->display();
		delay(5000);
		resetFunc();  //call reset
		break;

		case victory_st:
		delay(500);
		display->fillRect(0, 0, 128, 30, BLACK);
		display->setCursor(10, 10);
		display->setTextSize(2);
		display->setTextColor(WHITE);
		display->println(" Victory!");
		display->display();
		delay(5000);
		resetFunc();  //call reset
		break;
	}

	//Moore Actions
	switch (currentState) {
		case init_st:
		currentState = idle_st;
		break;
		case idle_st:
		if (buttons_readAll() & BITMASK_BTN_LEFT) {
			if (user->get_x_pos() > 0)
			user->move(LEFT);
		}
		if (buttons_readAll() & BITMASK_BTN_RIGHT) {
			if (user->get_x_pos() + user->get_width() < display->width())
			user->move(RIGHT);
		}

		if (buttons_readAll() & BITMASK_BTN_A) {

			//userShot->forceMove(user->get_x_pos() + 5, user->get_y_pos() - 4);
			bulletHandler->shootUserBullet();

		}
		checkCollisions();
		if(user->isAlive()==false){
			currentState = game_over_st;
		}
		if(alienholder->allDead()){
			currentState = level_increment_st;
		}
		if(alienholder->allDead() && level == 10){
			currentState = victory_st;
		}
		break;

		case level_increment_st:
		currentState = idle_st;
		break;

		case game_over_st:
		break;

		case victory_st:
		break;
	}
	display->display();
}
