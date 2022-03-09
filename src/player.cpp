#include <iostream>
#include "player.h"
#include "engine.h"
#include "game.h"
#include "collision.h"


void Player::update()
{
	// move with input
	if (keys[SDL_SCANCODE_D])
		x += move_speed * delta_time;
	if (keys[SDL_SCANCODE_A])
		x -= move_speed * delta_time;

	/*
	if (keys[SDL_SCANCODE_W])
		y -= 400 * delta_time;
	if (keys[SDL_SCANCODE_S])
		y += 400 * delta_time;
		*/

	// shoot! pew pew
	shoot_timer -= delta_time;
	if (keys[SDL_SCANCODE_SPACE] && shoot_timer < 0.f)
	{
		Ball& proj = balls[next_projectile_index];
		proj.alive = true;

		//Projectile position = player position
		proj.x = x;
		proj.y = y - 10;


		proj.velocity_x = 200.f;
		
		if (next_projectile_index % 2)
			proj.velocity_y = 200.f;
		else
			proj.velocity_y = -200.f;
			

		shoot_timer = 0.2f;

		next_projectile_index++;
		next_projectile_index = next_projectile_index % BALL_MAX;
	}
}

void Player::draw()
{
	//Set the color
	SDL_SetRenderDrawColor(render, 150, 25, 40, 255);
	//Create Player rect
	SDL_Rect rect = { (int)x - w/2, (int)y - h/2, w, h };

	//Render
	SDL_RenderFillRect(render, &rect);
}
