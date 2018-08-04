#include "SpriteComponent.h"



SpriteComponent::SpriteComponent(class Actor* owner, int animFrames):Component(owner)
{
	this->animFrames = animFrames;
}


SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::Update()
{
	// TODO Implement
}
