#pragma once
#include "Actor.h"
#include <Adafruit_SSD1306.h>

class GameDuino
{
protected:
	// Set to array of pointers in constructor
	Actor** actors;
	
	enum state { INIT, LOOPING, END } game_state;
	Adafruit_SSD1306* display;
	

	/**
	* Clear screen, update each actor, update physics, draw each actor & object
	*/
	virtual void Update();
public:
	GameDuino();
	~GameDuino();

	state getState();
	void setState(state s);

	/**
	* Do whatever setup is necessary before the loop begins.
	* NOTE: Arduino file should call init, loop, then end (in order).
	*/
	virtual void init();

	/** 
	* Calls update in a while loop as long as state == LOOPING
	*/
	virtual void loop();

	/**
	* Runs code for ending the game
	*/
	virtual void end();

};

