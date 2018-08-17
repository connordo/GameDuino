#pragma once
#include <Actor.h>
#include "Example_SC.h"

class Example_Ship :
	public Actor
{
public:
	Example_Ship(class GameDuino* game, Position* initPos, Size* size);
	~Example_Ship();
};

