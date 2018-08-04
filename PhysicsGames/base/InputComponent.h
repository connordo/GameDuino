#pragma once
#include "Component.h"
class InputComponent :
	public Component
{
public:
	InputComponent(class Actor* owner);
	~InputComponent();

	void Update() override;
};

