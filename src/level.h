#pragma once

#include "brick.h"

#define MAP_COLS 16
#define MAP_ROWS 20
#define NUM_BRICKS (MAP_COLS * MAP_ROWS)

struct Level 
{
	Brick* bricks[MAP_COLS * MAP_ROWS];

	void create();
	void reset();
	void draw();

	void win();
	void remove_brick();

private:
	int brick_count = 0;
};
