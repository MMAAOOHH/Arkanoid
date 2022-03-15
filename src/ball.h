#pragma once

struct Ball
{
	bool alive = false;

	//Position
	float x;
	float y;

	float size = 8;

	float velocity_x;
	float velocity_y;

	void update();
	void draw();

	bool step(float dx, float dy);

	bool hit_paddle = false;
};
