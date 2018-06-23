#include "MrGameDuino.h"

static const unsigned char PROGMEM idle_1[]=
{
  0b00111000, 0b00111110, 0b00101000, 0b00111000, 0b01111100, 0b10111010, 0b10111010, 0b10101010, 0b00101000, 0b00101000, 0b01101100,
};

static const unsigned char PROGMEM idle_2[]=
{
  0b00000000, 0b00111000, 0b00111110, 0b00101000, 0b00111000, 0b01111100, 0b10111010, 0b10111010, 0b10101010, 0b00101000, 0b01101100,
};

static const unsigned char PROGMEM right_1[]=
{
  0b00111000, 0b00111110, 0b00101000, 0b00111000, 0b01111100, 0b10111100, 0b10111010, 0b10101000, 0b00101000, 0b11101000, 0b10001100,
};

static const unsigned char PROGMEM right_2[]=
{
  0b00111000, 0b00111110, 0b00101000, 0b00111000, 0b01111100, 0b01111111, 0b01111000, 0b00101000, 0b00100100, 0b00100100, 0b00110110,
};

static const unsigned char PROGMEM left_1[]=
{
  0b00011100, 0b01111100, 0b00010100, 0b00011100, 0b00111110, 0b00111101, 0b01011101, 0b00010101, 0b00010100, 0b00010111, 0b00110001,
};

static const unsigned char PROGMEM left_2[]=
{
  0b00011100, 0b01111100, 0b00010100, 0b00011100, 0b00111110, 0b11111110, 0b00011110, 0b00010100, 0b00100100, 0b00100100, 0b01101100,
};

MrGameDuino::getSpriteBmp(){
  if(buttons_readAll() & BTN_RIGHT){
    if(currentSprite == 1) return right_1;
    if(currentSprite == 2) return right_2;
  }
  if(buttons_readAll() & BTN_LEFT){
    if(currentSprite == 1) return left_1;
    if(currentSprite == 2) return left_2;
  }
  if(currentSprite  == 1) return idle_1;
  if(currentSprite  == 2) return idle_2;
}

MrGameDuino::MrGameDuino(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos)
:Entity(display, init_x_pos, init_y_pos){
  width = 8;
  height = 11;
  bmp_width = 8;
  animationSpeed = 3;
  currentSprite = 1;
}

void MrGameDuino::draw(){
  display->drawBitmap(x_pos, y_pos, getSpriteBmp(), width, height, WHITE);
}

void MrGameDuino::animate(){
  if(animationCounter++ >= animationSpeed){
    display->fillRect(x_pos, y_pos, width, height, BLACK);
    currentSprite == 1 ? currentSprite = 2 : currentSprite = 1;
draw();
    animationCounter = 0;
  }
}

void MrGameDuino::move(int d){
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
