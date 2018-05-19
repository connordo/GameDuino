#include "AlienHolder.h"

AlienHolder::AlienHolder(Adafruit_SSD1306 *display) {
	this->display = display;
	array_length = ALIENCOUNT;
	entities = new Entity*[ALIENCOUNT]{
		new Alien(display, 0, 0),
		new Alien(display, 15, 0),
		new Alien(display, 30, 0),
		new Alien(display, 45, 0),
		new Alien(display, 60, 0),
		new Alien(display, 75, 0),
		new Alien(display, 90, 0),
		new Alien(display, 0, 10),
		new Alien(display, 15, 10),
		new Alien(display, 30, 10),
		new Alien(display, 45, 10),
		new Alien(display, 60, 10),
		new Alien(display, 75, 10),
		new Alien(display, 90, 10)
	};

  movementCounter = 0;
  directionOfMovement = 1;
  width = 101; //may be changed later.
  height = 18;
  x_pos = 0;
  y_pos = 0;
}

void AlienHolder::initilizeAliens(){
  for(int i = 0; i < ALIENCOUNT; i++){
    entities[i]->draw();
  }
}

void AlienHolder::iterateThroughAliens(){
  if(movementCounter++ >= MOVEMENT_COUNTER_MAX){
    movementCounter = 0;
    if (directionOfMovement > 0 && (x_pos + width) < 127){
      for(int i = 0; i < ALIENCOUNT; i++){
        entities[i]->move(RIGHT);
      }
	  x_pos++;
      if(x_pos >= 22){
        directionOfMovement = -1;
        for(int i = 0; i < ALIENCOUNT; i++){
          entities[i]->move(DOWN);
        }
		y_pos++;
      }
    }
    else if(directionOfMovement < 0 && x_pos > 0){
      for(int i = 0; i < ALIENCOUNT; i++){
        entities[i]->move(LEFT);
      }
	  x_pos--;
      if(x_pos <= 1){
        directionOfMovement = 1;
        for(int i = 0; i < ALIENCOUNT; i++){
          entities[i]->move(DOWN);
        }
		y_pos++;
      }
    }
  }
  for(int i = 0; i < ALIENCOUNT; i++){
	  Alien * alien = (Alien*)entities[i];
    if(alien->isAlive()){
      alien->animate();
    }
  }
}
