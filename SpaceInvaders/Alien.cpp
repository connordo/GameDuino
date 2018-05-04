#include "Alien.h"

static const unsigned char PROGMEM alien1[]=
{
0b00100000, 0b10000000, 0b00010001, 0b00000000, 0b00111111, 0b10000000, 0b01101110, 0b11000000, 0b11111111, 0b11100000, 0b10111111, 0b10100000, 0b10100000, 0b10100000, 0b00011011, 0b00000000,
};

static const unsigned char PROGMEM alien2[]=
{
0b00100000, 0b10000000, 0b10010001, 0b00100000, 0b10111111, 0b10100000, 0b11101110, 0b11100000, 0b11111111, 0b11100000, 0b01111111, 0b11000000, 0b00100000, 0b10000000, 0b01000000, 0b01000000,
};

Alien::Alien(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos)
:Entity(display, init_x_pos, init_y_pos){
  height = 8;
  width = 16;
  speed = 1;
  animationSpeed = 5;
}

void Alien::move(int d){
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

void Alien::draw(){
    display->drawBitmap(x_pos, y_pos, sprite_bmp, width, height, WHITE);
}
