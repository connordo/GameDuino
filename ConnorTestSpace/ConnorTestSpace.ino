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
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

//image width:  8
//image height: 11
static const unsigned char PROGMEM MrGameDuino[]=
{
  0b00111000, 0b00111110, 0b00101000, 0b00111000, 0b01111100, 0b10111010, 0b10111010, 0b10101010, 0b00101000, 0b00101000, 0b01101100,
};

MrGameDuino *user;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  user = new MrGameDuino(display, 20, 20);
  display.display();
}

void loop() {
  if(buttons_readAll() & BTN_RIGHT){
    user->move(3);
  }
  if(buttons_readAll() & BTN_LEFT){
    user->move(2);
  }
}
