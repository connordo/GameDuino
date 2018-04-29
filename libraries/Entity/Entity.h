#pragma once
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Entity {
    protected:
        int x_pos;
        int y_pos;
        int width;
        int height;
        static unsigned char sprite_bmp[];
       
    public:
        Entity(int init_x_pos, int init_y_pos);
        virtual void draw(Adafruit_SSD1306 display);
        virtual void move(Adafruit_SSD1306 display, int d);

};