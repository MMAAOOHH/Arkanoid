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
		velocity_y = -velocity_y + sign(-velocity_y) * 10;
	}
}

void Ball::draw()
{
	if (!alive)
		return;

	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
	SDL_Rect rect = { (int)x - 4, (int)y - 4, 8, 8 };

	SDL_RenderFillRect(render, &rect);
}

bool Ball::step(float dx, float dy)
{
	//Collision circle for collision
	Circle circle = { x + dx, y + dy, 4 };
	//draw_circle(circle);

	for (int i = 0; i < NUM_BRICKS; ++i)
	{
		/* Brick& brick = bricks[i];
		if (!brick.alive)
			continue; */		
		
		Brick* brick = bricks[i];
		if (brick == nullptr)
			continue;

		//Makes collision for brick
		AABB box = AABB::make_from_position_size(brick->x, brick->y, brick->w, brick->h);

		//Collisioncheck with bricks
		if (aabb_circle_intersect(box, circle))
		{
			brick->take_damage();
			return false;
		}
	}

	//Check collision with player
	Player& p = player;
	AABB box = AABB::make_from_position_size(p.x, p.y, p.w, p.h);
	if (aabb_circle_intersect(box, circle))
		return false;

	// Check collisions with game borders
	if (x + dx < 0 || x + dx >= 800 ||
		y + dy < 0 || y + dy >= 600)
	{
		return false;
	}

	x += dx;
	y += dy;
	return true;
}
