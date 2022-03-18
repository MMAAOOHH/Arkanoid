#include "game.h" //#include - "pastes" code in.

int main()
{
	game.init();
	game.level.create();
	game.start();

	//Gameloop
	while (game.running())
	{
		game.handle_events();//input
		game.update();
		game.render();

		//Limits fps, ( 60 )
		SDL_Delay(16); 
	}
	game.clean();
	return 0;
}
