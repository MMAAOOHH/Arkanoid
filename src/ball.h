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

	//bool check_collisions();
	bool step(float dx, float dy);

	//void split(); 
	//int bricks_since_paddle = 0;

	bool hit_paddle = false;


};
