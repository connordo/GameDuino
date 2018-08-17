/*
 Name:		GameDuinoWorkbench.ino
 Created:	8/4/2018 2:25:21 PM
 Author:	taylo
*/
#include <SPI.h>
#include <Wire.h>
#include <GameDuino.h>
#include "ExampleGame.h"

GameDuino* game;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  Serial.println("Starting");
	game = new ExampleGame();
  Serial.println("End Setup");
}

// the loop function runs over and over again until power down or reset
void loop() {
  Serial.println("Start INIT");
	game->init();
 Serial.println("Start LOOP");
	game->loop();
 Serial.println("Start End");
	game->end();
}
