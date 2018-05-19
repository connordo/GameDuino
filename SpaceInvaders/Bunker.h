#include "EntityGroup.h"
#include "BunkerBlock.h"

class Bunker : public EntityGroup{
protected:

public:
Bunker(Adafruit_SSD1306 *display, int init_x_pos, int init_y_pos);
};
