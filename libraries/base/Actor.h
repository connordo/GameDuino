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
public:
	struct Position {
		int x;
		int y;
		Position(int x, int y) {
			this->x = x;
			this->y = y;
		}
	};
	struct Size {
		int h;
		int w;
		Size(int h, int w) {
			this->h = h;
			this->w = w;
		}
	};

	// Set components in constructor of children.
	Actor(class GameDuino* game, Position* initPos, Size* size);
	~Actor();

	Position* getPosition();
	Size* getSize();

	SpriteComponent* getSpriteComponent();
	PhysicsComponent* getPhysicsComponent();

	/**
	* Override to add more functionality. 
	*/
	virtual void Update();

protected:
	// Pointer to game
	class GameDuino* game;

	// Position and size
	Position* position;
	Size* size;

	// Components (others can be added as needed)
	PhysicsComponent* pc;
	SpriteComponent* sc;

};

