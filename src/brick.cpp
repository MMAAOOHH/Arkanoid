#include "brick.h"
#include "collision.h"
#include "engine.h"
#include <SDL/SDL.h>


void Brick::take_damage()
{
	if (type == unbreakable)
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
			SDL_SetRenderDrawColor(render, 255, 200, 255, 255);
			break;
		case 2:
			SDL_SetRenderDrawColor(render, 255, 200, 200, 255);
			break;
		case 3:
			SDL_SetRenderDrawColor(render, 255, 200, 150, 255);
			break;
	}

	SDL_Rect rect = { (int)x - w/2, (int)y - h/2, w, h};
	SDL_RenderFillRect(render, &rect);
}
