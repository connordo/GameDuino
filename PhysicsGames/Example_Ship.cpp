#include "Example_Ship.h"



Example_Ship::Example_Ship(class GameDuino* game, Position* initPos, Size* size):Actor(game, initPos, size)
{
	sc = new Example_SC(this, Example_SC::ALIEN_UP, 2, 10, 16);
}


Example_Ship::~Example_Ship()
{
}
