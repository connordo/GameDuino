#include "SI_StateMachine.h"
#include <buttons.h>

SI_StateMachine::SI_StateMachine(){
  currentState = init_st;
  user = new Spaceship((128/2)-4, 64-8);
}

SI_StateMachine::tick(Adafruit_SSD1306 display){
  //Mealey Actions
  switch(currentState){
    case init_st:
    user->draw(display);
    display.display();
    break;
    case idle_st:
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
    else if(buttons_readAll() & BITMASK_BTN_RIGHT){
      if(user->get_x_pos() + user->get_width() < display.width())
      user->move(display, 3);
    }
    break;
  }
}
