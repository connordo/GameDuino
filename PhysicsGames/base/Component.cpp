#include "Component.h"



Component::Component(class Actor* owner)
{
	this->owner = owner;
}


Component::~Component()
{
}
