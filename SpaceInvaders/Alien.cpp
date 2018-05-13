#include "Alien.h"
#include "Arduino.h"
#define RANDOMFIRELOW 100
#define RANDOMFIREHIGH 500
unsigned char Alien::sprite_bmp[]=
{
  0b00100000, 0b10000000, 0b00010001, 0b00000000, 0b00111111, 0b10000000, 0b01101110, 0b11000000, 0b11111111, 0b11100000, 0b10111111, 0b10100000, 0b10100000, 0b10100000, 0b00011011, 0b00000000,
};

Alien::Alien(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos)
:Entity(display, init_x_pos, init_y_pos){
  height = 8;
  width = 16;
  true_width = 11;
  speed = 1;
  type = 'a';
  alive = true;
  animationSpeed = 40;
  animationCounter = 0;
  fireCounter = 0;
  FireMax = (int)random(RANDOMFIRELOW, RANDOMFIREHIGH);
  currentSprite = 1;
  for(int i = 0; i < 16; i++){
    sprite_bmp[i] = alien1[i];
  }
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

void Alien::explode()
{
	display->drawBitmap(x_pos, y_pos, sprite_bmp, width, height, BLACK);

}

void Alien::animate(){
  if(animationCounter++ >= animationSpeed){
    display->fillRect(x_pos, y_pos, width, height, BLACK);
    switch((currentSprite == 1 ? currentSprite = 2 : currentSprite = 1)){
      case 1:
      for(int i = 0; i < 16; i++){
        sprite_bmp[i] = alien1[i];
      }
      break;
      case 2:
      for(int i = 0; i < 16; i++){
        sprite_bmp[i] = alien2[i];
      }
      break;
      default:
      break;
    }
    display->drawBitmap(x_pos, y_pos, sprite_bmp, width, height, WHITE);
    animationCounter = 0;
  }
}


void Alien::draw(){
  display->drawBitmap(x_pos, y_pos, sprite_bmp, width, height, WHITE);
}

bool Alien::isAlive(){
  return alive;
}
