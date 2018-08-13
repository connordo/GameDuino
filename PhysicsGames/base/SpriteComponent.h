#pragma once
#include "Component.h"
#include <Adafruit_SSD1306.h>

class SpriteComponent :
	public Component
{
private:
	static Adafruit_SSD1306 * display;	
protected:
	int animFrames;
	int startSprite;
	int currentSpriteNum;
	int numOfSprites;
	int animCounter;

	int bmpWidth;

	virtual const unsigned char* getCurrentSprite()=0;
public:
	SpriteComponent(class Actor* owner, int startSprite, int numOfSprites, int animFrames, int bmpWidth);
	~SpriteComponent();

	void setNewSprite(int startSprite, int numOfSprites, int animFrames, int bmpWidth);
	void setAnimSpeed(int animFrames);

	// TODO Might want getters

	void draw();
	void Update() override;
};

