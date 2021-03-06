#include "GameDuino.h"

Adafruit_SSD1306* GameDuino::display = new Adafruit_SSD1306(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

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
	game_state = LOOPING;
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
