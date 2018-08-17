#include "SpriteComponent.h"
#include "Actor.h"

Adafruit_SSD1306 * SpriteComponent::display = SpriteComponent::initDisplay();

Adafruit_SSD1306 * SpriteComponent::initDisplay()
{
	Adafruit_SSD1306 * new_display = new Adafruit_SSD1306(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
	new_display->begin(SSD1306_SWITCHCAPVCC);
	return new_display;
}

SpriteComponent::SpriteComponent(Actor * owner, int startSprite, int numOfSprites, int animFrames, int bmpWidth):Component(owner)
{
	this->currentSpriteNum = startSprite;
	this->startSprite = startSprite;
	this->numOfSprites = numOfSprites;
	this->animFrames = animFrames;
	this->bmpWidth = bmpWidth;
	animCounter = 0;

}

SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::setNewSprite(int startSprite, int numOfSprites, int animFrames, int bmpWidth)
{
	this->startSprite = startSprite;
	this->numOfSprites = numOfSprites;
	this->animFrames = animFrames;
}

void SpriteComponent::setAnimSpeed(int animFrames)
{
	this->animFrames = animFrames;
}

void SpriteComponent::draw()
{
	display->drawBitmap(owner->getPosition()->x, owner->getPosition()->y, getCurrentSprite(), 
		bmpWidth, owner->getSize()->h, WHITE);
}

void SpriteComponent::Update()
{
	if (numOfSprites > 1) {
		// Then there is another sprite this actor can display as
		if (++animCounter >= animFrames) {
			// Sprite should change
			if (++currentSpriteNum - startSprite > numOfSprites) {
				currentSpriteNum = startSprite;
			}
		}
	}
}
