#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "buttons.h"
#include "sprites.h"
#include "ledArray.h"

// If using software SPI (the default case):
#define OLED_MOSI   9 //SDA on the Board
#define OLED_CLK   10 //SCL on the Board
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13

#define MAZE_X_SIZE 21
#define MAZE_Y_SIZE 10


Adafruit_SSD1306 *display;

#define EMPTY_BLOCK_WIDTH 8
#define EMPTY_BLOCK_HEIGHT 4
static const unsigned char PROGMEM EmptyBlock[]=
{
  0b11110000, 0b11110000, 0b11110000, 0b11110000,
};

void setup() {
  display = new Adafruit_SSD1306(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
  display->begin(SSD1306_SWITCHCAPVCC);
  display->clearDisplay();  int maze[MAZE_X_SIZE][MAZE_Y_SIZE] = {0};
  display->fillScreen(WHITE);
  display->drawBitmap(1, 1, EmptyBlock, EMPTY_BLOCK_WIDTH, EMPTY_BLOCK_HEIGHT, BLACK);
  randomSeed(analogRead(0));
Serial.begin(9600);
  //Generate the Maze!!
  mazeGenerator(display, maze, 0, 0);
  display->display();
}

void loop() {
}

void mazeGenerator(Adafruit_SSD1306 *display, int maze[MAZE_X_SIZE][MAZE_Y_SIZE], int16_t x, int16_t y){
  Serial.println(freeRam());
  maze[x][y] = 1;
  int16_t optionsLeft = 4;
  while(optionsLeft > 0){
    //Get the available options
    int options[4] = {0};
    if(y - 1 >= 0 && maze[x][y - 1] == 0){
      options[0] = 1;
    }
    if(x + 1 < MAZE_X_SIZE && maze[x + 1][y] == 0){
      options[1] = 2;
    }
    if(y + 1 < MAZE_Y_SIZE && maze[x][y + 1] == 0){
      options[2] = 3;
    }
    if(x - 1 >= 0 && maze[x - 1][y] == 0){
      options[3] = 4;
    }
    optionsLeft = 0;
    for(int i = 0; i < 4; i++){
      if(options[i]!=0){
        optionsLeft++;
      }
    }

    //randomly select one of them
    uint8_t rando = random(0, 4);
    if(optionsLeft > 0){
      while(options[rando] == 0){
        rando = random(0, 4);
      }
    }

    switch(options[rando]){
      case 1:
      display->drawBitmap((x*6)+1, ((y-1)*6)+1, EmptyBlock, EMPTY_BLOCK_WIDTH, EMPTY_BLOCK_HEIGHT, BLACK);
      display->drawBitmap((x*6)+1, ((y-1)*6)+4, EmptyBlock, EMPTY_BLOCK_WIDTH, EMPTY_BLOCK_HEIGHT, BLACK);
      display->display();
      mazeGenerator(display, maze, x, y - 1);
      break;
      case 2:
      display->drawBitmap((((x + 1))*6)+1, ((y)*6)+1, EmptyBlock, EMPTY_BLOCK_WIDTH, EMPTY_BLOCK_HEIGHT, BLACK);
      display->drawBitmap((((x + 1))*6)-1, ((y)*6)+1, EmptyBlock, EMPTY_BLOCK_WIDTH, EMPTY_BLOCK_HEIGHT, BLACK);
      display->display();
      mazeGenerator(display, maze, x + 1, y);
      break;
      case 3:
      display->drawBitmap((((x))*6)+1, ((y + 1)*6)+1, EmptyBlock, EMPTY_BLOCK_WIDTH, EMPTY_BLOCK_HEIGHT, BLACK);
      display->drawBitmap((((x))*6)+1, ((y + 1)*6)-1, EmptyBlock, EMPTY_BLOCK_WIDTH, EMPTY_BLOCK_HEIGHT, BLACK);
      display->display();
      mazeGenerator(display, maze, x, y + 1);
      break;
      case 4:
      display->drawBitmap((((x - 1))*6)+1, ((y)*6)+1, EmptyBlock, EMPTY_BLOCK_WIDTH, EMPTY_BLOCK_HEIGHT, BLACK);
      display->drawBitmap((((x - 1))*6)+4, ((y)*6)+1, EmptyBlock, EMPTY_BLOCK_WIDTH, EMPTY_BLOCK_HEIGHT, BLACK);
      display->display();
      mazeGenerator(display, maze, x - 1, y);
      break;
      default:
      break;
    }
    optionsLeft--;
  }
}

int freeRam(){
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
