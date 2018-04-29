#pragma once
#include "GameObject.h"
#include <buttons.h>
#include "StarFruit.h"
#include "Arduino.h"


class StarGame: public GameObject {
    private:
        StarFruit* starFruit;
    public:
        StarGame();
        void start(Adafruit_SSD1306 display);
        void tick(Adafruit_SSD1306 display);
};