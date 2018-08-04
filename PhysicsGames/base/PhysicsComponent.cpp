#include "PhysicsComponent.h"



PhysicsComponent::PhysicsComponent(class Actor* owner) :Component(owner)
{
}


PhysicsComponent::~PhysicsComponent()
{
}

PhysicsComponent::Vector PhysicsComponent::getVelocity()
{
	return velocity;
}

void PhysicsComponent::setVelocity(Vector v)
{
	this->velocity = v;
}

PhysicsComponent::Vector PhysicsComponent::getAccell()
{
	return accelleration;
}

void PhysicsComponent::setAccell(Vector a)
{
	this->accelleration = a;
}

void PhysicsComponent::Update()
{
	//TODO Implement
}
