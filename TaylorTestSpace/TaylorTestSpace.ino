/*
Welcome to the GameDuino Test file! This file will you through the basics of how
to interface with the 128X64 OLED screen over SPI. For a more detailed summary
of what the Adafruit_GFX and Adafruit_SSD1306 libraries are capable of, I
reccomend you go and read the .h files
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "buttons.h"
#include "sprites.h"
#include "ledArray.h"
#include "StarGame.h"

// If using software SPI (the default case):
#define OLED_MOSI   9 //SDA on the Board
#define OLED_CLK   10 //SCL on the Board
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
#define TIME 100
#define FAST 50
#define MEDIUM 100
#define SLOW 200

StarGame* starGame;

void setup()   {
  // Serial.begin(9600);
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  display.display();
  ledArray_init();
  ledArray_writeLeds(0);
  delay(100);

  starGame = new StarGame();
  starGame->start(display);
}

void loop() {
  starGame->tick(display);
}
