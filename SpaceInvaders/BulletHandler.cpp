#include "BulletHandler.h"

BulletHandler::BulletHandler(Adafruit_SSD1306 *display){
  userShot = new Bullet(display, 0, -10);
}
