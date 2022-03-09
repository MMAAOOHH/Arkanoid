#pragma once

struct Player
{
	//Start position
	float x = 400.f;
	float y = 560.f;

	//Paddle size
	float w = 128.f;
	float h = 16.f;

	float move_speed = 800.f;

	float shoot_timer = 0.f;
	int next_projectile_index = 0;

	void update();
	void draw();
};
