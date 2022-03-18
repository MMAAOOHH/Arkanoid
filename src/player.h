#pragma once

struct Player
{
	//Start position
	float x = 400.f;
	float y = 580.f;

	//Paddle size
	float w = 128.f;
	float h = 12.f;

	float move_speed = 800.f;

	int lives = 3;

	void update();
	void draw();

	void take_damage();

	//bool check_border_collision();
};
