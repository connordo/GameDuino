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
#include "TaylorYoshiGame.h"
#include "ledArray.h"

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



bool screen[128][64] = {0};


testGame *newGame;
void setup()   {
  // Serial.begin(9600);
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  display.display();
  ledArray_init();
  ledArray_writeLeds(0);
  delay(100);




  newGame = new testGame();
}

void loop() {
  //  Serial.println("testing...");
  newGame->tick(display);
  //   for (int i = 0; i < 100; i++) {
  //     // drawLink(i, 47, 1);
  //     display.display();
  //     delay(25);
  //     // drawLink(i, 47, 0);
  //   }
  // }
  //
  // void letterByLetterPrint( String phrase, uint16_t x, uint16_t y, uint16_t textSize, uint16_t printSpeed, uint16_t COLOR) {
  //   display.setTextSize(textSize);
  //   display.setTextColor(COLOR);
  //   display.setCursor(x, y);
  //   for (int i = 0; i < phrase.length(); i++) {
  //     display.print(phrase.charAt(i));
  //     display.display();
  //     delay(printSpeed);
  //   }
}
