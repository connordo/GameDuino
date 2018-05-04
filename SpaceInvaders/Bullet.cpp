#include "Bullet.h"

static const unsigned char PROGMEM Bullet::sprite_bmp[]=
{
0b10000000, 0b10000000, 0b10000000, 0b10000000,
};

Bullet::Bullet(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos):Entity(display, init_x_pos,init_y_pos){
  height = 4;
  width = 8;
}

void Bullet::move(int d){
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
void Bullet::forceMove(int x, int y){
  Serial.begin(9600);
  Serial.println("Force move beginning");
  display->drawBitmap(x_pos, y_pos, sprite_bmp, width, height, BLACK);
  x_pos = x;
  y_pos = y;
  display->drawBitmap(x_pos, y_pos, sprite_bmp, width, height, WHITE);
  Serial.println("Force move ending");

}
void Bullet::draw(){
    display->drawBitmap(x_pos, y_pos, sprite_bmp, width, height, WHITE);
}
