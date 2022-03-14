#pragma once

#include <SDL/SDL.h>
#include "engine.h"
#include "player.h"
#include "level.h"
#include "ball.h"

#define BALL_MAX 10

extern Player player;
extern Level level;
extern Ball balls[BALL_MAX];

//TODO: Struck vs class, weird to have a private?
struct Game 
{
	//TODO: Dont know if really needed
	//Constructor 
	Game();
	//Destructor
	~Game();

	void init();
	void handleEvents();
	void update();
	void render();
	void clean();

	//TODO: Find C# equivalent to understand better, maybe just use isRunning bool.
	bool running() { return isRunning; }

private:
	bool isRunning = false;
};
