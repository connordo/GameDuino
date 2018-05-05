#include "SI_StateMachine.h"
#include <buttons.h>

SI_StateMachine::SI_StateMachine(Adafruit_SSD1306 *display){
  this->display = display;
  currentState = init_st;
  user = new Spaceship(display, (128/2)-4, 64-8);
  testbug = new Alien(display, 10, 10);
  userShot = new Bullet(display, 0, -10);
}

void SI_StateMachine::tick(){
  //Mealey Actions
  switch(currentState){
    case init_st:
    user->draw();
    testbug->draw();
    break;
    case idle_st:
    testbug->animate();
    if(userShot->get_y_pos() > -4){
      userShot->move(0);
      userShot->move(0);
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

    if(buttons_readAll() & BITMASK_BTN_A){
      if(userShot->get_y_pos() < 0){
        userShot->forceMove(user->get_x_pos() + 5, user->get_y_pos() - 4);

      }
    }
    break;
  }
  display->display();
}
