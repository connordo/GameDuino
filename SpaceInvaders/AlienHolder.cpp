#include "AlienHolder.h"

AlienHolder::AlienHolder(Adafruit_SSD1306 *display) {
	this->display = display;
  movementCounter = 0;
  directionOfMovement = 1;
  width = 101; //may be changed later.
  height = 18;
  x_pos = 0;
  y_pos = 0;
}

void AlienHolder::initilizeAliens(){
  for(int i = 0; i < ALIENCOUNT; i++){
    alienArray[i].draw();
  }
}

void AlienHolder::iterateThroughAliens(){
  if(movementCounter++ >= MOVEMENT_COUNTER_MAX){
    movementCounter = 0;
    if (directionOfMovement > 0 && (x_pos + width) < 127){
      for(int i = 0; i < ALIENCOUNT; i++){
        alienArray[i].move(RIGHT);
      }
	  x_pos++;
      if(x_pos >= 22){
        directionOfMovement = -1;
        for(int i = 0; i < ALIENCOUNT; i++){
          alienArray[i].move(DOWN);
        }
		y_pos++;
      }
    }
    else if(directionOfMovement < 0 && x_pos > 0){
      for(int i = 0; i < ALIENCOUNT; i++){
        alienArray[i].move(LEFT);
      }
	  x_pos--;
      if(x_pos <= 1){
        directionOfMovement = 1;
        for(int i = 0; i < ALIENCOUNT; i++){
          alienArray[i].move(DOWN);
        }
		y_pos++;
      }
    }
  }
  for(int i = 0; i < ALIENCOUNT; i++){
    if(alienArray[i].isAlive()){
      alienArray[i].animate();
    }
  }
}
