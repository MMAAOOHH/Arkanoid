#include "game.h"

const char* LEVEL =
"................"
"................"
"................"
".##############."
"..############.."
"...##########..."
"................"
"................"
"................"
".##############."
".##############."
"................"
"................"
"................"
"................"
"................"
"................"
"................"
"................"
"................";

Player player;
Ball balls[BALL_MAX];
Brick* bricks[MAP_COLS * MAP_ROWS] = { nullptr };

void loadMap()
{
	const char* ptr = LEVEL;
	for (int y = 0; y < MAP_ROWS; ++y)
	{
		for (int x = 0; x < MAP_COLS; ++x, ++ptr)
		{
			if (*ptr != '#')
				continue;

			Brick* brick = new Brick();
			brick->x = x * (brick->w + 1);
			brick->y = y * (brick->h + 1);

			bricks[y * MAP_COLS + x] = brick;
		}
	}
}

Game::Game(){}
Game::~Game(){}

void Game::init()
{
	//Initilalize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		isRunning = true;
	}
	else
		isRunning = false;

	//Gets the current CPU counter value.
	previous_ticks = SDL_GetPerformanceCounter();
}

void Game::handleEvents()
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
	//For framerate independence, delta time, 
	Uint64 ticks = SDL_GetPerformanceCounter();
	Uint64 delta_ticks = ticks - previous_ticks;
	previous_ticks = ticks;
	delta_time = (float)delta_ticks / SDL_GetPerformanceFrequency();

	player.update();

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

	player.draw();

	//All balls
	for (int i = 0; i < BALL_MAX; ++i)
	{
		balls[i].draw();
	}

	// Draw all bricks
	/*for (int i = 0; i < NUM_BRICKS; ++i)
	{
		Brick* brick = bricks[i];
		if (brick == nullptr)
			continue;

		brick->draw();
	}*/

	SDL_RenderPresent(renderer);
}
void Game::clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
