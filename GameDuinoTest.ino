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
#include "ConnorFirstGame.h"
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
ledArray_writeLeds(0xff);
digitalWrite(LED9,HIGH);
digitalWrite(LED10, HIGH);
// ledArray_writeLeds(0b0000110000);
// delay(100);
// ledArray_writeLeds(0b0001111000);
// delay(100);
// ledArray_writeLeds(0b0011111100);
// delay(100);
// ledArray_writeLeds(0b0111111110);
// delay(100);
// ledArray_writeLeds(0b1111111111);

  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.

  // Clear the buffer.
/////
//delay(2000);
//drawDinoRight(display,10,30,WHITE);
//delay(2000);
//drawDinoRight(display,10,30,WHITE);
//delay(5000);


//  display.drawLine(x, y - 11, x, y - 7, COLOR);
//  display.drawLine(x + 1, y - 9, x + 1, y - 6, COLOR);
//  display.drawLine(x + 2, y - 8, x + 2, y - 5, COLOR);
//  display.fillRect(x + 3, y - 7, 6, 4, COLOR);
//  display.fillRect(x + 4, y - 3, 5, 4, COLOR);
//  display.drawLine(x + 6, y - 2, x + 6, y, BLACK);
//  display.drawLine(x + 5, y - 1, x + 7, y - 1, BLACK);
//  display.drawPixel(x + 7, y, BLACK);
//  display.drawPixel(x + 9, y, COLOR);
//  display.fillRect(x + 6, y - 9, 5, 4, COLOR);
//  display.fillRect(x + 8, y - 16, 3, 12, COLOR);
//  display.drawPixel(x + 10, y - 5, BLACK);
//  display.drawPixel(x + 7, y - 10, BLACK);
//  display.drawLine(x + 5, y - 8, x + 12, y - 8, COLOR);
//  display.drawPixel(x + 12, y - 7, COLOR);
//  display.drawPixel(x + 8, y - 16, BLACK);
//  display.drawPixel(x + 10, y - 15, BLACK);
//  display.fillRect(x + 11, y - 16, 5, 6, COLOR);
//  display.drawPixel(x + 15, y - 16, BLACK);
//  display.drawPixel(x + 15, y - 11, BLACK);
//  display.drawLine(x + 12, y - 12, x + 15, y - 12, BLACK);
//  display.display();
/////delay(200);


  //
  // digitalWrite(LED1, HIGH);
  // digitalWrite(LED2, HIGH);
  // digitalWrite(LED3, HIGH);
  // digitalWrite(LED4, HIGH);
  // digitalWrite(LED5, HIGH);
  // digitalWrite(LED6, HIGH);
  // digitalWrite(LED7, HIGH);
  // digitalWrite(LED8, HIGH);
  // digitalWrite(LED9, HIGH);
  //
  // // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  // display.begin(SSD1306_SWITCHCAPVCC);
  //
  // delay(1000);
  // /////////////////////////
  // display.clearDisplay();
  // drawPlaneRight(display, 20, 20, WHITE);
  // drawDinoRight(display, 0, 63, WHITE);
  // drawNinjaRight(display, 25, 63, WHITE);
  // drawGalagaAlien(display, 40, 10, WHITE);
  // drawAxeManLeft(display, 50, 63, WHITE);
  // drawSwordManLeft(display, 67, 63, WHITE);
  // drawMaceManLeft(display, 85, 63, WHITE);
  // drawSpaceShip(display, 55, 10, WHITE);
  // delay(10000);
  //
  // display.clearDisplay();
  //
  // //////////////////////////////////////
  // letterByLetterPrint("hello there", 0, 0, 1, FAST, WHITE);
  // letterByLetterPrint("hello there", 0, 10, 1, MEDIUM, WHITE);
  // letterByLetterPrint("hello there", 0, 20, 1, SLOW, WHITE);
  //
  // delay(10000);
  // display.clearDisplay();
  // //////////////////////////////////////////////////////////////////////////////////////
  // display.setTextSize(1);
  // display.setTextColor(WHITE);
  // display.setCursor(0, 0);
  // display.println("Demonstration of some \nsimple display \nmovement...");
  // for (int j = 0 ; j < 3; j++) {
  //   for (int i = 0; i < 100; i++) {
  //     display.fillRect(i, 47, 10, 63, WHITE);
  //     display.display();
  //     delay(25);
  //     display.fillRect(i, 47, 10, 63, BLACK);
  //   }
  // }
  //
  // display.clearDisplay();
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
