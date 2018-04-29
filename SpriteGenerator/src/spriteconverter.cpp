#include <cstdio>
#include "bitmap_image.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void writeBufferToConsole(std::vector<int> v){
  if(v.size()==8)
  cout << "0b";
  for(int i = 0; i < 8; i++){
    cout << v.at(i);
  }
  cout << ", ";
}

int main(int argc, char** argv)
{
  cout << argv[1] << endl;

  if(argc != 3){
    printf("Error\n");
    return 1;
  }
  bitmap_image image(argv[1]);
  string spriteName = argv[2];
  if (!image)
  {
    cout << "Error - Failed to open: " << argv[1] << endl;
    return 1;
  }
  unsigned int total_number_of_pixels = 0;

  int height = image.height();
  int width  = image.width();

  cout << "image height: " << image.height() << endl;
  cout << "image width:  " << image.width() << endl;

  cout << "\n\n\n" << endl;
  cout << "static const unsigned char PROGMEM " << spriteName << "[]=\n{ " << endl;
  std::vector<int> v;
  v.clear();
  for (int y = 0; y < height; y++)
  {
    for (int x = 0; x < width; x++)
    {
      rgb_t colour;
      image.get_pixel(x, y, colour);
      if(colour.red < 100)
      v.push_back(1);
      else
      v.push_back(0);
      if(v.size()==8){
        writeBufferToConsole(v);
        v.clear();
      }
    }
  }
  if(v.size()>0){
    while(v.size()!=8){
      v.push_back(0);
    }
  }
  cout <<  "\n};" << endl;
  return 0;
}

// void drawDinoRight(Adafruit_SSD1306 display, uint16_t x, uint16_t y , uint16_t COLOR) {
//   display.drawLine(x, y - 11, x, y - 7, COLOR);
//   display.drawLine(x + 1, y - 9, x + 1, y - 6, COLOR);
//   display.drawLine(x + 2, y - 8, x + 2, y - 5, COLOR);
//   display.fillRect(x + 3, y - 7, 6, 4, COLOR);
//   display.fillRect(x + 4, y - 3, 5, 4, COLOR);
//   display.drawLine(x + 6, y - 2, x + 6, y, BLACK);
//   display.drawLine(x + 5, y - 1, x + 7, y - 1, BLACK);
//   display.drawPixel(x + 7, y, BLACK);
//   display.drawPixel(x + 9, y, COLOR);
//   display.fillRect(x + 6, y - 9, 5, 4, COLOR);
//   display.fillRect(x + 8, y - 16, 3, 12, COLOR);
//   display.drawPixel(x + 10, y - 5, BLACK);
//   display.drawPixel(x + 7, y - 10, BLACK);
//   display.drawLine(x + 5, y - 8, x + 12, y - 8, COLOR);
//   display.drawPixel(x + 12, y - 7, COLOR);
//   display.drawPixel(x + 8, y - 16, BLACK);
//   display.drawPixel(x + 10, y - 15, BLACK);
//   display.fillRect(x + 11, y - 16, 5, 6, COLOR);
//   display.drawPixel(x + 15, y - 16, BLACK);
//   display.drawPixel(x + 15, y - 11, BLACK);
//   display.drawLine(x + 12, y - 12, x + 15, y - 12, BLACK);
//   display.display();
// }
