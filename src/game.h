#pragma once

#include <SDL/SDL.h>
#include "engine.h"
#include "player.h"
#include "ball.h"
#include "brick.h"

#define BALL_MAX 10
#define MAP_COLS 16
#define MAP_ROWS 20
#define NUM_BRICKS (MAP_COLS * MAP_ROWS)

extern Player player;
extern Ball balls[BALL_MAX];
extern Brick* bricks[MAP_COLS * MAP_ROWS];

void loadMap();

struct Game 
{
	//Constructor 
	Game();
	//Destructor
	~Game();

	void init();
	void handleEvents();
	void update();
	void render();
	void clean();

	//Find C# equivalent to understand better
	bool running() { return isRunning; }

private:
	bool isRunning;
};

