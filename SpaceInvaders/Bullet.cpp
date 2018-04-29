#include "Bullet.h"

static const unsigned char PROGMEM Bullet::sprite_bmp[]=
{
0b10000000, 0b10000000, 0b10000000, 0b10000000,
};

Bullet::Bullet(int init_x_pos, int init_y_pos):Entity(init_x_pos,init_y_pos){
  height = 4;
  width = 8;
}

void Bullet::move(Adafruit_SSD1306 display, int d){
    display.drawBitmap(x_pos, y_pos, sprite_bmp, width, height, BLACK);
    switch(d){
        case 0:
            display.drawBitmap(x_pos, --y_pos, sprite_bmp, width, height, WHITE);
            break;
        case 1:
            display.drawBitmap(x_pos, ++y_pos, sprite_bmp, width, height, WHITE);
            break;
        case 2:
            display.drawBitmap(--x_pos, y_pos, sprite_bmp, width, height, WHITE);
            break;
        case 3:
            display.drawBitmap(++x_pos, y_pos, sprite_bmp, width, height, WHITE);
            break;
    }
    display.display();
}
void Bullet::forceMove(Adafruit_SSD1306 display, int x, int y){
  display.drawBitmap(x_pos, y_pos, sprite_bmp, width, height, BLACK);
  x_pos = x;
  y_pos = y;
  display.drawBitmap(x_pos, y_pos, sprite_bmp, width, height, WHITE);
}
void Bullet::draw(Adafruit_SSD1306 display){
    display.drawBitmap(x_pos, y_pos, sprite_bmp, width, height, WHITE);
}
