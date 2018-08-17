#include "Component.h"



Component::Component(Actor* owner)
{
	this->owner = owner;
}


Component::~Component()
{
}
