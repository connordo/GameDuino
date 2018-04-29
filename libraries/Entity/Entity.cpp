#include "Entity.h"

Entity::Entity(int init_x_pos, int init_y_pos){
    x_pos = init_x_pos;
    y_pos = init_y_pos;
}

void Entity::move(Adafruit_SSD1306 display, int d){
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

void Entity::draw(Adafruit_SSD1306 display){
    display.drawBitmap(x_pos, y_pos, sprite_bmp, width, height, WHITE);
}

