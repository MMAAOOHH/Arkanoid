#include "brick.h"
#include "engine.h"

void Brick::take_damage()
{
	if (type == u)
		return;

	hit_points--;

	if (hit_points <= 0)
		alive = false;
}

void Brick::draw()
{
	if (!alive)
		return;

	switch(hit_points) 
	{
		case 1:
			SDL_SetRenderDrawColor(renderer, 255, 200, 150, 255);
			break;
		case 2:
			SDL_SetRenderDrawColor(renderer, 255, 200, 200, 255);
			break;
		case 3:
			SDL_SetRenderDrawColor(renderer, 255, 200, 255, 255);
			break;
	}

	SDL_Rect rect = { x, y , w, h };
	SDL_RenderFillRect(renderer, &rect);
}
