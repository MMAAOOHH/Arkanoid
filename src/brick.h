#pragma once
#include "collision.h"

struct Brick
{
	bool alive = true;
	bool unbreakable = false;
	int hit_points = 3;

	//Position
	float x;
	float y;

	//Size
	float w = 50.f;
	float h = 20.f;

	AABB getCollision() { return { x, y, x + w, y + h}; }

	void take_damage();
	void draw();
};
