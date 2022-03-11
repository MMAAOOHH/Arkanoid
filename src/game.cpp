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

//Refactoring
void Game::init()
{
	//Initilalize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if(renderer)
			SDL_SetRenderDrawColor(renderer, 25, 25, 40, 255);

		isRunning = true;
	}
	else
		isRunning = false;
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


			// (scancode == SDL_SCANCODE_ESCAPE)
				//Running = false;

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
	//player.update();
	//ball.update(); etc
}

void Game::render() 
{
	//Clear the current rendering target with the drawing color.
	SDL_RenderClear(renderer);
						
	//	add what to render ex player.draw();


	//All balls
	/*for (int i = 0; i < BALL_MAX; ++i)
	{
		balls[i].draw();
	}*/

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
