#pragma once
#include "Actor.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_MOSI   9 //SDA on the Board
#define OLED_CLK   10 //SCL on the Board
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13

class GameDuino
{
protected:
	// Set to array of pointers in constructor
	Actor** actors;
	
	enum state { INIT, LOOPING, END } game_state;
	static Adafruit_SSD1306* display;
	static Adafruit_SSD1306 * initDisplay();

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

