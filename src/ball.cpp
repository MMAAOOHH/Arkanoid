#include <iostream>
#include "ball.h"
#include "engine.h"
#include "collision.h"
#include "game.h"

float sign(float a) { return a > 0.f ? 1.f : -1.f; }

void Ball::update()
{
	if (!alive)
		return;

	if (!step(velocity_x * delta_time, 0.f))
	{
		velocity_x = -velocity_x + sign(-velocity_x) * 10;
	}

	if (!step(0.f, velocity_y * delta_time))
	{
		if (hit_paddle)
		{
			//Direction depending where on paddle we hit
			if ((x < player.x && velocity_x > 0) || (x > player.x && velocity_x < 0))
				velocity_x = -velocity_x;
		}
		
		velocity_y = -velocity_y + sign(-velocity_y) * 10;
	}
}

void Ball::draw()
{
	if (!alive)
		return;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_Rect rect = { (int)x - size/2, (int)y - size / 2, size, size };

	SDL_RenderFillRect(renderer, &rect);
}

bool Ball::step(float dx, float dy)
{
	//Collision circle for ball
	Circle circle = { x + dx, y + dy, 4 };

	//Collision with bricks
	for (int i = 0; i < NUM_BRICKS; ++i)
	{
		Brick* brick = bricks[i];
		if (brick == nullptr || !brick->alive)
			continue;

		//Collision with bricks
		if (aabb_circle_intersect(brick->getCollision(), circle))
		{
			hit_paddle = false;
			brick->take_damage();
			return false;
		}
	}

	//Collision with paddle
	Player& p = player;
	AABB player_box = AABB::make_from_position_size(p.x, p.y, p.w, p.h);
	if (aabb_circle_intersect(player_box, circle))
	{
		hit_paddle = true;
		return false;
	}

	//Collision with game borders (top, left, right)
	if (x + dx < 0 || x + dx >= 800 || y + dy < 0) 
	{
		hit_paddle = false;
		return false;
	}
	
	//Kill on bot-border
	if (y + dy >= 600)
		alive = false;

	//Ball movement
	x += dx;
	y += dy;
	return true;
}
