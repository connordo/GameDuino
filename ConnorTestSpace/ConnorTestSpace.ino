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
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

static const unsigned char PROGMEM testbitmap[]=
{
  B00000000, B11000000,
    B00000001, B11000000,
    B00000001, B11000000,
};

static const unsigned char PROGMEM SpaceShipBitmap[]=
{
0b00000001, 0b10000000, 0b00000001, 0b10000000, 0b00000001, 0b10000000, 0b00000001, 0b10000000, 0b00010001, 0b10001000, 0b00010001, 0b10001000, 0b00010111, 0b11101000, 0b00011111, 0b11111000, 0b00011111, 0b11111000, 0b10111111, 0b11111101, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11000011, 0b11000011, 0b00000011, 0b11000000, 0b00000111, 0b11100000, 0b00001101, 0b10110000, };
void setup() {
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  display.drawBitmap(30, 16,  testbitmap, 16, 3, 1);
  display.drawBitmap(60, 16,  SpaceShipBitmap, 16, 16, 1);
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:

}
