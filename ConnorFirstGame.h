#ifndef _CONNOR_FIRST_GAME_H
#define _CONNOR_FIRST_GAME_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "buttons.h"
#include "sprites.h"
#include "essentials.h"
#include "Arduino.h"

class testGame {
    int timer;
  private:
    int xpos;
    int ypos;
    enum attitude_SM_t {init_st, welcome_st, menu_st, idle_st, move_l_st, move_r_st} currentState;
  public:
    testGame();
    void tick(Adafruit_SSD1306 display);
};
#endif // _CONNOR_FIRST_GAME_H
