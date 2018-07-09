#include "MrGameDuino.h"
#include "Arduino.h"
static const unsigned char PROGMEM MrGameDuinofullmap[]=
{
  0b00111000, 0b00111110, 0b00101000, 0b00111000, 0b01111100, 0b10111010, 0b10111010, 0b10101010, 0b00101000, 0b00101000, 0b01101100, 0b00000000, 0b00111000, 0b00111110, 0b00101000, 0b00111000, 0b01111100, 0b10111010, 0b10111010, 0b10101010, 0b00101000, 0b01101100, 0b00011100, 0b01111100, 0b00010100, 0b00011100, 0b00111110, 0b00111101, 0b11011101, 0b00010101, 0b00010100, 0b00010011, 0b00110001, 0b00011100, 0b01111100, 0b00010100, 0b00011100, 0b00111110, 0b00111110, 0b00011110, 0b00010100, 0b00010100, 0b00001100, 0b00001100, 0b00111000, 0b00111110, 0b00101000, 0b00111000, 0b01111100, 0b10111100, 0b10111011, 0b10101000, 0b00101000, 0b11001000, 0b10001100, 0b00111000, 0b00111110, 0b00101000, 0b00111000, 0b01111100, 0b01111100, 0b01111000, 0b00101000, 0b00101000, 0b00110000, 0b00110000,
};

static const unsigned char PROGMEM MrGameDuino::idle_1[]=
{
  0b00111000, 0b00111110, 0b00101000, 0b00111000, 0b01111100, 0b10111010, 0b10111010, 0b10101010, 0b00101000, 0b00101000, 0b01101100,
};

static const unsigned char PROGMEM MrGameDuino::idle_2[]=
{
  0b00000000, 0b00111000, 0b00111110, 0b00101000, 0b00111000, 0b01111100, 0b10111010, 0b10111010, 0b10101010, 0b00101000, 0b01101100,
};

static const unsigned char PROGMEM MrGameDuino::right_1[]=
{
  0b00111000, 0b00111110, 0b00101000, 0b00111000, 0b01111100, 0b10111100, 0b10111011, 0b10101000, 0b00101000, 0b11001000, 0b10001100,
};

static const unsigned char PROGMEM MrGameDuino::right_2[]=
{
  0b00111000, 0b00111110, 0b00101000, 0b00111000, 0b01111100, 0b01111100, 0b01111000, 0b00101000, 0b00101000, 0b00110000, 0b00110000,
};

static const unsigned char PROGMEM MrGameDuino::left_1[]=
{
  0b00011100, 0b01111100, 0b00010100, 0b00011100, 0b00111110, 0b00111101, 0b11011101, 0b00010101, 0b00010100, 0b00010011, 0b00110001,
};

static const unsigned char PROGMEM MrGameDuino::left_2[]=
{
  0b00011100, 0b01111100, 0b00010100, 0b00011100, 0b00111110, 0b00111110, 0b00011110, 0b00010100, 0b00010100, 0b00001100, 0b00001100,
};

unsigned char* MrGameDuino::SpriteMapParser(int index){
  unsigned char* returnSprite;
  for(int i = 0; i < height; i++){
    returnSprite[i] = MrGameDuinofullmap[index++];
    // returnSprite[i] = MrGameDuinofullmap[i];
  }
  return returnSprite;
}

  const unsigned char* MrGameDuino::getSpriteBmp(){
  // if(buttons_readAll() & BITMASK_BTN_RIGHT){
  //   if(currentSprite == 1) return right_1;
  //   if(currentSprite == 2) return right_2;
  // }
  // if(buttons_readAll() & BITMASK_BTN_LEFT){
  //   if(currentSprite == 1) return left_1;
  //   if(currentSprite == 2) return left_2;
  // }
  // if(currentSprite  == 1) return idle_1;
  // if(currentSprite  == 2) return idle_2;
  ////
  int index_val = 0;

  if(buttons_readAll() & BITMASK_BTN_RIGHT){
    if(currentSprite == 1) index_val = 0 + (height * 4);
    if(currentSprite == 2) index_val = 0 + (height * 5);
  }
  if(buttons_readAll() & BITMASK_BTN_LEFT){
    if(currentSprite == 1) index_val = 0 + (height * 2);
    if(currentSprite == 2) index_val = 0 + (height * 3);
  }
  if(currentSprite  == 1) index_val = 0 + (height * 0);
  if(currentSprite  == 2) index_val = 0 + (height * 1);

  const unsigned char* returnSprite = SpriteMapParser(index_val);
  return returnSprite;
}

MrGameDuino::MrGameDuino(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos)
:Entity(display, init_x_pos, init_y_pos){
  width = 8;
  height = 11;
  bmp_width = 8;
  animationSpeed = 5;
  currentSprite = 1;
  animationCounter = 0;
}

void MrGameDuino::draw(){
  display->drawBitmap(x_pos, y_pos, getSpriteBmp(), width, height, WHITE);
}

void MrGameDuino::animate(){
  if(animationCounter++ >= animationSpeed){
    // Serial.begin(9600);
    // Serial.println("got inside");
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
