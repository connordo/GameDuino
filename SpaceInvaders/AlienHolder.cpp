#include "AlienHolder.h"

AlienHolder::AlienHolder(Adafruit_SSD1306 *display){
  this->display = display;
}

void AlienHolder::initilizeAliens(){
  for(int i = 0; i < ALIENCOUNT; i++){
    alienArray[i].draw();
  }
}

void AlienHolder::iterateThroughAliens(){
  for(int i = 0; i < ALIENCOUNT; i++){
    // if(alienArray[i].isAlive()){
      alienArray[i].animate();
    // }
  }
}
