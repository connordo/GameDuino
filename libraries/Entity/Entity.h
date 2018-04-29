#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

enum Direction {UP, DOWN, LEFT, RIGHT};

class Entity {
    protected:
        int x_pos;
        int y_pos;
        int width;
        int height;
        unsigned char sprite_bmp[];
       
    public:
        Entity(int init_x_pos, int init_y_pos);
        virtual void draw();
        virtual void move(Direction d);

}