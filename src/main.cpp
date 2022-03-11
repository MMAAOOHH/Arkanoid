//#include - "pastes" in code, includes it.
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

//main entry point, needed for all .exe files. 
int main()
{
	//Creates game
	Game* game = new Game();
	game->init();

	//Gets cpu ticks
	Uint64 previous_ticks = SDL_GetPerformanceCounter();
 
	//Gameloop
	while (game->running())
	{
		game->handleEvents();

		//For framerate independence, delta time
		Uint64 ticks = SDL_GetPerformanceCounter();
		Uint64 delta_ticks = ticks - previous_ticks;
		previous_ticks = ticks;
		delta_time = (float)delta_ticks / SDL_GetPerformanceFrequency();

		game->update();
		game->render();

		//Limits fps, ( 60 )
		SDL_Delay(16); 
	}
}
