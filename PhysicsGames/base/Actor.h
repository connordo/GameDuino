#pragma once
#include "SpriteComponent.h"
#include "PhysicsComponent.h"

/**
* Any element on the screen.
*	All are given a PhysicsComponent for the PhysicsEngine to access.
*	If they do not move set the boolean in PhysicsComponent
*	
*/
class Actor
{
protected:
	// Pointer to game
	class GameDuino* game;

	// Position and size
	struct Position {
		int x;
		int y;
	} position;
	struct Size {
		int h;
		int w;
	} size;

	// Components (others can be added as needed)
	PhysicsComponent* pc;
	SpriteComponent* sc;
	
public:
	// Set components in constructor of children.
	Actor(class GameDuino* game);
	~Actor();

	Position getPosition();
	Size getSize();

	SpriteComponent* getSpriteComponent();
	PhysicsComponent* getPhysicsComponent();

	/**
	* Override to add more functionality. 
	*/
	virtual void Update();

	
};

