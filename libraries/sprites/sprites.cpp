#include "sprites.h"
uint16_t dinoRight[17] =
{ 0b0000000001111110, //16
  0b0000000011011111, //15
  0b0000000011111111, //14
  0b0000000011111111, //13
  0b0000000011110000, //12
  0b1000000011111110, //11
  0b1000000111100000, //10
  0b1100001111100000, //9
  0b1110011111111000, //8
  0b1111111111101000, //7
  0b0111111111100000, //6
  0b0011111111000000, //5
  0b0001111110000000, //4
  0b0000111110000000, //3
  0b0000110110000000, //2
  0b0000100010000000, //1
  0b0000110011000000
}; //0

uint16_t dinoLeft[17] =
{ 0b0111111000000000, //16
  0b1111101100000000, //15
  0b1111111100000000, //14
  0b1111111100000000, //13
  0b0000111100000000, //12
  0b0111111100000000, //11
  0b0000011110000001, //10
  0b0000011111000011, //9
  0b0001111111100111, //8
  0b0001011111111111, //7
  0b0000011111111110, //6
  0b0000001111111100, //5
  0b0000000111111000, //4
  0b0000000111110000, //3
  0b0000000110110000, //2
  0b0000000100010000, //1
  0b0000001100110000
}; //0

void drawPixMap(Adafruit_SSD1306 display, uint16_t PixMap[], int mapSize, uint16_t x, uint16_t y , uint16_t COLOR) {
  for (int i = 0; i < mapSize; i++) {
    uint16_t temp = PixMap[i];
  }
}

void drawLink(Adafruit_SSD1306 display, uint16_t x, uint16_t y , uint16_t COLOR) {
  //row 0
  display.drawPixel(x + 4, y, COLOR);
  display.drawPixel(x + 5, y, COLOR);
  display.drawPixel(x + 6, y, COLOR);
  display.drawPixel(x + 7, y, COLOR);
  display.drawPixel(x + 8, y, COLOR);
  //row 1
  display.drawPixel(x + 3, y + 1, COLOR);
  display.drawPixel(x + 9, y + 1, COLOR);
  display.drawPixel(x + 10, y + 1, COLOR);
  //row 2
  display.drawPixel(x + 2, y + 2, COLOR);
  display.drawPixel(x + 8, y + 2, COLOR);
  display.drawPixel(x + 11, y + 2, COLOR);
  //row 3
  display.drawPixel(x + 1, y + 3, COLOR);
  display.drawPixel(x + 4, y + 3, COLOR);
  display.drawPixel(x + 7, y + 3, COLOR);
  display.drawPixel(x + 11, y + 3, COLOR);
  display.drawPixel(x + 12, y + 3, COLOR);
  display.drawPixel(x + 13, y + 3, COLOR);
  //row 4
  display.drawPixel(x + 0, y + 4, COLOR);
  display.drawPixel(x + 3, y + 4, COLOR);
  display.drawPixel(x + 5, y + 4, COLOR);
  display.drawPixel(x + 6, y + 4, COLOR);
  display.drawPixel(x + 10, y + 4, COLOR);
  display.drawPixel(x + 11, y + 4, COLOR);
  display.drawPixel(x + 12, y + 4, COLOR);
  //row 5
  display.drawPixel(x + 0, y + 5, COLOR);
  display.drawPixel(x + 3, y + 5, COLOR);
  display.drawPixel(x + 6, y + 5, COLOR);
  display.drawPixel(x + 8, y + 5, COLOR);
  display.drawPixel(x + 9, y + 5, COLOR);
  display.drawPixel(x + 10, y + 5, COLOR);
  //row 6
  display.drawPixel(x + 0, y + 6, COLOR);
  display.drawPixel(x + 1, y + 6, COLOR);
  display.drawPixel(x + 3, y + 6, COLOR);
  display.drawPixel(x + 6, y + 6, COLOR);
  display.drawPixel(x + 7, y + 6, COLOR);
  display.drawPixel(x + 9, y + 6, COLOR);
  display.drawPixel(x + 11, y + 6, COLOR);
  display.drawPixel(x + 12, y + 6, COLOR);
  //row 7
  display.drawPixel(x + 2, y + 7, COLOR);
  display.drawPixel(x + 3, y + 7, COLOR);
  display.drawPixel(x + 6, y + 7, COLOR);
  display.drawPixel(x + 9, y + 7, COLOR);
  display.drawPixel(x + 12, y + 7, COLOR);
  //row 8
  display.drawPixel(x + 3, y + 8, COLOR);
  display.drawPixel(x + 6, y + 8, COLOR);
  display.drawPixel(x + 11, y + 8, COLOR);
  //row 9
  display.drawPixel(x + 3, y + 9, COLOR);
  display.drawPixel(x + 4, y + 9, COLOR);
  display.drawPixel(x + 6, y + 9, COLOR);
  display.drawPixel(x + 10, y + 9, COLOR);
  //row 10
  display.drawPixel(x + 3, y + 10, COLOR);
  display.drawPixel(x + 5, y + 10, COLOR);
  display.drawPixel(x + 6, y + 10, COLOR);
  display.drawPixel(x + 7, y + 10, COLOR);
  display.drawPixel(x + 8, y + 10, COLOR);
  display.drawPixel(x + 9, y + 10, COLOR);
  display.drawPixel(x + 10, y + 10, COLOR);
  //row 11
  display.drawPixel(x + 2, y + 11, COLOR);
  display.drawPixel(x + 5, y + 11, COLOR);
  display.drawPixel(x + 8, y + 11, COLOR);
  display.drawPixel(x + 10, y + 11, COLOR);
  //row 12
  display.drawPixel(x + 2, y + 12, COLOR);
  display.drawPixel(x + 5, y + 12, COLOR);
  display.drawPixel(x + 8, y + 12, COLOR);
  display.drawPixel(x + 10, y + 12, COLOR);
  //row 13
  display.drawPixel(x + 2, y + 13, COLOR);
  display.drawPixel(x + 3, y + 13, COLOR);
  display.drawPixel(x + 4, y + 13, COLOR);
  display.drawPixel(x + 5, y + 13, COLOR);
  display.drawPixel(x + 6, y + 13, COLOR);
  display.drawPixel(x + 7, y + 13, COLOR);
  display.drawPixel(x + 8, y + 13, COLOR);
  display.drawPixel(x + 9, y + 13, COLOR);
  display.drawPixel(x + 10, y + 13, COLOR);
  //row 14
  display.drawPixel(x + 3, y + 14, COLOR);
  display.drawPixel(x + 8, y + 14, COLOR);
  display.drawPixel(x + 9, y + 14, COLOR);
  display.drawPixel(x + 10, y + 14, COLOR);
  //row 15
  display.drawPixel(x + 2, y + 15, COLOR);
  display.drawPixel(x + 3, y + 15, COLOR);
  display.drawPixel(x + 4, y + 15, COLOR);
  display.drawPixel(x + 5, y + 15, COLOR);
  display.drawPixel(x + 6, y + 15, COLOR);
  display.drawPixel(x + 7, y + 15, COLOR);
  display.drawPixel(x + 8, y + 15, COLOR);
  display.drawPixel(x + 9, y + 15, COLOR);
  display.drawPixel(x + 10, y + 15, COLOR);
  display.drawPixel(x + 11, y + 15, COLOR);
  display.display();
}

void drawPlaneRight(Adafruit_SSD1306 display, uint16_t x, uint16_t y , uint16_t COLOR) {
  display.drawLine(x - 12, y - 2, x + 11, y - 2, COLOR);
  display.drawLine(x - 14, y + 2, x + 10, y + 2, COLOR);
  display.drawLine(x - 14, y + 2, x - 15, y - 3, COLOR);
  display.drawLine(x - 15, y - 3, x - 12, y - 2, COLOR);
  display.drawTriangle(x - 3, y , x + 5, y, x - 9, y + 7, COLOR);
  display.drawTriangle(x - 4, y - 2 , x + 3, y - 2, x - 9, y - 6, COLOR);
  display.drawLine(x - 3, y , x + 5, y, BLACK);
  display.drawPixel(x + 11, y - 1, COLOR);
  display.drawPixel(x + 12, y , COLOR);
  display.drawPixel(x + 12, y + 1, COLOR);
  display.drawPixel(x + 11, y + 1, COLOR);
  display.drawPixel(x + 10, y + 2, COLOR);
  display.drawLine(x, y + 2, x - 4, y + 2, BLACK);
  display.display();
}

void drawDinoRight(Adafruit_SSD1306 display, uint16_t x, uint16_t y , uint16_t COLOR) {
  display.drawLine(x, y - 11, x, y - 7, COLOR);
  display.drawLine(x + 1, y - 9, x + 1, y - 6, COLOR);
  display.drawLine(x + 2, y - 8, x + 2, y - 5, COLOR);
  display.fillRect(x + 3, y - 7, 6, 4, COLOR);
  display.fillRect(x + 4, y - 3, 5, 4, COLOR);
  display.drawLine(x + 6, y - 2, x + 6, y, BLACK);
  display.drawLine(x + 5, y - 1, x + 7, y - 1, BLACK);
  display.drawPixel(x + 7, y, BLACK);
  display.drawPixel(x + 9, y, COLOR);
  display.fillRect(x + 6, y - 9, 5, 4, COLOR);
  display.fillRect(x + 8, y - 16, 3, 12, COLOR);
  display.drawPixel(x + 10, y - 5, BLACK);
  display.drawPixel(x + 7, y - 10, BLACK);
  display.drawLine(x + 5, y - 8, x + 12, y - 8, COLOR);
  display.drawPixel(x + 12, y - 7, COLOR);
  display.drawPixel(x + 8, y - 16, BLACK);
  display.drawPixel(x + 10, y - 15, BLACK);
  display.fillRect(x + 11, y - 16, 5, 6, COLOR);
  display.drawPixel(x + 15, y - 16, BLACK);
  display.drawPixel(x + 15, y - 11, BLACK);
  display.drawLine(x + 12, y - 12, x + 15, y - 12, BLACK);
  display.display();
}
void drawNinjaRight(Adafruit_SSD1306 display, uint16_t x, uint16_t y , uint16_t COLOR) {
  display.drawLine(x + 1, y - 8, x + 1, y - 4, COLOR);
  display.drawLine(x , y - 14, x + 2, y - 12, COLOR);
  display.fillRect(x + 2, y - 12, 5, 4, COLOR);
  display.fillRect(x + 3, y - 13, 4, 14, COLOR);
  display.fillRect(x + 4, y - 3, 2, 4, BLACK);
  display.fillRect(x + 7, y - 11, 1, 3, COLOR);
  display.fillRect(x + 8, y - 8, 1, 4, COLOR);
  display.fillRect(x + 3, y - 20, 7, 7, COLOR);
  display.fillRect(x + 3, y - 15, 1, 2, BLACK);
  display.fillRect(x + 8, y - 20, 2, 1, BLACK);
  display.drawPixel(x + 3, y - 20, BLACK);
  display.drawPixel(x + 9, y - 14, BLACK);
  display.drawRect(x + 5, y - 18, 3, 3, BLACK);
  display.drawPixel(x + 8, y - 18, BLACK);
  display.drawPixel(x + 8, y - 16, BLACK);
  display.display();
}

void drawGalagaAlien(Adafruit_SSD1306 display, uint16_t x, uint16_t y , uint16_t COLOR) {
  display.fillRect(x, y - 3, 1, 3, COLOR);
  display.fillRect(x + 1, y - 4, 9, 2, COLOR);
  display.fillRect(x + 2, y - 5, 7, 6, COLOR);
  display.fillRect(x + 3, y - 1, 5, 1, BLACK);
  display.drawPixel(x + 5, y, BLACK);
  display.drawPixel(x + 2, y, BLACK);
  display.drawPixel(x + 8, y, BLACK);
  display.fillRect(x + 10, y - 3, 1, 3, COLOR);
  display.drawPixel(x + 2, y - 7, COLOR);
  display.drawPixel(x + 3, y - 6, COLOR);
  display.drawPixel(x + 7, y - 6, COLOR);
  display.drawPixel(x + 8, y - 7, COLOR);
  display.drawPixel(x + 3, y - 4, BLACK);
  display.drawPixel(x + 7, y - 4, BLACK);
  display.display();
}
void drawAxeManLeft(Adafruit_SSD1306 display, uint16_t x, uint16_t y , uint16_t COLOR) {
  display.fillRect(x, y - 19, 7, 6, COLOR);
  display.drawPixel(x, y - 19, BLACK);
  display.drawPixel(x + 6, y - 19, BLACK);
  display.drawPixel(x, y - 14, BLACK);
  display.drawPixel(x + 6, y - 14, BLACK);
  display.fillRect(x + 2, y - 19, 3, 2, BLACK);
  display.fillRect(x + 2, y - 15, 3, 2, BLACK);
  display.fillRect(x + 3, y - 18, 1, 14, COLOR);
  display.fillRect(x + 2, y - 11, 13, 3, COLOR);
  display.drawPixel(x + 14, y - 11, BLACK);
  display.fillRect(x + 7, y - 11, 6, 12, COLOR);
  display.fillRect(x + 9, y - 4, 2, 5, BLACK);
  display.fillRect(x + 13, y - 8, 2, 3, COLOR);
  display.fillRect(x + 8, y - 16, 4, 5, COLOR);
  display.fillRect(x + 9, y - 14, 2, 1, BLACK);
  display.display();
}

void drawSwordManLeft(Adafruit_SSD1306 display, uint16_t x, uint16_t y , uint16_t COLOR) {
  display.fillRect(x + 1, y - 15, 2, 10, COLOR);
  display.drawPixel(x + 1, y - 15, BLACK);
  display.drawPixel(x, y - 8, COLOR);
  display.fillRect(x + 3, y - 10, 5, 4, COLOR);
  display.fillRect(x + 3, y - 10, 1, 2, BLACK);
  display.fillRect(x + 5, y - 11, 3, 12, COLOR);
  display.fillRect(x + 7, y - 4, 2, 5, BLACK);
  display.drawPixel(x + 8, y - 5, COLOR);
  display.fillRect(x + 6, y - 16, 4, 5, COLOR);
  display.fillRect(x + 7, y - 14, 2, 1, BLACK);
  display.fillRect(x + 9, y - 3, 2, 4, COLOR);
  display.drawPixel(x + 9, y - 4, COLOR);
  display.fillRect(x + 9, y - 11, 5, 6, COLOR);
  display.drawPixel(x + 9, y - 11, BLACK);
  display.fillRect(x + 11, y - 10, 1, 4, BLACK);
  display.fillRect(x + 10, y - 9, 3, 1, BLACK);
  display.fillRect(x + 10, y - 5, 3, 1, COLOR);
  display.drawPixel(x + 11, y - 4, COLOR);
  display.display();
}
void drawMaceManLeft(Adafruit_SSD1306 display, uint16_t x, uint16_t y , uint16_t COLOR) {
  display.fillRect(x, y - 18, 4, 7, COLOR);
  display.drawPixel(x, y - 17, BLACK);
  display.drawPixel(x, y - 15, BLACK);
  display.drawPixel(x, y - 13, BLACK);
  display.drawPixel(x + 3, y - 17, BLACK);
  display.drawPixel(x + 3, y - 15, BLACK);
  display.drawPixel(x + 3, y - 13, BLACK);
  display.fillRect(x + 1, y - 11, 2, 6, COLOR);
  display.drawPixel(x + 3, y - 7, COLOR);
  display.fillRect(x + 3, y - 9, 2, 2, COLOR);
  display.fillRect(x + 5, y - 11, 4, 12, COLOR);
  display.drawPixel(x + 4, y - 10, COLOR);
  display.fillRect(x + 9, y - 4, 4, 5, COLOR);
  display.fillRect(x + 8, y - 4, 2, 5, BLACK);
  display.drawPixel(x + 12, y - 4, BLACK);
  display.fillRect(x + 9, y - 5, 2, 2, COLOR);
  display.drawPixel(x + 10, y - 6, BLACK);
  display.fillRect(x + 6, y - 12, 3, 1, COLOR);
  display.fillRect(x + 6, y - 18, 7, 6, COLOR);
  display.drawPixel(x + 7, y - 18, BLACK);
  display.drawPixel(x + 9, y - 18, BLACK);
  display.drawPixel(x + 11, y - 18, BLACK);
  display.fillRect(x + 7, y - 16, 2, 1, BLACK);
  display.fillRect(x + 10, y - 16, 2, 1, BLACK);
  display.fillRect(x + 7, y - 14, 5, 1, BLACK);
  display.fillRect(x + 10, y - 12, 7, 6, COLOR);
  display.fillRect(x - 10, y - 12, 3, 1, BLACK);
  display.fillRect(x + 11, y - 6, 5, 2, COLOR);
  display.drawPixel(x + 11, y - 5, BLACK);
  display.drawPixel(x + 15, y - 5, BLACK);
  display.fillRect(x + 13, y - 10, 1, 5, BLACK);
  display.fillRect(x + 12, y - 9, 3, 1, BLACK);
  display.drawPixel(x + 13, y - 4, COLOR);
  display.display();
}
void drawSpaceShip(Adafruit_SSD1306 display, uint16_t x, uint16_t y , uint16_t COLOR) {
  display.fillRect(x, y - 3, 9, 3, COLOR);
  display.drawPixel(x + 4, y, COLOR);
  display.drawPixel(x + 2, y - 1, BLACK);
  display.drawPixel(x + 6, y - 1, BLACK);
  display.drawPixel(x + 1, y - 4, COLOR);
  display.drawPixel(x + 7, y - 4, COLOR);
  display.drawRect(x + 3, y - 7, 3, 4, COLOR);
  display.drawPixel(x + 4, y - 8, COLOR);
  display.display();
}

void drawpixelman(Adafruit_SSD1306 display, uint16_t x, uint16_t y , uint16_t COLOR) {
  display.drawPixel(x + 4, y - 2, COLOR);
  display.drawPixel(x + 5, y - 2, COLOR);
  display.drawPixel(x + 6, y - 2, COLOR);
  display.drawPixel(x + 9, y - 2, COLOR);
  display.drawPixel(x + 10, y - 2, COLOR);
  display.drawPixel(x + 11, y - 2, COLOR);
  display.drawPixel(x + 6, y - 3, COLOR);
  display.drawPixel(x + 9, y - 3, COLOR);
  display.drawPixel(x + 6, y - 4, COLOR);
  display.drawPixel(x + 7, y - 4, COLOR);
  display.drawPixel(x + 8, y - 4, COLOR);
  display.drawPixel(x + 9, y - 4, COLOR);
  display.drawPixel(x + 7, y - 5, COLOR);
  display.drawPixel(x + 8, y - 5, COLOR);
  display.drawPixel(x + 3, y - 6, COLOR);
  display.drawPixel(x + 4, y - 6, COLOR);
  display.drawPixel(x + 7, y - 6, COLOR);
  display.drawPixel(x + 8, y - 6, COLOR);
  display.drawPixel(x + 11, y - 6, COLOR);
  display.drawPixel(x + 12, y - 6, COLOR);
  display.drawPixel(x + 4, y - 7, COLOR);
  display.drawPixel(x + 5, y - 7, COLOR);
  display.drawPixel(x + 7, y - 7, COLOR);
  display.drawPixel(x + 8, y - 7, COLOR);
  display.drawPixel(x + 10, y - 7, COLOR);
  display.drawPixel(x + 11, y - 7, COLOR);
  display.drawPixel(x + 5, y - 8, COLOR);
  display.drawPixel(x + 6, y - 8, COLOR);
  display.drawPixel(x + 7, y - 8, COLOR);
  display.drawPixel(x + 8, y - 8, COLOR);
  display.drawPixel(x + 9, y - 8, COLOR);
  display.drawPixel(x + 10, y - 8, COLOR);
  display.drawPixel(x + 7, y - 9, COLOR);
  display.drawPixel(x + 8, y - 9, COLOR);
  display.drawPixel(x + 5, y - 10, COLOR);
  display.drawPixel(x + 6, y - 10, COLOR);
  display.drawPixel(x + 7, y - 10, COLOR);
  display.drawPixel(x + 8, y - 10, COLOR);
  display.drawPixel(x + 9, y - 10, COLOR);
  display.drawPixel(x + 10, y - 10, COLOR);
  display.drawPixel(x + 5, y - 11, COLOR);
  display.drawPixel(x + 10, y - 11, COLOR);
  display.drawPixel(x + 5, y - 12, COLOR);
  display.drawPixel(x + 6, y - 12, COLOR);
  display.drawPixel(x + 8, y - 12, COLOR);
  display.drawPixel(x + 10, y - 12, COLOR);
  display.drawPixel(x + 5, y - 13, COLOR);
  display.drawPixel(x + 10, y - 13, COLOR);
  display.drawPixel(x + 5, y - 14, COLOR);
  display.drawPixel(x + 6, y - 14, COLOR);
  display.drawPixel(x + 7, y - 14, COLOR);
  display.drawPixel(x + 8, y - 14, COLOR);
  display.drawPixel(x + 9, y - 14, COLOR);
  display.drawPixel(x + 10, y - 14, COLOR);
  display.display();
}

void drawOrangeRight(Adafruit_SSD1306 display, uint16_t x, uint16_t y , uint16_t COLOR) {
  display.drawPixel(x + 3, y - 1, COLOR);
  display.drawPixel(x + 4, y - 1, COLOR);
  display.drawPixel(x + 5, y - 1, COLOR);
  display.drawPixel(x + 6, y - 1, COLOR);
  display.drawPixel(x + 9, y - 1, COLOR);
  display.drawPixel(x + 10, y - 1, COLOR);
  display.drawPixel(x + 11, y - 1, COLOR);
  display.drawPixel(x + 3, y - 2, COLOR);
  display.drawPixel(x + 4, y - 2, COLOR);
  display.drawPixel(x + 9, y - 2, COLOR);
  display.drawPixel(x + 3, y - 3, COLOR);
  display.drawPixel(x + 4, y - 3, COLOR);
  display.drawPixel(x + 9, y - 3, COLOR);
  display.drawPixel(x + 10, y - 3, COLOR);
  display.drawPixel(x + 3, y - 4, COLOR);
  display.drawPixel(x + 4, y - 4, COLOR);
  display.drawPixel(x + 10, y - 4, COLOR);
  display.drawPixel(x + 4, y - 5, COLOR);
  display.drawPixel(x + 5, y - 5, COLOR);
  display.drawPixel(x + 10, y - 5, COLOR);
  display.drawPixel(x + 5, y - 6, COLOR);
  display.drawPixel(x + 6, y - 6, COLOR);
  display.drawPixel(x + 9, y - 6, COLOR);
  display.drawPixel(x + 10, y - 6, COLOR);
  display.drawPixel(x + 2, y - 7, COLOR);
  display.drawPixel(x + 3, y - 7, COLOR);
  display.drawPixel(x + 6, y - 7, COLOR);
  display.drawPixel(x + 7, y - 7, COLOR);
  display.drawPixel(x + 9, y - 7, COLOR);
  display.drawPixel(x + 10, y - 7, COLOR);
  display.drawPixel(x + 3, y - 8, COLOR);
  display.drawPixel(x + 4, y - 8, COLOR);
  display.drawPixel(x + 7, y - 8, COLOR);
  display.drawPixel(x + 8, y - 8, COLOR);
  display.drawPixel(x + 9, y - 8, COLOR);
  display.drawPixel(x + 10, y - 8, COLOR);
  display.drawPixel(x + 13, y - 8, COLOR);
  display.drawPixel(x + 4, y - 9, COLOR);
  display.drawPixel(x + 6, y - 9, COLOR);
  display.drawPixel(x + 10, y - 9, COLOR);
  display.drawPixel(x + 11, y - 9, COLOR);
  display.drawPixel(x + 13, y - 9, COLOR);
  display.drawPixel(x + 4, y - 10, COLOR);
  display.drawPixel(x + 5, y - 10, COLOR);
  display.drawPixel(x + 9, y - 10, COLOR);
  display.drawPixel(x + 10, y - 10, COLOR);
  display.drawPixel(x + 11, y - 10, COLOR);
  display.drawPixel(x + 13, y - 10, COLOR);
  display.drawPixel(x + 5, y - 11, COLOR);
  display.drawPixel(x + 8, y - 11, COLOR);
  display.drawPixel(x + 11, y - 11, COLOR);
  display.drawPixel(x + 12, y - 11, COLOR);
  display.drawPixel(x + 13, y - 11, COLOR);
  display.drawPixel(x + 5, y - 12, COLOR);
  display.drawPixel(x + 10, y - 12, COLOR);
  display.drawPixel(x + 11, y - 12, COLOR);
  display.drawPixel(x + 5, y - 13, COLOR);
  display.drawPixel(x + 6, y - 13, COLOR);
  display.drawPixel(x + 10, y - 13, COLOR);
  display.drawPixel(x + 11, y - 13, COLOR);
  display.drawPixel(x + 6, y - 14, COLOR);
  display.drawPixel(x + 7, y - 14, COLOR);
  display.drawPixel(x + 8, y - 14, COLOR);
  display.drawPixel(x + 9, y - 14, COLOR);
  display.drawPixel(x + 10, y - 14, COLOR);
  display.display();
}

void drawOrangeLeft(Adafruit_SSD1306 display, uint16_t x, uint16_t y , uint16_t COLOR) {
  display.drawPixel(x + 4, y - 1, COLOR);
  display.drawPixel(x + 5, y - 1, COLOR);
  display.drawPixel(x + 6, y - 1, COLOR);
  display.drawPixel(x + 9, y - 1, COLOR);
  display.drawPixel(x + 10, y - 1, COLOR);
  display.drawPixel(x + 11, y - 1, COLOR);
  display.drawPixel(x + 12, y - 1, COLOR);
  display.drawPixel(x + 6, y - 2, COLOR);
  display.drawPixel(x + 11, y - 2, COLOR);
  display.drawPixel(x + 12, y - 2, COLOR);
  display.drawPixel(x + 5, y - 3, COLOR);
  display.drawPixel(x + 6, y - 3, COLOR);
  display.drawPixel(x + 11, y - 3, COLOR);
  display.drawPixel(x + 12, y - 3, COLOR);
  display.drawPixel(x + 5, y - 4, COLOR);
  display.drawPixel(x + 11, y - 4, COLOR);
  display.drawPixel(x + 12, y - 4, COLOR);
  display.drawPixel(x + 5, y - 5, COLOR);
  display.drawPixel(x + 10, y - 5, COLOR);
  display.drawPixel(x + 11, y - 5, COLOR);
  display.drawPixel(x + 5, y - 6, COLOR);
  display.drawPixel(x + 6, y - 6, COLOR);
  display.drawPixel(x + 9, y - 6, COLOR);
  display.drawPixel(x + 10, y - 6, COLOR);
  display.drawPixel(x + 5, y - 7, COLOR);
  display.drawPixel(x + 6, y - 7, COLOR);
  display.drawPixel(x + 8, y - 7, COLOR);
  display.drawPixel(x + 9, y - 7, COLOR);
  display.drawPixel(x + 12, y - 7, COLOR);
  display.drawPixel(x + 13, y - 7, COLOR);
  display.drawPixel(x + 2, y - 8, COLOR);
  display.drawPixel(x + 5, y - 8, COLOR);
  display.drawPixel(x + 6, y - 8, COLOR);
  display.drawPixel(x + 7, y - 8, COLOR);
  display.drawPixel(x + 8, y - 8, COLOR);
  display.drawPixel(x + 11, y - 8, COLOR);
  display.drawPixel(x + 12, y - 8, COLOR);
  display.drawPixel(x + 2, y - 9, COLOR);
  display.drawPixel(x + 4, y - 9, COLOR);
  display.drawPixel(x + 5, y - 9, COLOR);
  display.drawPixel(x + 9, y - 9, COLOR);
  display.drawPixel(x + 11, y - 9, COLOR);
  display.drawPixel(x + 2, y - 10, COLOR);
  display.drawPixel(x + 4, y - 10, COLOR);
  display.drawPixel(x + 5, y - 10, COLOR);
  display.drawPixel(x + 6, y - 10, COLOR);
  display.drawPixel(x + 10, y - 10, COLOR);
  display.drawPixel(x + 11, y - 10, COLOR);
  display.drawPixel(x + 2, y - 11, COLOR);
  display.drawPixel(x + 3, y - 11, COLOR);
  display.drawPixel(x + 4, y - 11, COLOR);
  display.drawPixel(x + 7, y - 11, COLOR);
  display.drawPixel(x + 10, y - 11, COLOR);
  display.drawPixel(x + 4, y - 12, COLOR);
  display.drawPixel(x + 5, y - 12, COLOR);
  display.drawPixel(x + 10, y - 12, COLOR);
  display.drawPixel(x + 4, y - 13, COLOR);
  display.drawPixel(x + 5, y - 13, COLOR);
  display.drawPixel(x + 9, y - 13, COLOR);
  display.drawPixel(x + 10, y - 13, COLOR);
  display.drawPixel(x + 5, y - 14, COLOR);
  display.drawPixel(x + 6, y - 14, COLOR);
  display.drawPixel(x + 7, y - 14, COLOR);
  display.drawPixel(x + 8, y - 14, COLOR);
  display.drawPixel(x + 9, y - 14, COLOR);
  display.display();
}
