#include "Actor.h"



Actor::Actor(class GameDuino* game)
{
	this->game = game;
}


Actor::~Actor()
{
}

void Actor::Update()
{
	sc->Update();
}

Actor::Position Actor::getPosition()
{
	return position;
}

Actor::Size Actor::getSize()
{
	return size;
}

SpriteComponent * Actor::getSpriteComponent()
{
	return sc;
}

PhysicsComponent * Actor::getPhysicsComponent()
{
	return pc;
}
