#include "game.h"

Game game;
Game::Game(){}
Game::~Game(){}

void Game::init()
{
	//Initilalize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		isRunning = true;
	}
	else
		isRunning = false;

	//Gets the current CPU counter value.
	previous_ticks = SDL_GetPerformanceCounter();
}

void Game::handle_events()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;

		case SDL_KEYDOWN:
		{
			//Gets key down
			int scancode = event.key.keysym.scancode;
			
			//Quit with esc
			if(scancode == SDL_SCANCODE_ESCAPE)
				isRunning = false;

			keys[scancode] = true;

			break;
		}

		case SDL_KEYUP:
		{
			//Gets key up
			int scancode = event.key.keysym.scancode;
			keys[scancode] = false;

			break;
		}

		case SDL_MOUSEMOTION:

			//Get mouse things
			break;
		}
	}
}

void Game::update() 
{
	//For framerate independence, setting delta time  TODO: Move to engine.update();
	Uint64 ticks = SDL_GetPerformanceCounter();
	Uint64 delta_ticks = ticks - previous_ticks;
	previous_ticks = ticks;
	delta_time = (float)delta_ticks / SDL_GetPerformanceFrequency();

	//Player
	player.update();

	//Ball
	for (int i = 0; i < BALL_MAX; ++i) 
	{
		balls[i].update();
	}
}

void Game::render() 
{
	SDL_SetRenderDrawColor(renderer, 25, 25, 40, 255);
	//Clear the current rendering target with the drawing color.
	SDL_RenderClear(renderer);

	level.draw();
	player.draw();

	//All balls
	for (int i = 0; i < BALL_MAX; ++i)
	{
		balls[i].draw();
	}

	SDL_RenderPresent(renderer);
}
void Game::clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}


void Game::shoot_ball()
{
	Ball& ball = balls[next_ball_index];
	ball.alive = true;

	//Ball start position = player position
	ball.x = game.player.x;
	ball.y = game.player.y - 10;

	ball.velocity_x = 200.f;
	ball.velocity_y = -200.f;

	next_ball_index++;
	next_ball_index = next_ball_index % BALL_MAX;
}
