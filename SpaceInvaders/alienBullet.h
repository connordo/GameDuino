#include "bullet.h"

class alienBullet : public Bullet{
private:
  const unsigned char * getSpriteBmp();
public:
  static const unsigned char PROGMEM alien_bullet_bmp[];
  alienBullet(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos);
};
