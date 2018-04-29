#include "StarGame.h"


StarGame::StarGame(){
    starFruit = new StarFruit(16, 16);
}

void StarGame::start(Adafruit_SSD1306 display){
    starFruit->draw(display);
}

void StarGame::tick(Adafruit_SSD1306 display){
    // Read the buttons and move if necessary 
    if (buttons_readAll()&BITMASK_BTN_LEFT) {
        starFruit->move(display, 2);
    }
    if (buttons_readAll()&BITMASK_BTN_RIGHT) {
        starFruit->move(display, 3);
    }
    if (buttons_readAll()&BITMASK_BTN_UP){
        starFruit->move(display, 0);
    }
    if (buttons_readAll()&BITMASK_BTN_DOWN){
        starFruit->move(display, 1);
    }
}

