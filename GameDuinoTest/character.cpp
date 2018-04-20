#include "character.h"

character::character() {
  x_position = 0;
  y_position = 63;
}
character::drawSprite(Adafruit_SSD1306 display, int x, int y) {
  x_position = x;
  y_position = y;
  int COLOR = 1;
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
}
character::eraseSprite(Adafruit_SSD1306 display) {
  int COLOR = BLACK;
  int x = x_position;
  int y = y_position;
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
}
