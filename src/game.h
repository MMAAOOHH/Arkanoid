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

//TODO: Struck vs class, weird to have structs with private fields?
// feedback: only difference between struct vs class is the default-private members of classes.
// actually this is the point with classes: some things should be hidden for "external" users of the class.
// For example player object could be private here and then Game class will provide functions to access it. This will limit
// the design of your program to your intentions, so it will be more clear what is expected/allowed from your code and what is not.
// Right now player object is completely exposed to whoever has instance of the game class. And maybe this is not something that you
// would like to do from the design perspective.
struct Game 
{
	// feedback: they are not required by compiler, only needed if you want to do something useful in them, like deleting previously allocated memory.
	// In this case I'd say they could be skipped.
	//TODO: Dont know if really needed? 
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
