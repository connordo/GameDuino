#include "Sprite.h"

Sprite::Sprite(const char bitmapInput[], int bitmapInputLength, int w, int h){
  for(int i = 0; i < bitmapInputLength; i++){
    bitmap[i] = bitmapInput[i];
  }
  width = w;
  height = h;
}
