#include "SI_StateMachine.h"
#include <buttons.h>

SI_StateMachine::SI_StateMachine(Adafruit_SSD1306 *display){
  this->display = display;
  currentState = init_st;
  user = new Spaceship(display, (128/2)-4, 64-8);
  bulletIndex = 1;
}

SI_StateMachine::tick(){
  //Mealey Actions
  switch(currentState){
    case init_st:
    user->draw();
    break;
    case idle_st:
    for(int i = 0; i < BULLETCOUNT; i++){
      if(shot[i].get_y_pos() > -4){
        shot[i].move(0);
        shot[i].move(0);
      }
    }
    break;
  }

  //Moore Actions
  switch(currentState){
    case init_st:
    currentState=idle_st;
    break;
    case idle_st:
    if(buttons_readAll() & BITMASK_BTN_LEFT){
      if(user->get_x_pos() > 0)
      user->move(2);
    }
    if(buttons_readAll() & BITMASK_BTN_RIGHT){
      if(user->get_x_pos() + user->get_width() < display->width())
      user->move(3);
    }
    Serial.begin(9600);
    Serial.println(bulletIndex);

    if(buttons_readAll() & BITMASK_BTN_A){
      Serial.println("inside the a button");
      int prevBulletIndex;
      if(bulletIndex==0)
      prevBulletIndex = BULLETCOUNT-1;
      else
      prevBulletIndex = bulletIndex-1;

      if(shot[prevBulletIndex].get_y_pos() < user->get_y_pos()-10){
        shot[bulletIndex].forceMove(user->get_x_pos() + 5, user->get_y_pos() - 4);
        if(bulletIndex==BULLETCOUNT-1){

          bulletIndex=0;
        }
        else{

          bulletIndex++;
        }
      }
    }
    break;
  }
  display->display();
}
