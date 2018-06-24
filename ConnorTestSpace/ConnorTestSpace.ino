#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "buttons.h"
#include "sprites.h"
#include "ledArray.h"
#include "MrGameDuino.h"

// If using software SPI (the default case):
#define OLED_MOSI   9 //SDA on the Board
#define OLED_CLK   10 //SCL on the Board
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 *display;

//image width:  8
//image height: 11

MrGameDuino *user;

void setup() {
  display = new Adafruit_SSD1306(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
  display->begin(SSD1306_SWITCHCAPVCC);
  display->clearDisplay();
  user = new MrGameDuino(display, 20, 20);
  user->draw();
  display->display();
  // while(1);
}

void loop() {
  if(buttons_readAll() & BITMASK_BTN_RIGHT){
    user->move(3);
  }
  if(buttons_readAll() & BITMASK_BTN_LEFT){
    user->move(2);
  }
  user->animate();
  display->display();
}
