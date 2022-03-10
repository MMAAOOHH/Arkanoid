#pragma once

struct Brick
{
	bool alive = true;

	enum brick_type 
	{
		a = 1, 
		b = 2, 
		c = 3, 
		unbreakable
	};

	brick_type type = c;
	//hitpoints defined by type
	int hit_points = type;

	//Position
	float x = 400.f;
	float y = 300.f;

	//Size
	float w = 60.f;
	float h = 20.f;

	void take_damage();
	void draw();
};
