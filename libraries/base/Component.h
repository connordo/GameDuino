#pragma once

class Actor;
class Component
{
protected:
	Actor* owner;
public:
	Component(Actor* owner);
	~Component();

	virtual void Update() = 0;
};

