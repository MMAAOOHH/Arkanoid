#pragma once
#include "collision.h"

struct Brick
{
	bool alive = true;

	enum brick_type 
	{
		a = 1, 
		b = 2, 
		c = 3, 
		u //unbreakable
	};

	brick_type type = c;

	//hitpoints defined by type
	int hit_points = type;

	//Position
	float x;
	float y;

	//Size
	float w = 50.f;
	float h = 20.f;

	AABB getCollision() { return { x, y, w, h}; }

	void take_damage();
	void draw();
};
