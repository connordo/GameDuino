#include "GameDuino.h"

Adafruit_SSD1306* GameDuino::display = GameDuino::initDisplay();

Adafruit_SSD1306 * GameDuino::initDisplay()
{
	Adafruit_SSD1306 * new_display = new Adafruit_SSD1306(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
	new_display->begin(SSD1306_SWITCHCAPVCC);
	return new_display;
}

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
