#include "SpriteComponent.h"

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
	display->drawBitmap(owner->getPosition().x, owner->getPosition().y, getCurrentSprite(), 
		bmpWidth, owner->getSize().h, WHITE);
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
