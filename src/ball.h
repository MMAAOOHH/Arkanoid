#pragma once

struct Ball
{
	bool alive = false;

	//Position
	float x;
	float y;

	float size = 8; // feedback: format: float values are usually initialized with .f of .0f format. 

	float velocity_x;
	float velocity_y;

	void update();
	void draw();

	//bool check_collisions();
	bool step(float dx, float dy); // feedback: I'd suggest to combine this function with update(), as this one is called from update it seems but
								 // is doing somewhat similar thing.

	int bricks_since_paddle = 0;
	bool hit_paddle = false;

	void grow_for_split();
	void ask_to_split();
};
