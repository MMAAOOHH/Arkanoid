#include <iostream>
#include "player.h"
#include "engine.h"
#include "game.h"
#include "collision.h"


void Player::update()
{
	//Move with input if not hitting edge of screen
	//TODO: Make method of collision check
	if ((keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_RIGHT]) && (x + w / 2) <= SCREEN_WIDTH)
		x += move_speed * delta_time;
	if ((keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_LEFT]) && (x - w / 2) >= 0)
		x -= move_speed * delta_time;

	//Shoot ball TODO: Move from player maybe?
	if ((keys[SDL_SCANCODE_SPACE] && !game.has_ball))
		game.shoot_ball();
}

void Player::draw()
{
	//Set the color
	SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255);
	//Create Player rect
	SDL_Rect rect = { (int)x - w/2, (int)y - h/2, w, h };
	//Render
	SDL_RenderFillRect(renderer, &rect);
}

void Player::take_damage() 
{
	lives--;
	std::cout << "Player lives : " << lives << std::endl;

	if (lives <= 0)
		game.lose();
}
