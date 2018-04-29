#include "SI_StateMachine.h"
#include <buttons.h>

SI_StateMachine::SI_StateMachine(){
  currentState = init_st;
  user = new Spaceship((128/2)-4, 64-8);
  bulletIndex = 0;
}

SI_StateMachine::tick(Adafruit_SSD1306 display){
  //Mealey Actions
  switch(currentState){
    case init_st:
    user->draw(display);
    display.display();
    break;
    case idle_st:
    for(int i = 0;i < 5; i++){
      if(shot[i].get_y_pos()>-4){
        shot[i].move(display, 0);
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
      user->move(display, 2);
    }
    if(buttons_readAll() & BITMASK_BTN_RIGHT){
      if(user->get_x_pos() + user->get_width() < display.width())
      user->move(display, 3);
    }
    if(buttons_readAll() & BITMASK_BTN_A){
      if(shot[bulletIndex-1].get_y_pos() < user->get_y_pos()-10){
        shot[bulletIndex].forceMove(display, user->get_x_pos()+5, user->get_y_pos()-4);
        if(bulletIndex==4)
          bulletIndex=0;
        else
          bulletIndex++;

      }
    }
    break;
  }
}
