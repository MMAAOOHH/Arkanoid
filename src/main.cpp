#include "game.h" //#include - "pastes" code in.

int main()
{
	game.init();
	//Gameloop
	while (game.running())
	{
		game.handleEvents();
		game.update();
		game.render();

		//Limits fps, ( 60 )
		SDL_Delay(16); 
	}
	game.clean();
	return 0;
}
