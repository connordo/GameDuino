#pragma once
#include <SpriteComponent.h>
class Example_SC :
	public SpriteComponent
{
private:
	static const unsigned char PROGMEM alien_up_bmp[];
	static const unsigned char PROGMEM alien_down_bmp[];
	static const unsigned char PROGMEM death_animation_bmp[];
	static const unsigned char PROGMEM spaceship_bmp[];

protected:
	const unsigned char* getCurrentSprite() override;

public:
	enum sprite_type{
		ALIEN_UP, ALIEN_DOWN, DEATH, SPACESHIP
	};
	Example_SC(Actor* owner, sprite_type startSprite, int numOfSprites, int animFrames, int bmpWidth);
	~Example_SC();
};

