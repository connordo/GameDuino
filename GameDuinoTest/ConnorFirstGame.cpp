#include "ConnorFirstGame.h"

#define OLED_MOSI   9 //SDA on the Board
#define OLED_CLK   10 //SCL on the Board
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13

testGame::testGame() {
  // Serial.begin(9600);
  currentState = init_st;
}

void testGame::tick(Adafruit_SSD1306 display) {
  switch (currentState) {
    case  init_st:
    // Serial.println("init_st");
    break;

    case welcome_st:
    // Serial.println("welcome_st");
    timer++;
    break;

    case  menu_st:
    // Serial.println("menu_st");
    break;

    case  idle_st:
    // Serial.println("idle_st");
    break;

    case  move_l_st:
    // Serial.println("move_l_st");
    break;

    case  move_r_st:
    // Serial.println("move_r_st");
    break;
  }

  switch (currentState) {
    case  init_st:
    welcomeScreen(display);
    timer = 0;
    currentState = welcome_st;
    break;
    case welcome_st:
    if (timer >= 100) {
      display.clearDisplay();
      display.display();
      menuScreen(display);

      currentState = menu_st;
    }
    break;
    case  menu_st:
    if (buttons_readAll()&BITMASK_BTN_A) {
      display.clearDisplay();
      display.display();
      xpos = 0;
      ypos = 63;
      direction = 1;
      drawYoshiRight(display, xpos, ypos, WHITE);

      currentState = idle_st;
    }
    break;
    case  idle_st:
    if (buttons_readAll()&BITMASK_BTN_LEFT) {
      if (xpos > 0) {
        if(direction > 0){
          drawYoshiRight(display, xpos, ypos, BLACK);
        }
        else if(direction < 0){
          drawYoshiLeft(display, xpos, ypos, BLACK);
        }
        drawYoshiLeft(display, --xpos, ypos, WHITE);
        direction = -1;
      }
    }
    if (buttons_readAll()&BITMASK_BTN_RIGHT) {
      if (xpos < 117) {

        if(direction > 0){
          drawYoshiRight(display, xpos, ypos, BLACK);
        }
        else if(direction < 0){
          drawYoshiLeft(display, xpos, ypos, BLACK);
        }
        drawYoshiRight(display, ++xpos, ypos, WHITE);
        direction = 1;
      }
    }
    break;
    case  move_l_st:

    break;
    case  move_r_st:

    break;
  }
}
