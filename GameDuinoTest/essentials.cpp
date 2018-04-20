#include "essentials.h"

void welcomeScreen(Adafruit_SSD1306 display) {
  display.clearDisplay();
  display.display();

  display.setTextSize(1);
  display.setTextColor(1);
  display.setCursor(35, 21);
  display.println("Welcome to");

  display.setTextSize(2);
  display.setCursor(11, 21 + 8);
  display.setTextColor(WHITE);
  display.print("GameDuino");

  display.drawLine(0, 0, 127, 0, 1);
  display.drawLine(0, 0, 0, 63, 1);
  display.drawLine(127, 0, 127, 63, 1);
  display.drawLine(0, 63, 127, 63, 1);
  display.display();
}

void menuScreen(Adafruit_SSD1306 display) {
  display.clearDisplay();
  display.display();

  display.setTextSize(2);
  display.setTextColor(1);
  display.setCursor(15, 21);
  display.println("Dino Test");

  display.setTextSize(1);
  display.setCursor(10, 50);
  display.setTextColor(WHITE);
  display.print("Press 'A' to Start");
  display.display();
}
