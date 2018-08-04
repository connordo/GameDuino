#pragma once
#include "Component.h"
class PhysicsComponent :
	public Component
{
private:
	struct Vector {
		int x;
		int y;
	} velocity, accelleration;

public:
	PhysicsComponent(class Actor* owner);
	~PhysicsComponent();

	Vector getVelocity();
	void setVelocity(Vector v);

	Vector getAccell();
	void setAccell(Vector a);

	void Update() override;
};

