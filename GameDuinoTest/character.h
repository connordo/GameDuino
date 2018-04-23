#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class character {
    int x_position;
    int y_position;
    character();
    drawSprite(Adafruit_SSD1306 display, int x, int y);
    eraseSprite(Adafruit_SSD1306 display);


};
#endif // _CHARACTER_H
