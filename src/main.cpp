#include "game.h" //#include - "pastes" in code, includes it.

//main entry point, needed for all .exe files. 
int main()
{
	//Creates game
	Game* game = new Game();
	game->init();

	//Gameloop
	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();

		//Limits fps, ( 60 )
		SDL_Delay(16); 
	}
	game->clean();
}
