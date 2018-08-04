#pragma once
#include "Component.h"
#include <Adafruit_SSD1306.h>

class SpriteComponent :
	public Component
{
private:
	static Adafruit_SSD1306 * display;
	int animFrames;
public:
	SpriteComponent(class Actor* owner, int animFrames);
	~SpriteComponent();

	void Update() override;
};

