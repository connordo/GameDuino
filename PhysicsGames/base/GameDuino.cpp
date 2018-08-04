#include "GameDuino.h"



void GameDuino::Update()
{
}

GameDuino::GameDuino()
{
}


GameDuino::~GameDuino()
{
}

GameDuino::state GameDuino::getState()
{
	return game_state;
}

void GameDuino::setState(state s)
{
	this->game_state = s;
}


void GameDuino::init()
{
}

void GameDuino::loop()
{
	while (game_state == LOOPING) {
		Update();
	}
}

void GameDuino::end()
{
}
