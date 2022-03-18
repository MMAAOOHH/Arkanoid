#include "ball.h"
#include "engine.h"
#include "collision.h"
#include "game.h"

float sign(float a) { return a > 0.f ? 1.f : -1.f; } //Where does this live?

void Ball::update()
{
	if (!alive)
		return;

	if (!step(velocity_x * delta_time, 0.f))
	{
		velocity_x = -velocity_x + sign(-velocity_x) * 2;
	}

	if (!step(0.f, velocity_y * delta_time))
	{
		if (hit_paddle)
		{
			//Direction depending where on paddle we hit
			if ((x < game.player.x && velocity_x > 0) || (x > game.player.x && velocity_x < 0))
				velocity_x = -velocity_x;
		}
		velocity_y = -velocity_y + sign(-velocity_y) * 2;
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
		Brick* brick = game.level.bricks[i];
		if (brick == nullptr || !brick->alive)
			continue;

		if (aabb_circle_intersect(brick->getCollision(), circle))
		{
			hit_paddle = false;
			brick->damage(this);
			return false;
		}
	}

	//Collision with paddle
	if (dy > 0) //Depenetration-ish
	{
		AABB player_box = AABB::make_from_position_size(game.player.x, game.player.y, game.player.w, game.player.h);
		if (aabb_circle_intersect(player_box, circle))
		{
			hit_paddle = true;
			bricks_since_paddle = 0;
			return false;
		}
	}

	//Collision with game borders (top, left, right)
	if (x + dx < 0 || x + dx >= SCREEN_WIDTH || y + dy < 0) 
	{
		hit_paddle = false;
		return false;
	}
	
	//Kill on bot-border
	if (y + dy >= SCREEN_HEIGHT) 
	{
		alive = false;

		game.active_balls--;
		if (game.active_balls <= 0)
		{
			game.player.take_damage();
			game.has_ball = false;
		}
	}
			
	//Ball movement
	x += dx;
	y += dy;
	return true;
}

void Ball::grow_for_split()
{
	bricks_since_paddle++;
	if (bricks_since_paddle >= 5)
		ask_to_split();
}

void Ball::ask_to_split()
{
	bricks_since_paddle = 0;
	game.split_ball(*this);
}
