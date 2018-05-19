#include "bullet.h"

class AlienBullet : public Bullet{
private:
  const unsigned char * getSpriteBmp();
public:
  static const unsigned char PROGMEM alien_bullet_bmp[];
  AlienBullet(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos);
};
