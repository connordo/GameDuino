#include "Alien.h"
#include "Arduino.h"
#define RANDOMFIRELOW 100
#define RANDOMFIREHIGH 500

const unsigned char PROGMEM Alien::alien_up_bmp[]=
{
  0b00100000, 0b10000000, 0b00010001, 0b00000000, 0b00111111, 0b10000000, 0b01101110, 0b11000000, 0b11111111, 0b11100000, 0b10111111, 0b10100000, 0b10100000, 0b10100000, 0b00011011, 0b00000000,
};

const unsigned char PROGMEM Alien::alien_down_bmp[]=
{
  0b00100000, 0b10000000, 0b10010001, 0b00100000, 0b10111111, 0b10100000, 0b11101110, 0b11100000, 0b11111111, 0b11100000, 0b01111111, 0b11000000, 0b00100000, 0b10000000, 0b01000000, 0b01000000,
};



Alien::Alien(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos)
:Entity(display, init_x_pos, init_y_pos){
  height = 8;
  width = 11;
  bmp_width = 16;
  speed = 1;
  type = 'a';
  alive = true;
  animationSpeed = 40;
  animationCounter = 0;
  fireCounter = 0;
  FireMax = (int)random(RANDOMFIRELOW, RANDOMFIREHIGH);
  currentSprite = 1;
}

void Alien::move(int d){
  display->drawBitmap(x_pos, y_pos, getSpriteBmp(), width, height, BLACK);
  switch(d){
    case 0:
    display->drawBitmap(x_pos, --y_pos, getSpriteBmp(), width, height, WHITE);
    break;
    case 1:
    display->drawBitmap(x_pos, ++y_pos, getSpriteBmp(), width, height, WHITE);
    break;
    case 2:
    display->drawBitmap(--x_pos, y_pos, getSpriteBmp(), width, height, WHITE);
    break;
    case 3:
    display->drawBitmap(++x_pos, y_pos, getSpriteBmp(), width, height, WHITE);
    break;
  }
}

void Alien::explode()
{
  display->drawBitmap(x_pos, y_pos, getSpriteBmp(), width, height, BLACK);
  alive = false;
  x_pos = -10;
}

void Alien::animate(){
  if(animationCounter++ >= animationSpeed){
    display->fillRect(x_pos, y_pos, width, height, BLACK);
    currentSprite == 1 ? currentSprite = 2 : currentSprite = 1;
    display->drawBitmap(x_pos, y_pos, getSpriteBmp(), width, height, WHITE);
    animationCounter = 0;
  }
}

void Alien::draw(){
  display->drawBitmap(x_pos, y_pos, getSpriteBmp(), width, height, WHITE);
}

bool Alien::isAlive(){
  return alive;
}

const unsigned char* Alien::getSpriteBmp(){
  if(currentSprite == 1){
    return alien_up_bmp;
  }
  else{
    return alien_down_bmp;
  }
}
