#pragma once

struct Brick
{
	//Why are d
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
	float x = 300.f;
	float y = 200.f;

	//Size
	float w = 80.f;
	float h = 20.f;

	void take_damage();
	void draw();
};
