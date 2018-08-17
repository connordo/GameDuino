#pragma once
#include <GameDuino.h>
#include "Example_Ship.h"

class ExampleGame :
	public GameDuino
{
protected:
	void Update() override;
public:
	ExampleGame();
	~ExampleGame();
};

