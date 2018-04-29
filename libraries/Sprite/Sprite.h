#ifndef _SPRITE_H
#define _SPRITE_H

class Sprite{
public:
 static unsigned char bitmap[];
  int width;
  int height;

  Sprite(const char bitmapInput[], int bitmapInputLength, int w, int h);
};
#endif // _SPRITE_H
