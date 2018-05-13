#include "AlienHolder.h"

AlienHolder::AlienHolder(Adafruit_SSD1306 *display){
  this->display = display;
  movementCounter = 0;
  directionOfMovement = 1;
  blockwidth = 101; //may be changed later.
  block_x_position = 0;
  block_y_position = 0;
}

void AlienHolder::initilizeAliens(){
  for(int i = 0; i < ALIENCOUNT; i++){
    alienArray[i].draw();
  }
}

void AlienHolder::iterateThroughAliens(){
  if(movementCounter++ >= MOVEMENT_COUNTER_MAX){
    movementCounter = 0;
    if (directionOfMovement > 0 && (block_x_position + blockwidth) < 127){
      for(int i = 0; i < ALIENCOUNT; i++){
        alienArray[i].move(RIGHT);
        block_x_position++;
      }
      if(block_x_position >= 27){
        directionOfMovement = -1;
        for(int i = 0; i < ALIENCOUNT; i++){
          alienArray[i].move(DOWN);
        }
      }
    }
    else if(directionOfMovement < 0 && block_x_position > 0){
      for(int i = 0; i < ALIENCOUNT; i++){
        alienArray[i].move(LEFT);
        block_x_position--;
      }
      if(block_x_position <= 1){
        directionOfMovement = 1;
        for(int i = 0; i < ALIENCOUNT; i++){
          alienArray[i].move(DOWN);
        }
      }
    }
  }
  for(int i = 0; i < ALIENCOUNT; i++){
    if(alienArray[i].isAlive()){
      alienArray[i].animate();
    }
  }
}
