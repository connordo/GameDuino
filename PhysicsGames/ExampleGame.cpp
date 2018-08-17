#include "ExampleGame.h"



void ExampleGame::Update()
{
	display->clearDisplay();
	for (int i = 0; i < 3; i++) {
		actors[i]->Update();
	}
	for (int i = 0; i < 3; i++) {
		actors[i]->getSpriteComponent()->draw();
	}
	display->display();
}

ExampleGame::ExampleGame()
{	
	actors = new Actor*[3]{
		new Example_Ship(this, new Actor::Position(12, 13), new Actor::Size(8, 11)),
		new Example_Ship(this, new Actor::Position(23, 42), new Actor::Size(8, 11)),
		new Example_Ship(this, new Actor::Position(42, 50), new Actor::Size(8, 11))
	};
}


ExampleGame::~ExampleGame()
{
}
