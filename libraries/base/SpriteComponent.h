#pragma once
#include "Component.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_MOSI   9 //SDA on the Board
#define OLED_CLK   10 //SCL on the Board
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13

class SpriteComponent :
	public Component
{
private:
	static Adafruit_SSD1306 * display;
	static Adafruit_SSD1306 * initDisplay();
protected:
	int animFrames;
	int startSprite;
	int currentSpriteNum;
	int numOfSprites;
	int animCounter;

	int bmpWidth;

	virtual const unsigned char* getCurrentSprite()=0;
public:
	SpriteComponent(Actor* owner, int startSprite, int numOfSprites, int animFrames, int bmpWidth);
	~SpriteComponent();

	void setNewSprite(int startSprite, int numOfSprites, int animFrames, int bmpWidth);
	void setAnimSpeed(int animFrames);

	// TODO Might want getters

	void draw();
	void Update() override;
};

