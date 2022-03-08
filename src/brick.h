#pragma once

struct Brick
{
	bool alive = true;

	float x = 600;
	float y = 200;

	float w = 100.f;
	float h = 40.f;

	void draw();
};
