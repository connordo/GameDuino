#pragma once
class Component
{
private:
	class Actor* owner;
public:
	Component(class Actor* owner);
	~Component();

	virtual void Update() = 0;
};

