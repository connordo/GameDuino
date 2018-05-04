#include "Spaceship.h"

static const unsigned char PROGMEM Spaceship::sprite_bmp[]=
{
0b00000100, 0b00000000, 0b00001110, 0b00000000, 0b00001110, 0b00000000, 0b00001110, 0b00000000, 0b01111111, 0b11000000, 0b11111111, 0b11100000, 0b01101110, 0b11000000, 0b00101010, 0b10000000,
};

Spaceship::Spaceship(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos)
:Entity(display, init_x_pos, init_y_pos){
  height = 8;
  width = 16;
}

void Spaceship::move(int d){
    display->drawBitmap(x_pos, y_pos, sprite_bmp, width, height, BLACK);
    switch(d){
        case 0:
            display->drawBitmap(x_pos, --y_pos, sprite_bmp, width, height, WHITE);
            break;
        case 1:
            display->drawBitmap(x_pos, ++y_pos, sprite_bmp, width, height, WHITE);
            break;
        case 2:
            display->drawBitmap(--x_pos, y_pos, sprite_bmp, width, height, WHITE);
            break;
        case 3:
            display->drawBitmap(++x_pos, y_pos, sprite_bmp, width, height, WHITE);
            break;
    }
}

void Spaceship::draw(){
    display->drawBitmap(x_pos, y_pos, sprite_bmp, width, height, WHITE);
}
