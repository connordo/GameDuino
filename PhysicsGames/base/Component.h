#pragma once
class Component
{
protected:
	class Actor {
	public:
		struct Position {
			int x;
			int y;
		} getPosition();
		struct Size {
			int h;
			int w;
		} getSize();
	} *owner;
public:
	Component(class Actor* owner);
	~Component();

	virtual void Update() = 0;
};

