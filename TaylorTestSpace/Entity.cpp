#include "Entity.h"

Entity::Entity(int init_x_pos, int init_y_pos){
    x_pos = init_x_pos;
    y_pos = init_y_pos;
}

Entity::move(Direction d){
    display.drawBitmap(x_pos, y_pos, sprite_bmp, width, height, BLACK);
    switch(d){
        case UP:
            display.drawBitmap(x_pos, --y_pos, sprite_bmp, width, height, WHITE);
            break;
        case DOWN:
            display.drawBitmap(x_pos, ++y_pos, sprite_bmp, width, height, WHITE);
            break;
        case LEFT:
            display.drawBitmap(--x_pos, y_pos, sprite_bmp, width, height, WHITE);
            break;
        case RIGHT:
            display.drawBitmap(++x_pos, y_pos, sprite_bmp, width, height, WHITE);
            break;
    }
    display.display();
}