#include "Bunker.h"
#define BLOCKCOUNT 6
Bunker::Bunker(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos):EntityGroup(){
  this->display = display;
  x_pos = init_x_pos;
  y_pos = init_y_pos;
  width = 24;
  height = 8;
  entities = new Entity*[BLOCKCOUNT]{
    new BunkerBlock(display, x_pos, y_pos),
    new BunkerBlock(display, x_pos + 4, y_pos),
    new BunkerBlock(display, x_pos + 8, y_pos),
    new BunkerBlock(display, x_pos + 12, y_pos),
    new BunkerBlock(display, x_pos + 12, y_pos + 4),
    new BunkerBlock(display, x_pos, y_pos + 4)
  };
  array_length = BLOCKCOUNT;
}
