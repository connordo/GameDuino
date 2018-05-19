#pragma once
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Bullet.h"
#include "AlienBullet.h"


class BulletHandler {
private:
  Adafruit_SSD1306 *display;
  Bullet *userShot;
  AlienBullet alienShots[5] = {
    AlienBullet(display, 0, -10),
    AlienBullet(display, 0, -10),
    AlienBullet(display, 0, -10),
    AlienBullet(display, 0, -10),
    AlienBullet(display, 0, -10)
  };
public:
  BulletHandler(Adafruit_SSD1306 *display);
};
