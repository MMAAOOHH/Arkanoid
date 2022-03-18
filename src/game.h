#pragma once

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "engine.h"
#include "player.h"
#include "level.h"
#include "ball.h"

#define BALL_MAX 6
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

	int next_ball_index = 0;
	int active_balls = 0;

	bool has_ball = false;

	//const char* levels[3];
	//int level_index = 0;

	void init();
	void handle_events();
	void update();
	void render();
	void clean();

	//TODO: Find C# equivalent to understand better, maybe just use isRunning bool.
	bool running() { return isRunning; }

	void start();
	//void win();
	void lose();

	void shoot_ball();
	void split_ball(Ball& ball_to_split);

private:
	bool isRunning = false;
};

extern Game game;
