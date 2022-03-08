//#include - "pastes" in code, includes it.
#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "engine.h"
#include "player.h"
#include "game.h"
#include "collision.h"

//main entry point, needed for all .exe files. 
int main()
{

	SDL_Init(SDL_INIT_EVERYTHING); 
	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,600,0); 
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
 
	bool running = true;

	//Gets cpu ticks
	Uint64 previous_ticks = SDL_GetPerformanceCounter();

	//Creates bricks
	for(int i=0; i<BRICK_MAX; ++i)
	{
		bricks[i].y = 140 * i;
	}
 
	//Gameloop
	while (running)
	{
		//For framerate independence, delta time
		Uint64 ticks = SDL_GetPerformanceCounter();
		Uint64 delta_ticks = ticks - previous_ticks;
		previous_ticks = ticks; 
		delta_time = (float)delta_ticks / SDL_GetPerformanceFrequency(); 
 

		//Input handling
		SDL_Event event;
		while(SDL_PollEvent(&event)) 
		{
			switch(event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
 
			case SDL_KEYDOWN:
			{
				//Gets key down
				int scancode = event.key.keysym.scancode;


				if (scancode == SDL_SCANCODE_ESCAPE)
					running = false;

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
			}
		}
 
		//Set the color used for drawing operations(Rect, Line and Clear).
		SDL_SetRenderDrawColor(render, 25, 25, 40, 255);

		//Clear the current rendering target with the drawing color.
		SDL_RenderClear(render);

		player.update();
		player.draw();

		//All projectiles
		for(int i=0; i<BALL_MAX; ++i)
		{
			balls[i].update();
			balls[i].draw();
		}

		//All bricks
		for(int i=0; i<BRICK_MAX; ++i)
		{
			bricks[i].draw();
		}

		//Update the screen with any rendering performed since the previous call.
		SDL_RenderPresent(render);
 
		//Limits fps, ( 60 )
		SDL_Delay(16); 
	}
}
