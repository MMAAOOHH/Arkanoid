#pragma once

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "engine.h"
#include "player.h"
#include "level.h"
#include "ball.h"

#define BALL_MAX 10
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

//TODO: Struck vs class, weird to have a private field?
struct Game 
{
	//TODO: Dont know if really needed
	//Constructor 
	Game();
	//Destructor
	~Game();

	Player player;
	Level level;
	Ball balls[BALL_MAX];

	void init();
	void handleEvents();
	void update();
	void render();
	void clean();

	//TODO: Find C# equivalent to understand better, maybe just use isRunning bool.
	bool running() { return isRunning; }

	void start();
	void win();
	void lose();

private:
	bool isRunning = false;
};

extern Game game;
